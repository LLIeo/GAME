#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "Functions_for_game.h"
#include <sstream>
#include <string>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <algorithm>
#include <vector>
#include <random>
//Cуть игры такова: на человечка сверху падают камни. Перемещение сделать через чек getch (Ф и В)
//Гораздо логичнее было бы сделать класс Персонаж, хранящий его координаты, но не додумался сразу
using namespace std;
//Ширина(Высота) поля
const int ZV = 10;

int main()
{
	//Ставим кастомный шрифт, размер и цвет. Некоторые антивирусы ругаются
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 28;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Bookman");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	//---------------------------------------------------------------------------------------//
	cout << "Loading..." << endl;
	//создаем поле, заполняем ПУСТОТОЙ
	setlocale(LC_CTYPE, "");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	bool bump = 0;
	int Points = 0;
	int CounterToSpawn = 2;
	char** field = new char* [ZV];
	for (int i = 0; i < ZV; i++)
	{
		field[i] = new char[ZV];
		for (int k = 0; k < ZV; k++)
		{
			field[i][k] = ' ';
		}
	}
	//Создаем персонажа (1 - код смайлика)
	int COUNT = 0;
	field[ZV - 2][5] = 1;
	static pair <int, int> p;
	p.first = ZV - 2;
	p.second = 5;
	clearConsole();
	//---------------------------------------------------------------------------------------//
	//Запуск!
	PrintHello();
	_getch();
	//Создание неиницализированных переменных, определяющих сложность.
	int SleepTime;
	int Min;
	int Max;
	int Interval;
	int MinusToSleepTime;
	string Mode;
	//Я горжусь этим циклом, оаоаоа
	Menu:
	while (PrintMenu())
	{
		//Выбор сложности с редактирование игровых настроек
		char a;
		cout << "Select your difficulty: \n1. EZ\n2. NORMAL\n3. INSANE";
		a = _getch();

		switch (a)
		{
		case('1'):
		{
			//EZ
			SleepTime = 1000;
			Min = 2;
			Max = 7;
			Interval = 3;
			MinusToSleepTime = 2;
			Mode = "Easy";
			goto ActualGame;
			break;
		}
		case ('2'):
		{//MD
			SleepTime = 900;
			Min = 2;
			Max = 6;
			Interval = 3;
			MinusToSleepTime = 3;
			Mode = "Medium";
			goto ActualGame;
			break;
		}
		case ('3'):
		{//INS
			SleepTime = 600;
			Min = 2;
			Max = 5;
			Interval = 2;
			MinusToSleepTime = 5;
			Mode = "Insane";
			goto ActualGame;
			break;
		}

		default:
		{
			cout << "\nWrong menu choice! NORMAL difficlty selected.";
			SleepTime = 900;
			Min = 2;
			Max = 6;
			Interval = 3;
			MinusToSleepTime = 3;
			Mode = "Medium";
			Sleep(1000);
			goto ActualGame;
			break;
		
		}
	ActualGame:
		Points = 0;
		while (bump == 0)
		{

			
			PrintField(field);
			cout << "\n\n" << Points;
			bump = MoveChara(field, SleepTime -= MinusToSleepTime, p);
			bump += Move(field, CounterToSpawn, Interval, p, Points, Min, Max);
		}
		cout << "\nThat was good!\nMode: " << Mode << ". Score : " << Points << ".\n "; cout << "Press any key to return to main menu!\n";
		bump = 0;
		ClearF(field, ZV ,ZV);
		
		_getch();
		goto Menu;
		}
		cout << "So on, homie!";
		Sleep(1000);

		return 11130;
	}
}


