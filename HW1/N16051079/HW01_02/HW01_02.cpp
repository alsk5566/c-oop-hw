//N16051079 吳冠達 HW1_2

#include"stdafx.h"
#include"HW01_02.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<cmath>
#include <iomanip>
using namespace std;

namespace MyGeometry
{

	double Point::Length()											//由cmath給的sqrt得出距離
	{
		return sqrt(x*x + y*y);
	}

	string Point::CoutPoint() 
	{
		string c;													//設立一個string c儲存欲回傳的格式
		ostringstream px;											//20~26行為將float轉換為string的方式
		ostringstream py;
		px << x;
		py << y;
		string pxo = px.str();
		string pyo = py.str();
		c ="("+pxo+","+pyo+")";

		return c;
	}
	
	Point *LoadPoint(const char *filename, unsigned int& nPoint)	//*filename儲存txt檔的名字
	{																//&nPoint，&作為reference將改變
		Point *point =NULL;											//初始化*point
		
		int count=0;											    //用來計算有幾個點的初始值
		const char *fname= filename;
		fstream pt;													//36~37開啟txt檔
		pt.open(fname, ios::in);
		
		FILE *p=fopen(fname,"r");									//39~43計算有幾個點
		char test[100];												//fgets的引數需要char*

		while (fgets(test,100,p) != NULL)							//如果讀取檔案時該值不為NULL則count++
			count++;

		nPoint = count;												//修正原先輸入的nPoint
	
		point = new Point[nPoint];									//建立一個儲存nPoint個Point structure的矩陣
		for (int i = 0; i < nPoint; i++)							//將點依序輸入矩陣point
		{
			pt >> point[i].x;
			pt >> point[i].y;			
		}
		
		return point;												//回傳矩陣point以供後續使用
	}


	Point *MinVerticalDistance(Point*LPoint, int nPoint)			//將LoadPoint的陣列LPoint、點數目number丟入計算與x軸的距離
	{
		Point *testPoint =LPoint;									//宣告Point陣列testPoint為Lpoint陣列
		float tempx;												//建立兩個temp用來儲存排序的暫存值	
		float tempy;	
	
		for (int i = 0; i < nPoint; i++)							//66~81為距離x軸大小的排序
		{
			for (int j = 0; j < nPoint-1; j++) 
			{
				if (abs(testPoint[j].y) > abs(testPoint[j + 1].y)) 
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
		cout << endl;

		return testPoint;
	}

	Point *SortbyLength(Point*Lpoint, int nPoint)				    //找尋距離原點的長度		
	{
		Point *sortPoint = Lpoint;									//與上一個MinVertical的方法相同
		float tempx;
		float tempy;
		for (int i = 0; i < nPoint; i++)
		{
			for (int j = 0; j < nPoint - 1; j++)
			{
				if (sortPoint[j].Length()>sortPoint[j+1].Length())	//用已有的函數Length去做判別
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
		return sortPoint;
	}
	void Report(const char*fname,int n)																//作業要求的格式
	{
		cout << "物件導向程式設計第一次作業 \n" << "N16051079 吳冠達 \n";
		unsigned nu = n;
		unsigned int &number = nu;
		Point*lpoint = LoadPoint(fname, number);
		cout << fname << "點數目: " << number<<endl;
		cout << "各點的座標: " << endl;
		for (int i = 0; i < number; i++) 
		{
			cout<<"#"<<": "<< i + 1 <<" "<<lpoint[i].CoutPoint()<<" 與原點距離: "<<lpoint[i].Length()<<endl;
		}
		Point*xpoint = MinVerticalDistance(lpoint, number);
		cout << "最接近x軸的點: " << xpoint[0].CoutPoint() << endl;
		Point*closepoint=SortbyLength(lpoint, number);
		cout << "與原點距離最遠的點: " << closepoint[number-1].CoutPoint() 
			 << " 距離為: " << closepoint[number-1].Length();
	}
}