//
// Author: mouse71rus(Сергей Жимерин)
// 
//
#include "stdafx.h"
#include "Task1.h"

#include "Test.h"
#include "Point.h"
#include "Line.h"
#include "otrezok.h"
#include "OtherFunctions.h"

#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
using namespace std;

string strPPPO = "Проверить, пересекаются ли заданные прямолинейные отрезки.";
string strVPPO = "Найти все пересечения прямолинейных отрезков.";

#pragma region ПППО
ifstream fin;
ofstream fout;
bool err = false;
void OpenFileStream(string FileName)
{
	try
	{
		err = false;
		fin.open(FileName);
		if (fin.fail() || fin.bad())
		{
			throw runtime_error("Во время открытия файла " + FileName + " произошла ошибка.");
		}
	}
	catch (const exception &er)//Информация по обработке такой ошибки взята отсюда http://www.cyberforum.ru/cpp-beginners/thread1724161.html#post9086315
	{
		err = true;
		system("cls");
		strstrstr(45, '*');
		cout << er.what() << endl;
		strstrstr(45, '*');
	}
}
void PPPO()//Проверить, пересекаются ли заданные прямолинейные отрезки
{
	system("cls");
	cout << "Задание: "<< strPPPO << endl;
	strstrstr();
	cout << "Дано: n прямолинейных отрезков на плоскости.\nТребуется: определить факт пересечения хотя бы двух из них.\nОтвет задачи – «да», если пересекаются, или «нет» в противном случае." << endl;
	strstrstr();
	cout << "Введите имя файла, содержащего координаты точек: ";
	string FileName;
	cin >> FileName;
	FileName += ".txt";
	OpenFileStream(FileName);
	if (err)
		return;
	
	int N;//считываем кол-во отрезков
	fin >> N;
	//Формируем массив отрезков
	Otrezok *otr = new Otrezok[N];
	for (int i = 0, x1, y1, x2, y2; i < N; i++)
	{
		fin >> x1;
		fin >> y1;
		fin >> x2;
		fin >> y2;

		Point p1(x1, y1);
		Point p2(x2, y2);

		otr[i] = Otrezok(p1, p2);
	}
	int kol = 0;
	for (int i = 0; i < N - 1; i++)
		for (int j = i + 1; j < N; j++)
		{
			if (Otrezok::isIntersectionLine(otr[i].GetA(), otr[i].GetB(), otr[j].GetA(), otr[j].GetB()))
				kol++;
		}

	if (kol > 0)
		cout << "Ответ: Да" << endl;
	else 
		cout << "Ответ: Нет" << endl;
	strstrstr();
	try
	{
		fout.open("Output_T1_z1.txt");
		if (fout.fail() || fout.bad())
		{
			throw runtime_error("Во время открытия файла Output_T1_z1.txt произошла ошибка.");
		}
		if (kol > 0)
			fout << "Да" << endl;
		else
			fout << "Нет" << endl;
	}
	catch (const exception &er)
	{
		system("cls");
		strstrstr(45, '*');
		cout << er.what() << endl;
		strstrstr(45, '*');
		return;
	}


	if (!fout.bad())
		fout.close();

	if(!fin.bad())
		fin.close();
	delete[]otr;
}
#pragma endregion



#pragma region ВППО

void VPPO()//Найти все пересечения прямолинейных отрезков
{
	int Answer = -1;
	do
	{
		system("cls");
		cout << "Задание: " << strVPPO << endl;
		strstrstr();
		cout << "Дано: n прямолинейных отрезков на плоскости.\nТребуется: Найти все попарные пересечения отрезков.\nОтвет задачи: \n\t1. Число попарных пересечений\n\t2. Перечень всех пар пересекающихся отрезков\nВыбор: ";
		cin >> Answer;
	} while (Answer < 1 || Answer >2);
	strstrstr();
	cout << "Введите имя файла, содержащего координаты точек: ";
	string FileName;
	cin >> FileName;
	FileName += ".txt";
	OpenFileStream(FileName);
	if (err)
		return;

	int N;//считываем кол-во отрезков
	fin >> N;
	//Формируем массив отрезков
	Otrezok *otr = new Otrezok[N];
	for (int i = 0, x1, y1, x2, y2; i < N; i++)
	{
		fin >> x1;
		fin >> y1;
		fin >> x2;
		fin >> y2;

		Point p1(x1, y1);
		Point p2(x2, y2);

		otr[i] = Otrezok(p1, p2);
	}
	int kol = 0;
	try
	{
		fout.open("Output_T1_z2.txt");
		if (fout.fail() || fout.bad())
		{
			throw runtime_error("Во время открытия файла Output_T1_z2.txt произошла ошибка.");
		}
	}
	catch (const exception &er)
	{
		system("cls");
		strstrstr(45, '*');
		cout << er.what() << endl;
		strstrstr(45, '*');
		return;
	}
	if (Answer == 1)
	{
		for (int i = 0; i < N - 1; i++)
			for (int j = i + 1; j < N; j++)
			{

				if (Otrezok::isIntersectionLine(otr[i].GetA(), otr[i].GetB(), otr[j].GetA(), otr[j].GetB()))
					kol++;
			}
		cout << "Ответ: Число попарных пересечений: " << kol << endl;
		fout << kol << endl;

	}
	else
	{
		fout << "Перечень всех пар пересекающихся отрезков:" << endl;

		for (int i = 0; i < N - 1; i++)
			for (int j = i + 1; j < N; j++)
			{
				Point p1 = otr[i].GetA();
				Point p2 = otr[i].GetB();
				Point p3 = otr[j].GetA();
				Point p4 = otr[j].GetB();

				if (Otrezok::isIntersectionLine(p1, p2, p3, p4))
				{
					kol++;

					fout << "\tОтрезок " << i << " [(" << p1.GetX() << ", " << p1.GetY() << "), (" << p2.GetX() << ", " << p2.GetY() << ")] пересекается с отрезком " << j << " [(" << p3.GetX() << ", " << p3.GetY() << "), (" << p4.GetX() << ", " << p4.GetY() << ")]" << endl;
				}
			}
		if (kol == 0) 
		{
			cout << "Ни одна из пар отрезков не пересекается." << endl;
			fout << "\tНи одна из пар отрезков не пересекается." << endl;
		}
	}
	strstrstr();
	if (!fout.bad())
		fout.close();
	if (!fin.bad())
		fin.close();
	delete[]otr;
}
#pragma endregion

void HelpTask1()
{
	system("cls");
	cout << "Справка:" << endl;
	strstrstr(80, '*');
	cout<<"Имя входного текстового файла вводится без указания его расширения(без *.txt).\n\t\t\tСодержание файла:\nВходной файл в первой строке содержит число N, отвечающее за кол-во отрезков.\nДалее в N строках записаны координаты отрезков(по 4 числа в каждой строке).\nФормат каждой строки: x1 y1 x2 y2" << endl;
	strstrstr(30);
	cout << "Пример входного файла: " << endl;

	printf("%5d\n", 6);
	printf("%5d %5d %5d %5d\n", -4, 4, -2, 1);
	printf("%5d %5d %5d %5d\n", -3, -1, 3, -1);
	printf("%5d %5d %5d %5d\n", -1, 0, -1, 4);
	printf("%5d %5d %5d %5d\n", 1, 1, 2, 4);
	printf("%5d %5d %5d %5d\n", 2, 2, 7, -1);
	printf("%5d %5d %5d %5d\n", 4, 0, 3, -4);

	strstrstr(30);
	strstrstr(80, '*');
	system("pause");
	system("cls");
}


void StartTask1()
{
	system("cls");
	int Answer = -1;
	do
	{
		cout << "Решение задач о пересечениях отрезков\n1. " << strPPPO << "\n2. " << strVPPO << "\n3. Справка\n\n0. Назад" << endl << "Выбор: ";
		cin >> Answer;
		switch (Answer)
		{
		case 1:
		{
			PPPO();
			break;
		}
		case 2:
		{
			VPPO();
			break;
		}
		case 3:
		{
			HelpTask1();
			break;
		}
		default:
			break;
		}
	} while (Answer != 0);
}

