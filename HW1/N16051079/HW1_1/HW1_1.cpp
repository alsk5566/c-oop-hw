// HW1_1.cpp : 定義主控台應用程式的進入點。
//N16051079 機械碩一 吳冠達 HW1_1

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;

template <class T>											//找尋陣列最大值的樣板函式
void sortMax(T *b, int n);

template<>													//特定位搜尋char字串長度設定的特定樣板函式
void sortMax<char*>(char **b, int n);

int main()
{
	const int s = 6;										//short陣列有6個值；double陣列有9個值;char陣列有8個字串
	const int d = 9;
	const int c_test = 8;
	short shortarray[s];								    //有6個short值的shortarray		
	
	short seed;												//25~32產生亂數並輸入short矩陣
	seed=(short)time(NULL);
	srand(seed);
	
	for(int i=0;i<s;i++)
	{
		shortarray[i]=(short) (rand()%1000);				//雖然題目沒規定，但為了方便閱讀所以將範圍限定在1000內
	}
	
	short *a = shortarray;									//設立a作為shortarray的指標
	cout<<"原本的short矩陣: ";								//輸出以亂數產生的short矩陣
	for(int i=0;i<s;i++)
	{
		cout<<shortarray[i]<<" ";
		if(i==s-1)
		cout<<endl;	
	}	
	sortMax(a, s);											//找出亂數的最大值
		
	double doublearray[d];									//double矩陣
	double dseed;											//45~51產生double亂數並輸入進去doublearray矩陣
	dseed=(double)time(NULL);
	srand(dseed);
	for(int i=0;i<d;i++)
	{
		doublearray[i]=((double)(rand()%1000)/(RAND_MAX+1.0)*RAND_MAX);
	}
	
	double *c=doublearray;
	cout<<"原本的double矩陣: ";
	for(int i=0;i<d;i++)
	{
		cout<<doublearray[i]<<" ";
		if(i==d-1)
		cout<<endl;	
	}	
	sortMax(c, d);

	//建立char矩陣
	char *test[c_test] = {"hello","he","you","cool","world","microsoft","applepie","enterprise"};
	cout << "字串矩陣為: "<<endl;
	
	for (int i = 0; i < c_test; i++) 
	{
		cout <<left<<setw(10)<<*(test + i) << " 地址為:"<<(test+i)<<endl;
	}

	cout << endl;
	sortMax(test, 8);
	return 0;
}

template<class T>
void sortMax(T *b, int n) 
{
	T x = 0;
	T *temp=new T;											//建立一個temp儲存之後排序用的暫存值
	T max;
	int i, j;
	for (i = 0; i < n - 1; i++)								//典型泡沫排序法
	{
		for (j = 0; j < n-1; j++) 
		{
			if (*(b+j) > *(b+j+1)) 
			{
				*temp = *(b+j);
				*(b+j) = *(b+j+1);
				*(b+j+1)= *temp;
			}
		}
	}
	
	max=*(b+n-1);											//由於我的排序法將最大值放到矩陣最後面所以輸出矩陣最後一位即為最大值
	cout<<"矩陣最大值: "<<max<<endl; 
	
}

template<>void sortMax<char*>(char **b, int n)				//找尋最長char陣列的函示
{															//char的字串陣列為二維陣列，所以要用char**
	int i, j;
	char *temp =new char;
	char **test = b;
	int x=0;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (strlen(*(test + j)) >strlen( *(test + j + 1)))		//字串長度的比較
			{
			
				//cout << *(b + j) << endl;
				temp = *(test + j);
				*(test + j) = *(test + j + 1);
				*(test + j + 1) = temp;
			}
		}
	}	
	cout << "字串陣列的最長字為: " << *(test + n - 1) << " 地址為:" << (test + n - 1);

}
