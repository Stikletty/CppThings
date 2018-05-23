/**
 * Loggger header file
 * Logger.h
 * Purpose: Make logging easier.
 *
 * @author Stikletty
 * @version 0.1 05/22/18
*/

#pragma once

#include <string>
//fájl mûveletekhez
#include <iostream>
#include <fstream>
//idõ megállapításhoz
#include <iomanip>
#include <ctime>
#include <sstream>
//aktuális könyvtárhoz
#include <Windows.h>
#include <direct.h>

class Logger
{
//functions
public:
	Logger();
	Logger(const std::string& logfilepath);
	~Logger();

private:
	inline bool DirectoryExists(const std::string& name);
	std::string GetCurrentTimeString();
	int GetWorkDir();
	
//variables
private:
	std::ofstream logfile;


};

