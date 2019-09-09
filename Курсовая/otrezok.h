//
// Author: mouse71rus(������ �������)
// 
//
#pragma once
#include "Point.h"
#include "OtherFunctions.h"

class Otrezok
{
private:
	Point mA;
	Point mB;
public:
	#pragma region ������������_�_����������
	Otrezok();
	Otrezok(Point, Point);
	Otrezok(double, double, double, double);

	~Otrezok();
#pragma endregion

	#pragma region Get_Set
	Point GetA();
	Point GetB();

	void SetA(Point);
	void SetB(Point);
#pragma endregion

	#pragma region ������
	double lengh();//����� �������
	static double lengh(Point, Point);//���������� ����� ����� �������

	static bool isIntersectionLine(Point, Point, Point, Point);
	static bool isPoint_in_Line(Point, Otrezok);//����������� �� ����� �������?
#pragma endregion
};
