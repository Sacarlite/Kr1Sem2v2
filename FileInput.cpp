#include "FileInput.h"//Подключение HeaderFile с вводом данных из фаила
#include <fstream>//Библиотека ввода и вывода из фаила
#include <iostream>//Библиотека ввода и вывода
#include "CheckExeption.h"//Подключение HeaderFile с пользовательским классом ошибок ввода
#include "Checks.h"//Подключение HeaderFile с обработкой ошибок пользовательского ввода
#include <filesystem>//Подключение библеотеки для проверки состояния фаила

std::vector<Apartment> FileDataInput()//Функция ввода списка квартир из фаила
{
	std::vector<Apartment> apartments;//Объявления вектора объектов apartment
	std::string fileName;//Объявление переменной имени фаила
	std::ifstream file;//Создание потока для чтения из фаила
	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);//Установка побитовых флагов ошибок фаилового взаимодействия
	while (true)
	{
		std::cout << "Введите имя фаила (в разрешении .txt): " << std::endl;
		std::cin >> fileName;//Ввод пути к фаилу
		try
		{
			if (fileName.find(".txt") == std::string::npos)//Поиск в имени фаила части .txt если указатель не указывает на элемент строки происходит повторный запрос
			{
				std::cout << "Не верное разрешение у файла. Повторитие попытку. " << std::endl;
				continue;
			}
			
			if (std::filesystem::is_regular_file(fileName))//Проверка на системные фаилы
			{
				std::cout << "Фаил открыт успешно. " << std::endl;

			}
			file.open(fileName);
			
		}
		catch (const std::exception&)//Обработка ошибки при чтении из фаила
		{
			std::cout << " Произошла ошибка при открытии фаила.Повторите попытку:" << std::endl;
			continue;

		}
		std::string adress;//Переменная адреса
		int floor;//Переменная этажа
		int roomCount;//Переменная кол-ва комнат
		double roomArea;//Переменная площади
		try {
			int objectCount = CheckLineI(file);//Считывание количества объектов
			for (int i = 0; i < objectCount; i++) {
				adress = CheckLineS(file);//Ввод адреса
				floor = CheckLineI(file);//Ввод этажа
				roomCount = CheckLineI(file);//Ввод кол-ва комнат
				roomArea = CheckLineD(file);//Ввод площади
				Apartment apartment(adress, floor, roomCount, roomArea);//Создание объекта типа apartment
				apartments.push_back(apartment);//Добавление объекта в конец вектора
			}

		}
		catch (const std::exception) {//Обработка ошибки
			std::cout << " Произошла ошибка при чтении информации. Повторите попытку:" << std::endl;
			apartments.clear();//Отчиста вектора квартир
			file.close();
			continue;
		}
		catch (const CheckException err) {//Обработка ошибки пользовательского ввода
			std::cout << err.GetMessage() << std::endl;//Вывод сообщения об ошибки
			apartments.clear();//Отчиста вектора квартир
			file.close();//Закрытия потока
			continue;
		}
		file.close();//закрытие потока
		return  apartments;
	}
}
