// ==========================================================
// Project: SpotiHole
// 
// Component: SpotiHole.dll
//
// Purpose: Initialization checks
//          
// Initial author: meik97
//
// Started: 18.10.2020
// ==========================================================

#include "..\include\BaseInclude.hpp"

namespace Modules
{
	void Initialization::WelcomeMessage()
	{
		Utils::Utils::DebugPrint("SpotiHole v0.0.5 - by meik97");
	}

	void Initialization::InitDone()
	{
		Utils::Utils::DebugPrint("Done.");
	}

	bool Initialization::CheckSpotify()
	{
		if (Utils::Utils::GetFileSize("Spotify.exe") != 23412456)
		{
			Utils::Utils::DebugPrint("Wrong Spotify version!\nPlease reinstall Spotify with the correct Version");
			return false;
		}
		return true;
	}

	void Initialization::Console()
	{
		if (Utils::Utils::FileExists("console"))
		{
			ShowWindow(GetConsoleWindow(), SW_HIDE);
		}
	}
	
	Initialization::Initialization()
	{
		Initialization::Console();
		Initialization::WelcomeMessage();

		if (Initialization::CheckSpotify())
		{
			AutoUpdates::AutoUpdates();
			Adblock::Adblock();
			QuickPatch::QuickPatch();
			//Bitrate::Bitrate();
			Initialization::InitDone();
		}
	}
}