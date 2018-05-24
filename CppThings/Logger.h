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
#include <iostream> //fájl mûveletekhez
#include <fstream> //fájl mûveletekhez
#include <iomanip> //idõ megállapításhoz
#include <ctime> //idõ megállapításhoz
#include <sstream> //idõ megállapításhoz
#include <Windows.h> //aktuális könyvtárhoz
#include <direct.h> //aktuális könyvtárhoz

class Logger
{
//functions
public:
	Logger();
	Logger(const std::string& logfilename);
	~Logger();

private:
	inline bool DirectoryExists(const std::string& name);
	std::string GetCurrentTimeString();
	std::string GetWorkDir();
	
//variables
private:
	std::ofstream logfile;


};

