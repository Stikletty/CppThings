// CppThings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Logger.h"

int main()
{
	Logger logfile("Events.log");

	std::cout << "Program start";

	system("pause");

    return 0;
}

