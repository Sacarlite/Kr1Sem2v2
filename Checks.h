#pragma once
#include <string>//Подключение библиотеки строк
#include<fstream>//Подключение библиотеки файлового ввода

double GetPositiveDoubleMoreThen0();//Функция ввода с консоли значения с плавающей точкой
int GetPositiveIntMoreThen0();//Функция ввода с консоли целого положительного значения
int SetMenuPoint();//Функция ввода с консоли значения меню 
std::tuple<int,int> GetFloorRange();//Функция ввода с консоли диапазона рассматриваемых этажей
std::string CheckLineS(std::ifstream& file);//Функция ввода из фаила строкового значения
std::string GetAdress();//Функция ввода с консоли адреса
int CheckLineI(std::ifstream& file);//Функция ввода из фаила целого положительного значения
double CheckLineD(std::ifstream& file);//Функция ввода из фаила значения с плавающей точкой
int GetChoise();//Функция ввода пользовательского ввода