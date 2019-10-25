#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class TestCopy
{
private:
	int size;
	int* data;

public:
	TestCopy();
	TestCopy(int size);
	TestCopy(const TestCopy& other);
	TestCopy & operator = (const TestCopy& other);

	int set() { return size; }
	int& operator[] (int index) { return data[index];}
	~TestCopy();
};

class Point
{
private:
	int x;
	int y;
	int z;

public:
	Point()
	{
		x = y = z = 0;
	}

	Point(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void setx(int value) { this->x = value; }
	void sety(int value) { this->y = value; }

	bool operator ==(const Point& other) { return (this->x == other.x && this->y == other.y); }
	bool operator !=(const Point& other) { return !(this->x == other.x && this->y == other.y); }

	bool operator < (const Point& other) { return (this->x < other.x && this->y < other.y); }
	bool operator > (const Point& other) { return (this->x > other.x && this->y > other.y); }

	bool operator <=(const Point& other) { return (this->x <= other.x && this->y <= other.y); }
	bool operator >=(const Point& other) { return (this->x >= other.x && this->y >= other.y); }

	friend ostream& operator << (ostream& os, const Point& point);
	friend istream& operator >> (istream& is, Point& point);
};

ostream& operator << (ostream& os, const Point& point)
{
	os << "X:" << point.x << " Y:" << point.y << " Z:" << point.z;
	return os;
}

istream& operator>> (istream& is, Point& point)
{
	is >> point.x >> point.y >> point.z;
	return is;
}


//class Point
//{
//private:
//	int x; 
//	int y;
//	int z;
//	string nameFile = "MyFilePoint1.txt";
//
//public:
//	Point()
//	{
//		x = y = z = 0;
//	}
//
//	Point(int x, int y, int z)
//	{
//		this->x = x;
//		this->y = y;
//		this->z = z;
//	}
//
//	string getNameFile()
//	{
//		return nameFile;
//	}
//
//	friend ostream& operator<<(ostream& os, const Point& point);
//	friend istream& operator>>(istream& is, Point& point);
//};



int main()
{
	setlocale(LC_ALL, "ru");

	string nameFile = "FilePoint1234.txt";
	Point point(154, 867, 345);
	fstream fs;

	fs.open(nameFile, fstream::in | fstream::out | fstream::app);
	if (!fs.is_open())
	{
		cout << "Ошибка!!!" << endl;
	}
	else
	{
		cout << "Файл отрыт!" << endl;
		fs << point << "\n";
	}
	fs.close();
	cout << "Файл закрыт!" << endl;

	fs.open(nameFile, fstream::in);
	if (!fs.is_open())
	{
		cout << "Ошибка!!!" << endl;
	}
	else
	{
		cout << "Файл отрыт!" << endl;
		while (true)
		{
			Point p;
			fs >> p;
			if (fs.eof())
			{
				break;
			}
			cout << p << endl;
		}
	}
}
