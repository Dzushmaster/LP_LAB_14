#pragma once
#include "FST.h"

#define FST_INTEGER word,8,\
FST::NODE(1, FST::RELATION('i',1)),\
FST::NODE(1, FST::RELATION('n',2)),\
FST::NODE(1, FST::RELATION('t',3)),\
FST::NODE(1, FST::RELATION('e',4)),\
FST::NODE(1, FST::RELATION('g',5)),\
FST::NODE(1, FST::RELATION('e',6)),\
FST::NODE(1, FST::RELATION('r',7)),\
FST::NODE()

#define FST_STRING word, 7,\
FST::NODE(1, FST::RELATION('s',1)),\
FST::NODE(1, FST::RELATION('t',2)),\
FST::NODE(1, FST::RELATION('r',3)),\
FST::NODE(1, FST::RELATION('i',4)),\
FST::NODE(1, FST::RELATION('n',5)),\
FST::NODE(1, FST::RELATION('g',6)),\
FST::NODE()

#define FST_FUNCTION word, 9,\
FST::NODE(1, FST::RELATION('f',1)),\
FST::NODE(1, FST::RELATION('u',2)),\
FST::NODE(1, FST::RELATION('n',3)),\
FST::NODE(1, FST::RELATION('c',4)),\
FST::NODE(1, FST::RELATION('t', 5)),\
FST::NODE(1, FST::RELATION('i',6)),\
FST::NODE(1, FST::RELATION('o',7)),\
FST::NODE(1, FST::RELATION('n',8)),\
FST::NODE()

#define FST_DECLARE word, 8,\
FST::NODE(1, FST::RELATION('d',1)),\
FST::NODE(1, FST::RELATION('e',2)),\
FST::NODE(1, FST::RELATION('c',3)),\
FST::NODE(1, FST::RELATION('l',4)),\
FST::NODE(1, FST::RELATION('a',5)),\
FST::NODE(1, FST::RELATION('r',6)),\
FST::NODE(1, FST::RELATION('e',7)),\
FST::NODE()

#define FST_RETURN word, 7,\
FST::NODE(1, FST::RELATION('r',1)),\
FST::NODE(1, FST::RELATION('e',2)),\
FST::NODE(1, FST::RELATION('t',3)),\
FST::NODE(1, FST::RELATION('u',4)),\
FST::NODE(1, FST::RELATION('r',5)),\
FST::NODE(1, FST::RELATION('n',6)),\
FST::NODE()

#define FST_PRINT word, 6,\
FST::NODE(1, FST::RELATION('p',1)),\
FST::NODE(1, FST::RELATION('r',2)),\
FST::NODE(1, FST::RELATION('i',3)),\
FST::NODE(1, FST::RELATION('n',4)),\
FST::NODE(1, FST::RELATION('t',5)),\
FST::NODE()

#define FST_MAIN word, 5,\
FST::NODE(1,FST::RELATION('m',1)),\
FST::NODE(1,FST::RELATION('a',2)),\
FST::NODE(1,FST::RELATION('i',3)),\
FST::NODE(1,FST::RELATION('n',4)),\
FST::NODE()

#define FST_NUMBLITERAL word,1,\
FST::NODE(11, FST::RELATION('1',0),\
			  FST::RELATION('2',0),\
			  FST::RELATION('3',0),\
			  FST::RELATION('4',0),\
			  FST::RELATION('5',0),\
			  FST::RELATION('6',0),\
			  FST::RELATION('7',0),\
			  FST::RELATION('8',0),\
			  FST::RELATION('9',0),\
			  FST::RELATION('0',0),\
			  FST::NODE())



#define FST_IDENTIFICATOR word, 1,\
FST::NODE(28, FST::RELATION('a',0),\
			  FST::RELATION('b',0),\
			  FST::RELATION('c',0),\
			  FST::RELATION('d',0),\
			  FST::RELATION('e',0),\
			  FST::RELATION('f',0),\
			  FST::RELATION('g',0),\
			  FST::RELATION('h',0),\
			  FST::RELATION('i',0),\
			  FST::RELATION('j',0),\
			  FST::RELATION('k',0),\
			  FST::RELATION('l',0),\
			  FST::RELATION('m',0),\
			  FST::RELATION('n',0),\
			  FST::RELATION('o',0),\
			  FST::RELATION('p',0),\
			  FST::RELATION('q',0),\
			  FST::RELATION('r',0),\
			  FST::RELATION('s',0),\
			  FST::RELATION('t',0),\
			  FST::RELATION('u',0),\
			  FST::RELATION('v',0),\
			  FST::RELATION('w',0),\
			  FST::RELATION('x',0),\
			  FST::RELATION('y',0),\
			  FST::RELATION('z',0),\
			  FST::NODE())

#define FST_STRLITERAL word,4,\
FST::NODE(1, FST::RELATION('\'',1)),\
FST::NODE(37, FST::RELATION('a',2),\
			  FST::RELATION('b',2),\
			  FST::RELATION('c',2),\
			  FST::RELATION('d',2),\
			  FST::RELATION('e',2),\
			  FST::RELATION('f',2),\
			  FST::RELATION('g',2),\
			  FST::RELATION('h',2),\
			  FST::RELATION('i',2),\
			  FST::RELATION('j',2),\
			  FST::RELATION('k',2),\
			  FST::RELATION('l',2),\
			  FST::RELATION('m',2),\
			  FST::RELATION('n',2),\
			  FST::RELATION('o',2),\
			  FST::RELATION('p',2),\
			  FST::RELATION('q',2),\
			  FST::RELATION('r',2),\
			  FST::RELATION('s',2),\
			  FST::RELATION('t',2),\
			  FST::RELATION('u',2),\
			  FST::RELATION('v',2),\
			  FST::RELATION('w',2),\
			  FST::RELATION('x',2),\
			  FST::RELATION('y',2),\
			  FST::RELATION('z',2),\
			  FST::RELATION('A',2),\
			  FST::RELATION('B',2),\
			  FST::RELATION('C',2),\
			  FST::RELATION('D',2),\
			  FST::RELATION('E',2),\
			  FST::RELATION('F',2),\
			  FST::RELATION('G',2),\
			  FST::RELATION('H',2),\
			  FST::RELATION('I',2),\
			  FST::RELATION('J',2),\
			  FST::RELATION('K',2),\
			  FST::RELATION('L',2),\
			  FST::RELATION('M',2),\
			  FST::RELATION('N',2),\
			  FST::RELATION('O',2),\
			  FST::RELATION('P',2),\
			  FST::RELATION('Q',2),\
			  FST::RELATION('R',2),\
			  FST::RELATION('S',2),\
			  FST::RELATION('T',2),\
			  FST::RELATION('U',2),\
			  FST::RELATION('V',2),\
			  FST::RELATION('W',2),\
			  FST::RELATION('X',2),\
			  FST::RELATION('Y',2),\
			  FST::RELATION('Z',2),\
			  FST::RELATION('1',2),\
			  FST::RELATION('2',2),\
			  FST::RELATION('3',2),\
			  FST::RELATION('4',2),\
			  FST::RELATION('5',2),\
			  FST::RELATION('6',2),\
			  FST::RELATION('7',2),\
			  FST::RELATION('8',2),\
			  FST::RELATION('9',2),\
			  FST::RELATION('0',2),\
			  FST::RELATION(' ',2),\
			  FST::RELATION('&',2),\
			  FST::RELATION('!',2),\
			  FST::RELATION('@',2),\
			  FST::RELATION('#',2),\
			  FST::RELATION('$',2),\
			  FST::RELATION('%',2),\
			  FST::RELATION('^',2),\
			  FST::RELATION('*',2),\
			  FST::RELATION('(',2),\
			  FST::RELATION(')',2),\
			  FST::RELATION(':',2),\
			  FST::RELATION(';',2),\
			  FST::RELATION('"',2),\
			  FST::RELATION('-',2),\
			  FST::RELATION('+',2),\
			  FST::RELATION('=',2),\
			  FST::RELATION('*',2),\
			  FST::RELATION('?',2),\
			  FST::RELATION('.',2),\
			  FST::RELATION(',',2),\
			  FST::RELATION('>',2),\
			  FST::RELATION('<',2)),\
FST::NODE(1,FST::RELATION('\'',3)),\
FST::NODE()

#define SEMICOLON word,1,\
FST::NODE(1,FST::RELATION(';',0),\
			FST::NODE())

#define COMMA word,1,\
FST::NODE(1,FST::RELATION(',',0),\
			FST::NODE())

#define LEFTBRACE word,1,\
FST::NODE(1,FST::RELATION('{',0),\
			FST::NODE())

#define BRACELEFT word,1,\
FST::NODE(1,FST::RELATION('}',0),\
			FST::NODE())

#define LEFTHESIS word,1,\
FST::NODE(1,FST::RELATION('(',0),\
			FST::NODE())

#define REIGHTHESIS word,1,\
FST::NODE(1,FST::RELATION(')',0),\
			FST::NODE())

#define PLUS word,1,\
FST::NODE(1,FST::RELATION('+',0),\
			FST::NODE())

#define MINUS word,1,\
FST::NODE(1,FST::RELATION('-',0),\
			FST::NODE())

#define STAR word,1,\
FST::NODE(1,FST::RELATION('*',0),\
			FST::NODE())

#define DIRSLASH word,1,\
FST::NODE(1,FST::RELATION('/',0),\
			FST::NODE())

#define EQUALS word, 1,\
FST::NODE(1, FST::RELATION('=',0),\
			 FST::NODE())

#define AMOUNTLEXEM 21
#define ALL_MACHINES \
FST::FST Integer(FST_INTEGER);\
FST::FST String(FST_STRING);\
FST::FST Function(FST_FUNCTION);\
FST::FST Declare(FST_DECLARE);\
FST::FST Return(FST_RETURN);\
FST::FST Print(FST_PRINT);\
FST::FST Identificator(FST_IDENTIFICATOR);\
FST::FST NumberLiteral(FST_NUMBLITERAL);\
FST::FST Main(FST_MAIN);\
FST::FST STRLiteral(FST_STRLITERAL);\
FST::FST Braceleft(BRACELEFT); \
FST::FST Leftbrace(LEFTBRACE);\
FST::FST Semicolon(SEMICOLON);\
FST::FST Comma(COMMA);\
FST::FST Lefthesis(LEFTHESIS);\
FST::FST Reighthesis(REIGHTHESIS);\
FST::FST Plus(PLUS);\
FST::FST Minus(MINUS);\
FST::FST Star(STAR);\
FST::FST Dirslash(DIRSLASH);\
FST::FST Equals(EQUALS);\
FST::FST CHOOSINGMACHINE[AMOUNTLEXEM] = {Integer, String, Function, Declare, Return, Print,Main,NumberLiteral,STRLiteral,Identificator, Braceleft,Leftbrace, Semicolon,Comma, Lefthesis, Reighthesis, Plus, Minus, Star, Dirslash,Equals};

bool changingMachine(char* word, In::IN in , LT::LexTable& lextable, IT::IdTable& idtable, FST::FST machine, int kindOfMachine);
void inputToIdTable(IT::IdTable& idtable,In::IN in, IT::IDDATATYPE dataType, char* word, bool* isTypeOfId, bool&);
void inputToIdTable(IT::IdTable& idtable,In::IN in ,IT::IDDATATYPE dataType, char* word, IT::IDTYPE);
void DefineScope(IT::Entry&, bool&, bool*);
void inputToLexTable(LT::LexTable& lextable, In::IN in, char lexem);
IT::IDTYPE typeofId(bool* isTypeOfId);
void defineIdName(IT::Entry&, char*);
char* inputWord(int sizeText, int wordSize);