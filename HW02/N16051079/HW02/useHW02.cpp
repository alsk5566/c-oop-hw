//N16051079 �d�a�F HW02
//�U��...�u�n��J�I���񪺮ɭԯu���䪺��....���U�����U�⻴�@�I><
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "HW02.h"
using namespace std;
int main() 
{
	Point *pt = new Point[21];
	float a, b;
<<<<<<< HEAD
	Point find;
	cout << "�п�J����M���y���I: ";
	cin >> find;

	float f = 25.0;
	
=======
	
	/*cout << "�п�J����M���y���I: ";
	cin >> pt[20];
	*/
>>>>>>> f76a06fac7a85804f7b31306bb811cd48dd02808

	
	fstream file;
	file.open("Point_HW2.txt", ios::in);
	

	if (!file) 
	{
		cout << "can't open file"<<endl;
	}

		
	for (int i = 0; i < 20; i++) 
	{
		file >> pt[i];
		//cout <<pt[i] << endl;
	}
<<<<<<< HEAD
	cout << endl;
	Point first_st(0, 0);
=======

	Point first_st(0, 0);
	
	Point *root = NULL;
	QuadtreeNode *roots=new QuadtreeNode(*root , first_st, 100),*mover=roots;

	for (int i = 0; i < 20; i++) 
	{
		if (roots->InsertPoint(*(pt + i)))
		{
			cout << "point inserted" << endl;
		}
	}
>>>>>>> f76a06fac7a85804f7b31306bb811cd48dd02808
	
	Point *root = NULL;
	QuadtreeNode *roots = new QuadtreeNode(*root, first_st, 100);

	cout << "��: " << endl;
	for (int i = 0; i < 20; i++) 
	{
		cout << i+1 << ":";
		cout << *(pt + i) << endl;
		roots->InsertPoint(*(pt + i));
		cout << endl;
	}
	cout << "��A����\n";
	Point findpoint;
	

	cout << "find closest point: " << endl;

	if (&(roots->FindClosestPoint(find)) != nullptr) 
	{
		cout << (roots->FindClosestPoint(find)) << endl;
	}
	else 
	{
		cout << "NullPoint!" << endl;
	}
	
	//cout << find;
	
	

	
	return 0;
}