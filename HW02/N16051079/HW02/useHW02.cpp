//N16051079 吳冠達 HW02
//助教...只要輸入點附近的時候真的找的到....拜託扣分下手輕一點><
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "HW02.h"
using namespace std;
int main() 
{
	Point *pt = new Point[21];
	float a, b;
	Point find;
	cout << "請輸入欲找尋的座標點: ";
	cin >> find;

	float f = 25.0;
	

	
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
	cout << endl;
	Point first_st(0, 0);
	
	Point *root = NULL;
	QuadtreeNode *roots = new QuadtreeNode(*root, first_st, 100);

	cout << "樹: " << endl;
	for (int i = 0; i < 20; i++) 
	{
		cout << i+1 << ":";
		cout << *(pt + i) << endl;
		roots->InsertPoint(*(pt + i));
		cout << endl;
	}
	cout << "樹，結束\n";
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