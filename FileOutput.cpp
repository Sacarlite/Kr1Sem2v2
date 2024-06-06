#include "FileOutput.h"//Подключение HeaderFile с выводом данных в фаил
#include <fstream>//Библиотека ввода и вывода из фаила
#include <iostream>//Библиотека ввода и вывода
#include "Checks.h"//Подключение HeaderFile с обработкой ошибок пользовательского ввода
#include "MainMenu.h"//Подключение HeaderFile с Enum menu
#include "PersonalInterface.h"//Подключение HeaderFile с пользовательским интерфейсом
#include <filesystem>//Подключение библеотеки для проверки состояния фаила
class FileWriteException//Пользовательский класс ошибок фаилового взаимодействия
{
public:
	FileWriteException(std::string message) : message{ message } {}//Конструктор класса 
	std::string getMessage() const { return message; }//Возврат сообщение об ошибки
private:
	std::string message;//Поле хранящее сообщение об ошибке
};

void WriteApartments(std::vector<Apartment> apartments,std::string fileName)//Функция записи данных квартир в фаил
{
	std::ofstream  out;//Создания потока записи в фаил
	out.exceptions(std::ofstream::badbit | std::ofstream::failbit);//Установка побитовых флагов ошибок фаилового взаимодействия
	try {
		out.open(fileName);//открытие фаила для записи
		//Запись данных
		out << apartments.size() << std::endl;//Запись кол-ва объектов в векторе
		for (auto i = apartments.begin(); i < apartments.end(); ++i)//Перебор вектора квартир при помощи итератора
		{
			out << i->GetAdress() << std::endl;//Запись в фаил адреса
			out << i->GetFloor() << std::endl;//Запись в фаил этажа
			out << i->GetRoomCount() << std::endl;//Запись в фаил кол-ва комнат
			out << i->GetArea() << std::endl;//Запись в фаил площади квартиры
		}
		out.close();//закрытия потока
		std::cout << "Данные успешно сохранены" << std::endl;
	}
	catch(const std::exception&)//Обработка ошибки
	{
		throw FileWriteException("Невозможно записать данные в файл.Повторите попытку.");//Выброс пользовательской ошибки фаилового вывода
	}
}
void FileOutput(std::vector<Apartment> apartments)
{
	std::ifstream out2;//Создания потока чтения из фаила
	std::string fileName;//Переменная имени или пути фаила
	out2.exceptions(std::ifstream::badbit | std::ifstream::failbit);//Установка побитовых флагов ошибок фаилового взаимодействия
	int userChoice = 0;//Переменная пользовательского ввода
	while (true) {
		std::cout << "Введите имя фаила (в разрешении .txt): ";
		std::cin >> fileName;//Ввод пути к фаилу
		try {
			if(fileName.find(".txt") == std::string::npos)//Поиск в имени фаила части .txt если указатель не указывает на элемент строки происходит повторный запрос
			{
				std::cout << "Не верное разрешение у файла. Повторитие попытку. "<<std::endl;
				continue;
			}
			try
			{
				if (std::filesystem::is_regular_file(fileName))//Проверка на системные фаилы
				{
					std::cout << "Файл с таким именем уже существует" << std::endl;
				}
			}
			catch (const std::exception&)
			{
				throw FileWriteException("Невозможно записать данные в файл. Повторите попытку.");//Выброс пользовательской ошибки фаилового вывода

			}
			out2.open(fileName);//Попытка открытия фаила
			ShowOutputChoise();//Функция вывода на консоль выбора файла
			userChoice = GetChoise();//Ввод пользовательского выбора
			if (userChoice == Yes) {
				
				out2.close();//Закрытия потока чтения из фаила
				WriteApartments(apartments, fileName);//Функция записи в фаил
			}
			else {
				out2.close();//Закрытия потока чтения из фаила
				continue;
			}
			break;
		}
		catch (const std::exception&) {
			try {
				WriteApartments(apartments, fileName);//Функция записи в фаил
				break;
			}
			catch ( FileWriteException err) {//Обработка ошибки взаимодействия с фаилом
				std::cout << err.getMessage() << std::endl;//Вывод сообщения об ошибки
			}
		}
		catch (FileWriteException err) {//Обработка ошибки взаимодействия с фаилом
			std::cout << err.getMessage() << std::endl;//Вывод сообщения об ошибки
		}

	}
}
