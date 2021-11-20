#pragma once
#include "stdafx.h"
#include "LT.h"
#include "IT.h"

/*

найти выражение для конвертирования
определить границы конвертирования
конвертация 
внесения выражения в таблице лескем
удаления пустых лексем

*/

namespace PN {
	void PolishNotation(LT::LexTable lexTable, IT::IdTable idTable);
	void ConvertToPolishNotation(LT::LexTable lexTable, IT::IdTable idTable, int startIndex, LT::Entry *expression);
}