//
// Author: mouse71rus(Сергей Жимерин)
// 
//
#pragma once
#include "Point.h"

class Line// Общее уравнение прямой Ax + By + C = 0
{
private:
	double mA;
	double mB;
	double mC;
public:
	#pragma region Конструкторы_и_Деструктор
	Line();
	Line(double, double, double);//Задание коэфицентов A,B,C
	Line(Point, Point);//Уравнение прямой по двум точкам
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

#pragma region Методы
	static bool EqualLine(Line l1, Line l2);//Совпадают ли прямые?
	static bool CrossLine(Line, Line);//Пересекаются ли прямые?
	static Line EquationLine(Point, Point);// уравнение прямой, проходящей через две точки 
	static double Coefficient_K(Point, Point);//Уравнение прямой вида: y=kx+b, где k - искомый коэф.
	static double Coefficient_B(Point, Point);//Уравнение прямой вида: y=kx+b, где b - искомый коэф.
	double Coefficient_B();//Уравнение прямой вида: y=kx+b, где b - искомый коэф.
	double Coefficient_K();//Уравнение прямой вида: y=kx+b, где k - искомый коэф.
	void Show();//Отображение коэфицентов A,B,C
#pragma endregion

};