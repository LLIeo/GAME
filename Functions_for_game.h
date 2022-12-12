#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include<algorithm>
#include <vector>
#include <random>
using namespace std;
void PrintField(char** field);
void ClearF(char** field, int h, int w);
bool Move(char** field, int& CounterToSpawn, int generated, pair<int, int>& p, int& points, int Min, int Max);
int Random(int a, int b);
bool MoveChara(char** field, int S, pair <int, int> &p);
void clearConsole();
void PrintHello();
bool PrintMenu();