// HW1_1.cpp : 定義主控台應用程式的進入點。
//N16051079 機械碩一 吳冠達 HW1_1

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

template <class T>
void sortMax(T *b, int n);

template<>void sortMax<char*>(char **b, int n);


int main()
{
	const int s = 6;
	const int d = 9.0;
	const int c_test = 8;
	short A1[s];
	
	short seed;
	seed=(short)time(NULL);
	srand(seed);
	
	for(int i=0;i<s;i++)
	{
		A1[i]=(short) (rand()%1000);
	}
	
	short *a = A1;	
	cout<<"原本的short矩陣: ";
	for(int i=0;i<s;i++)
	{
		cout<<A1[i]<<" ";
		if(i==s-1)
		cout<<endl;	
	}	
	sortMax(a, s);
	cout << "之後的short矩陣: ";
	for (int i = 0; i<s; i++)
	{
		cout << A1[i] << " ";
		if (i == s - 1)
			cout << endl;
	}
	
	
	double A2[d];
	double dseed;
	dseed=(double)time(NULL);
	srand(dseed);
	for(int i=0;i<d;i++)
	{
		A2[i]=((double)(rand()%1000)/(RAND_MAX+1.0)*RAND_MAX);
	}
	
	double *c=A2;
	cout<<"原本的double矩陣: ";
	for(int i=0;i<d;i++)
	{
		cout<<A2[i]<<" ";
		if(i==d-1)
		cout<<endl;	
	}	
	sortMax(c, d);

	char *test[c_test] = {"hello","he","you","cool","world","microsoft","applepie","enterprise"};
	cout << "字串矩陣為: "<<endl;
	
	for (int i = 0; i < c_test; i++) 
	{
		cout <<*(test + i) << " 地址為:"<<(test+i)<<endl;
	}

	cout << endl;
	sortMax(test, 8);
	return 0;
}

template<class T>
void sortMax(T *b, int n) 
{
	T x = 0;
	T *temp=new T;
	T max;
	int i, j;
	for (i = 0; i < n - 1; i++) 
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
	
	max=*(b+n-1);
	cout<<"矩陣最大值: "<<max<<endl; 
	
}

template<>void sortMax<char*>(char **b, int n) 
{
	int i, j;
	char *temp =new char;
	char **test = b;
	int x=0;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (strlen(*(test + j)) >strlen( *(test + j + 1)))
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
