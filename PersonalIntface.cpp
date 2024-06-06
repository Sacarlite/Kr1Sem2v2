#include <iostream>//Подключение библиотеки ввода и вывода
#include "PersonalInterface.h"

void ShowMenu()
{
	std::cout << "Перед вами меню запросов" << std::endl;
	std::cout << "1)Выборка квартир,имеющих заданное число комнат" << std::endl;
	std::cout << "2)Выборка квартир,имеющих заданное число комнат и расположенных на этаже, который находится в определенном промежутке" << std::endl;
	std::cout << "3)Выборка квартир,имеющих площадь, превосходящую заданную" << std::endl;
	std::cout << "Ввод:" << std::endl;
}
void ShowTask() {
	std::cout << "Квартира: адрес, этаж, количество комнат, площадь. Создать массив" << std::endl;
	std::cout << "объектов. Реализовать возможность получения:" << std::endl;
	std::cout << "– списка квартир, имеющих заданное число комнат, " << std::endl;
	std::cout << "– списка квартир, имеющих заданное число комнат и расположенных на этаже, который находится в определенном промежутке," << std::endl;
	std::cout << "– списка работников, списка квартир, имеющих площадь, превосходящую заданную." << std::endl;
}

void ShowOutputDataOption()
{
	std::cout << "Вы хотите сохранить исходные данные в файл?" << std::endl;
	std::cout << "1)Да" << std::endl;
	std::cout << "2)Нет" << std::endl;
}
void ShowInputOption()
{
	std::cout << "Какой вид ввода данных вы хотите использовать?" << std::endl;
	std::cout << "1)Фаиловый" << std::endl;
	std::cout << "2)Консольный" << std::endl;
}

void ShowGreetings()
{
	std::cout << "Контрольная работа №1 Кутькина Олеся 4304г" << std::endl;
}

void ShowOutputType()
{
	std::cout << "Вы хотите записать данные в файл?" << std::endl;
	std::cout << "1)Да" << std::endl;
	std::cout << "2)Нет" << std::endl;
}


void ShowOutputChoise()
{
	std::cout << "Вы хотите перезаписать данный фаил?" << std::endl;
	std::cout << "1)Да" << std::endl;
	std::cout << "2)Ввести новое имя(путь к фаилу)" << std::endl;
}
