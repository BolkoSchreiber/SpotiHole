// ==========================================================
// Project: SpotiHole
// 
// Component: SpotiHole.dll
//
// Purpose: Adblocker
//          
// Initial author: meik97
//
// Started: 18.06.2020
// ==========================================================

#pragma once

namespace Modules
{
	class Adblock
	{
	private:
		static const char* currentTrack;
		static bool isAd;
		static std::string savedSong;

	public:
		Adblock();
		static bool _fastcall EnableSkips_hk(void* _this, DWORD edx);
		static std::string GetCurrentTrack();
		static void __fastcall SetCurrentTrack_stub(void* _this, DWORD edx, int a2, int a3, __int64 speed, int normalization, int urgency, int flag, int a8, int stream_type);
		static void IsAdOrTrack();
		static void SkipAd();
		static void __fastcall DisableBanner_stub(void* _this, DWORD edx, int a2, int a3);
		static void __fastcall DisableVideoAds_stub(void* __this, DWORD edx, int a2, int a3);
		static void __fastcall DisableVideoAds_stub2(void* __this, DWORD edx, int a2, int a3);
		static void __fastcall ResponseError_stub(void* __this, DWORD edx, int a2, int a3);
	};
}