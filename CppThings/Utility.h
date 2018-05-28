#pragma once

#include <string>
#include <iomanip> //id� meg�llap�t�shoz
#include <ctime> //id� meg�llap�t�shoz
#include <sstream> //id� meg�llap�t�shoz
#include <windows.h> //aktu�lis k�nyvt�rhoz
#include <direct.h> //aktu�lis k�nyvt�rhoz

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

