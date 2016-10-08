// HW01_02.cpp : 定義主控台應用程式的進入點。
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

