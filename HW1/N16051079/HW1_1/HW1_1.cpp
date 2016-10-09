// HW1_1.cpp : �w�q�D���x���ε{�����i�J�I�C
//N16051079 ����Ӥ@ �d�a�F HW1_1

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;

template <class T>											//��M�}�C�̤j�Ȫ��˪O�禡
void sortMax(T *b, int n);

template<>													//�S�w��j�Mchar�r����׳]�w���S�w�˪O�禡
void sortMax<char*>(char **b, int n);

int main()
{
	const int s = 6;										//short�}�C��6�ӭȡFdouble�}�C��9�ӭ�;char�}�C��8�Ӧr��
	const int d = 9;
	const int c_test = 8;
	short shortarray[s];								    //��6��short�Ȫ�shortarray		
	
	short seed;												//25~32���Ͷüƨÿ�Jshort�x�}
	seed=(short)time(NULL);
	srand(seed);
	
	for(int i=0;i<s;i++)
	{
		shortarray[i]=(short) (rand()%1000);				//���M�D�بS�W�w�A�����F��K�\Ū�ҥH�N�d�򭭩w�b1000��
	}
	
	short *a = shortarray;									//�]��a�@��shortarray������
	cout<<"�쥻��short�x�}: ";								//��X�H�üƲ��ͪ�short�x�}
	for(int i=0;i<s;i++)
	{
		cout<<shortarray[i]<<" ";
		if(i==s-1)
		cout<<endl;	
	}	
	sortMax(a, s);											//��X�üƪ��̤j��
		
	double doublearray[d];									//double�x�}
	double dseed;											//45~51����double�üƨÿ�J�i�hdoublearray�x�}
	dseed=(double)time(NULL);
	srand(dseed);
	for(int i=0;i<d;i++)
	{
		doublearray[i]=((double)(rand()%1000)/(RAND_MAX+1.0)*RAND_MAX);
	}
	
	double *c=doublearray;
	cout<<"�쥻��double�x�}: ";
	for(int i=0;i<d;i++)
	{
		cout<<doublearray[i]<<" ";
		if(i==d-1)
		cout<<endl;	
	}	
	sortMax(c, d);

	//�إ�char�x�}
	char *test[c_test] = {"hello","he","you","cool","world","microsoft","applepie","enterprise"};
	cout << "�r��x�}��: "<<endl;
	
	for (int i = 0; i < c_test; i++) 
	{
		cout <<left<<setw(10)<<*(test + i) << " �a�}��:"<<(test+i)<<endl;
	}

	cout << endl;
	sortMax(test, 8);
	return 0;
}

template<class T>
void sortMax(T *b, int n) 
{
	T x = 0;
	T *temp=new T;											//�إߤ@��temp�x�s����ƧǥΪ��Ȧs��
	T max;
	int i, j;
	for (i = 0; i < n - 1; i++)								//�嫬�w�j�ƧǪk
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
	
	max=*(b+n-1);											//�ѩ�ڪ��ƧǪk�N�̤j�ȩ��x�}�̫᭱�ҥH��X�x�}�̫�@��Y���̤j��
	cout<<"�x�}�̤j��: "<<max<<endl; 
	
}

template<>void sortMax<char*>(char **b, int n)				//��M�̪�char�}�C�����
{															//char���r��}�C���G���}�C�A�ҥH�n��char**
	int i, j;
	char *temp =new char;
	char **test = b;
	int x=0;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (strlen(*(test + j)) >strlen( *(test + j + 1)))		//�r����ת����
			{
			
				//cout << *(b + j) << endl;
				temp = *(test + j);
				*(test + j) = *(test + j + 1);
				*(test + j + 1) = temp;
			}
		}
	}	
	cout << "�r��}�C���̪��r��: " << *(test + n - 1) << " �a�}��:" << (test + n - 1);

}
