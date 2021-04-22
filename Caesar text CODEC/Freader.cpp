#include <iostream>
#include <fstream>
#include <string>
#include <locale>

int mainad() 
{
	setlocale(LC_ALL, ""); 

	std::string txt = "Árvíztûrõ tükörfúrógép";
	std::ofstream fstream;


	fstream.open("C:\\Dev\\alma.txt");
	//fstream.imbue(std::locale(""));
	fstream << txt;
	fstream.close();

	std::ifstream ifstream;
	ifstream.open("C:\\Dev\\alma.txt");
	//ifstream.imbue(std::locale(""));


	while (getline(ifstream, txt)) 
	{
		std::cout << txt << "\n";
	}
	std::cout << "\n";
	ifstream.close();
	return 0;
}
