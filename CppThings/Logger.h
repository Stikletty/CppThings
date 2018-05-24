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
#include <iomanip> //id� meg�llap�t�shoz
#include <ctime> //id� meg�llap�t�shoz
#include <sstream> //id� meg�llap�t�shoz
#include <Windows.h> //aktu�lis k�nyvt�rhoz
#include <direct.h> //aktu�lis k�nyvt�rhoz

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

