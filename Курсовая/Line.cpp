//
// Author: mouse71rus(������ �������)
// 
//
#include "stdafx.h"
#include "Point.h"
#include "Line.h"
#include <math.h>
#include "OtherFunctions.h"
using namespace std;

#pragma region ������������_�_����������
Line::Line()
{
	mA = 0.0;
	mB = 0.0;
	mC = 0.0;
}

Line::Line(double A, double B, double C)//������� ����������� A,B,C
{
	mA = A;
	mB = B;
	mC = C;
}
Line::Line(Point A, Point B)//��������� ������ �� ���� ������
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

#pragma region ������
bool Line::EqualLine(Line l1, Line l2)//��������� �� ������?
{
	/*
	y=k1*x+b1 � y=k2*x+b2. ����������, ������������ �� ��� ������ ��������� ��� �����������
	� ������ ����������� ���� ��������� �� ������� ������������ k1 == k2, ���������, ���� ����� ����� ��������� �����������
	��������� ��������� ������ b1 == b2 �� ���� ������ ������� ������ ������������
	*/
	if (!Line::CrossLine(l1, l2))//���� ��� �����������, ��������� �� ��������� b
	{
		double b1 = l1.Coefficient_B();
		double b2 = l2.Coefficient_B();

		if (DoubleEq(b1, b2))//���� ���(����. b) ����� � ������ ���������
			return true;
		else
			return false;
	}
	else
		return false;
}
bool Line::CrossLine(Line l1, Line l2)//������������ �� ������?
{
	/*
	y=k1*x+b1 � y=k2*x+b2. ����������, ������������ �� ��� ������ ��������� ��� �����������
	� ������ ����������� ���� ��������� �� ������� ������������ k1 == k2, ���������, ���� ����� ����� ��������� ����������� 
	��������� ��������� ������ b1 == b2 �� ���� ������ ������� ������ ������������
	*/
	double k1 = l1.Coefficient_K();
	double k2 = l2.Coefficient_K();

	if (DoubleEq(k1, k2))
	{
		return false;
	}
	else
		return true;
	/*����� �������
	double st;
	st = l1.GetA()*l2.GetB() - l2.GetA()*l1.GetB();
	return !DoubleEq(st, 0);*/
}

Line Line::EquationLine(Point A, Point B)// ��������� ������, ���������� ����� ��� �����
{
	double a = A.GetY() - B.GetY();
	double b = B.GetX() - A.GetX();
	double c = A.GetX()*B.GetY() - B.GetX()*A.GetY();
	Line rez(a, b, c);
	return rez;
}

double Line::Coefficient_K(Point p1, Point p2)//��������� ������ ����: y=kx+b, ��� k - ������� ����.
{
	return -((p1.GetY() - p2.GetY()) / (p2.GetX() - p1.GetX()));
}

double Line::Coefficient_B(Point p1, Point p2)//��������� ������ ����: y=kx+b, ��� b - ������� ����.
{
	return -((p1.GetX()*p2.GetY() - p2.GetX()*p1.GetY()) / (p2.GetX() - p1.GetX()));
}
double Line::Coefficient_B()//��������� ������ ����: y=kx+b, ��� b - ������� ����.
{
	return -(mC / mB);
}

double Line::Coefficient_K()//��������� ������ ����: y=kx+b, ��� k - ������� ����.
{
	return -(mA / mB);
}

void Line::Show()//����������� ����������� A,B,C
{
	printf("\n%5.2lf * X + %5.2lf * Y + %5.2lf \n", mA, mB, mC);
}
#pragma endregion