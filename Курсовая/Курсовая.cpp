// Курсовая.cpp: определяет точку входа для консольного приложения.
//
// Author: mouse71rus(Сергей Жимерин)
// 
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;
#include "Line.h"
#include "Vector.h"
#include "otrezok.h"
#include "OtherFunctions.h"
#include "Test.h"
#include "Task1.h"
#include "Task2.h"




int main()
{
	setlocale(0, "");
	int Answer = -1;
	do
	{
		system("cls");
		cout << "Меню:\n1. Задачи о поиске всех пересечений в наборе отрезков." << "\n2. Выпуклые оболочки"<< "\n\n0. Выход" << endl << "Выбор: ";
		cin >> Answer;
		switch (Answer)
		{
		case 1:
		{
			StartTask1();
			break;
		}
		case 2:
		{
			StartTask2();
			break;
		}
		default:
			break;
		}
	} while (Answer != 0);
	//StartTest_CrossLine();//Запуск теста пересечения отрезков
	system("pause");
    return 0;
}