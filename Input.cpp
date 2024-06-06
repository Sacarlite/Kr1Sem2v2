#include "Input.h"//Подключение HeaderFile с вводом данных с консоли
#include <iostream>//Библиотека ввода и вывода
#include "Checks.h"//Подключение HeaderFile с проверками пользовательского ввода
#include "MainMenu.h"//Подключение HeaderFile с Enum menu

std::vector<Apartment> ConsoleIput()
{
	std::vector<Apartment> apartmens;//Объявления вектора объектов apartment
	std::cout << "Добавление квартир" << std::endl;
	int counter = 1;//Объявление счётчика 
	int userChoice = 0;//Объявление переменной пользовательского ввода
	while(true)
	{

		std::cout << "Квартира №" << counter<< std::endl;
		std::string adress = GetAdress();//Ввод переменной адреса
		std::cout << "Введите этаж:"<< std::endl;
		int floor = GetPositiveIntMoreThen0();//Ввод переменной этажа
		std::cout << "Введите количество комнат:" << std::endl;
		int roomCount = GetPositiveIntMoreThen0();//Ввод переменной  количества комнат
		std::cout << "Введите площадь квартиры:" << std::endl;
		double roomArea = GetPositiveDoubleMoreThen0();//Ввод переменной площади квартиры
		Apartment apartment(adress, floor, roomCount, roomArea);//Создание объекта типа Apartment
		apartmens.push_back(apartment);//Добавление в конец вектора обекта
		std::cout << "Хотите добавить ещё квартиру"<<std::endl;
		std::cout << "1)Да" << std::endl;
		std::cout << "2)Нет" << std::endl;
		userChoice = GetChoise();//Ввод пользовательского решения
		if(userChoice== Yes)
		{
			counter++;
			continue;
		}
		else
		{
			return apartmens;
		}
	}
}
