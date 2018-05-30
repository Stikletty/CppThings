#pragma once

#include <string>
#include <iostream> //f�jl m�veletekhez
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
	bool DirectoryExists(const std::string& name);	
	std::string GetCurrentTimeString();
	std::string GetWorkDir();
	std::string GetThisComputerName();
	std::string GetThisUserName();

private:
	std::string WcharToString(const wchar_t input[INFO_BUFFER_SIZE]);
};

