#include <iostream>
#include <string>
#include <locale>

int maing() 
{
	setlocale(LC_ALL, "");
	//std::wcin.imbue(std::locale(""));
	std::wstring text;
	std::wcin >> text;
	std::wcout << "\n" << text << "\n";
	return 0;
}