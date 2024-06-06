#include <iostream>//Библиотека ввода и вывода
#include <windows.h>//Библиотека ответственная за русскую локализацию консоли
#include <conio.h>//Библиотека ответственная за функцию getch
#include <vector>//Библиотека подключения вектора
#include "Apartment.h"//Подключение HeaderFile с классом Apartment
#include "MainMenu.h"//Подключение HeaderFile с Enum-меню
#include "Checks.h"//Подключение HeaderFile с проверками пользовательского ввода
#include "ConsoleOutput.h"//Подключение HeaderFile с выводом списка апартаментов на консоль
#include "FileInput.h"//Подключение HeaderFile с файловым вводом
#include "FileOutput.h"//Подключение HeaderFile с файловым выводом
#include "Input.h"//Подключение HeaderFile с вводом с консоли
#include "PersonalInterface.h"//Подключение HeaderFile пользовательского интерфейса
#include "Samplings.h"//Подключение HeaderFile с функциями отбора
#define QUIT 27//Макрос присваивания Esc значение 27
int main()
{
	setlocale(LC_CTYPE, "RU");//Локализация
	SetConsoleCP(1251);//функции для настройки локализации в строковых переменных при вводе
	SetConsoleOutputCP(1251);//функции для настройки локализации в строковых переменных при выводе
	int userChoice = 0;//Переменная пользовательского ввода
	std::vector<Apartment> apartments;//Вектор вводных апартаментов
	std::vector<Apartment> sortedApartments;//Вектор выбранных апартаментов
	ShowGreetings();//Вывод приветствия
	ShowTask();//Вывод задания
	do
	{
		ShowInputOption();//Вывод типа вввода
		userChoice = GetChoise();//Ввод пользовательского решения
		switch (userChoice)//switch выбора консольного ввода или файлового
		{
		case  (ConsoleInput):
			apartments = ConsoleIput();//Ввод данных об апартаментов с консоли 
			break;
		case (FileInput):
			apartments = FileDataInput();//Ввод данных об апартаментов из файла
			ConsoleOutput(apartments);//Вывод считанных данных на консоль
			break;
		}
		if (userChoice != FileInput) {
			ShowOutputType();//Вывод предложения сохранения в файл
			userChoice = GetChoise();//Ввод пользовательского решения
			if (userChoice == Yes) 
			{
				FileOutput(apartments);//Сохранение введёных апартаментов в файл
			}
		}
		int roomCount = 0;
		std::tuple<int, int> floorRange;
		double area = 0.0;
			do {
				ShowMenu();//Меню алгоритмов
				userChoice = SetMenuPoint();//Выбор пункта меню
				switch (userChoice) {//switch выбора метода выборки
				case SamplingByRoomCount://Выборка по количеству комнат
					std::cout << "Введите количество комнат:" << std::endl;
					roomCount = GetPositiveIntMoreThen0();//Ввод количества квартир
					sortedApartments = SamplingApartmentsByRoomCount(apartments, roomCount);//Заполнение вектора выбранными квартирами
					break;
				case SamplingByRoomCountAndFloorGap://Выборка по кол-ву комнат и положения на этаже в заданом промежутке
					std::cout << "Введите количество комнат:" << std::endl;
					roomCount = GetPositiveIntMoreThen0();//Ввод количества квартир
					floorRange = GetFloorRange();//Ввод рассматриваемого диапазона
					sortedApartments = SamplingApartmentsByRoomCountAndFloorGap(apartments, roomCount, floorRange);//Заполнение вектора выбранными квартирами
					break;
					
				case SamplingByApartmentArea://Выборка по площади квартир
					std::cout << "Введите площадь:" << std::endl;
					area = GetPositiveDoubleMoreThen0();//Ввод площади квартир
					sortedApartments = SamplingApartmentsByArea(apartments,area);//Заполнение вектора выбранными квартирами
					break;
				}
				//В случае если массив пуст
				if (sortedApartments.empty()) {
					std::cout << "Нет элементов удовлетворяющих поиску" << std::endl;
					continue;
				}
				else {
					ConsoleOutput(sortedApartments);//Вывод итогового массива на консоль
					ShowOutputType();//Вывод сообщения об сохранении выбранных данных в файл
					userChoice = GetChoise(); // Ввод пользовательского решения
					if (userChoice == Yes) {
						FileOutput(sortedApartments);//Сохранение итогового массива в фаил
					}
				}
				sortedApartments.clear();//Чистка вектора выбранных квартир
				std::cout << "Нажмите Esc чтобы завершить работу с подменю." << std::endl;
				std::cout << "Нажмите Enter чтобы продолжить." << std::endl;
				std::cout << " " << std::endl;
				userChoice = _getch();//Ввод кода символа введённого с клавиатуры
			} while (userChoice != QUIT);//Проверка что код символа равен коду макроса Quit
		
		apartments.clear();//Чистка вектора квартир
		std::cout << "Нажмите Esc чтобы завершить работу программы." << std::endl;
		std::cout << "Нажмите Enter чтобы продолжить." << std::endl;
		userChoice = _getch();//Ввод кода символа введённого с клавиатуры
	}
	while (userChoice!= QUIT);//Проверка что код символа равен коду макроса Quit
}
