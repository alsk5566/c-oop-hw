// HW02.cpp : 定義主控台應用程式的進入點。
//N16051079 吳冠達 HW02


#include "stdafx.h"
#include <iostream>
#include "HW02.h"
#include <iomanip>
using namespace std;
//float *pin = new float[2];
//float *pf = new float[20];

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
	//std::cout << "end of the process" << std::endl;
}

void Point::Set_data(float x, float y) 
{
	this->x = x;
	this->y = y;
}

float Point::operator[](int i) const 
{
	float pin[2];
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


<<<<<<< HEAD
bool QuadtreeNode::InsertPoint(const Point& p)
{
	//startptr永遠指向根節點
	QuadtreeNode *startptr = this;

	//當插入的點到正確的位子的時候end=true，還不對的時候進入判斷的迴圈
	bool end = false;

	//每次進入insertpoint的時候因為要判斷下一個象限所以size大小都先/2
	float ssize = size / 2;

	
	while (!end)
	{
		//之後要更改seperatepoint所用
		Point s(startptr->separate_point[0], startptr->separate_point[1]);

		//第一象限
		if (p[0] > startptr->separate_point[0] && p[1] >startptr->separate_point[1])
		{
			//一旦進入一個象限就更改下一次的separatepoint
			Point s(s[0] + (ssize), s[1] + (ssize));

			//如果該象限的nextnode還是null代表還沒有插點進去
			if (nextNode[0] == NULL)
			{
				cout << "last seperate point: " << startptr->separate_point << " of size:" << size << endl;
				cout << "象限1" << endl;
				//將該象限的nextnode插入使用者欲插點的Quadtreenode物件
				startptr->nextNode[0] = new QuadtreeNode(p, s, ssize);

				//如果 startptr->data!=NULL代表該nextnode已經有值
				//這時候就要把原父節點的值往下下放做之後象限的判斷
				if (startptr->data != NULL)
				{
					const Point *temp = data;
					startptr->data = NULL;
					this->InsertPoint(*temp);

					cout << *temp << endl;
				}
				else
				{
					cout << "data is null" << endl;
				}

				//點已經插入到正確的位子，end=true
				end = true;
			}

			else
			{
				cout << "seperate point: " << startptr->nextNode[0]->separate_point << " of size:" << startptr->nextNode[0]->size << endl;
				cout << "象限1: " << endl;

				//如果該子節點有值則在該子節點再插入一個四元樹
				end = startptr->nextNode[0]->InsertPoint(p);
			}

		}

		//此後的象限都與第一象限相同
		//第二象限
		if (p[0] < startptr->separate_point[0] && p[1] > startptr->separate_point[1])
		{

			Point s((s[0]) - (ssize), (s[1]) + (ssize));

			if (startptr->nextNode[1] == NULL)
			{

				cout << "last seperate point: " << startptr->separate_point << " of size:" << size << endl;
				cout << "象限2" << endl;
				startptr->nextNode[1] = new QuadtreeNode(p, s, ssize);
				if (startptr->data != NULL)
				{
					const Point *temp = data;
					startptr->data = NULL;
					this->InsertPoint(*temp);

					cout << *temp << endl;
				}
				else
				{
					cout << "data is null" << endl;
				}
				end = true;
			}

			else
			{

				cout << "seperate point: " << startptr->nextNode[1]->separate_point << " of size:" << startptr->nextNode[1]->size << endl;
				cout << "象限2: " << endl;
				end = startptr->nextNode[1]->InsertPoint(p);
			}

			

		}
		//第三象限
		if (p[0] < startptr->separate_point[0] && p[1] < startptr->separate_point[1])
		{

			Point s((s[0]) - (ssize), (s[1]) - (ssize));
			if (startptr->nextNode[2] == NULL)
			{

				cout << "last seperate point: " << startptr->separate_point << " of size:" << startptr->size << endl;
				cout << "象限3" << endl;
				startptr->nextNode[2] = new QuadtreeNode(p, s, ssize);
				if (startptr->data != NULL)
				{
					const Point *temp = data;
					startptr->data = NULL;
					this->InsertPoint(*temp);

					cout << *temp << endl;
				}
				else
				{
					cout << "data is null" << endl;
				}
				end = true;
			}

			else
			{

				cout << "seperate point: " << startptr->nextNode[2]->separate_point << " of size:" << startptr->nextNode[2]->size << endl;
				cout << "象限3: " << endl;
				end = startptr->nextNode[2]->InsertPoint(p);
			}
			

		}
		//第四象限
		if (p[0] > startptr->separate_point[0] && p[1] < startptr->separate_point[1])
		{

			Point s(s[0] + (ssize), (s[1]) - (ssize));
			if (startptr->nextNode[3] == NULL)
			{

				cout << "last seperate point: " << startptr->separate_point << " of size:" << startptr->size << endl;
				cout << "象限4" << endl;
				startptr->nextNode[3] = new QuadtreeNode(p, s, ssize);
				if (startptr->data != NULL)
				{
					const Point *temp = data;
					startptr->data = NULL;
					this->InsertPoint(*temp);

					cout << *temp << endl;
				}
				else
				{
					cout << "data is null" << endl;
				}
				end = true;


			}

			else
			{
				cout << "seperate point: " << startptr->nextNode[3]->separate_point << " of size:" << startptr->nextNode[3]->size << endl;
				cout << "象限4: " << endl;
				end = startptr->nextNode[3]->InsertPoint(p);
			}

		}
		
=======
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
>>>>>>> f76a06fac7a85804f7b31306bb811cd48dd02808

			startptr = startptr->nextNode[3];
		}
		
	}
	return true;
<<<<<<< HEAD
}
const Point QuadtreeNode::FindClosestPoint(const Point& p) const 
{
	const QuadtreeNode *startptr = this;
	bool end = false;
	float ssize = size / 2;
	int level;
	

	//概念跟insertpoint一樣，但此時不再做對前一個點做分割
	while (!end)
	{
		Point s(startptr->separate_point[0], startptr->separate_point[1]);
	
		//第一象限
		if (p[0] > startptr->separate_point[0] && p[1] >startptr->separate_point[1])
		{
			Point s(s[0] + (ssize), s[1] + (ssize));
			if (startptr->nextNode[0]== NULL)
			{
				
				if (startptr->data != NULL)
				{
					return *startptr->data;					
				}
				end = true;				
			}
			else 
			{
				cout << "進入1" << endl;
			}
			startptr = startptr->nextNode[0];
		

		}
		//第二象限
		if (p[0] < startptr->separate_point[0] && p[1] > startptr->separate_point[1])
		{
=======
>>>>>>> f76a06fac7a85804f7b31306bb811cd48dd02808

			Point s(s[0] - (ssize), s[1] + (ssize));
			if (startptr->nextNode[1] == NULL)
			{
				
				if (startptr->data != NULL)
				{
					
					return *startptr->data;
				}
				end = true;
				
				
			}
			else
			{
				cout << "進入2" << endl;
			}
			startptr = startptr->nextNode[1];


			
		}
		//第三象限
		if (p[0] < startptr->separate_point[0] && p[1] < startptr->separate_point[1])
		{

			Point s(s[0] - (ssize), s[1] - (ssize));
			if (startptr->nextNode[2] == NULL)
			{
			
				if (startptr->data != NULL)
				{
					return *startptr->data;
					
				}
				end = true;
				
				
			}
			else
			{
				cout << "進入3" << endl;
			}
			startptr = startptr->nextNode[2];
			

		}
		//第四象限
		if (p[0] > startptr->separate_point[0] && p[1] < startptr->separate_point[1])
		{
			Point s(s[0] + (ssize), s[1] - (ssize));
			if (startptr->nextNode[3] == NULL)
			{				
				if (startptr->data != NULL)
				{
					return *startptr->data;
					
				}
				end = true;
			
				
			}
			else
			{
				cout << "進入4" << endl;
			}
			startptr = startptr->nextNode[3];
			
		}

		//找不到點，輸入Null!
		
	}
	if (&(startptr->data) == NULL)
	{
		Point s(0, 0);
		cout << "NULL!" << endl;
		return s;
	}
	
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