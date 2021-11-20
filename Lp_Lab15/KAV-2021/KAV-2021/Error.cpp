#include "stdafx.h"
#include "Error.h"

/*
	0-99: Системные ошибки
	100-109: Ошибки параметров
	110-119: Ошибки открытия и чтения файлов
	200-299: Ошибки лексического анализатора
	300-399: Ошибки синтаксического анализатора
	400-499: Ошибки семантического анализоатора
*/
Error::ERROR errors[ERROR_MAX_ENTRY] = {
	ERROR_ENTRY(0, "Недопустимый код ошибки"),
	ERROR_ENTRY(1, "Системный сбой"),
	ERROR_ENTRY_NODEF(2),ERROR_ENTRY_NODEF(3),ERROR_ENTRY_NODEF(4),ERROR_ENTRY_NODEF(5),
	ERROR_ENTRY_NODEF(6),ERROR_ENTRY_NODEF(7),ERROR_ENTRY_NODEF(8),ERROR_ENTRY_NODEF(9),
	ERROR_ENTRY_NODEF10(10),ERROR_ENTRY_NODEF10(20),ERROR_ENTRY_NODEF10(30),ERROR_ENTRY_NODEF10(40),
	ERROR_ENTRY_NODEF10(50),ERROR_ENTRY_NODEF10(60),ERROR_ENTRY_NODEF10(70),ERROR_ENTRY_NODEF10(80),
	ERROR_ENTRY_NODEF10(90),
	ERROR_ENTRY(100, "Параметр -in должен быть задан"),
	ERROR_ENTRY_NODEF(101),ERROR_ENTRY_NODEF(102),ERROR_ENTRY_NODEF(103),
	ERROR_ENTRY(104, "Превышена длина входного параметра"),
	ERROR_ENTRY_NODEF(105),ERROR_ENTRY_NODEF(106),ERROR_ENTRY_NODEF(107),ERROR_ENTRY_NODEF(108),
	ERROR_ENTRY_NODEF(109),
	ERROR_ENTRY(110, "Ошибка при открытии файла с исходным кодом (-in)"),
	ERROR_ENTRY(111, "Недопустимый символ в исходном файле (-in)"),
	ERROR_ENTRY(112, "Ошибка при создании файла протокола(-log)"),
	ERROR_ENTRY_NODEF(113),ERROR_ENTRY_NODEF(114),ERROR_ENTRY_NODEF(115),ERROR_ENTRY_NODEF(116),
	ERROR_ENTRY_NODEF(117),ERROR_ENTRY_NODEF(118),ERROR_ENTRY_NODEF(119),
	ERROR_ENTRY_NODEF10(120),ERROR_ENTRY_NODEF10(130),ERROR_ENTRY_NODEF10(140), ERROR_ENTRY_NODEF10(150),
	ERROR_ENTRY_NODEF10(160), ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
	ERROR_ENTRY(200, "Превышено максимальное количество строк в таблице лексем"),
	ERROR_ENTRY(201, "Превышена максимальная емкость таблицы лексем"),
	ERROR_ENTRY(202, "Выход за пределы таблицы лексем"),
	ERROR_ENTRY(203, "Множественное объявление лексемы"),
	ERROR_ENTRY(204, "Идентификатор не объявлен"),
	ERROR_ENTRY(205, "Целочисленный литерал не может быть отрицательным"),
	ERROR_ENTRY(206, "Превышено максимальное количество строк в таблице идентификаторов"),
	ERROR_ENTRY(207, "Превышена максимальная емкость таблицы идентификаторов"),
	ERROR_ENTRY(208, "Выход за пределы таблицы идентификаторов"),
	ERROR_ENTRY(209, "Неопознанная лексема"),
	ERROR_ENTRY(210, "Отсутствует точка входа"),
	ERROR_ENTRY(211, "Несколько точек входа"),
	ERROR_ENTRY(212, "Превышена максимальная длина идентификатора"),
	ERROR_ENTRY_NODEF(213),ERROR_ENTRY_NODEF(214),ERROR_ENTRY_NODEF(215),
	ERROR_ENTRY_NODEF(216),ERROR_ENTRY_NODEF(217),ERROR_ENTRY_NODEF(218),ERROR_ENTRY_NODEF(219),
	ERROR_ENTRY_NODEF10(220),ERROR_ENTRY_NODEF10(230),ERROR_ENTRY_NODEF10(240),ERROR_ENTRY_NODEF10(250),
	ERROR_ENTRY_NODEF10(260),ERROR_ENTRY_NODEF10(270),ERROR_ENTRY_NODEF10(280),ERROR_ENTRY_NODEF10(290),
	ERROR_ENTRY(300,"Неверная структура программы"),
	ERROR_ENTRY(301,"Ошибочный оператор"),
	ERROR_ENTRY(302,"Ошибка в выражении"),
	ERROR_ENTRY(303,"Ошибка в параметрах функции"),
	ERROR_ENTRY(304,"Ошибка в параметрах вызываемой функции"),
	ERROR_ENTRY(305, "Ошибка в подвыражении"),
	ERROR_ENTRY(306, "Неверный номер правила"),
	ERROR_ENTRY_NODEF(307),ERROR_ENTRY_NODEF(308),ERROR_ENTRY_NODEF(309),
	ERROR_ENTRY_NODEF10(310),ERROR_ENTRY_NODEF10(320),ERROR_ENTRY_NODEF10(330),ERROR_ENTRY_NODEF10(340),
	ERROR_ENTRY_NODEF10(350),ERROR_ENTRY_NODEF10(360),ERROR_ENTRY_NODEF10(370),ERROR_ENTRY_NODEF10(380),
	ERROR_ENTRY_NODEF10(390),
	ERROR_ENTRY(400, "Ошибка в возвращаемом значении"),
	ERROR_ENTRY(401, "Ошибка в параметрах функции"),
	ERROR_ENTRY(402, "Ошибка в параметрах функции библиотеки"),
	ERROR_ENTRY(403, "Ошибка в параметрах функции библиотеки (неверное кол-во аргументов)"),
	ERROR_ENTRY(404, "Ошибка в значении для вывода в консоль"),
	ERROR_ENTRY(405, "Несоответствие возвращаемого и присваемого типов данных"),
	ERROR_ENTRY(406, "Несоответсвие присваимаего типа данных"),
	ERROR_ENTRY(407, "Несоответствие типа функции и возвращаемого значения"),
	ERROR_ENTRY(408, "main должен возвращать числовое значение"),
	ERROR_ENTRY(409, "Использование имени переменной в качестве функции"),
	ERROR_ENTRY(410, "Ошибка в выражении цикла"),
	ERROR_ENTRY(411, "Ошибка в условии if"),
	ERROR_ENTRY(412, "Попытка присовоить отрицательное значение"),
	ERROR_ENTRY_NODEF10(420),ERROR_ENTRY_NODEF10(430),ERROR_ENTRY_NODEF10(440),ERROR_ENTRY_NODEF10(450),
	ERROR_ENTRY_NODEF10(460),ERROR_ENTRY_NODEF10(470),ERROR_ENTRY_NODEF10(480),ERROR_ENTRY_NODEF10(490),
	ERROR_ENTRY_NODEF(417),ERROR_ENTRY_NODEF(418),ERROR_ENTRY_NODEF(419),
	ERROR_ENTRY_NODEF100(500),ERROR_ENTRY_NODEF100(600),ERROR_ENTRY_NODEF100(700),ERROR_ENTRY_NODEF100(800),
	ERROR_ENTRY_NODEF100(900)

};

Error::ERROR Error::geterror(int id) 
{
	if ((0 < id) && (id < ERROR_MAX_ENTRY)) {
		return errors[id];
	}
	return errors[0];
}

Error::ERROR Error::geterrorin(int id, int line, int column) 
{
	if ((0 < id) && (id < ERROR_MAX_ENTRY)) {
		Error::ERROR* temp = &errors[id];
		temp->place = { (short)line, (short)column };
		return *temp;
	}
	return errors[0];
}

Error::ERROR Error::geterrorword(int id, int line, std::string word) {
	if ((0 < id) && (id < ERROR_MAX_ENTRY)) {
		Error::ERROR* temp = &errors[id];
		temp->word = { (short)line, word };
		return *temp;
	}
	return errors[0];
}
