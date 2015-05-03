// CFile.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "MyFile.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		printf("Not enough arguments\n");
		return 1;
	}

	CMyFile input(argv[1], "r"), output(argv[2], "w");
	if (!input.Open())
	{
		printf("Error: cannot open input file\n");
		return 0;
	}
	if (!output.Open())
	{
		printf("Error: cannot create output file\n");
		return 0;
	}

	vector<char> dataFromFile;
	char symbol;
	while ((symbol = input.GetChar()) != EOF)
	{
		dataFromFile.push_back(symbol);
	}
	reverse(dataFromFile.begin(), dataFromFile.end());

	for (auto symbol : dataFromFile)
	{
		output.PutChar(symbol);
	}
	return 0;
}

