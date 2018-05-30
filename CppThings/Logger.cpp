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
* Logges class constructor overload
* Log file will be in the directory where the program exe is.
*
* @param std::string logfilepath The path to the Logfile
* @return
*/
Logger::Logger(const std::string& logFileName)
{
	std::string fullLogFilePath = utility.GetWorkDir() + logFileName;

	logfile.open(fullLogFilePath, std::fstream::out | std::fstream::app);
	if (logfile.is_open())
	{
		logfile << utility.GetCurrentTimeString() << " - ******Logger started.******" << std::endl;
		logfile << utility.GetCurrentTimeString() << " - Computer name: " << utility.GetThisComputerName() << std::endl;
		logfile << utility.GetCurrentTimeString() << " - User name: " << utility.GetThisUserName() << std::endl;
		logfile << utility.GetCurrentTimeString() << " - Logging directory: " << utility.GetWorkDir() << std::endl;
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

	if (utility.DirectoryExists(logFileDirectory)) {
		fullLogFilePath = logFileDirectory + logFileName;
	}
	else {
		fullLogFilePath = utility.GetWorkDir() + logFileName;
		customDirectoryExists = false;
	}	

	std::cout << "!! DEBUG !! -> full path:" << fullLogFilePath << std::endl;

	this->logfile.open(fullLogFilePath, std::fstream::out | std::fstream::app);
	if (this->logfile.is_open())
	{
		this->logfile << utility.GetCurrentTimeString() << " - ******Logger started.******" << std::endl;
		this->logfile << utility.GetCurrentTimeString() << " - Work directory: " << utility.GetWorkDir() << std::endl;
		this->logfile << utility.GetCurrentTimeString() << " - Computer name: " << utility.GetThisComputerName() << std::endl;
		this->logfile << utility.GetCurrentTimeString() << " - User name: " << utility.GetThisUserName() << std::endl;
		if (customDirectoryExists) {
			this->logfile << utility.GetCurrentTimeString() << " - Log directory: " << logFileDirectory << std::endl;
		}
		else {
			this->logfile << utility.GetCurrentTimeString() << " - Can't open defined log directory. Log directory will be the work directory: " << utility.GetWorkDir() << std::endl;
		}
		//logfile.close();
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
	if (this->logfile.is_open()) {
		this->logfile << utility.GetCurrentTimeString() << " - ******Logger ended.******" << std::endl;
		this->logfile.close();
	}
}

void Logger::LogToFile(const std::string message)
{

	if (this->logfile.is_open()) {
		this->logfile << utility.GetCurrentTimeString() << " - " << message << std::endl;
	}

}
