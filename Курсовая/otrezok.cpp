//
// Author: mouse71rus(Сергей Жимерин)
// 
//
#include "stdafx.h"
#include "otrezok.h"
#include "Point.h"
#include <math.h>
#include <cmath>
#include "Line.h"
#include "Vector.h"
#include "OtherFunctions.h"


#pragma region Конструкторы_и_Деструктор
Otrezok::Otrezok()
{
}

Otrezok::Otrezok(Point A, Point B)
{
	mA = A;
	mB = B;
}

Otrezok::Otrezok(double A_X, double A_Y, double B_X, double B_Y)
{
	mA.SetX(A_X);
	mA.SetY(A_Y);
	mB.SetX(B_X);
	mB.SetY(B_Y);
}


Otrezok::~Otrezok()
{
}
#pragma endregion

#pragma region Get_Set
Point Otrezok::GetA()
{
	return mA;
}
Point Otrezok::GetB()
{
	return mB;
}


void Otrezok::SetA(Point A)
{
	mA = A;
}
void Otrezok::SetB(Point B)
{
	mB = B;
}
#pragma endregion

#pragma region Методы
double Otrezok::lengh()//готов
{
	return (double)sqrt(pow((mB.GetX() - mA.GetX()), 2) + pow((mB.GetY() - mA.GetY()), 2));
}

double Otrezok::lengh(Point A, Point B)//готов
{
	return (double)sqrt(pow((B.GetX() - A.GetX()), 2) + pow((B.GetY() - A.GetY()), 2));
}

bool Otrezok::isIntersectionLine(Point A_p1, Point A_p2, Point B_p1, Point B_p2)
{
	Line L1;
	L1 = Line::EquationLine(A_p1, A_p2);

	Line L2;
	L2 = Line::EquationLine(B_p1, B_p2);

	double st = L1.GetA()*L2.GetB() - L2.GetA()*L1.GetB();

	Otrezok otr1(A_p1, A_p2);
	Otrezok otr2(B_p1, B_p2);

	if (Line::CrossLine(L1, L2) == true)//Если пересекаются - ищем точку пересечения
	{
		double dx = L1.GetC()*L2.GetB() - L2.GetC()*L1.GetB();
		double dy = L1.GetA()*L2.GetC() - L2.GetA()*L1.GetC();
		double X = -dx / st;
		double Y = -dy / st;

		Point Intersection(X, Y);

		if (isPoint_in_Line(Intersection, otr1) && isPoint_in_Line(Intersection, otr2))
			return true;
		else
			return false;
	}
	else//проверяем, а не совпадают ли они
	{
		if (Line::EqualLine(L1, L2) == true)//Если совпадают – проверяем принадлежность крайних точек отрезка второму отрезку
		{
			//серия проверок
			if (isPoint_in_Line(A_p1, otr2) || isPoint_in_Line(A_p2, otr2) || isPoint_in_Line(B_p1, otr1) || isPoint_in_Line(B_p2, otr1))//Принадлежит ли точка отрезку? isPoint_in_Line2(Point, Otrezok);
				return true;
			else
				return false;
		}
		else//Иначе отрезки не пересекаются
			return false;
	}
}

bool Otrezok::isPoint_in_Line(Point Temp, Otrezok OTR)//)//Принадлежит ли точка отрезку. По Окулову
{
	if (Point::EqualPoint(OTR.GetA(), OTR.GetB()))
		return Point::EqualPoint(OTR.GetA(), Temp);
	else
	{
		return (DoubleEq(((OTR.GetB().GetX() - OTR.GetA().GetX())*(Temp.GetY() - OTR.GetA().GetY())),
			((OTR.GetB().GetY() - OTR.GetA().GetY())*(Temp.GetX() - OTR.GetA().GetX())))
			&& ((DoubleMoreEq(Temp.GetX(), OTR.GetA().GetX()) && DoubleMoreEq(OTR.GetB().GetX(), Temp.GetX()))
				|| (DoubleMoreEq(Temp.GetX(), OTR.GetB().GetX()) && DoubleMoreEq(OTR.GetA().GetX(), Temp.GetX()))))
			// проверка крайних точек, если вдруг отрезки будут иметь одинаковые начальные точки, Окулов это не предусмотрел
			|| (Point::EqualPoint(Temp, OTR.GetA()) || Point::EqualPoint(Temp, OTR.GetB()));


	}
}
#pragma endregion
