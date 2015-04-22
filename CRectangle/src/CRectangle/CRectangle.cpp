// CRectangle.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Rectangle.h"

using namespace std;

void InitializationRectangle(CRectangle &rectangle, ifstream &inputFileRectangle)
{
	int width, height, left, top;
	inputFileRectangle >> left >> top >> width >> height;
	rectangle.SetLeft(left);
	rectangle.SetTop(top);
	rectangle.SetWidth(width);
	rectangle.SetHeight(height);
}

void MoveRectangle(CRectangle &rectangle, ifstream &inputFileRectangle)
{
	int dx, dy;
	inputFileRectangle >> dx >> dy;
	rectangle.Move(dx, dy);
}

void ScaleRectangle(CRectangle &rectangle, ifstream &inputFileRectangle)
{
	int sx, sy;
	inputFileRectangle >> sx >> sy;
	rectangle.Scale(sx, sy);
}

void ReadFromFile(const string &fileName, CRectangle &rectangle)
{
	ifstream inputRectangle;
	inputRectangle.open(fileName, ifstream::in);
	string initialization;
	while (inputRectangle.good())
	{
		inputRectangle >> initialization;
		if (initialization == "Rectangle")
		{
			InitializationRectangle(rectangle, inputRectangle);
		}
		if (initialization == "Move")
		{
			MoveRectangle(rectangle, inputRectangle);
		}
		if (initialization == "Scale")
		{
			ScaleRectangle(rectangle, inputRectangle);
		}
	}
	inputRectangle.close();
}

void PrintRectangleValues(const CRectangle &rectangle)
{
	cout << "	Left Top : " << rectangle.GetLeft() << " ; " << rectangle.GetTop() << "\n";
	cout << "	Size : " << rectangle.GetWidth() << " * " << rectangle.GetHeight() << "\n";
	cout << "	Right Bottom : " << rectangle.GetRight() << " ; " << rectangle.GetBottom() << "\n";
	cout << "	Area : " << rectangle.GetSquare() << "\n";
	cout << "	Perimetr : " << rectangle.GetPerimetr() << "\n";
}

int main(int argc, char* argv[])
{
	string inputFileName1 = "rectangle1.txt";
	string inputFileName2 = "rectangle2.txt";
	CRectangle firstRectangle, secondRectangle;
	ReadFromFile(inputFileName1, firstRectangle);
	cout << "Rectangle1:\n";
	PrintRectangleValues(firstRectangle);
	ReadFromFile(inputFileName2, secondRectangle);
	cout << "Rectangle2:\n";
	PrintRectangleValues(secondRectangle);
	cout << "Intersection rectangle:\n";
	firstRectangle.Intersect(secondRectangle);
	PrintRectangleValues(firstRectangle);
	return 0;
}

