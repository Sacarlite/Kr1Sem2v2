#include "Samplings.h"//Подключение HeaderFile с выборками
#include "Checks.h"//Подключение HeaderFile с проверками пользовательского ввода
#include <iostream>//Подключение библиотеки ввода и вывода
#include <tuple>//Подключение библиотеки кортежей

std::vector<Apartment> SamplingApartmentsByRoomCount(std::vector<Apartment> apartments, int roomCount)//Выборка по кол-ву квартир
{
	std::vector<Apartment> sampledApartments;//Объявления вектора выбранных объектов apartment
	for (auto i = apartments.begin(); i < apartments.end(); ++i)//Перебор вектора квартир при помощи итератора
	{
		if(i->GetRoomCount()== roomCount)//Если совпадает кол-во комнат объекта с кол-вом введёным пользователем
		{
			sampledApartments.push_back(*i);//Добавление в конец вектора подходящий объект типа apartment 
		}
	}
	return sampledApartments;

}

std::vector<Apartment> SamplingApartmentsByRoomCountAndFloorGap(std::vector<Apartment> apartments, int roomCount, std::tuple<int, int> floorRange)//Выборка по кол-ву квартир и положения на этаже в заданом промежутке
{
	
	std::vector<Apartment> sampledApartments;//Объявления вектора выбранных объектов apartment
	for (auto i = apartments.begin(); i < apartments.end(); ++i)//Перебор вектора квартир при помощи итератора
	{
		if (i->GetRoomCount() == roomCount && i->GetFloor()>= std::get<0>(floorRange) && i->GetFloor() <= std::get<1>(floorRange))//Если совпадает кол-во квартир и находится от 1 значения кортежа до второго
		{
			sampledApartments.push_back(*i);//Добавление в конец вектора подходящий объект типа apartment 
		}
	}
	return sampledApartments;
}

std::vector<Apartment> SamplingApartmentsByArea(std::vector<Apartment> apartments,double area)//Выборка по площади
{
	std::vector<Apartment> sampledApartments;//Объявления вектора выбранных объектов apartment
	for (auto i = apartments.begin(); i < apartments.end(); ++i)//Перебор вектора квартир при помощи итератора
	{
		if (i->GetArea()> area)//Если площадь превосходит заданную пользователем
		{
			sampledApartments.push_back(*i);//Добавление в конец вектора подходящий объект типа apartment 
		}
	}
	return sampledApartments;


}
