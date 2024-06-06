#include <vector>//Библиотека подключения вектора
#include "Apartment.h"//Подключение HeaderFile с классом Apartment
#include "ConsoleOutput.h"//Подключение HeaderFile с выводом данных на консоль
#include <iostream>//Библиотека ввода и вывода


void ConsoleOutput(std::vector<Apartment> apartments)
{
	std::cout << "Количество подходящих квартир:" << apartments.size() << std::endl;
	std::cout << "Список квартир:" << std::endl;
	for (auto i = apartments.begin(); i < apartments.end(); ++i)//Перебор вектора квартир при помощи итератора https://metanit.com/cpp/tutorial/7.3.php
	{
		std::cout << "Квартира:" << std::endl;
		std::cout << "	Aдрес - ";
		i->ShowAdress();//Вывод адреса
		std::cout << "	Этаж - ";
		i->ShowFloor();//Вывод этажа
		std::cout << "	Количество комнат - ";
		i->ShowRoomCount();//Вывод количества комнат
		std::cout << "	Площадь - ";
		i->ShowArea();//Вывод площади
	}
}
