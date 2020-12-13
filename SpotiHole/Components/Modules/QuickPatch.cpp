// ==========================================================
// Project: SpotiHole
// 
// Component: SpotiHole.dll
//
// Purpose: Apply quick patches to Spotify
//          
// Initial author: meik97
//
// Started: 28.07.2020
// ==========================================================

#include "..\include\BaseInclude.hpp"

namespace Modules
{
	double QuickPatch::newspeed = 1;

	void QuickPatch::ToggleDeveloperTools(bool active)
	{
		bool* isDev = (bool*)0x01A14118;
		*isDev = active;
	}

	void QuickPatch::Branding()
	{
		DWORD OldProtection;

		VirtualProtect((LPVOID)0x1291708, sizeof(std::string), PAGE_EXECUTE_READWRITE, &OldProtection);
		*(std::string*)0x1291708 = (std::string)"SpotiHole";
		VirtualProtect((LPVOID)0x1291708, sizeof(std::string), OldProtection, &OldProtection);
	}

	void QuickPatch::ChangeSpeed(double speed)
	{
		if (speed < 0 || speed > 10)
		{
			Utils::Utils::DebugPrint("Please select a value between 1 and 10");
		}
		else
		{
			newspeed = speed;
		}
	}

	void __declspec(naked) __fastcall QuickPatch::CreateTrack_stub(void* _this, DWORD edx, int a2, int a3, double speed, int normalization, int urgency, int flag, int a8, int stream_type)
	{
		__asm
		{
			push    ebp
			mov     ebp, esp
			push	-1
			push    1218161h
			push	0CB608Ah
			retn
		}
	}

	void __fastcall QuickPatch::CreateTrack_hk(void* _this, DWORD edx, int a2, int a3, double speed, int normalization, int urgency, int flag, int a8, int stream_type)
	{
		CreateTrack_stub(_this, edx, a2, a3, newspeed, normalization, urgency, flag, a8, stream_type);
	}

	void QuickPatch::Commands()
	{
		std::string cmd;
		std::string number;
		double speed;

		std::getline(std::cin, cmd);
		
		if (strstr(cmd.c_str(), "speed") != nullptr)
		{
			try
			{
				number = cmd.substr(cmd.find("speed") + 6);
				speed = std::stod(number);
			}
			catch (std::out_of_range& ex )
			{
				Utils::Utils::DebugPrint("Invalid command - Use <cmd> <arg>");
				Commands();
			}
			catch (std::invalid_argument& ex)
			{
				Utils::Utils::DebugPrint("Invalid argument");
				Commands();
			}
			ChangeSpeed(speed);
		}

		Commands();
	}

	QuickPatch::QuickPatch()
	{
		Utils::Utils::DebugPrint("Applying QuickPatch patch...");
		Utils::Hook::InstallJmp(Functions::CreateTrack, CreateTrack_hk);
		QuickPatch::ToggleDeveloperTools(1);
		QuickPatch::Branding();
		std::thread t1(QuickPatch::Commands);
		t1.detach();
	}
}