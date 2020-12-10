// ==========================================================
// Project: SpotiHole
// 
// Component: SpotiHole.dll
//
// Purpose: Force high bitrate
//          
// Initial author: meik97
//
// Started: 10.12.2020
// ==========================================================

#include "..\include\BaseInclude.hpp"

namespace Modules
{

	int __fastcall Bitrate::sub_E71850_hk(void* __this, DWORD edx, int a2)
	{
		return 320000;
	}

	int Bitrate::sub_E70170_hk(int a1)
	{
		return 320000;
	}


	void __declspec(naked) __fastcall Bitrate::sub_E71280_stub_0(void* __this, DWORD edx, int a2, char a3, int bitrate)
	{
		__asm
		{
			mov     edx, 320000
			mov     ecx, eax
			mov		[ebp - 4], ecx
			cmp     esi, edx
			push	0E712AFh
			retn
		}
	}

	void __declspec(naked) __fastcall Bitrate::sub_E71280_stub_1(void* __this, DWORD edx, int a2, char a3, int bitrate)
	{
		__asm
		{
			mov		ecx, 320000
			mov     edx, eax
			mov		[ebp - 8], edx
			cmp     esi, ecx
			push	0E7138Eh
			retn
		}
	}

	void __declspec(naked) __fastcall Bitrate::sub_E71280_stub_2(void* __this, DWORD edx, int a2, char a3, int bitrate)
	{
		__asm
		{
			mov		eax, 320000
			cmp     eax, esi
			push	0E7144Dh
			retn
		}
	}

	void __declspec(naked) __fastcall Bitrate::sub_E71280_stub_3(void* __this, DWORD edx, int a2, char a3, int bitrate)
	{
		__asm
		{
			push    ebp
			mov     ebp, esp
			sub     esp, 8
			push    esi
			push	0E71287h
			retn
		}
	}

	void __fastcall Bitrate::sub_E71280_hk(void* __this, DWORD edx, int a2, char a3, int bitrate)
	{
		sub_E71280_stub_3(__this, edx, a2, a3, 320000);
	}


	int bitrate = 320000;
	void __declspec(naked) Bitrate::sub_E5F120_stub(signed int* a1, int a2, int a3, int a4, DWORD* a5, int a6, char* a7)
	{
		__asm
		{
			mov     eax, 160000
			cmp     ebx, eax
			cmovg   ebx, bitrate
			push	0E5F2ADh
			retn
		}
	}

	Bitrate::Bitrate()
	{
		Utils::Utils::DebugPrint("Applying Bitrate patch...");

		Utils::Hook::InstallJmp((void*)0xE71850, sub_E71850_hk);
		Utils::Hook::InstallJmp((void*)0xE70170, sub_E70170_hk);
		Utils::Hook::InstallJmp((void*)0xE60290, sub_E70170_hk);
		Utils::Hook::InstallCall((void*)0xE5F24B, sub_E70170_hk);
		Utils::Hook::InstallJmp((void*)0xE99840, sub_E70170_hk);
		Utils::Hook::InstallJmp((void*)0xE712A1, sub_E71280_stub_0);
		Utils::Hook::InstallJmp((void*)0xE71380, sub_E71280_stub_1);
		Utils::Hook::InstallJmp((void*)0xE71446, sub_E71280_stub_2);
		Utils::Hook::InstallJmp((void*)0xE71280, sub_E71280_hk);
		Utils::Hook::InstallJmp((void*)0xE5F2A3, sub_E5F120_stub);
	}
}
