//
// Author: mouse71rus(������ �������)
// 
//
#pragma once
#include "Point.h"

class Line// ����� ��������� ������ Ax + By + C = 0
{
private:
	double mA;
	double mB;
	double mC;
public:
	#pragma region ������������_�_����������
	Line();
	Line(double, double, double);//������� ����������� A,B,C
	Line(Point, Point);//��������� ������ �� ���� ������
	~Line();
#pragma endregion

	#pragma region Get_Set
	double GetA();
	double GetB();
	double GetC();

	void SetA(double);
	void SetB(double);
	void SetC(double);
#pragma endregion

#pragma region ������
	static bool EqualLine(Line l1, Line l2);//��������� �� ������?
	static bool CrossLine(Line, Line);//������������ �� ������?
	static Line EquationLine(Point, Point);// ��������� ������, ���������� ����� ��� ����� 
	static double Coefficient_K(Point, Point);//��������� ������ ����: y=kx+b, ��� k - ������� ����.
	static double Coefficient_B(Point, Point);//��������� ������ ����: y=kx+b, ��� b - ������� ����.
	double Coefficient_B();//��������� ������ ����: y=kx+b, ��� b - ������� ����.
	double Coefficient_K();//��������� ������ ����: y=kx+b, ��� k - ������� ����.
	void Show();//����������� ����������� A,B,C
#pragma endregion

};