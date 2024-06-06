#include "Apartment.h"//Подключение HeaderFile с классом Apartment
#include <iostream>//Подключение библиотеки ввода и вывода
/*Все коментарии прописаны в Apartment.h*/
Apartment::Apartment(std::string adress, int floor, int roomCount, double area)//Конструктор класса apartment
	:_adress(adress),_floor(floor),_roomCount(roomCount),_area(area)
{
}

void Apartment::SetAdress(std::string adress)//Установка поля адресс пользовательскими данными
{
	_adress = adress;
}
std::string Apartment::GetAdress()//Получение поля адресс
{
	return _adress;
}
void Apartment::ShowAdress()//Вывод на консоль поля аддрес
{
	std::cout << _adress << std::endl;
}

void Apartment::SetFloor(int floor)
{
	_floor = floor;
}
int Apartment::GetFloor()
{
	return _floor;
}
void Apartment::ShowFloor()
{
	std::cout << _floor << std::endl;
}

void Apartment::SetRoomCount(int roomCount)
{
	_roomCount = roomCount;
}
int Apartment::GetRoomCount()
{
	return _roomCount;
}
void Apartment::ShowRoomCount()
{
	std::cout << _roomCount << std::endl;
}

void Apartment::SetArea(double area)
{
	_area = area;
}
double Apartment::GetArea()
{
	return _area;
}
void Apartment::ShowArea()
{
	std::cout << _area << std::endl;
}
// перегузка операторов
bool operator == (Apartment& app1, Apartment& app2)
{
	return app1.GetAdress() == app2.GetAdress() && app1.GetArea() == app2.GetArea()
		&& app1.GetFloor() == app2.GetFloor() && app1.GetRoomCount() == app2.GetRoomCount();
}