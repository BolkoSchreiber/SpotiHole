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

#pragma once

namespace Modules
{
	class QuickPatch
	{
	private:
		static double newspeed;

	public:
		QuickPatch();
		static void ToggleDeveloperTools(bool active);
		static void Branding();
		static void ChangeSpeed(double speed);
		static void Commands();
		static void __fastcall CreateTrack_hk(void* _this, DWORD edx, int a2, int a3, double speed, int normalization, int urgency, int flag, int a8, int stream_type);
		static void __fastcall CreateTrack_stub(void* _this, DWORD edx, int a2, int a3, double speed, int normalization, int urgency, int flag, int a8, int stream_type);
	};
}