//
// Author: mouse71rus(Сергей Жимерин)
// 
//
#pragma once


class Point
{
private:
	double mX;
	double mY;
public:
	#pragma region Конструкторы_и_Деструктор
	Point();
	Point(double, double);
	/*Point(Point &);*/

	~Point();
#pragma endregion

	#pragma region GetSet
	double GetX();
	double GetY();

	void SetX(double);
	void SetY(double);
#pragma endregion
	
	#pragma region Методы
	void ShowPosition();
	static bool EqualPoint(Point, Point);//Совпадают ли точки
#pragma endregion
};