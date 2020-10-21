#include "Error.h"
#include "In.h"
#include "FST.h"
#include "Machines.h"
#include <fstream>

using namespace In;
//если нельз€ разобрать автоматом, то идентификатор
void FillingTheWord(In::IN in, int wordSize, char*word)
{
	int indexStartFilling = in.size - wordSize;
	for (int i = 0; i < wordSize; i++)
		word[i] = in.text[indexStartFilling+i];
	word[wordSize-1] = '\0';
}
IN In::getin(wchar_t inFile[],LT::LexTable& lextable, IT::IdTable& idtable)
{
	std::ifstream FileIn(inFile);
	if (!FileIn.is_open())
		throw ERROR_THROW(110);
	unsigned char Uch;
	IN in;
	in.text = new unsigned char[IN_MAX_LEN_TEXT];
	in.textAfterLex = new unsigned char[IN_MAX_LEN_TEXT];
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
			x.inext.col = in.currentPosition;
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
			in.currentPosition++;
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
				in.currentPosition++;
			}
			if (isExpression)
				in.size--;
			break;
		}
		case IN::E://¬ыражени€
		{
			isWord = false;
			isSpace ? (in.text[in.size - 1] = Uch, isSpace = false, in.ignor++) : (in.text[in.size] = Uch, in.currentPosition++, in.size++);
			isExpression = true;
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
					throw ERROR_THROW_IN(105, in.lines, in.currentPosition);
			}
			char* word = new char[sizeOfSTRLiteral];
			FillingTheWord(in, sizeOfSTRLiteral, word);
			inputToIdTable(idtable,lextable, in, IT::IDDATATYPE::STR, word, IT::IDTYPE::L);
			inputToLexTable(lextable, in, LEX_LITERAL, idtable.size);
			delete[] word;
			break;
		}
		default:
			in.text[in.size] = in.code[Uch];
			lextable.table[lextable.size].sn = in.lines;
			lextable.table[lextable.size].idxTI = lextable.size+1;
			lextable.table[lextable.size++].lexema = LINE_BREAK;
			in.lines++;
			in.currentPosition = 0;
			in.size++;
			isExpression = false;
			isWord = false;
			break;
		}
		if (!isWord)
		{
			choiceOfMachines(wordSize,in, lextable, idtable);//дл€ выбора автоматов	
			if(isExpression && Uch!=' ')
				choiceOfMachines((char)Uch, in, lextable, idtable);
			wordSize = 0;
		}
	}
	in.textAfterLex[in.sizeAfterLex] = '\0';
	in.text[in.size] = '\0';
	FileIn.close();
	return in;
}