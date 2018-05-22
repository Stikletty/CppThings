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
#include <iostream>
#include <fstream>

class Logger
{
public:
	Logger();
	Logger(const std::string& logfilepath);
	~Logger();

private:
	std::ofstream logfile;
};

