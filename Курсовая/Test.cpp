//
// Author: mouse71rus(Сергей Жимерин)
// 
//
#include "stdafx.h"

#include "Test.h"
#include "Point.h"
#include "Line.h"
#include "otrezok.h"
#include "OtherFunctions.h"

#include <iostream>
#include <string>
#include <string.h>
using namespace std;




void ShowAll(Point A, Point B, Point C, Point D)
{
	cout << "\tA: \n";
	A.ShowPosition();
	strstrstr();
	cout << "\tB: \n";
	B.ShowPosition();
	strstrstr();
	cout << "\tC: \n";
	C.ShowPosition();
	strstrstr();
	cout << "\tD: \n";
	D.ShowPosition();
	strstrstr();
}

void Testing(int NumberTest, int Part, string Otr1, string Otr2, Point A, Point B, Point C, Point D)
{
	system("cls");
	cout << "Test №" << NumberTest << "\t\tPart " << Part << ": " << Otr1 << " " << Otr2 << endl;
	ShowAll(A, B, C, D);
	if (Otrezok::isIntersectionLine(A, B, C, D))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}


void StartTest_CrossLine()
{
	setlocale(0, "");

	int NumberTest = 1;
	int Part = 0;
	int answer = 2;
	cout << "Тестирование пересечения отрезков: " << endl;
	do
	{
		if (answer == 2)
		{
			Part++;
		}
		else
		{
			Part = 1;
			NumberTest++;
		}

		int x, y;

		string o1;
		cout << "Первый отрезок: ";
		cin >> o1;

		string o2;
		cout << "Второй отрезок: ";
		cin >> o2;


		cout << o1[0] << "(x)=";
		cin >> x;
		cout << o1[0] << "(y)=";
		cin >> y;
		Point A(x, y);
		strstrstr();

		cout << o1[1] << "(x)=";
		cin >> x;
		cout << o1[1] << "(y)=";
		cin >> y;
		Point B(x, y);
		strstrstr();

		cout << o2[0] << "(x)=";
		cin >> x;
		cout << o2[0] << "(y)=";
		cin >> y;
		Point C(x, y);
		strstrstr();

		cout << o2[1] << "(x)=";
		cin >> x;
		cout << o2[1] << "(y)=";
		cin >> y;
		Point D(x, y);
		strstrstr();

		Testing(NumberTest, Part, o1, o2, A, B, C, D);
		strstrstr();
		cout << "1.Новый тест\n2. Новая часть\n0. Выход из теста" << endl;
		cin >> answer;
	} while (answer != 0);
}
