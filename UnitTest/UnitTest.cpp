#include "pch.h"
#include "CppUnitTest.h"
#include "..\Apartment.cpp"
#include "..\Samplings.cpp"
#include <vector>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	private:
		//Создание тестируемых объектов Класса Apartment
		Apartment app1{ /*Адрес:*/"test1",/*Этаж:*/ 2,/*Кол-во комнат:*/ 2,/*Площадь*/ 10};
		Apartment app2{ /*Адрес:*/"test2",/*Этаж:*/ 2,/*Кол-во комнат:*/ 3,/*Площадь*/ 11 };
		Apartment app3{ /*Адрес:*/"test3",/*Этаж:*/ 3,/*Кол-во комнат:*/ 4,/*Площадь*/ 12 };
		Apartment app4{ /*Адрес:*/"test4",/*Этаж:*/ 3,/*Кол-во комнат:*/ 5,/*Площадь*/ 13 };
		Apartment app5{ /*Адрес:*/"test5",/*Этаж:*/ 3,/*Кол-во комнат:*/ 6,/*Площадь*/ 14 };
	public:
		//Проверка выборки по кол-ву комнат
		TEST_METHOD(TestMethod1)
		{
			//Создание списка тестируемых квартир
			std::vector<Apartment> apartments;
			//Добваление квартир в конец вектора
			apartments.push_back(app1);
			apartments.push_back(app2);
			apartments.push_back(app3);
			apartments.push_back(app4);
			apartments.push_back(app5);
			//Выборка квартир с 2мя комнатами, т.е подходит объект app1
			std::vector<Apartment> sortedApartments = SamplingApartmentsByRoomCount(apartments,/*Ввод критерия отбора т.е кол-во квартир*/ 2);
			Assert::IsTrue(sortedApartments.size() == 1);//Проверка на то что в векторе 1 подходящая квартира
			Assert::IsTrue(sortedApartments.at(0) == app1);//Проверка что этот объект app1 т.е квартира по адресу: test1
			//Выборка квартир с 3мя комнатами, т.е подходит объект app2
			 sortedApartments = SamplingApartmentsByRoomCount(apartments,/*Ввод критерия отбора т.е кол-во квартир*/ 3);
			 Assert::IsTrue(sortedApartments.size() == 1);//Проверка на то что в векторе 1 подходящая квартира
			Assert::IsTrue(sortedApartments.at(0) == app2);//Проверка что этот объект app2 т.е квартира по адресу: test2
			//Выборка квартир с 4мя комнатами, т.е подходит объект app3
			 sortedApartments = SamplingApartmentsByRoomCount(apartments,/*Ввод критерия отбора т.е кол-во квартир*/ 4);
			 Assert::IsTrue(sortedApartments.size() == 1);//Проверка на то что в векторе 1 подходящая квартира
			Assert::IsTrue(sortedApartments.at(0) == app3);//Проверка что этот объект app3 т.е квартира по адресу: test3
			//Выборка квартир с 5ю комнатами, т.е подходит объект app4
			sortedApartments = SamplingApartmentsByRoomCount(apartments,/*Ввод критерия отбора т.е кол-во квартир*/ 5);
			Assert::IsTrue(sortedApartments.size() == 1);//Проверка на то что в векторе 1 подходящая квартира
			Assert::IsTrue(sortedApartments.at(0) == app4);//Проверка что этот объект app4 т.е квартира по адресу: test4
			//Выборка квартир с 6ю комнатами, т.е подходит объект app5
			sortedApartments = SamplingApartmentsByRoomCount(apartments,/*Ввод критерия отбора т.е кол-во квартир*/ 8);
			Assert::IsTrue(sortedApartments.empty());//Проверка на то что в векторе нет подходящих объектов
		}
		//Проверка выборки по кол-ву комнат и наождению в определённом этаже
		TEST_METHOD(TestMethod2)
		{
			//Создание списка тестируемых квартир
			std::vector<Apartment> apartments;
			//Добваление квартир в конец вектора
			apartments.push_back(app1);
			apartments.push_back(app2);
			apartments.push_back(app3);
			apartments.push_back(app4);
			apartments.push_back(app5);
			//Выборка квартир с 3мя комнатами находящихся в промежутке этажей со 2 до 3, т.е подходит объект app2
			std::vector<Apartment> sortedApartments = SamplingApartmentsByRoomCountAndFloorGap(apartments,/*кол-во комнат*/3,/*диапазон этажей*/std::tuple<int, int>(2, 3));
			Assert::IsTrue(sortedApartments.size() == 1);//Проверка на то что в векторе 1 подходящая квартира
			Assert::IsTrue(sortedApartments.at(0) == app2);//Проверка что этот объект app2 т.е квартира по адресу: test2
		}
		//Проверка выборки по кол-ву комнат и наождению в определённом этаже
		TEST_METHOD(TestMethod3)
		{
			//Создание списка тестируемых квартир
			std::vector<Apartment> apartments;
			//Добваление квартир в конец вектора
			apartments.push_back(app1);
			apartments.push_back(app2);
			apartments.push_back(app3);
			apartments.push_back(app4);
			apartments.push_back(app5);
			//Выборка квартир с 4мя комнатами находящихся в промежутке этажей с 4 до 3, т.е никакие квариры не подходят
			std::vector<Apartment> sortedApartments = SamplingApartmentsByRoomCountAndFloorGap(apartments, /*кол-во комнат*/4, /*диапазон этажей*/std::tuple<int, int>(4, 5));
			Assert::IsTrue(sortedApartments.empty());//Проверка на то что в векторе нет объектов
		}
		//Проверка выборки по площади
		TEST_METHOD(TestMethod4)
		{
			//Создание списка тестируемых квартир
			std::vector<Apartment> apartments;
			//Добваление квартир в конец вектора
			apartments.push_back(app1);
			apartments.push_back(app2);
			apartments.push_back(app3);
			apartments.push_back(app4);
			apartments.push_back(app5);
			//Выборка квартир с площадью больше 12, т.е подходит объект app4,app5
			std::vector<Apartment> sortedApartments = SamplingApartmentsByArea(apartments, /*площадь*/12);
			Assert::IsTrue(sortedApartments.size() == 2);//Проверка на то что в векторе 2 подходящих квартиры
			Assert::IsTrue(sortedApartments.at(0) == app4);//Проверка что этот объект app4 т.е квартира по адресу: test4
			Assert::IsTrue(sortedApartments.at(1) == app5);//Проверка что этот объект app5 т.е квартира по адресу: test5
		}
		TEST_METHOD(TestMethod5)
		{
			//Создание списка тестируемых квартир
			std::vector<Apartment> apartments;
			//Добваление квартир в конец вектора
			apartments.push_back(app1);
			apartments.push_back(app2);
			apartments.push_back(app3);
			apartments.push_back(app4);
			apartments.push_back(app5);
			//Выборка квартир с площадью больше 20, т.е т.е никакие квариры не подходят
			std::vector<Apartment> sortedApartments = SamplingApartmentsByArea(apartments,/*площадь*/ 20);
			Assert::IsTrue(sortedApartments.empty());//Проверка на то что в векторе нет объектов
		}
	};
}
