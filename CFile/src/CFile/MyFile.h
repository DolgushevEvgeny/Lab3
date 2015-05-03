#pragma once
class CMyFile
{
public:
	CMyFile();
	CMyFile(const char *fileName, const char *mode);
	~CMyFile();

	static const int FILE_ERROR;

	bool Open();
	void Close();
	bool IsFileOpened() const;
	bool IsEndOfFile() const;
	int GetChar();
	bool PutChar(char symbol);
	long GetLength() const;
	long GetPosition() const;
	bool Seek(long offset);
	size_t Read(void *data, size_t size, size_t count);
	size_t Write(const void *data, size_t size, size_t count);
private:
	FILE *m_file;
	bool m_isFileOpen;
	std::string m_fileName;
	std::string m_mode;
};

