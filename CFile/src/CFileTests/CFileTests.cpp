// CFileTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../CFile/MyFile.h"

const char *inputFileName = "input.txt";
const char *nonExistentFileName = "nonexistentfile.txt";
const char *outputFileName = "output.txt";
const char *modeRead = "r";
const char *modeWrite = "w";

const char dataCheck[] = { 't', 'e', 's', 't' };

struct MyFileFixture
{
	CMyFile file;
};

BOOST_AUTO_TEST_CASE(OpenAndCloseFile)
{	
	CMyFile openFile(inputFileName, modeRead);
	BOOST_CHECK(openFile.Open());
	BOOST_CHECK_EQUAL(openFile.IsFileOpened(), true);
	openFile.Close();
	BOOST_CHECK_EQUAL(openFile.IsFileOpened(), false);
}

BOOST_AUTO_TEST_CASE(OpenNonExistentFile)
{
	CMyFile openFile(nonExistentFileName, modeRead);
	BOOST_CHECK(!(openFile.Open()));
	BOOST_CHECK_EQUAL(openFile.IsFileOpened(), false);
}

BOOST_AUTO_TEST_CASE(OpenFileTwice)
{
	CMyFile openFile(inputFileName, modeRead);
	openFile.Open();
	openFile.Open();
	BOOST_CHECK_EQUAL(openFile.IsFileOpened(), true);
}

BOOST_AUTO_TEST_CASE(EachFileHaveEnd)
{
	CMyFile openFile(inputFileName, modeRead);
	BOOST_CHECK(openFile.Open());
	BOOST_CHECK_EQUAL(openFile.IsEndOfFile(), false);
}

BOOST_AUTO_TEST_CASE(ReadFromFile)
{
	CMyFile openFile(inputFileName, modeRead);
	BOOST_CHECK(!openFile.IsFileOpened());
	openFile.Open();
	BOOST_CHECK_EQUAL(openFile.IsFileOpened(), true);
	int char1 = openFile.GetChar();
	int char2 = openFile.GetChar();
	BOOST_CHECK_EQUAL(char1, 't');
	BOOST_CHECK_EQUAL(char2, 'e');
}

BOOST_AUTO_TEST_CASE(WriteToFile)
{
	CMyFile openFile(outputFileName, modeWrite);
	BOOST_CHECK(!openFile.IsFileOpened());
	openFile.Open();
	BOOST_CHECK(openFile.PutChar('t'));
	openFile.Close();

	CMyFile openFileNew(outputFileName, modeRead);
	openFileNew.Open();
	BOOST_CHECK_EQUAL(openFileNew.GetChar(), 't');
	openFileNew.Close();
}

BOOST_AUTO_TEST_CASE(CheckPositionInFile)
{
	CMyFile openFile(inputFileName, modeRead);
	BOOST_CHECK(!openFile.IsFileOpened());
	openFile.Open();
	int char1;
	char1 = openFile.GetChar();
	BOOST_CHECK_EQUAL(openFile.GetPosition(), 1);
	BOOST_CHECK_EQUAL(char1, 't');
}

BOOST_AUTO_TEST_CASE(OperationSeekInFile)
{
	CMyFile openFile(inputFileName, modeRead);
	BOOST_CHECK(!openFile.IsFileOpened());
	openFile.Open();
	openFile.Seek(2);
	BOOST_CHECK_EQUAL(openFile.GetChar(), 's');
	openFile.Seek(10);
	BOOST_CHECK_EQUAL(openFile.GetChar(), '\n');
	openFile.Close();
}

BOOST_AUTO_TEST_CASE(BlockReadFromFile)
{
	CMyFile openFile(inputFileName, modeRead);
	BOOST_CHECK(!openFile.IsFileOpened());
	openFile.Open();
	char data[4];
	BOOST_CHECK_EQUAL(openFile.Read(data, sizeof(char), 4), 4);
	for (size_t i = 0; i < 4; ++i)
	{
		BOOST_CHECK_EQUAL(data[i], dataCheck[i]);
	}
}

BOOST_AUTO_TEST_CASE(BlockWriteToFile)
{
	CMyFile openFile(outputFileName, modeWrite);
	BOOST_CHECK(!openFile.IsFileOpened());
	openFile.Open();
	BOOST_CHECK_EQUAL(openFile.Write(dataCheck, sizeof(char), 4), 4);
	openFile.Close();

	CMyFile openFileNew(outputFileName, modeRead);
	BOOST_CHECK(!openFileNew.IsFileOpened());
	openFileNew.Open();
	char newData[4];
	BOOST_CHECK_EQUAL(openFileNew.Read(newData, sizeof(char), 4), 4);
	for (size_t i = 0; i < 4; ++i)
	{
		BOOST_CHECK_EQUAL(newData[i], dataCheck[i]);
	}
}
