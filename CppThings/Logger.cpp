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

/**
* Könyvtár létezést vizsgálja.
*
* @param std::string name Directory path
* @return bool true -> exists, false -> not exists
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
* Log file will be in the directory where the program exe is.
*
* @param std::string logfilepath The path to the Logfile
* @return
*/
Logger::Logger(const std::string& logFileName)
{
	std::string fullLogFilePath = this->GetWorkDir() + logFileName;

	logfile.open(fullLogFilePath, std::fstream::out | std::fstream::app);
	if (logfile.is_open())
	{
		logfile << this->GetCurrentTimeString() << " - Logging started." << std::endl;
		logfile << this->GetCurrentTimeString() << " - Logging directory: " << this->GetWorkDir() << std::endl;
		logfile.close();
	}
	else std::cout << "ERROR: Unable to open file: " << fullLogFilePath << std::endl;
}

/**
* Logges class constructor overload
* User defined log directory
*
* @param std::string logFileDirectory The path to the logfile with "\" on the end.
* @param std::string logfilepath The path to the Logfile.
* @return
*/
Logger::Logger(const std::string& logFileDirectory, const std::string& logFileName)
{
	std::string fullLogFilePath = "";
	bool customDirectoryExists = true;

	if (this->DirectoryExists(logFileDirectory)) {
		fullLogFilePath = logFileDirectory + logFileName;
	}
	else {
		fullLogFilePath = this->GetWorkDir() + logFileName;
		customDirectoryExists = false;
	}	

	std::cout << "!! DEBUG !! -> full path:" << fullLogFilePath << std::endl;

	logfile.open(fullLogFilePath, std::fstream::out | std::fstream::app);
	if (logfile.is_open())
	{
		logfile << this->GetCurrentTimeString() << " - Logging started." << std::endl;
		logfile << this->GetCurrentTimeString() << " - Work directory: " << this->GetWorkDir() << std::endl;
		if (customDirectoryExists) {
			logfile << this->GetCurrentTimeString() << " - Log directory: " << logFileDirectory << std::endl;
		}
		else {
			logfile << this->GetCurrentTimeString() << " - Can't open defined log directory. Log directory will be the work directory: " << this->GetWorkDir() << std::endl;
		}
		logfile.close();
	}
	else std::cout << "ERROR: Unable to open file: " << fullLogFilePath << std::endl;
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
