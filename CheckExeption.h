#pragma once
#include <string>//Подключение библиотеки строк

class CheckException//Класс ошибок пользовательского ввода
{
public:
	CheckException(std::string message) : message{ message } {}//Конструктор класса 
	std::string GetMessage() const { return message; }//Возврат сообщение об ошибки
private:
	std::string message;//Поле хранящее сообщение об ошибке
};
