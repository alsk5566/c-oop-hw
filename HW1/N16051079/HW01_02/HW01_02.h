#pragma once
#include"stdafx.h"
#include<iostream>
using namespace std;
namespace MyGeometry
{
	struct Point									
	{
		float x;
		float y;		
		double Length();							//計算每一點距離原點的函式
		string CoutPoint();							//列出每一個點的座標
	};

	Point *LoadPoint(const char* , unsigned int& ); //讀取txt檔並儲存每一個座標，同時回傳有幾個點	
	Point *MinVerticalDistance(Point*, int);		//計算與x軸最小距離的點
	Point *SortbyLength(Point*, int);				//計算與原點最遠的點
	void Report(const char*filename, int);			//按照作業要求的方式回傳
}
