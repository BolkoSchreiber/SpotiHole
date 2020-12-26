#pragma once

namespace Utils
{
	class Utils
	{
	public:
		static void DebugPrint(const char*);
		static void DebugPrint(int);
		static int GetFileSize(const char* filename);
		static bool FileExists(std::string file);
	};
}