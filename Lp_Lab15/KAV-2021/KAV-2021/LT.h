#pragma once
#include "stdafx.h"
#include "Parm.h"
#define LEXEMA_FIXSIZE	1			
#define LT_MAXSIZE		4096		
#define LT_TI_NULLIDX	0xfffffff	
#define LEX_INTEGER		'n'	
#define LEX_STRING		's'
#define LEX_DATATYPE	't'
#define LEX_ID			'i'	
#define LEX_INTEGER_LIT '1'
#define LEX_STRING_LIT	'2' 
#define LEX_STRLEN		'c'
#define LEX_SUBSTR		'c'
#define LEX_FUNCTION	'f'	
#define LEX_DECLARE		'd'	
#define LEX_RETURN		'r'	
#define LEX_PRINT		'p'	
#define LEX_MAIN		'm'	
#define LEX_SEMICOLON	';'	
#define LEX_COMMA		','	
#define LEX_MREQUAL		'{'	
#define LEX_LSEQUAL		'}'	
#define LEX_LEFTTHESIS	'('	
#define LEX_RIGHTTHESIS	')'	
#define LEX_PLUS		'+'	
#define LEX_MINUS		'-'	
#define LEX_STAR		'*'
#define LEX_DIRSLASH	'/'
#define LEX_OPERATOR	'v'	
#define LEX_EQUAL		'='

namespace LT {
	struct Entry {
		char lexema; // �������
		int sn; // ����� ������ � �������� ������
		int idxTI; // ������ � ������� ��������������� ��� LT_TI_NULLIDX
	};

	struct LexTable
	{
		int maxsize;
		int size;
		Entry* table;
	};

	LexTable Create(int size);
	void Add(LexTable& lextable, Entry entry);
	Entry GetEntry(LexTable& lextable, int n);
	void Delete(LexTable& lextable);
	void ShowTable(LexTable& lextable, std::ofstream *stream);
}