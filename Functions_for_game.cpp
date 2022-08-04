#include "Functions_for_game.h"
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "Functions_for_game.h"
#include <sstream>
#include <string>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <thread>
#include <functional>
#include<algorithm>
#include <vector>
#include <random>
using namespace std;
const int ZV = 10;


//������� ������ ����
void PrintField(char** field)
{
	clearConsole();
	//������ �������� � ������� ���� � ������������� ��������
	for (int i = 0; i < ZV + 1; i++)
		printf("%*s", 2, "-");
	cout << "\n";
	//������ ���� � �������� ������������ ������� � �������������� ���������
	for (int i = 0; i < ZV; i++)
	{
		cout << "|";
		for (int k = 0; k < ZV; k++)
		{
			printf("%*c", 2, field[i][k]);
		}
		cout << "|\n";
	}
	for (int i = 0; i < ZV + 1; i++)
		printf("%*s", 2, "-");
}

//�������, ���������� ��������� ����
bool Move(char** field, int& CounterToSpawn, int generated, pair<int, int> &p, int &points, int Min, int Max)
{
	bool bump = 0;
	srand(time(NULL));
	field[p.first][p.second] = ' ';
	//������� ��� ���� �� ���� ����� ����
	for (int i = ZV - 1; i > 0; i--)
	{
		char* tmp = field[i - 1];
		field[i - 1] = field[i];
		field[i] = tmp;
	}
	if (field[p.first][p.second] == '+')
	{
		bump = 1;
		return bump;
	}
	else {
	//��������� ����� �� �����
	field[p.first][p.second] = 1;
	for (int i = 0; i < ZV; i++)
	{
		field[0][i] = ' ';
	}
	CounterToSpawn++;
	srand(time(0));
	int x = 0;
	//�������� ��������� ��� �������������� ���������, ������� �������� �) ������ ���� ������� ��� ������� � RD. �) ������� ������������� �������� ��������
	if (CounterToSpawn == generated || CounterToSpawn > 4)
	{
		Generate:
		for (int i = 0; i < ZV; i++)
		{
			int t = Random(Min, Max);
			if (t == 2 || t == 7)
			{
				field[0][i] = '+';
				x++;
			}
			else field[0][i] = ' ';
		}
		if (x == 0) goto Generate;
		CounterToSpawn = 0;
	}
	points++;
	return bump;
}
}
//���������������� ��������������� ���� ����� �� �����
int Random(int a, int b)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(a, b);
	return dis(gen);
}

bool MoveChara(char** field, int S, pair<int, int> &p)
{
	//������� ����������� ����, ������� ���������� �� ��������� ������� �������� ������� Move.|| UPD: Sleep(ST) ����� ���� ������, ��� � � ������)
	auto start = clock();
	char mov;
	bool fin = 0;
	while (true)
	{
		if (start + S < clock())
			break;
		if (_kbhit()) 
		{
			mov = _getch();
		
				if (mov == 'd' || mov == 'D' || mov == '�' ||  mov == '�')
				{
					if (p.second != 9) {
						if (field[ZV - 2][p.second + 1] == '+')
						{
							fin = 1;
							goto ret;
						}
						else {
							swap(field[ZV - 2][p.second + 1], field[ZV - 2][p.second]);
							p.second += 1;
						}
						PrintField(field);
					}
				}
				if (mov == 'a' || mov == '�' || mov == '�' || mov =='A')
				{
					if (p.second != 0) {
						if (field[ZV - 2][p.second - 1] == '+')
						{
							fin = 1;
							goto ret;
						}
						else {
							swap(field[ZV - 2][p.second - 1], field[ZV - 2][p.second]);
							p.second -= 1;
						}
						PrintField(field);
					}
				}
			}
		}
	ret:
	return fin;
}


//���������� (�� ��������� � CLS) ������� �������
void clearConsole() {
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}


//�������� ��������, �?)
void PrintHello()
{
	cout << " _____    _____   _      _   ______" << endl;
	cout << "|        |     | | \\    / | |      " << endl;
	cout << "|        |     | |  \\  /  | |      " << endl;
	cout << "|        |     | |   \\/   | |      " << endl;
	cout << "|    __  |_____| |        | |----- " << endl;
	cout << "|      | |     | |        | |      " << endl;
	cout << "|      | |     | |        | |      " << endl;
	cout << " ------  |     | |        | |______" << endl;
	cout << "\tGame 1.0.2 by Sheo\n\tPress any key to continue!" << endl;
}

bool PrintMenu()
{
	char a = 0;
	while (1)
	{
		clearConsole();
		cout << "Welcome to my game! Hope you will enjoy it!" << endl;
		cout << "Enter your choice: " << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "1. Start a GAME" << endl;
		cout << "2. Help" << endl;
		cout << "3. Credits" << endl;
		cout << "z. Exit" << endl;
		a = _getch();
		switch (a)
		{
		case('1'):
		{
			return 1;
			break;
		}
		case ('2'):
		{
			cout << "\n\nThis is a simple console computer game, which was being made \nfor almost 20 hours by a single person just to show off. \n\n" << "~~~~~~~~\n" <<
				"Gameplay is way too simple: YOU HAVE TO AVOID OBSTACKLES!\n\n" << "~~~~~~~~\n" <<
				"Switch on ENGLISH KEYBOARD WITHOUT CAPSLOCK on your device. \n\nIt is important, cause Russian language is kinda destructive for console games.\n";
			cout << "I hope you will enjoy it!\n\n Press any key to continue...\n";
			_getch();
			break;
		}
		case ('3'):
		{
			cout << "Developer: Sheo\n";
			cout << "Testers: sadlemon, Kuomi, ArtemPutinZZZ\n";
			cout << "Special thx to: you :)\n";
			cout << "Press any key to go to main menu...\n";
			_getch();
			break;
		}
		case ('z'):
		{
			return 0;
			break;
		}
		case ('Z'):
		{
			return 0;
			break;
		}
		default:
			cout << "Wrong menu choice!" << endl;
			cout << "Press any key to go to main menu...\n";
			_getch();
			break;
		}

	}
}