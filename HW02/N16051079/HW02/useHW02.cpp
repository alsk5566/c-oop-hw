#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "HW02.h"
using namespace std;
int main() 
{
	Point *pt= new Point[20];
	fstream file;
	file.open("Point_HW2.txt", ios::in);
	if (!file) 
	{
		cout << "can't open file"<<endl;
	}
		
	for (int i = 0; i < 20; i++) 
	{
		file >> pt[i];
		cout << pt[i] << endl;
	}
	
	


	
	return 0;
}