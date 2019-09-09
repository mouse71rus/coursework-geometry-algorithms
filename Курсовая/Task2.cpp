//
// Author: mouse71rus(Сергей Жимерин)
// 
//
#include "stdafx.h"
#include "Task2.h"

#include "Test.h"
#include "Point.h"
#include "Line.h"
#include "otrezok.h"
#include "OtherFunctions.h"

#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <vector>
using namespace std; 


#pragma region Алгоритм Джарвиса
int OrientTriangl2(Point &p1, Point &p2, Point &p3)//ориентированная площадь http://www.e-maxx-ru.1gb.ru/algo/oriented_area
{
	return p1.GetX() * (p2.GetY() - p3.GetY()) + p2.GetX() * (p3.GetY() - p1.GetY()) + p3.GetX() * (p1.GetY() - p2.GetY());
}
bool isInside(Point &p1, Point &p, Point &p2)//находится ли точка в прямоугольнике, который образуют 2 точки
{
	return (p1.GetX() <= p.GetX() && p.GetX() <= p2.GetX() &&
		p1.GetY() <= p.GetY() && p.GetY() <= p2.GetY());
}
void ConvexHullJarvis(vector<Point> &mas, vector<int> &convex_hull, int N)
{
	// находим самую левую из самых нижних
	int base = 0;
	for (int i = 1; i<N; i++)
	{
		if (mas[i].GetY() < mas[base].GetY())
			base = i;
		else
			if (mas[i].GetY() == mas[base].GetY() &&
				mas[i].GetX() <  mas[base].GetX())
				base = i;
	}
	// эта точка точно входит в выпуклую оболочку
	convex_hull.push_back(base);// Добавление элемента в конец вектора

	int first = base;
	int cur = base;
	do
	{
		int next = (cur + 1) % N;
		for (int i = 0; i<N; i++)
		{
			int sign = OrientTriangl2(mas[cur], mas[next], mas[i]);
			// точка mas[i] находится левее прямой ( mas[cur], mas[next] )
			if (sign < 0) // обход выпуклой оболочки против часовой стрелки
				next = i;
			// точка лежит на прямой, образованной точками  mas[cur], mas[next]
			else if (sign == 0)
			{
				// точка mas[i] находится дальше, чем mas[next] от точки mas[cur]
				if (isInside(mas[cur], mas[next], mas[i]))
					next = i;
			}
		}
		cur = next;
		convex_hull.push_back(next);// Добавление элемента в конец вектора
	} while (cur != first);
}

#pragma endregion




ifstream finT2;
ofstream foutT2;
bool errT2 = false;
void OpenFileStreamT2(string FileName)
{
	try
	{
		errT2 = false;
		finT2.open(FileName);
		if (finT2.fail() || finT2.bad())
		{
			throw runtime_error("Во время открытия файла " + FileName + " произошла ошибка.");
		}
	}
	catch (const exception &er)//Информация по обработке такой ошибки взята отсюда http://www.cyberforum.ru/cpp-beginners/thread1724161.html#post9086315
	{
		errT2 = true;
		system("cls");
		strstrstr(45, '*');
		cout << er.what() << endl;
		strstrstr(45, '*');
	}
}


#include "iomanip"//для форматированного вывода
void FindingPerimeter()
{
	system("cls");
	cout << "Задание: " << "Найти минимальный периметр многоугольника, содержащего все заданные точки" << endl;
	strstrstr();
	cout << "Дано: На плоскости заданы N точек своими декартовыми координатами. Найти минимальный периметр многоугольника, содержащего все эти точки. Гарантируется, что искомый многоугольник имеет ненулевую площадь." << endl;
	strstrstr();
	cout << "Входные данные: Входной файл в первой строке содержит число N, далее - N строк с парами координат (xi, yi). \nОграничения: 3 <= N <= 1000, -10 000 <= xi, yi <= 10 000, все числа целые, все точки различны." << endl;
	strstrstr();
	cout << "Выходные данные: В выходной файл выведите одно вещественное число - длину периметра полученного многоугольника с одним знаком после запятой." << endl;
	strstrstr();
	cout << "Введите имя файла, содержащего координаты точек: ";
	string FileName;
	cin >> FileName;
	FileName += ".txt";
	OpenFileStreamT2(FileName);
	if (errT2)
		return;
	vector<Point> mas;
	vector<int> convex_hull;
	int N;//считываем кол-во точек
	finT2 >> N;
	mas.resize(N);
	for (int i = 0, t1, t2; i < N; i++)
	{
		finT2 >> t1;
		mas[i].SetX(t1);

		finT2 >> t2;
		mas[i].SetY(t2);
	}
	double P = 0;

	ConvexHullJarvis(mas, convex_hull, N);
	for (size_t i = 0; i < convex_hull.size() - 1; i++)
		P += Otrezok::lengh(mas[convex_hull[i]], mas[convex_hull[i + 1]]);

	printf("Ответ: %0.1f\n", P);
	try
	{
		foutT2.open("Output_T2_z1.txt");
		if (foutT2.fail() || foutT2.bad())
		{
			throw runtime_error("Во время открытия файла Output_T2_z1.txt произошла ошибка.");
		}
		foutT2 << fixed << setprecision(1) << P << endl;
	}
	catch (const exception &er)//Информация по обработке такой ошибки взята отсюда http://www.cyberforum.ru/cpp-beginners/thread1724161.html#post9086315
	{
		system("cls");
		strstrstr(45, '*');
		cout << er.what() << endl;
		strstrstr(45, '*');
		return;
	}

	if (!finT2.bad())
		finT2.close();
	if (!foutT2.bad())
		foutT2.close();
}
//Дано n точек на плоскости. Построить их минимальную выпуклую оболочку.
//В первой строке задано количество точек n (3 ≤ n ≤ 10^5). Следующие n строк содержат пары целых чисел xi и yi (-10^9 ≤ xi, yi ≤ 10^9) - координаты точек.
void HelpTask2()
{
	system("cls");
	cout << "Справка:" << endl;
	strstrstr(80, '*');
	cout << "Имя входного текстового файла вводится без указания его расширения(без *.txt).\n\t\t\tСодержание файла:\nВходной файл в первой строке содержит число N, отвечающее за кол-во точек.\nДалее в N строках записаны координаты точек(по 2 числа в каждой строке).\nФормат каждой строки: x y" << endl;
	strstrstr(30);
	cout << "Пример входного файла: " << endl;

	printf("%5d\n", 8);
	printf("%5d %5d\n", -4, 4);
	printf("%5d %5d\n", -3, -1);
	printf("%5d %5d\n", -1, 0);
	printf("%5d %5d\n", -1, 4);
	printf("%5d %5d\n", 2, 4);
	printf("%5d %5d\n", 1, 1);
	printf("%5d %5d\n", 2, 2);
	printf("%5d %5d\n", 7, -1);

	strstrstr(30);
	strstrstr(80, '*');
	system("pause");
	system("cls");
}
void BuildingHull()
{
	system("cls");
	cout << "Задание: " << "Построить минимальную выпуклую оболочку заданных точек." << endl;
	strstrstr();
	cout << "Дано: Дано n точек на плоскости. Построить их минимальную выпуклую оболочку." << endl;
	strstrstr();
	cout << "Входные данные: В первой строке задано количество точек n (3 <= n <= 10^5). Следующие n строк содержат пары целых чисел xi и yi (-10^9 <= xi, yi <= 10^9) - координаты точек." << endl;
	strstrstr();
	cout << "Выходные данные: В первой строке выведите количество вершин n выпуклой оболочки. Следующие n строк должны содержать координаты вершин в порядке обхода. Никакие три подряд идущие точки не должны лежать на одной прямой." << endl;
	strstrstr();
	cout << "Введите имя файла, содержащего координаты точек: ";
	string FileName;
	cin >> FileName;
	FileName += ".txt";
	OpenFileStreamT2(FileName);
	if (errT2)
		return;
	vector<Point> mas;
	vector<int> convex_hull;
	int N;//считываем кол-во точек
	finT2 >> N;
	mas.resize(N);
	for (int i = 0, t1, t2; i < N; i++)
	{
		finT2 >> t1;
		mas[i].SetX(t1);

		finT2 >> t2;
		mas[i].SetY(t2);
	}

	ConvexHullJarvis(mas, convex_hull, N);
	cout << convex_hull.size() - 1 << endl;
	for (size_t i = 0; i < convex_hull.size() - 1; i++)
		cout << mas[convex_hull[i]].GetX() << " " << mas[convex_hull[i]].GetY() << endl;

	try
	{
		foutT2.open("Output_T2_z2.txt");
		if (foutT2.fail() || foutT2.bad())
		{
			throw runtime_error("Во время открытия файла Output_T2_z2.txt произошла ошибка.");
		}
		foutT2 << convex_hull.size() - 1 << endl;
		for (size_t i = 0; i < convex_hull.size() - 1; i++)
			foutT2 << mas[convex_hull[i]].GetX() << " " << mas[convex_hull[i]].GetY() << endl;
	}
	catch (const exception &er)//Информация по обработке такой ошибки взята отсюда http://www.cyberforum.ru/cpp-beginners/thread1724161.html#post9086315
	{
		system("cls");
		strstrstr(45, '*');
		cout << er.what() << endl;
		strstrstr(45, '*');
		return;
	}

	if (!finT2.bad())
		finT2.close();
	if (!foutT2.bad())
		foutT2.close();
}
void StartTask2()
{
	system("cls");
	int Answer = -1;
	do
	{
		cout << "Решение задач о выпуклых оболочках\n1. " << "Задача о нахождении периметра" << "\n2. " << "Задача на построение МВО" << "\n3. Справка\n\n0. Назад" << endl << "Выбор: ";
		cin >> Answer;
		switch (Answer)
		{
		case 1:
		{
			FindingPerimeter();
			break;
		}
		case 2:
		{
			BuildingHull();
			break;
		}
		case 3:
		{
			HelpTask2();
			break;
		}
		default:
			break;
		}
	} while (Answer != 0);
	strstrstr(60);
}