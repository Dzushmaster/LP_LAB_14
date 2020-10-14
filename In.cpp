#include "Error.h"
#include "In.h"
#include "FST.h"
#include "Machines.h"
#include <fstream>

using namespace In;
//если нельз€ разобрать автоматом, то идентификатор
IN In::getin(wchar_t inFile[],LT::LexTable& lextable, IT::IdTable& idtable)
{
	std::ifstream FileIn(inFile);
	if (!FileIn.is_open())
		throw ERROR_THROW(110);
	unsigned char Uch;
	IN in;
	in.text = new unsigned char[IN_MAX_LEN_TEXT];
	int CurrentPosition = 0;
	int wordSize = 0;
	for (;;)//проверка символов на разрешенность
	{
		Uch = FileIn.get();
		if (FileIn.eof())
			break;
		static bool isSpace = false;
		static bool isExpression = false;
		static bool isWord = false;
		switch (in.code[Uch])
		{
		case IN::F:
		{
			Error::ERROR x;
			x.inext.line = in.lines;
			x.inext.col = CurrentPosition;
			throw ERROR_THROW_IN(111, x.inext.line, x.inext.col);
			break;
		}
		case IN::I:
			in.ignor++;
			in.size--;
			isExpression = false;
			isWord = false;
			isSpace = false;
			break;
		case IN::T:
		{
			wordSize++;
			in.text[in.size] = Uch;//текущий символ
			isExpression = false;
			isSpace = false;
			isWord = true;
			in.size++;
			CurrentPosition++;
			continue;
		}
		case IN::S:
		{
			if (isSpace)
			{
				in.ignor++;
				continue;
			}
			else
			{
				isWord = false;
				isSpace = true;
				in.text[in.size++] = Uch;
				CurrentPosition++;
			}
			if (isExpression)
				in.size--;
			break;
		}
		case IN::E://¬ыражени€
		{
			isWord = false;
			isSpace ? (in.text[in.size - 1] = Uch, isSpace = false, in.ignor++) : (in.text[in.size] = Uch, CurrentPosition++, in.size++);
			isExpression = true;
			choiceOfMachines((char)Uch, in, lextable, idtable);
			break;
		}
		case IN::Q:
		{
			isWord = true;
			bool isQuote = false;//наличие первой кавычки
			int sizeOfSTRLiteral = 0;
			while (true)
			{
				in.text[in.size++] = Uch;
				Uch = FileIn.get();
				if (FileIn.eof())
					break;
				sizeOfSTRLiteral++;
				if (Uch == '\'')
				{
					in.text[in.size++] = Uch;
					isQuote = true;
					break;
				}
				else if (Uch == '\n' && !isQuote)
					throw ERROR_THROW_IN(105, in.lines, CurrentPosition);
			}
			char* word = new char[sizeOfSTRLiteral];
			
			inputToIdTable(idtable, in, IT::IDDATATYPE::STR, word, IT::IDTYPE::L);
			delete[]word;
			break;
		}
		default:
			in.text[in.size] = in.code[Uch];
			in.lines++;
			CurrentPosition = 0;
			in.size++;
			isWord = false;
			continue;
		}
		if (!isWord)
		{
			choiceOfMachines(wordSize,in, lextable, idtable);//дл€ выбора автоматов
			wordSize = 0;
		}
	}
	in.textAfterLex[in.sizeAfterLex] = '\0';
	in.text[in.size] = '\0';
	FileIn.close();
	return in;
}