// HW01_02.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include"stdafx.h"
#include"HW01_02.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<cmath>
using namespace std;


int main()
{
	using namespace MyGeometry;
	const char *fname= "Points.txt";
	unsigned int number = 100;
	Report(fname, number);
    return 0;
}

