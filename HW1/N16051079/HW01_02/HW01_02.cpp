#include"stdafx.h"
#include"HW01_02.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<cmath>
using namespace std;

namespace MyGeometry
{

	double Point::Length()											//��cmath����sqrt�o�X�Z��
	{
		return sqrt(x*x + y*y);
	}

	string Point::CoutPoint() 
	{
		string c;													//�]�ߤ@��string c�x�s���^�Ǫ��榡
		ostringstream px;											//20~26�欰�Nfloat�ഫ��string���覡
		ostringstream py;
		px << x;
		py << y;
		string pxo = px.str();
		string pyo = py.str();
		c ="("+pxo+","+pyo+")";
		return c;
	}
	
	Point *LoadPoint(const char *filename, unsigned int& nPoint)	//*filename�x�stxt�ɪ��W�r
	{																//&nPoint�A&�@��reference�N����
		Point *point =NULL;											//��l��*point
		
		int count=0;											    //�Ψӭp�⦳�X���I����l��
		const char *fname= filename;
		fstream pt;													//36~37�}��txt��
		pt.open(fname, ios::in);

		FILE *p=fopen(fname,"r");									//39~43�p�⦳�X���I
		char test[100];												//fgets���޼ƻݭnchar*

		while (fgets(test,100,p) != NULL)							//�p�GŪ���ɮ׮ɸӭȤ���NULL�hcount++
			count++;

		nPoint = count;												//�ץ������J��nPoint
	
		point = new Point[nPoint];									//�إߤ@���x�snPoint��Point structure���x�}
		for (int i = 0; i < nPoint; i++)							//�N�I�̧ǿ�J�x�}point
		{
			pt >> point[i].x;
			pt >> point[i].y;			
		}
		
		return point;												//�^�ǯx�}point�H�ѫ���ϥ�
	}


	Point *MinVerticalDistance(Point*LPoint, int nPoint)
	{
		Point *testPoint =LPoint;
		float tempx;
		float tempy;
		for (int i = 0; i < nPoint; i++) 
		{
			for (int j = 0; j < nPoint-1; j++) 
			{
				if (testPoint[j].x > testPoint[j + 1].x) 
				{
					tempx = testPoint[j].x;
					testPoint[j].x = testPoint[j+1].x;
					testPoint[j + 1].x = tempx;

					tempy = testPoint[j].y;
					testPoint[j].y = testPoint[j + 1].y;
					testPoint[j + 1].y = tempy;
				}
			}
		}
		return testPoint;
	}

	Point *SortbyLength(Point*Lpoint, int nPoint)
	{
		Point *sortPoint = Lpoint;
		float tempx;
		float tempy;
		for (int i = 0; i < nPoint; i++)
		{
			for (int j = 0; j < nPoint - 1; j++)
			{
				if (sortPoint[j].Length()>sortPoint[j+1].Length())
				{
					tempx = sortPoint[j].x;
					sortPoint[j].x = sortPoint[j + 1].x;
					sortPoint[j + 1].x = tempx;

					tempy = sortPoint[j].y;
					sortPoint[j].y = sortPoint[j + 1].y;
					sortPoint[j + 1].y = tempy;
				}
			}
		}
		/*cout <<"�P���I�Z���Ѥp��j�ƧǬ�: \n";
		for (int i = 0; i < nPoint; i++) 
		{
			cout << sortPoint[i].CoutPoint()<<": "<< sortPoint[i].Length()<<endl;
		}*/
		return sortPoint;
	}
	void Report(const char*fname,int n) 
	{
		cout << "����ɦV�{���]�p�Ĥ@���@�~ \n" << "N16051079 �d�a�F \n";
		unsigned nu = n;
		unsigned int &number = nu;
		Point*lpoint = LoadPoint(fname, number);
		cout << fname << "�I�ƥ�: " << number<<endl;
		Point*xpoint = MinVerticalDistance(lpoint, number);
		cout << "�̱���x�b���I: " << xpoint[0].CoutPoint() << endl;
		Point*closepoint=SortbyLength(lpoint, number);
		cout << "�P���I�Z���̻����I: " << closepoint[number-1].CoutPoint() 
			 << " �Z����: " << closepoint[number-1].Length();
	}
}