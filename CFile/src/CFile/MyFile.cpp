#include "stdafx.h"
#include "MyFile.h"

const int CMyFile::FILE_ERROR = EOF - 1995;

CMyFile::CMyFile()
	: m_file(nullptr)
	, m_isFileOpen(false)
	, m_fileName("")
	, m_mode("r")
{
}

CMyFile::CMyFile(const char *fileName, const char *mode)
	: m_file(nullptr)
	, m_isFileOpen(false)
	, m_fileName(fileName)
	, m_mode(mode)
{
}

CMyFile::~CMyFile()
{
	Close();
	m_file = nullptr;
}

bool CMyFile::IsFileOpened() const
{
	return m_isFileOpen;
}

bool CMyFile::Open()
{
	if (m_isFileOpen)
	{
		Close();
	}
	if (m_mode == "")
	{
		return false;
	}
	if (m_file = fopen(m_fileName.c_str(), m_mode.c_str()))
	{
		m_isFileOpen = true;
		return true;
	}
	return false;
}

void CMyFile::Close()
{
	if (m_isFileOpen)
	{
		m_isFileOpen = false;
		fclose(m_file);
	}
}

bool CMyFile::IsEndOfFile() const
{
	if (m_isFileOpen && feof(m_file))
	{
		return true;
	}
	return false;
}

int CMyFile::GetChar()
{
	if (!m_isFileOpen)
	{
		return FILE_ERROR;
	}
	if (feof(m_file))
	{
		return EOF;
	}
	if (ferror(m_file))
	{
		clearerr(m_file);
		return FILE_ERROR;
	}

	int symbolCode = fgetc(m_file);
	return symbolCode;
}

bool CMyFile::PutChar(char symbol)
{
	if (!m_isFileOpen)
	{
		return FILE_ERROR;
	}

	fputc(symbol, m_file); 
	if (ferror(m_file))
	{
		clearerr(m_file);
		return FILE_ERROR;
	}

	return true;
}

/*long CMyFile::GetLength() const
{
	if (!m_isFileOpen)
	{
		return FILE_ERROR;
	}

	struct stat fileStatus;
	int result = stat(m_fileName.c_str(), &fileStatus);
	return result == 0 ? fileStatus.st_size : -1;
}*/

long CMyFile::GetPosition() const
{
	if (!m_isFileOpen)
	{
		return FILE_ERROR;
	}

	long position = ftell(m_file);
	if (position == -1L)
	{
		clearerr(m_file);
		return FILE_ERROR;
	}

	return position;
}

bool CMyFile::Seek(long offset)
{
	if (!m_isFileOpen)
	{
		return FILE_ERROR;
	}
	int result = fseek(m_file, offset, SEEK_SET);
	if (ferror(m_file))
	{
		clearerr(m_file);
		return FILE_ERROR;
	}

	return result == 0;
}

size_t CMyFile::Read(void *data, size_t size, size_t count)
{
	if (!m_isFileOpen)
	{
		return FILE_ERROR;
	}

	size_t result = fread(data, size, count, m_file);
	if (ferror(m_file))
	{
		clearerr(m_file);
		return FILE_ERROR;
	}

	return result;
}

size_t CMyFile::Write(const void *data, size_t size, size_t count)
{
	if (!m_isFileOpen)
	{
		return FILE_ERROR;
	}

	size_t result = fwrite(data, size, count, m_file);
	if (ferror(m_file))
	{
		clearerr(m_file);
		return FILE_ERROR;
	}

	return result;
}