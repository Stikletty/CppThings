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
inline bool Utility::DirectoryExists(const std::string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
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
	//TODO: Hiba: TCHAR <-> const wchar_t

	TCHAR  infoBuf[INFO_BUFFER_SIZE];
	DWORD  bufCharCount = INFO_BUFFER_SIZE;

	if (!GetComputerName(infoBuf, &bufCharCount))
		printError(TEXT("GetComputerName"));
	_tprintf(TEXT("\nComputer name:      %s"), infoBuf);

	return std::string();
}

std::string Utility::GetThisUserName()
{
	//Source: https://stackoverflow.com/questions/27914311/get-computer-name-and-logged-user-name?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
	//TODO: Hiba: TCHAR <-> const wchar_t
	TCHAR  infoBuf[INFO_BUFFER_SIZE];
	DWORD  bufCharCount = INFO_BUFFER_SIZE;

	// Get and display the user name.
	if( !GetUserName( infoBuf, &bufCharCount ) )
	printError( TEXT("GetUserName") ); 
	_tprintf( TEXT("\nUser name:          %s"), infoBuf );

	return std::string();
}

void Utility::printError(TCHAR * msg)
{
	DWORD eNum;
	TCHAR sysMsg[256];
	TCHAR* p;

	eNum = GetLastError( );
	FormatMessage( FORMAT_MESSAGE_FROM_SYSTEM | 
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, eNum,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			sysMsg, 256, NULL );

	// Trim the end of the line and terminate it with a null
	p = sysMsg;
	while( ( *p > 31 ) || ( *p == 9 ) )
	++p;
	do { *p-- = 0; } while( ( p >= sysMsg ) &&
							( ( *p == '.' ) || ( *p < 33 ) ) );

	// Display the message
	_tprintf( TEXT("\n\t%s failed with error %d (%s)"), msg, eNum, sysMsg );
}
