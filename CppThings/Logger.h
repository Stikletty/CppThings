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
#include "Utility.h" //könyvtár, idõ, stb.. lekérdezés


class Logger
{
//functions
public:
	Logger();
	Logger(const std::string& logFileName);
	Logger(const std::string& logFileDirectory, const std::string& logFileName);
	~Logger();

private:

	
//variables
private:
	std::ofstream logfile;
	Utility utility;


};

