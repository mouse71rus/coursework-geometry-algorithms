//
// Author: mouse71rus(Сергей Жимерин)
// 
//
#pragma once
class Vector
{
private:
	double mX;
	double mY;
	double mZ;
public:
	#pragma region Конструкторы_и_Деструктор
	Vector();
	Vector(double, double, double);

	~Vector();
#pragma endregion

	#pragma region Get_Set
	double GetX();
	double GetY();
	double GetZ();

	void SetX(double _x);
	void SetY(double _y);
	void SetZ(double _z);
#pragma endregion

	#pragma region Методы
	void View();
	static double scalar(Vector,Vector);//скалярное произведение векторов
	static Vector VectorProiz(Vector, Vector);//векторное произведение
	static double VectorProizGeom(Vector, Vector);//векторное произведение геометрический смысл
#pragma endregion
};