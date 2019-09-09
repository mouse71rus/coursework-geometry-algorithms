//
// Author: mouse71rus(Сергей Жимерин)
// 
//
#include "stdafx.h"
#include <iostream>
#include "Point.h"
#include "OtherFunctions.h"

#pragma region Конструкторы_и_Деструктор
Point::Point()
{
	mX = 0.0;
	mY = 0.0;
}
Point::Point(double x, double y)
{
	mX = x;
	mY = y;
}


Point::~Point()
{
}
#pragma endregion

#pragma region Get_Set
double Point::GetX()
{
	return mX;
}
double Point::GetY()
{
	return mY;
}

void Point::SetX(double NewX)
{
	mX = NewX;
}
void Point::SetY(double NewY)
{
	mY = NewY;
}
#pragma endregion

#pragma region Методы
void Point::ShowPosition()
{
	std::cout << "X: " << mX << std::endl << "Y: " << mY << std::endl;
}
bool Point::EqualPoint(Point A, Point B)//Совпадают ли точки
{
	return DoubleEq(A.GetX(), B.GetX()) && DoubleEq(A.GetY(), B.GetY());
}
#pragma endregion
