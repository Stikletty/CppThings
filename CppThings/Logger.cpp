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


/*

	Get work directory path:

	int bytes = GetModuleFileName(NULL, pBuf, len);
	if(bytes == 0)
	return -1;
	else
	return bytes;
*/


/**
* Fájl létezést vizsgálja. Nem használom.
*
* @param std::string logfilepath The path to the Logfile
* @return
*/
inline bool exists(const std::string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

/**
* Logges class constructor overload
*
* @param std::string logfilepath The path to the Logfile
* @return
*/
Logger::Logger(const std::string& logfilepath)
{
	logfile.open(logfilepath, std::fstream::out | std::fstream::app);
	if (logfile.is_open())
	{
		logfile << "Logging started.";			
		logfile.close();
	}
	else std::cout << "Unable to open file";
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
