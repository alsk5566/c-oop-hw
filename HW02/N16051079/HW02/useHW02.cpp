#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "HW02.h"
using namespace std;
int main() 
{
	Point *pt = new Point[21];
	float a, b;
	
	/*cout << "�п�J����M���y���I: ";
	cin >> pt[20];
	*/

	
	fstream file;
	file.open("Point_HW2.txt", ios::in);
	if (!file) 
	{
		cout << "can't open file"<<endl;
	}
		
	for (int i = 0; i < 20; i++) 
	{
		file >> pt[i];
		cout <<pt[i] << endl;
	}

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
	
	


	
	return 0;
}