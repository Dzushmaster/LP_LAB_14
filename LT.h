#pragma once
#include <fstream>
#include <string>
#define LEXEMA_FIXSIZE 1				//фиксированный размер лексемы
#define LT_MAXSIZE 4096					//максимальное количество строк в таблице лексем
#define LT_TI_NULLIDX 0xffffffff		//нет элемента таблицы идентификаторов
#define AMOUNTEXPRESSIONS 10
#define LEX_INTEGER 't'					
#define LEX_STRING 't'
#define LEX_ID 'i'
#define LEX_LITERAL 'l'
#define LEX_FUNCTION 'f'
#define LEX_DECLARE 'd'
#define LEX_RETURN 'r'
#define LEX_PRINT 'p'
#define LEX_SEMICOLON ';'
#define LEX_COMMA ','
#define LEX_LEFTBRACE '{'
#define LEX_BRACELEFT '}'
#define LEX_LEFTHESIS '('
#define LEX_REIGHTHESIS ')'
#define LEX_PLUS '+'
#define LEX_MINUS '-'
#define LEX_STAR '*'
#define LEX_DIRSLASH '/'
#define LEX_EQUALS '='
#define LEX_MAIN 'm'
//#define LEX_PLUS 'v'
//#define LEX_MINUS 'v'
//#define LEX_STAR 'v'
//#define LEX_DIRSLASH 'v'				//лексема дл€ /
//#define LEX_EQUALS 'v'

//подключить в in эту библиотеку и если символ не нужно разбирать, то просто записать эту лексему
namespace LT//таблица лексем
{
	struct Entry//строка таблицы лексем
	{
		char lexema;//лексема
		int sn;						//номер строки в исходном тексте
		int idxTI;					//индекс в таблице идентификаторов или LT_TI_NULLIDX
	};
	struct LexTable//экземпл€р таблицы лексем
	{
		int maxsize;//емкость таблицы лексем < LT_MAXSIZE 
		int size;//текущий размер таблицы лексем <maxsize
		Entry* table;//массив строк таблицы лексем
	};

	LexTable Create(//создать таблицу лексем
		int size//емкость таблицы лексем < LT_MAXSIZE
	);
	void Add(		//добавить строку в таблицу лексем
		LexTable& lextable, //экземпл€р таблицы лексем
		Entry entry			//строка таблицы лексем
	);
	Entry GetEntry(//получить строку таблицы лексем
		LexTable& lextable,//экземлп€р таблицы лексем
		int n//номер получаемой строки
	);
	void Delete(LexTable& lextable);//удалить таблицу лексем(освободить пам€ть)
};
