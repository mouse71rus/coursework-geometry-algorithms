//
// Author: mouse71rus(Сергей Жимерин)
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
	#pragma region Конструкторы_и_Деструктор
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

	#pragma region Методы
	double lengh();//Длина отрезка
	static double lengh(Point, Point);//Расстояние между двумя точками

	static bool isIntersectionLine(Point, Point, Point, Point);
	static bool isPoint_in_Line(Point, Otrezok);//Принадлежит ли точка отрезку?
#pragma endregion
};
