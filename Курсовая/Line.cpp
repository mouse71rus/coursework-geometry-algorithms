//
// Author: mouse71rus(Сергей Жимерин)
// 
//
#include "stdafx.h"
#include "Point.h"
#include "Line.h"
#include <math.h>
#include "OtherFunctions.h"
using namespace std;

#pragma region Конструкторы_и_Деструктор
Line::Line()
{
	mA = 0.0;
	mB = 0.0;
	mC = 0.0;
}

Line::Line(double A, double B, double C)//Задание коэфицентов A,B,C
{
	mA = A;
	mB = B;
	mC = C;
}
Line::Line(Point A, Point B)//Уравнение прямой по двум точкам
{
	mA = A.GetY() - B.GetY();
	mB = B.GetX() - A.GetX();
	mC = A.GetX()*B.GetY() - B.GetX()*A.GetY();
}

Line::~Line()
{
}
#pragma endregion

#pragma region Get_Set
double Line::GetA()
{
	return mA;
}
double Line::GetB()
{
	return mB;
}
double Line::GetC()
{
	return mC;
}


void Line::SetA(double A)
{
	mA = A;
}
void Line::SetB(double B)
{
	mB = B;
}
void Line::SetC(double C)
{
	mC = C;
}
#pragma endregion

#pragma region Методы
bool Line::EqualLine(Line l1, Line l2)//Совпадают ли прямые?
{
	/*
	y=k1*x+b1 и y=k2*x+b2. Определить, пересекаются ли эти прямые совпадают или параллельны
	– прямые параллельны если одинаковы их угловые коэффициенты k1 == k2, совпадают, если кроме этого равенства соблюдается
	равенство свободных членов b1 == b2 во всех других случаях прямые пересекаются
	*/
	if (!Line::CrossLine(l1, l2))//Если они параллельны, проверяем их коэфицент b
	{
		double b1 = l1.Coefficient_B();
		double b2 = l2.Coefficient_B();

		if (DoubleEq(b1, b2))//Если они(коэф. b) равны – прямые совпадают
			return true;
		else
			return false;
	}
	else
		return false;
}
bool Line::CrossLine(Line l1, Line l2)//Пересекаются ли прямые?
{
	/*
	y=k1*x+b1 и y=k2*x+b2. Определить, пересекаются ли эти прямые совпадают или параллельны
	– прямые параллельны если одинаковы их угловые коэффициенты k1 == k2, совпадают, если кроме этого равенства соблюдается 
	равенство свободных членов b1 == b2 во всех других случаях прямые пересекаются
	*/
	double k1 = l1.Coefficient_K();
	double k2 = l2.Coefficient_K();

	if (DoubleEq(k1, k2))
	{
		return false;
	}
	else
		return true;
	/*Совет Окулова
	double st;
	st = l1.GetA()*l2.GetB() - l2.GetA()*l1.GetB();
	return !DoubleEq(st, 0);*/
}

Line Line::EquationLine(Point A, Point B)// уравнение прямой, проходящей через две точки
{
	double a = A.GetY() - B.GetY();
	double b = B.GetX() - A.GetX();
	double c = A.GetX()*B.GetY() - B.GetX()*A.GetY();
	Line rez(a, b, c);
	return rez;
}

double Line::Coefficient_K(Point p1, Point p2)//Уравнение прямой вида: y=kx+b, где k - искомый коэф.
{
	return -((p1.GetY() - p2.GetY()) / (p2.GetX() - p1.GetX()));
}

double Line::Coefficient_B(Point p1, Point p2)//Уравнение прямой вида: y=kx+b, где b - искомый коэф.
{
	return -((p1.GetX()*p2.GetY() - p2.GetX()*p1.GetY()) / (p2.GetX() - p1.GetX()));
}
double Line::Coefficient_B()//Уравнение прямой вида: y=kx+b, где b - искомый коэф.
{
	return -(mC / mB);
}

double Line::Coefficient_K()//Уравнение прямой вида: y=kx+b, где k - искомый коэф.
{
	return -(mA / mB);
}

void Line::Show()//Отображение коэфицентов A,B,C
{
	printf("\n%5.2lf * X + %5.2lf * Y + %5.2lf \n", mA, mB, mC);
}
#pragma endregion