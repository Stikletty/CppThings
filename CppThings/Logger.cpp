/**
 * Loggger cpp file
 * Logger.cpp
 * Purpose: Make logging easier.
 *
 * @author Stikletty
 * @version 0.1 05/22/18
*/

#include "stdafx.h"
#include "Logger.h"

/**
 * Logges class constructor
 *
 * @param 
 * @return
 */
Logger::Logger()
{
}

//TODO: Esetleg mappa ellenõrzésre használható lenne.
/*
#include <windows.h>
#include <string>

bool dirExists(const std::string& dirName_in)
{
  DWORD ftyp = GetFileAttributesA(dirName_in.c_str());
  if (ftyp == INVALID_FILE_ATTRIBUTES)
    return false;  //something is wrong with your path!

  if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
    return true;   // this is a directory!

  return false;    // this is not a directory!
}
*/


/**
* Fájl létezést vizsgálja. Nem használom.
*
* @param std::string logfilepath The path to the Logfile
* @return
*/
inline bool Logger::DirectoryExists(const std::string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

/**
* Dátum és idõ lekérésére szolgál.
*
* @param 
* @return std::string "%Y-%m-%d %H:%M:%S" formátumban az idõt adja vissza.
*/
std::string Logger::GetCurrentTimeString() {
	auto t = std::time(nullptr);
	std::tm tm;
	localtime_s(&tm, &t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    auto str = oss.str();
	return str;
}

std::string Logger::GetWorkDir()
{
	CHAR pBuf[MAX_PATH];
	std::string fileName;


	int bytes = GetModuleFileNameA(NULL, pBuf, MAX_PATH);
	if (bytes == 0)
		return "";
	else {
		fileName = pBuf;
		fileName.erase(fileName.find_last_of("\\")+1, fileName.length());
		return fileName;
	}
		
}

/**
* Logges class constructor overload
*
* @param std::string logfilepath The path to the Logfile
* @return
*/
Logger::Logger(const std::string& logfilename)
{
	std::string fullLogFilePath = this->GetWorkDir() + logfilename;

	logfile.open(fullLogFilePath, std::fstream::out | std::fstream::app);
	if (logfile.is_open())
	{
		logfile << this->GetCurrentTimeString() << " - Logging started." << std::endl;
		logfile << this->GetCurrentTimeString() << this->GetWorkDir() << " - Logging directory." << std::endl;
		logfile.close();
	}
	else std::cout << "Unable to open file" << std::endl;
}

Logger::Logger(const std::string& logFileDirectory, const std::string& logFileName)
{
	std::string fullLogFilePath = this->GetWorkDir() + logfilename;

	logfile.open(fullLogFilePath, std::fstream::out | std::fstream::app);
	if (logfile.is_open())
	{
		logfile << this->GetCurrentTimeString() << " - Logging started." << std::endl;
		logfile << this->GetCurrentTimeString() << this->GetWorkDir() << " - Logging directory." << std::endl;
		logfile.close();
	}
	else std::cout << "Unable to open file" << std::endl;
}

/**
 * Logges class destructor
 *
 * @param 
 * @return 
 */
Logger::~Logger()
{
}
