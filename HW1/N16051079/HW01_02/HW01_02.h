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
		double Length();							//�p��C�@�I�Z�����I���禡
		string CoutPoint();							//�C�X�C�@���I���y��
	};

	Point *LoadPoint(const char* , unsigned int& ); //Ū��txt�ɨ��x�s�C�@�Ӯy�СA�P�ɦ^�Ǧ��X���I	
	Point *MinVerticalDistance(Point*, int);		//�p��Px�b�̤p�Z�����I
	Point *SortbyLength(Point*, int);				//�p��P���I�̻����I
	void Report(const char*filename, int);			//���ӧ@�~�n�D���覡�^��
}
