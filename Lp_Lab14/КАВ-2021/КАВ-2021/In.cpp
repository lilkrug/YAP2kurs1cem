#include "stdafx.h"
#include "In.h"
#include "Error.h"

In::IN In::getin(std::string const infile) {
	auto result = std::make_unique<In::IN>();
	std::ifstream fin(infile);
	if (!fin) throw ERROR_THROW(110);
	unsigned char symbol;
	int numberInLine = 0;
	while (result->size < IN_MAX_LEN_TEXT) {
		symbol = fin.get();
		if (fin.eof()) {
			result->text += IN_CODE_SEP;
			++result->lines;
			break;
		}
		switch (result->code[(unsigned int)symbol]) {
		case 1024: // T
			result->text += symbol;
			++result->size;
			++numberInLine;
			break;
		case 2048: // F
			throw ERROR_THROW_IN(111, result->lines, numberInLine + 1);
		case 4096: // I
			++result->ignor;
			break;
		case 8192: // SPC
			if ((result->size - 1) < 0 || (result->code[(unsigned int)((unsigned char)result->text[result->size - 1])] != 8192 && result->code[(unsigned int)((unsigned char)result->text[result->size - 1])] != 32568)) {
				result->text += symbol;
				++numberInLine;
				++result->size;
			}
			else {
				++result->ignor;
			}
			break;
		case 16384: // S
			if ((result->size - 1 < 0) || result->code[(unsigned int)((unsigned char)result->text[result->size - 1])] != 16384) {
				result->text += IN_CODE_SEP;
				++result->size;
				++result->lines;
				numberInLine = 0;
			}
			else
			{
				++result->ignor;
			}
			break;
		case 32568: // LX
			if (((result->size - 1 < 0) && result->code[(unsigned int)((unsigned char)result->text[result->size - 1])] != 8192) || ((result->size - 1 > 0) && result->code[(unsigned int)((unsigned char)result->text[result->size - 1])] == 8192)) {
				result->text[result->size - 1] = symbol;
			}
			else {
				result->text += symbol;
				++result->size;
				++numberInLine;
			}
			break;
		default:
			result->text += result->code[(unsigned int)symbol];
			++result->size;
			++numberInLine;
			break;
		}
	}
	fin.close();
	return *result;
}