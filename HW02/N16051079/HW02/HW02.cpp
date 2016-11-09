// HW02.cpp : �w�q�D���x���ε{�����i�J�I�C
//N16051079 �d�a�F HW02


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
	//startptr�û����V�ڸ`�I
	QuadtreeNode *startptr = this;

	//���J���I�쥿�T����l���ɭ�end=true�A�٤��諸�ɭԶi�J�P�_���j��
	bool end = false;

	//�C���i�Jinsertpoint���ɭԦ]���n�P�_�U�@�ӶH���ҥHsize�j�p����/2
	float ssize = size / 2;

	
	while (!end)
	{
		//����n���seperatepoint�ҥ�
		Point s(startptr->separate_point[0], startptr->separate_point[1]);

		//�Ĥ@�H��
		if (p[0] > startptr->separate_point[0] && p[1] >startptr->separate_point[1])
		{
			//�@���i�J�@�ӶH���N���U�@����separatepoint
			Point s(s[0] + (ssize), s[1] + (ssize));

			//�p�G�ӶH����nextnode�٬Onull�N���٨S�����I�i�h
			if (nextNode[0] == NULL)
			{
				cout << "last seperate point: " << startptr->separate_point << " of size:" << size << endl;
				cout << "�H��1" << endl;
				//�N�ӶH����nextnode���J�ϥΪ̱����I��Quadtreenode����
				startptr->nextNode[0] = new QuadtreeNode(p, s, ssize);

				//�p�G startptr->data!=NULL�N���nextnode�w�g����
				//�o�ɭԴN�n�����`�I���ȩ��U�U�񰵤���H�����P�_
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

				//�I�w�g���J�쥿�T����l�Aend=true
				end = true;
			}

			else
			{
				cout << "seperate point: " << startptr->nextNode[0]->separate_point << " of size:" << startptr->nextNode[0]->size << endl;
				cout << "�H��1: " << endl;

				//�p�G�Ӥl�`�I���ȫh�b�Ӥl�`�I�A���J�@�ӥ|����
				end = startptr->nextNode[0]->InsertPoint(p);
			}

		}

		//���᪺�H�����P�Ĥ@�H���ۦP
		//�ĤG�H��
		if (p[0] < startptr->separate_point[0] && p[1] > startptr->separate_point[1])
		{

			Point s((s[0]) - (ssize), (s[1]) + (ssize));

			if (startptr->nextNode[1] == NULL)
			{

				cout << "last seperate point: " << startptr->separate_point << " of size:" << size << endl;
				cout << "�H��2" << endl;
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
				cout << "�H��2: " << endl;
				end = startptr->nextNode[1]->InsertPoint(p);
			}

			

		}
		//�ĤT�H��
		if (p[0] < startptr->separate_point[0] && p[1] < startptr->separate_point[1])
		{

			Point s((s[0]) - (ssize), (s[1]) - (ssize));
			if (startptr->nextNode[2] == NULL)
			{

				cout << "last seperate point: " << startptr->separate_point << " of size:" << startptr->size << endl;
				cout << "�H��3" << endl;
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
				cout << "�H��3: " << endl;
				end = startptr->nextNode[2]->InsertPoint(p);
			}
			

		}
		//�ĥ|�H��
		if (p[0] > startptr->separate_point[0] && p[1] < startptr->separate_point[1])
		{

			Point s(s[0] + (ssize), (s[1]) - (ssize));
			if (startptr->nextNode[3] == NULL)
			{

				cout << "last seperate point: " << startptr->separate_point << " of size:" << startptr->size << endl;
				cout << "�H��4" << endl;
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
				cout << "�H��4: " << endl;
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

		//�Ĥ@�H��
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
		//�ĤG�H��
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
		//�ĤT�H��
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
		//�ĥ|�H��
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
	

	//������insertpoint�@�ˡA�����ɤ��A����e�@���I������
	while (!end)
	{
		Point s(startptr->separate_point[0], startptr->separate_point[1]);
	
		//�Ĥ@�H��
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
				cout << "�i�J1" << endl;
			}
			startptr = startptr->nextNode[0];
		

		}
		//�ĤG�H��
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
				cout << "�i�J2" << endl;
			}
			startptr = startptr->nextNode[1];


			
		}
		//�ĤT�H��
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
				cout << "�i�J3" << endl;
			}
			startptr = startptr->nextNode[2];
			

		}
		//�ĥ|�H��
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
				cout << "�i�J4" << endl;
			}
			startptr = startptr->nextNode[3];
			
		}

		//�䤣���I�A��JNull!
		
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

		//�Ĥ@�H��
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
		//�ĤG�H��
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
		//�ĤT�H��
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
		//�ĥ|�H��
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