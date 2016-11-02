// HW02.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
#include "HW02.h"
#include <iomanip>
using namespace std;
float *pin = new float[2];
float *pf = new float[20];

Point::Point() 
{
	x = 0;
	y = 0;
}

Point::Point(float xx, float yy) 
{
	x = xx;
	y = yy;
}
Point :: ~Point()
{
	std::cout << "end of the process" << std::endl;
}

void Point::Set_data(float x, float y) 
{
	this->x = x;
	this->y = y;
}

float Point::operator[](int i) const 
{
	
	pin[0] = x;
	pin[1] = y;
	
	return pin[i];
}

std::istream & operator >> (std::istream& s, Point& p)
{
	s >> p.x >> p.y;
	return s;
}


std::ostream & operator<<(std::ostream& s, const Point& p) 
{
	s << fixed << setprecision(2);
	s << "(" << p.x << ", " << p.y << ")";
	return s;
}
/*
QuadtreeNode::QuadtreeNode(const Point& p1, const Point& p2, const float point)
{
	cout << ":";
}*/