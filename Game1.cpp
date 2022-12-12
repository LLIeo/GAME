#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <sstream>
#include <string>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <vector>
//Cуть игры такова: на человечка сверху падают камни. Перемещение сделать через чек getch (Ф и В)
using namespace std;
const int NIGGERS = 10;
void PrintField(char** field);
void Move(char** field,  int& CounterToSpawn, int generated);
int main()
{
	//создаем поле, заполняем ПУСТОТОЙ
	setlocale(LC_CTYPE, "");
	bool bump = 0;
	int CounterToSpawn = 0;
	char** field = new char* [NIGGERS];
	for (int i = 0; i < NIGGERS; i++)
	{
		field[i] = new char[NIGGERS];
		for (int k = 0; k < NIGGERS; k++)
		{
			field[i][k] = ' ';
		}
	}
	//Создаем персонажа (1 - код смайлика)
	field[NIGGERS - 2][5] = 1;
	field[NIGGERS - 4][3] = '+';
	//До тех пор, пока он не врежется
	while (bump == 0) 
	{
		system("cls");
		PrintField(field);
		int generated = rand() % 3 + 3;
		Move(field, CounterToSpawn, generated);
		Sleep(1000);
	}
	PrintField(field);
	return 11130;
}




//Функция вывода поля
void PrintField(char** field)
{

	//Печать верхушки и низушки поля с фиксированным отступом
	for(int i = 0; i<NIGGERS+1; i++)
		printf("%*s", 2 , "-");
	cout << "\n";
	//Печать поля с символос вертикальной палочки и фиксированными отступами
	for (int i = 0; i < NIGGERS; i++)
	{
		cout << "|";
		for (int k = 0; k < NIGGERS; k++)
		{
			printf("%*c", 2, field[i][k]);
		}
		cout << "|\n";
	}
	for (int i = 0; i < NIGGERS+1; i++)
		printf("%*s", 2, "-");
}

//Функция, изменяющая состояние поля
void Move(char** field,  int& CounterToSpawn, int generated)
{
	srand(time(0));
	
	pair <int, int> a;
	srand(time(NULL));
	//Сохраняем корды перса
	for (int i = 0; i < NIGGERS; i++)
	{
		for (int k = 0; k < NIGGERS; k++)
		{
			if (field[i][k] == 1)
			{
				a.first = i; a.second = k;
			}
		}
	}
	//Смещаем все поле на одну линию вниз
		for (int i = 1; i < NIGGERS; i++)
		{
				field[i] = field[i - 1];
				strcpy(field[i-1], "          ");
				i++;
		}
		
		//оставляем перса на месте
		field[a.first][a.second] = 1;
		for (int i = 0; i < NIGGERS; i++)
		{
			field[0][i] == ' ';
		}
		CounterToSpawn++;
		if (CounterToSpawn == generated)
		{
			for (int i = 0; i < NIGGERS; i++)
			{
				if (rand() % 3 == 0)
				{
					field[0][i] = '+';
				}
				else field[0][i] == ' ';
			}
			CounterToSpawn = 0;
		}
		cout << CounterToSpawn;

}