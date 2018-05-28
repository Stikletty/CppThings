#pragma once

#include <string>
#include <iomanip> //idõ megállapításhoz
#include <ctime> //idõ megállapításhoz
#include <sstream> //idõ megállapításhoz
#include <windows.h> //aktuális könyvtárhoz
#include <direct.h> //aktuális könyvtárhoz

#define INFO_BUFFER_SIZE 32767

class Utility
{
public:
	Utility();
	~Utility();

public:
	inline bool DirectoryExists(const std::string& name);
	std::string GetCurrentTimeString();
	std::string GetWorkDir();
	std::string GetThisComputerName();
	std::string GetThisUserName();

private:
	void printError( TCHAR* msg );
};

