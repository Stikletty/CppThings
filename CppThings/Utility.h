#pragma once

#include <string>
#include <iostream> //fájl mûveletekhez
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
	bool DirectoryExists(const std::string& name);	
	std::string GetCurrentTimeString();
	std::string GetWorkDir();
	std::string GetThisComputerName();
	std::string GetThisUserName();

private:
	std::string WcharToString(const wchar_t input[INFO_BUFFER_SIZE]);
};

