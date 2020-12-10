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

#pragma once

namespace Modules
{
	class Bitrate
	{
	public:
		Bitrate();
		static int __fastcall sub_E71850_hk(void* __this, DWORD edx, int a2);
		static int sub_E70170_hk(int a1);
		static void __fastcall sub_E71280_stub_0(void* __this, DWORD edx, int a2, char a3, int bitrate);
		static void __fastcall sub_E71280_stub_1(void* __this, DWORD edx, int a2, char a3, int bitrate);
		static void __fastcall sub_E71280_stub_2(void* __this, DWORD edx, int a2, char a3, int bitrate);
		static void __fastcall sub_E71280_stub_3(void* __this, DWORD edx, int a2, char a3, int bitrate);
		static void __fastcall sub_E71280_hk(void* __this, DWORD edx, int a2, char a3, int bitrate);
		static void sub_E5F120_stub(signed int* a1, int a2, int a3, int a4, DWORD* a5, int a6, char* a7);
	};
}
