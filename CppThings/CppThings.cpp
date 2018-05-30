// CppThings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Logger.h"

int main()
{
	std::cout << "Program start" << std::endl;

	//std::cout << "1 parameter constructor" << std::endl;
	//Logger logfile("Events.log");

	std::cout << "2 parameter constructor" << std::endl;
	Logger logfilecustomdir("c:\\!TG\\VisualStudio\\CppThings\\Debug\\CustomLogTry\\", "Events.log");
	logfilecustomdir.LogToFile("Program start!");
	logfilecustomdir.LogToFile("Teszt Log bejegyzés");
	std::cout << "Program end" << std::endl;

	system("pause");

	logfilecustomdir.LogToFile("Program end!");

    return 0;
}

