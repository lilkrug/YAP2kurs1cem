#include "stdafx.h"
#include "Lex.h"
#include "LT.h"
#include "In.h"
#include "REGS.h"
#include "Log.h"

char Lex::GetToken(const char* string) {
	std::array<std::string, 23> regexps = {
		REG_DECLARE, REG_STRING, REG_INTEGER, REG_FUNCTION, REG_RETURN, REG_PRINT,
		REG_MAIN, REG_INTEGER_LIT, REG_STRING_LIT, REG_SEMICOLON, REG_COMMA,
		REG_MREQUAL, REG_LSEQUAL, REG_LEFTTHESIS, REG_RIGHTTHESIS, REG_PLUS, REG_MINUS,
		REG_STAR, REG_DIRSLASH, REG_EQUAL, REG_STRLEN, REG_SUBSTR, REG_ID
	};
	const char tokens[] = {
		LEX_DECLARE, LEX_STRING, LEX_INTEGER, LEX_FUNCTION, LEX_RETURN, LEX_PRINT,
		LEX_MAIN, LEX_INTEGER_LIT, LEX_STRING_LIT, LEX_SEMICOLON, LEX_COMMA,
		LEX_MREQUAL, LEX_LSEQUAL, LEX_LEFTTHESIS, LEX_RIGHTTHESIS, LEX_PLUS, LEX_MINUS,
		LEX_STAR, LEX_DIRSLASH, LEX_EQUAL, LEX_STRLEN, LEX_SUBSTR, LEX_ID
	};
	for (int i = 0; i < sizeof(regexps) / sizeof(regexps[0]); ++i) {
		if (std::regex_match(string, std::regex(regexps[i]))) {
			return tokens[i];
		}
	}
	return EOF;
}


void Lex::Scan(LT::LexTable& lextable, IT::IdTable& idtable, In::IN& in, Parm::PARM& parm, Log::LOG& log) {
	std::ofstream outfile(parm.out);
	outfile << in.text << std::endl;
	outfile << "001 ";

	std::string word = "";

	int counter = 0;
	bool findStringLit = false;

	for (int i = 0, line = 1; i < in.text.size(); ++i)
	{
		IT::IDDATATYPE iddatatype;
		auto fillTable = [&] {
			char token = Lex::GetToken(word.c_str());
			if (token == EOF) {
				throw ERROR_THROW(209);
			}
			int ti_idx = TI_NULLIDX;
			
			if (token == LEX_INTEGER || token == LEX_INTEGER_LIT) {
				iddatatype = IT::IDDATATYPE::INT;
			}
			else if (token == LEX_STRING || token == LEX_STRING_LIT)
			{
				iddatatype = IT::IDDATATYPE::STR;
			}
			if (token == LEX_ID) {
				if (word.length() > 5) {
					throw ERROR_THROW_WORD(212, line, word);
				}
				ti_idx = IT::IsId(idtable, word);
				if (ti_idx == TI_NULLIDX)
				{
					if (lextable.size >= 2 && lextable.table[lextable.size - 2].lexema == LEX_DECLARE && (lextable.table[lextable.size - 1].lexema == LEX_INTEGER || lextable.table[lextable.size - 1].lexema == LEX_INTEGER)) {
						IT::Add(idtable, { lextable.size, word.c_str(), iddatatype, IT::IDTYPE::V });
					}
					else if (lextable.size >= 1 && lextable.table[lextable.size - 1].lexema == LEX_FUNCTION) {
						IT::Add(idtable, { lextable.size, word.c_str(), iddatatype, IT::IDTYPE::F });
					}
					else if (lextable.size >= 1 && lextable.table[lextable.size - 1].lexema == LEX_INTEGER || lextable.size >= 1 && lextable.table[lextable.size - 1].lexema == LEX_STRING) {
						IT::Add(idtable, { lextable.size, word.c_str(), iddatatype, IT::IDTYPE::P });
					}
				}
			}
			else if (token == LEX_STRING_LIT) {
				word = word.substr(1, word.length() - 2);
				ti_idx = IT::isLit(idtable, word);
				if (ti_idx == TI_NULLIDX) {
					IT::Add(idtable, { lextable.size, "L" + std::to_string(counter), IT::IDTYPE::L, word.c_str() });
					++counter;
				}
			}
			else if (token == LEX_INTEGER_LIT) {
				ti_idx = IT::isLit(idtable, word);
				if (ti_idx == TI_NULLIDX) {
					IT::Add(idtable, { lextable.size ,"L" + std::to_string(counter), IT::IDTYPE::L, std::stoi(word)});
					++counter;
				}
			}
			LT::Add(lextable, { token, line, ti_idx });	
			outfile << token;
			word.clear();
		};

		unsigned char ch = in.text[i];
		if (ch == '\'') findStringLit = !findStringLit;
		if (in.code[ch] == In::IN::T || findStringLit) {
			word += ch;
		}
		else if ((In::IN::LX == in.code[ch] || In::IN::SPC == in.code[ch] || ch == std::string(IN_CODE_SEP).c_str()[0]) && !findStringLit)
		{
			if (!word.empty())
			{
				fillTable();
			}
			if (in.code[ch] == In::IN::LX) {
				word = ch;
				fillTable();
			}
			if (ch == std::string(IN_CODE_SEP).c_str()[0]) {
				if (in.text[i + 1]) {
					outfile << "\n" << std::setw(3) << std::setfill('0') << ++line << " ";
				}
			}
		}
	}
}