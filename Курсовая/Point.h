//
// Author: mouse71rus(������ �������)
// 
//
#pragma once


class Point
{
private:
	double mX;
	double mY;
public:
	#pragma region ������������_�_����������
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
	
	#pragma region ������
	void ShowPosition();
	static bool EqualPoint(Point, Point);//��������� �� �����
#pragma endregion
};