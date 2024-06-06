#pragma once
#include <string>//Подключение библиотеки строк
/*
Класс квартира с приватными полями: адрес,этаж,количество комнат,площадь
*/
class Apartment//Класс квартира
{
private:
	std::string _adress{};//Поле адреса
	int _floor =0;//Поле этажа
	int _roomCount = 0;//Поле количества комнат
	double _area = 0;//Поле площади
public:
	Apartment() = default;//Конструктор по умолчанию
	Apartment(std::string adress, int floor,int roomCount,double area);//Конструктор

	void SetAdress(std::string adress);//Установка поля адрес
	std::string GetAdress();//Возврат значения поля адрес
	void ShowAdress();//Вывод на консоль поля адрес

	void SetFloor(int floor);//Установка поля этаж
	int GetFloor();//Возврат значения поля этаж
	void ShowFloor();//Вывод на консоль поля этаж

	void SetRoomCount(int roomCount);//Установка поля количества комнат
	int GetRoomCount();//Возврат значения поля количества комнат
	void ShowRoomCount();//Вывод на консоль поля количества комнат

	void SetArea(double area);//Установка поля площади квартиры
	double GetArea();//Возврат значения поля площади квартиры
	void ShowArea();//Вывод на консоль поля площади квартиры
};
