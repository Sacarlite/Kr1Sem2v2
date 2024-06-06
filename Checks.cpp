#include "Checks.h"//Подключение HeaderFile Checks
#include "CheckExeption.h"//Подключение HeaderFile с классом ошибки пользовательского ввода
#include <iostream>//Подключение библиотеки ввода и вывода
#include <tuple>//Подключение библиотеки tuple(кортежи)

double GetPositiveDoubleMoreThen0()//Функция ввода с консоли значения с плавающей точкой
{
    while (true) {
        std::string str;//Объявление переменной строки
        std::cin >> str;//Ввод строки с консоли
        try {
            double value = std::stod(str);//Перевод строки в значение с плавающей точкой
            if (value > 0) {
                std::cin.clear();//Возврат поток ввода в рабочее состояние 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
                return value;

            }
            else {
                throw std::exception();//Выбрасывание ошибки
            }
        }
        catch (std::exception&) {//Обработка произошедшей ошибки
            std::cin.clear();//Возврат поток ввода в рабочее состояние 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
            std::cout << "Были введены не корректные данные. Повторите ввод." << std::endl;//Вывод сообщения об ошибке
        }
    }
}


int GetPositiveIntMoreThen0()//Функция ввода с консоли целого положительного значения
{
    while (true) {
        std::string str;//Объявление переменной строки
        std::cin >> str;//Ввод строки с консоли
        try {
            int value = std::stoi(str);//Перевод строки в целочисленное значение
            if (value > 0) {
                std::cin.clear();//Возврат поток ввода в рабочее состояние 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
                return value;

            }
            else {
                throw std::exception();//Выбрасывание ошибки
            }
        }
        catch (std::exception&) {//Обработка произошедшей ошибки
            std::cin.clear();//Возврат поток ввода в рабочее состояние 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
            std::cout << "Были введены не корректные данные. Повторите ввод." << std::endl;//Вывод сообщения об ошибке
        }
        
    }
}

int SetMenuPoint()//Функция ввода с консоли значения меню
{
    while (true) {
        std::string str;//Объявление переменной строки
        std::cin >> str;//Ввод строки с консоли
        try {
            int value = std::stoi(str);//Перевод строки в целочисленное значение
            if (value == 1 || value == 2|| value==3) //Проверка на удовлетворяемость существующим пунктам
            {
                std::cin.clear();//Возврат поток ввода в рабочее состояние 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
                return value;

            }
            else {
                throw std::exception();//Выбрасывание ошибки
            }
        }
        catch (std::exception&) {
            std::cin.clear();//Возврат поток ввода в рабочее состояние 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
            std::cout << "Были введены не корректные данные. Повторите ввод." << std::endl;//Вывод сообщения об ошибке
        }
    }

}

std::tuple<int, int> GetFloorRange()//Функция ввода с консоли диапазона рассматриваемых этажей
{
   while (true) {
        std::cout << "Введите в каком промежутке вы хотите расмотреть квартиры" << std::endl;
        std::cout << "С какого этажа:" << std::endl;
        int first = GetPositiveIntMoreThen0();//Ввод целочисленного значения больше 0
        std::cout << "До какого этажа:" << std::endl;
        int second= GetPositiveIntMoreThen0();//Ввод целочисленного значения больше 0
        if(first<second)
        {
            return std::make_tuple(first, second);//Возврат кортежа из двух значений на первом месте начало диапазона на втором конец
        }
        std::cout << "Ошибка при вводе промежутка" << std::endl;//Вывод сообщения об ошибке
    }

}
bool isalpharus(char c)//Функция проверки на русские буквы
{
    return (c >= -64 && c <= -1) || c == -88 || c == -72;
}
//Коментарии см. функцию ввода адреса
std::string CheckLineS(std::ifstream& file)
{
    std::string temp_s = "";
    try
    {
        std::getline(file, temp_s);
        if (!temp_s.empty())
        {
            if (!isalpharus(temp_s[0]))
            {
                throw std::exception();
            }
        }
        else
        {
            throw std::exception();
        }
        for (int i = 1; i < temp_s.size(); i++)//Цикл по i от 2го символа до конца строки
        {
            if (!isalpharus(temp_s[i]) && !isdigit(temp_s[i]) && temp_s[i] != '.' && temp_s[i] != ',' && temp_s[i] != '-' && temp_s[i] != ' ' && temp_s[i] != '/')
            {
                throw std::exception();
            }
            if (temp_s[i] == '.' && temp_s[i - 1] == '.')
            {
                throw std::exception();
            }
            if (temp_s[i] == '/' && temp_s[i - 1] == '/')
            {
                throw std::exception();
            }
            if (temp_s[i] == ',' && temp_s[i - 1] == ',')
            {
                throw std::exception();
            }
            if (temp_s[i] == '-' && temp_s[i - 1] == '-')
            {
                throw std::exception();
            }
        }
        return temp_s;
       

    }
    catch (const std::exception&)
    {
        throw CheckException("Произошла ошибка при чтении информации из фаила");
    }
}

/*
 * В переменную адрес может быть записано предложение состоящее из русских букв, цифр, точек, запятых и тире,причём не может идти подряд две точки и две запятых
 * Пример:Троицкий пр., 1, Санкт-Петербург этаж 1 кв 1.
 */
std::string GetAdress()
{
    std::string temp_s = "";//Объявление переменной строки
    while (true)
    {
        try
        {
            std::cout << "Введите адрес:" << std::endl;
            getline(std::cin, temp_s);//Запись строки введёной на консоль в переменную temp_s
            if (!temp_s.empty())//Если строка пуста
            {
                if (!isalpharus(temp_s[0]))//Если первый символ не буква
                {
                    throw std::exception();//Выброс ошибки
                }
            }
            else
            {
                throw std::exception();//Выброс ошибки
            }
            for (int i = 1; i < temp_s.size(); i++)//Цикл по i от 2го символа до конца строки
            {
                if (!isalpharus(temp_s[i]) && !isdigit(temp_s[i]) && temp_s[i] != '.' && temp_s[i] != ',' && temp_s[i] != '-' && temp_s[i] != ' '&& temp_s[i] != '/')//Если символ не русская буква, цифр,точек, запятых, пробелов и тире
                {
                    throw std::exception();//Выброс ошибки
                }
            	if(temp_s[i]=='.'&& temp_s[i-1]=='.')//Если две точки идут подряд
                {
                    throw std::exception();//Выброс ошибки
                }
                if (temp_s[i] == '/' && temp_s[i - 1] == '/')//Если две дроби идут подряд
                {
                    throw std::exception();
                }
                if (temp_s[i] == ',' && temp_s[i - 1] == ',')//Если две запятых идут подряд
                {
                    throw std::exception();//Выброс ошибки
                }
                if (temp_s[i] == '-' && temp_s[i - 1] == '-')//Если два тире идут подряд
                {
                    throw std::exception();//Выброс ошибки
                }
            }
            return temp_s;

        }
        catch (const std::exception&)//Обработка ошибки
        {
            std::cout << "Произошла ошибка при обработке адреса повторите попытку" << std::endl;//Вывод сообщения об ошибке
        }
    }
}
int CheckLineI(std::ifstream& file)
{
    std::string temp_v = "";//Объявление переменной строки
    try
    {
        std::getline(file, temp_v);//Запись строки введёной на консоль в переменную temp_s
        int temp_i = stoi(temp_v);//Преобразование строки в целочисленный тип
        if (temp_i <= 0)

        {
            throw  std::exception();//Выброс ошибки
        }
        else

            return temp_i;
    }
    catch (const std::exception&)//Обработка ошибки
    {
        throw CheckException("Произошла ошибка при чтении информации из фаила");//Выброс ошибки пользовательского типа
    }
    
}
double CheckLineD(std::ifstream& file)
{
    std::string temp_v = "";//Объявление переменной строки
    try
    {
        std::getline(file, temp_v);//Запись строки введёной на консоль в переменную temp_s

        double temp_d = stod(temp_v);//Преобразование строки в значение с плавающей точкой
        if (temp_d < 0)
        {
            throw std::exception();//Выброс ошибки
        }
        else

            return temp_d;
    }
        catch (const std::exception&)//Обработка ошибки
        {
            throw CheckException("Произошла ошибка при чтении информации из фаила");//Выброс ошибки пользовательского типа
        }

    
}
int GetChoise()
{

    while (true) {
        std::string str;//Объявление переменной строки
        std::cin >> str;//Ввод строки с консоли
        try {
            int value = std::stoi(str);//Преобразование строки в целочисленный тип данных
            if (value == 1 || value == 2) {
                std::cin.clear();//Возврат поток ввода в рабочее состояние 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
                return value;

            }
            else {
                throw std::exception();//Выброс ошибки
            }
        }
        catch (std::exception&) {//Обработка ошибки
            std::cin.clear();//Возврат поток ввода в рабочее состояние 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
            std::cout << "Были введены не корректные данные. Повторите ввод." << std::endl;
        }
    }
}

