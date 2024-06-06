#pragma once
enum menu
{
	SamplingByRoomCount = 1,//Выборка по кол-ву квартир
	SamplingByRoomCountAndFloorGap = 2,//Выборка по кол-ву комнат и положения на этаже в заданом промежутке
	SamplingByApartmentArea = 3,//Выборка по площади квартир
	FileInput = 1,//Фаиловый ввод
	ConsoleInput = 2,//Консольный ввод
	Yes = 1//Пункт да
};