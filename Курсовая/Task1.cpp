//
// Author: mouse71rus(������ �������)
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

string strPPPO = "���������, ������������ �� �������� ������������� �������.";
string strVPPO = "����� ��� ����������� ������������� ��������.";

#pragma region ����
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
			throw runtime_error("�� ����� �������� ����� " + FileName + " ��������� ������.");
		}
	}
	catch (const exception &er)//���������� �� ��������� ����� ������ ����� ������ http://www.cyberforum.ru/cpp-beginners/thread1724161.html#post9086315
	{
		err = true;
		system("cls");
		strstrstr(45, '*');
		cout << er.what() << endl;
		strstrstr(45, '*');
	}
}
void PPPO()//���������, ������������ �� �������� ������������� �������
{
	system("cls");
	cout << "�������: "<< strPPPO << endl;
	strstrstr();
	cout << "����: n ������������� �������� �� ���������.\n���������: ���������� ���� ����������� ���� �� ���� �� ���.\n����� ������ � ���, ���� ������������, ��� ���� � ��������� ������." << endl;
	strstrstr();
	cout << "������� ��� �����, ����������� ���������� �����: ";
	string FileName;
	cin >> FileName;
	FileName += ".txt";
	OpenFileStream(FileName);
	if (err)
		return;
	
	int N;//��������� ���-�� ��������
	fin >> N;
	//��������� ������ ��������
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
		cout << "�����: ��" << endl;
	else 
		cout << "�����: ���" << endl;
	strstrstr();
	try
	{
		fout.open("Output_T1_z1.txt");
		if (fout.fail() || fout.bad())
		{
			throw runtime_error("�� ����� �������� ����� Output_T1_z1.txt ��������� ������.");
		}
		if (kol > 0)
			fout << "��" << endl;
		else
			fout << "���" << endl;
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



#pragma region ����

void VPPO()//����� ��� ����������� ������������� ��������
{
	int Answer = -1;
	do
	{
		system("cls");
		cout << "�������: " << strVPPO << endl;
		strstrstr();
		cout << "����: n ������������� �������� �� ���������.\n���������: ����� ��� �������� ����������� ��������.\n����� ������: \n\t1. ����� �������� �����������\n\t2. �������� ���� ��� �������������� ��������\n�����: ";
		cin >> Answer;
	} while (Answer < 1 || Answer >2);
	strstrstr();
	cout << "������� ��� �����, ����������� ���������� �����: ";
	string FileName;
	cin >> FileName;
	FileName += ".txt";
	OpenFileStream(FileName);
	if (err)
		return;

	int N;//��������� ���-�� ��������
	fin >> N;
	//��������� ������ ��������
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
			throw runtime_error("�� ����� �������� ����� Output_T1_z2.txt ��������� ������.");
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
		cout << "�����: ����� �������� �����������: " << kol << endl;
		fout << kol << endl;

	}
	else
	{
		fout << "�������� ���� ��� �������������� ��������:" << endl;

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

					fout << "\t������� " << i << " [(" << p1.GetX() << ", " << p1.GetY() << "), (" << p2.GetX() << ", " << p2.GetY() << ")] ������������ � �������� " << j << " [(" << p3.GetX() << ", " << p3.GetY() << "), (" << p4.GetX() << ", " << p4.GetY() << ")]" << endl;
				}
			}
		if (kol == 0) 
		{
			cout << "�� ���� �� ��� �������� �� ������������." << endl;
			fout << "\t�� ���� �� ��� �������� �� ������������." << endl;
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
	cout << "�������:" << endl;
	strstrstr(80, '*');
	cout<<"��� �������� ���������� ����� �������� ��� �������� ��� ����������(��� *.txt).\n\t\t\t���������� �����:\n������� ���� � ������ ������ �������� ����� N, ���������� �� ���-�� ��������.\n����� � N ������� �������� ���������� ��������(�� 4 ����� � ������ ������).\n������ ������ ������: x1 y1 x2 y2" << endl;
	strstrstr(30);
	cout << "������ �������� �����: " << endl;

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
		cout << "������� ����� � ������������ ��������\n1. " << strPPPO << "\n2. " << strVPPO << "\n3. �������\n\n0. �����" << endl << "�����: ";
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

