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


QuadtreeNode::QuadtreeNode(const Point& p1, const Point& p2, const float ssize):data(&p1),separate_point(p2),size(ssize)
{
	for (int i = 0; i < 4; i++)
	{
		nextNode[i] = NULL;
	}
}

QuadtreeNode::QuadtreeNode(const QuadtreeNode& p): QuadtreeNode(p)
{
	
}
QuadtreeNode::~QuadtreeNode() 
{
	
}


bool QuadtreeNode::InsertPoint(const Point& inpoint) 
{
	const Point p = inpoint;

	QuadtreeNode *startptr=this;
	QuadtreeNode *newptr;
	


	bool end = false;	
	float ssize = size;
	
	while (!end) 
	{
		Point s;		
		s.Set_data(separate_point[0], separate_point[1]);

		//第一象限
		if (p[0] > separate_point[0] && p[1] > separate_point[1])
		{
			ssize = ssize / 2;
			s.Set_data(ssize+(s[0] / 2), ssize+(s[1] / 2));			
			if (startptr->nextNode[0] == NULL) 
			{				
				newptr = new QuadtreeNode(p, s, ssize);
				startptr->nextNode[0] = newptr;
			}
			else 
			{
				const Point *temp = startptr->data;
				nextNode[0]->InsertPoint(p);
				startptr->data = NULL;
			}
			end = true;

			startptr = startptr->nextNode[0];
		}
		//第二象限
		if (p[0] < separate_point[0] && p[1] > separate_point[1])
		{
			ssize = ssize / 2;
			s.Set_data(-ssize - (s[0] / 2), ssize + (s[1] / 2));
			
			if (startptr->nextNode[1] == NULL)
			{
				newptr = new QuadtreeNode(p, s, ssize);
				startptr->nextNode[1] = newptr;
			}
			else
			{
				const Point *temp = startptr->data;
				nextNode[1]->InsertPoint(p);
				startptr->data = NULL;
			}
			end = true;

			startptr = startptr->nextNode[1];
		}
		//第三象限
		if (p[0] < separate_point[0] && p[1] < separate_point[1])
		{
			ssize = ssize / 2;
			s.Set_data(-ssize - (s[0] / 2), -ssize - (s[1] / 2));			
			if (startptr->nextNode[2] == NULL)
			{
				newptr = new QuadtreeNode(p, s, ssize);
				startptr->nextNode[2] = newptr;
			}
			else
			{
				const Point *temp = startptr->data;
				nextNode[2]->InsertPoint(p);
				startptr->data = NULL;
			}
			end = true;

			startptr = startptr->nextNode[2];
		}
		//第四象限
		if (p[0] > separate_point[0] && p[1] < separate_point[1])
		{
			ssize = ssize / 2;
			s.Set_data(ssize + (s[0] / 2), -ssize + (s[1] / 2));
			if (startptr->nextNode[3] == NULL)
			{
				newptr = new QuadtreeNode(p, s, ssize);
				startptr->nextNode[3] = newptr;
			}
			else
			{
				const Point *temp = startptr->data;
				nextNode[3]->InsertPoint(p);
				startptr->data = NULL;
			}
			end = true;

			startptr = startptr->nextNode[3];
		}
		
	}
	return true;




}
void QuadtreeNode::FindClosestPoint(const Point& inpoint)const
{
	const Point p = inpoint;

	const QuadtreeNode *startptr = this;
	QuadtreeNode *newptr;



	bool end = false;
	float ssize = size;

	while (!end)
	{
		Point s;
		s.Set_data(separate_point[0], separate_point[1]);

		//第一象限
		if (p[0] > separate_point[0] && p[1] > separate_point[1])
		{
			ssize = ssize / 2;
			s.Set_data(ssize + (s[0] / 2), ssize + (s[1] / 2));
			if (startptr->nextNode[0] == NULL)
			{
				newptr = new QuadtreeNode(p, s, ssize);
				startptr->nextNode[0] = newptr;
			}
			else
			{
				const Point *temp = startptr->data;
				nextNode[0]->InsertPoint(p);
				startptr->data = NULL;
			}
			end = true;

			startptr = startptr->nextNode[0];
		}
		//第二象限
		if (p[0] < separate_point[0] && p[1] > separate_point[1])
		{
			ssize = ssize / 2;
			s.Set_data(-ssize - (s[0] / 2), ssize + (s[1] / 2));

			if (startptr->nextNode[1] == NULL)
			{
				newptr = new QuadtreeNode(p, s, ssize);
				startptr->nextNode[1] = newptr;
			}
			else
			{
				const Point *temp = startptr->data;
				nextNode[1]->InsertPoint(p);
				startptr->data = NULL;
			}
			end = true;

			startptr = startptr->nextNode[1];
		}
		//第三象限
		if (p[0] < separate_point[0] && p[1] < separate_point[1])
		{
			ssize = ssize / 2;
			s.Set_data(-ssize - (s[0] / 2), -ssize - (s[1] / 2));
			if (startptr->nextNode[2] == NULL)
			{
				newptr = new QuadtreeNode(p, s, ssize);
				startptr->nextNode[2] = newptr;
			}
			else
			{
				const Point *temp = startptr->data;
				nextNode[2]->InsertPoint(p);
				startptr->data = NULL;
			}
			end = true;

			startptr = startptr->nextNode[2];
		}
		//第四象限
		if (p[0] > separate_point[0] && p[1] < separate_point[1])
		{
			ssize = ssize / 2;
			s.Set_data(ssize + (s[0] / 2), -ssize + (s[1] / 2));
			if (startptr->nextNode[3] == NULL)
			{
				newptr = new QuadtreeNode(p, s, ssize);
				startptr->nextNode[3] = newptr;
			}
			else
			{
				const Point *temp = startptr->data;
				nextNode[3]->InsertPoint(p);
				startptr->data = NULL;
			}
			end = true;

			startptr = startptr->nextNode[3];
		}

	}
}