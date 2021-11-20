#include "stdafx.h"
#include "PolishNotation.h"

int Preorities(char operation) {
	if (operation == LEX_LEFTTHESIS || operation == LEX_RIGHTTHESIS) {
		return 1;
	}
	if (operation == LEX_MINUS || operation == LEX_PLUS) {
		return 2;
	}
	if (operation == LEX_STAR || operation == LEX_DIRSLASH) {
		return 3;
	}
}

void PN::ConvertToPolishNotation(LT::LexTable lexTable, IT::IdTable idtable,int startIndex, LT::Entry *expression)
{
	std::stack<LT::Entry> stack;

	int expressionSize = 0;
	int startPosition = startIndex;
	short leftThesis = 0;

	for (; lexTable.table[startIndex].lexema != LEX_SEMICOLON; startIndex++) {
		LT::Entry lex = lexTable.table[startIndex];
		if ((lex.lexema == LEX_ID || lex.lexema == LEX_INTEGER_LIT) && IT::IDTYPE::F != idtable.table[lex.idxTI].idtype) {
			expression[expressionSize++] = lex;
		}
		else if (lex.lexema == LEX_RIGHTTHESIS) {
			while (stack.size()) {
				if (stack.top().lexema == LEX_LEFTTHESIS) break;
				expression[expressionSize++] = stack.top();
				stack.pop();
			}
			stack.pop(); leftThesis--;
		}
		else if (lex.lexema == LEX_LEFTTHESIS) {
			stack.push(lex);
			++leftThesis;
		}
		else if (idtable.table[lex.idxTI].idtype == IT::IDTYPE::F || lex.lexema == LEX_STRLEN /*|| lex.lexema == LEX_SUBSTR*/) {
			while (lex.lexema != LEX_RIGHTTHESIS) {
				expression[expressionSize++] = lex;
				lex = lexTable.table[++startIndex];
			}
			expression[expressionSize++] = lex;
		}
		else if (stack.empty() || stack.top().lexema == LEX_LEFTTHESIS) {
			stack.push(lex);
		}
		else
		{

			while (stack.size())
			{
				if (Preorities(lexTable.table[startIndex].lexema) > Preorities(stack.top().lexema)) break;
				expression[expressionSize++] = stack.top();
				stack.pop();
			}
			stack.push(lexTable.table[startIndex]);
		}
	}
	while (stack.size() != 0)
	{
		expression[expressionSize++] = stack.top();
		stack.pop();
	}
	for (int i = 0, j = startPosition; i < expressionSize; ++i, ++j) {
		lexTable.table[j] = expression[i];
	}
	for (int i = 0; i < startIndex - (startPosition + expressionSize); ++i) {
		for (int j = startPosition + expressionSize; j < lexTable.size; ++j) {
			lexTable.table[j] = lexTable.table[j + 1];
		}
	}
}


void PN::PolishNotation(LT::LexTable lexTable, IT::IdTable idTable) 
{
	for (auto i = 0; i < lexTable.size; ++i) {
		if (lexTable.table[i].lexema == LEX_EQUAL || lexTable.table[i].lexema == LEX_RETURN) {
			LT::Entry expression[100];
			PN::ConvertToPolishNotation(lexTable, idTable, i+1, expression);
		}
	}
}