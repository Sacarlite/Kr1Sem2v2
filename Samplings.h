#pragma once
#include <vector>//Библиотека подключения вектора
#include "Apartment.h"//Подключение HeaderFile с классом Apartment
std::vector<Apartment> SamplingApartmentsByRoomCount(std::vector<Apartment> apartments,int roomCount);//Выборка по кол-ву квартир
std::vector<Apartment> SamplingApartmentsByRoomCountAndFloorGap(std::vector<Apartment> apartments, int roomCount, std::tuple<int, int> floorRange);//Выборка по кол-ву комнат и положения на этаже в заданом промежутке
std::vector<Apartment> SamplingApartmentsByArea(std::vector<Apartment> apartments, double area);//Выборка по площади

//TODO Добавить оператор перегрузки