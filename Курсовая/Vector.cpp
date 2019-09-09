//
// Author: mouse71rus(Сергей Жимерин)
// 
//
#include "stdafx.h"
#include "Vector.h"
#include <iostream>
#include "OtherFunctions.h"

#pragma region Конструкторы_и_Деструктор
Vector::Vector()
{
	mX = 0;
	mY = 0;
	mZ = 0;
}
Vector::Vector(double x, double y, double z)
{
	mX = x;
	mY = y;
	mZ = z;
}

Vector::~Vector()
{
}
#pragma endregion

#pragma region Get_Set
double Vector::GetX()
{
	return mX;
}
double Vector::GetY()
{
	return mY;
}
double Vector::GetZ()
{
	return mZ;
}


void Vector::SetX(double x)
{
	mX = x;
}
void Vector::SetY(double y)
{
	mY = y;
}
void Vector::SetZ(double z)
{
	mZ = z;
}
#pragma endregion

#pragma region Методы
void Vector::View()
{
	std::cout << "Координаты вектора:" << std::endl;
	std::cout << mX << " " << mY << " " << mZ << std::endl;
}
double Vector::scalar(Vector a, Vector b)//скалярное произведение векторов
{
	return a.GetX() * b.GetX() + a.GetY() * b.GetY() + a.GetZ() * b.GetZ();
}

Vector Vector::VectorProiz(Vector A, Vector B)//векторное произведение
{
	Vector Temp;
	Temp.SetX(A.GetY() * B.GetZ() - B.GetY() * A.GetZ());
	Temp.SetY(A.GetZ() * B.GetX() - A.GetX() * B.GetZ());
	Temp.SetZ(A.GetX() * B.GetY() - A.GetY() * B.GetX());
	return Temp;
}

double Vector::VectorProizGeom(Vector A, Vector B)//векторное произведение геометрический смысл
{
	Vector Temp;
	Temp.SetX(A.GetY() * B.GetZ() - B.GetY() * A.GetZ());
	Temp.SetY(A.GetZ() * B.GetX() - A.GetX() * B.GetZ());
	Temp.SetZ(A.GetX() * B.GetY() - A.GetY() * B.GetX());

	return sqrt(pow(Temp.GetX(), 2) + pow(Temp.GetY(), 2) + pow(Temp.GetZ(), 2));
}
#pragma endregion
