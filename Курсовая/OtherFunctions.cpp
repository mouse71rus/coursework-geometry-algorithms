//
// Author: mouse71rus(������ �������)
// 
//
#include "stdafx.h"
#include <math.h>
#include <cmath>
#include "OtherFunctions.h"
#include <iostream>


void strstrstr(int N, char C)
{
	for (int i = 0; i < N; i++)
		std::cout << C;
	std::cout << std::endl;
}

bool DoubleEq(double a, double b)//������ �����
{
	return abs(a - b) <= EPS;
}


bool DoubleLess(double a, double b)//������ ������
{
	return (b - a) > EPS;
}
bool DoubleMoreEq(double a, double b)//������ ��� �����
{
	return (a - b) >= EPS;
}

