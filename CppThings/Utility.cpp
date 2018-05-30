#include "stdafx.h"
#include "Utility.h"


Utility::Utility()
{
}


Utility::~Utility()
{
}

/**
* Könyvtár létezést vizsgálja.
*
* @param std::string name Directory path
* @return bool true -> exists, false -> not exists
*/
bool Utility::DirectoryExists(const std::string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

std::string Utility::WcharToString(const wchar_t input[INFO_BUFFER_SIZE])
{
	std::wstring ws(input);
	std::string convertStringToReturn(ws.begin(), ws.end());

	return convertStringToReturn;
}

/**
* Dátum és idõ lekérésére szolgál.
*
* @param
* @return std::string "%Y-%m-%d %H:%M:%S" formátumban az idõt adja vissza.
*/
std::string Utility::GetCurrentTimeString() {
	auto t = std::time(nullptr);
	std::tm tm;
	localtime_s(&tm, &t);

	std::ostringstream oss;
	oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
	auto str = oss.str();
	return str;
}

std::string Utility::GetWorkDir()
{
	CHAR pBuf[MAX_PATH];
	std::string fileName;


	int bytes = GetModuleFileNameA(NULL, pBuf, MAX_PATH);
	if (bytes == 0)
		return "";
	else {
		fileName = pBuf;
		fileName.erase(fileName.find_last_of("\\") + 1, fileName.length());
		return fileName;
	}

}

std::string Utility::GetThisComputerName()
{
	//Source: https://stackoverflow.com/questions/27914311/get-computer-name-and-logged-user-name?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
	wchar_t infoBuf[INFO_BUFFER_SIZE];
	DWORD  bufCharCount = INFO_BUFFER_SIZE;
	
	if (!GetComputerName(infoBuf, &bufCharCount))
		perror("GetComputerName");
	//_tprintf(TEXT("\nComputer name:      %s"), infoBuf);

	return this->WcharToString(infoBuf);
}

std::string Utility::GetThisUserName()
{
	//Source: https://stackoverflow.com/questions/27914311/get-computer-name-and-logged-user-name?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa	
	TCHAR  infoBuf[INFO_BUFFER_SIZE];
	DWORD  bufCharCount = INFO_BUFFER_SIZE;

	// Get and display the user name.
	if( !GetUserName( infoBuf, &bufCharCount ) )
		perror("GetUserName");
	//_tprintf( TEXT("\nUser name:          %s"), infoBuf );

	return this->WcharToString(infoBuf);
}
