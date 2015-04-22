#pragma once

class CRectangle
{
public:
	CRectangle();
	CRectangle(int left, int top, int width, int height);
	~CRectangle();

	void SetWidth(int width);
	int GetWidth() const;

	void SetHeight(int height);
	int GetHeight() const;

	int GetSquare() const;
	int GetPerimetr() const;

	void SetLeft(int xCoordinate);
	int GetLeft() const;

	void SetRight(int right);
	int GetRight() const;

	void SetBottom(int bottom);
	int GetBottom() const;

	void SetTop(int yCoordinate);
	int GetTop() const;

	void Move(int dx, int dy);
	void Scale(int sx, int sy);
	bool Intersect(CRectangle const& other);
private:
	int m_width;
	int m_height;
	int m_left;
	int m_top;
};

