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
#include <iostream> //f�jl m�veletekhez
#include <fstream> //f�jl m�veletekhez
#include "Utility.h" //k�nyvt�r, id�, stb.. lek�rdez�s


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

