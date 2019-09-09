//
// Author: mouse71rus(������ �������)
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
	#pragma region ������������_�_����������
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

	#pragma region ������
	void View();
	static double scalar(Vector,Vector);//��������� ������������ ��������
	static Vector VectorProiz(Vector, Vector);//��������� ������������
	static double VectorProizGeom(Vector, Vector);//��������� ������������ �������������� �����
#pragma endregion
};