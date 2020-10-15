#include "Machines.h"
#include "IT.h"
#include "LT.h"
#include "PrintTables.h"
//char* inputWord()
//{
//
//}
void inputToIdTable(IT::IdTable& idtable,In::IN in, IT::IDDATATYPE dataType, char* word, bool* IntStrFunVarMain)
{
	IT::Entry partOfTable;
	partOfTable.iddatatype = dataType;
	partOfTable.idxfirstLE = in.lines;
	partOfTable.idtype = typeofId(IntStrFunVarMain);
	defineIdName(partOfTable, word);
	if (dataType == IT::IDDATATYPE::STR && (IT::F !=partOfTable.idtype || IT::O != partOfTable.idtype))//исправить
	{
		partOfTable.value.vstr->ken = 0;
		partOfTable.value.vstr->str[0] = TI_STR_DEFAULT;
	}
	else if (IT::F != partOfTable.idtype || IT::O != partOfTable.idtype)
		partOfTable.value.vint = TI_INT_DEFAULT;
	DefineScope(partOfTable, IntStrFunVarMain);
	IT::Add(idtable, partOfTable);
	//in.textAfterLex[in.sizeAfterLex++] = 'i';
}
void defineIdName(IT::Entry& partOfTable, char* word)//заменить переменную, в которую записываетс€ значение
{
	//partOfTable.idtype == IT::P? strncpy_s(partOfTable.prefix,word,PREFIX_SIZE): strncpy_s(partOfTable.id, word, 5) && partOfTable.prefix = '\0';
	if (partOfTable.idtype == IT::O)
	{
		strncpy_s(partOfTable.outsideFunction, word, PREFIX_SIZE);
		partOfTable.id[0] = '\0';
		return;
	}
	strncpy_s(partOfTable.id, word, ID_MAXSIZE + 1);
	partOfTable.outsideFunction[0] = '\0';

}
void inputToIdTable(IT::IdTable& idtable,In::IN in ,IT::IDDATATYPE iddatatype, char* word, IT::IDTYPE idtype)
{
	IT::Entry partOfTable;
	if (iddatatype == IT::IDDATATYPE::STR)
	{
		partOfTable.value.vstr->ken = strlen(word);
		strncpy_s(partOfTable.value.vstr->str, word, strlen(word));
	}
	else
		partOfTable.value.vint = atoi(word);
	in.textAfterLex[in.sizeAfterLex++] = 'i';
	partOfTable.iddatatype = iddatatype;
	partOfTable.idtype = idtype;
	partOfTable.id[0] = '\0';
	partOfTable.prefix[0] = '\0';
	partOfTable.outsideFunction[0] = '\0';
	partOfTable.idxfirstLE = in.lines;
	IT::Add(idtable, partOfTable);
}

IT::IDTYPE typeofId(bool* IntStrFunVarMain)
{
	if (IntStrFunVarMain[3] && IntStrFunVarMain[2]) //сторонн€€ функци€
		return IT::IDTYPE::O;
	if (IntStrFunVarMain[3])						//переменна€
		return IT::IDTYPE::V;
	if (IntStrFunVarMain[2])						//функци€
		return IT::IDTYPE::F;
	return IT::IDTYPE::P;							//параметр
}

void DefineScope(IT::Entry& partOfTable, bool* IntStrFunVarMain)
{
	static char nameFunction[PREFIX_SIZE];
	if ((IntStrFunVarMain[2] && !IntStrFunVarMain[3]))//возможно, заменить на функцию
	{
		strncpy_s(nameFunction, partOfTable.id, 10);
		IntStrFunVarMain[2] = false;
		partOfTable.prefix[0] = NULL;
		return;
	}
	if (IntStrFunVarMain[4])
	{
		strncpy_s(nameFunction, "main", 4);
		IntStrFunVarMain[4] = false;
		strncpy_s(partOfTable.prefix, nameFunction, PREFIX_SIZE);
		return;
	}
	strncpy_s(partOfTable.prefix, nameFunction, PREFIX_SIZE);
}

void inputToLexTable(LT::LexTable& lextable, In::IN in, char lexem)//работает
{
	LT::Entry partOfTable;
	partOfTable.lexema = lexem;
	partOfTable.sn = in.lines;
	partOfTable.idxTI = lextable.size + 1;
	LT::Add(lextable, partOfTable);
	in.textAfterLex[in.sizeAfterLex++] = lexem;
}


bool changingMachine(char* word, In::IN  line, LT::LexTable& lextable, IT::IdTable& idtable, FST::FST machine, int kindOfMachine)
{
	static bool IntStrFunVarMain[5] = { false,false,false,false,false };
	if (!FST::execute(machine))
		return false;
	switch (kindOfMachine)
	{
	case 0:
		inputToLexTable(lextable, line, LEX_INTEGER);
		IntStrFunVarMain[0]= true;
		return true;
	case 1:
		inputToLexTable(lextable, line, LEX_STRING);
		IntStrFunVarMain[1] = true;
		return true;
	case 2:
		inputToLexTable(lextable, line, LEX_FUNCTION);
		IntStrFunVarMain[2] = true;
		return true;
	case 3:
		inputToLexTable(lextable, line, LEX_DECLARE);
		IntStrFunVarMain[3] = true;
		return true;
	case 4:
		inputToLexTable(lextable, line, LEX_RETURN);
		return true;
	case 5:
		inputToLexTable(lextable, line, LEX_PRINT);
		return true;
	case 6:
		inputToLexTable(lextable, line, LEX_MAIN);
		IntStrFunVarMain[4] = true;
		return true;
	case 7:
		inputToIdTable(idtable,line ,IT::IDDATATYPE::INT, word, IT::IDTYPE::L);
		return true;
	case 8:
		inputToIdTable(idtable,line ,IT::IDDATATYPE::STR, word, IT::IDTYPE::L);
		return true;
	case 9:
		if (IntStrFunVarMain[0])
		{
			inputToIdTable(idtable,line ,IT::IDDATATYPE::INT, word, IntStrFunVarMain);
			IntStrFunVarMain[0] = false;
			IntStrFunVarMain[2] = false;
			IntStrFunVarMain[3] = false;
			return true;
		}
		if (IntStrFunVarMain[1])
		{
			inputToIdTable(idtable,line ,IT::IDDATATYPE::STR, word, IntStrFunVarMain);
			IntStrFunVarMain[1] = false;
			IntStrFunVarMain[2] = false;
			IntStrFunVarMain[3] = false;
			return true;
		}
		break;
	
	case 10:
		inputToLexTable(lextable, line, LEX_BRACELEFT);
		return true;
	case 11:
		inputToLexTable(lextable, line, LEX_LEFTBRACE);
		return true;
	case 12:
		inputToLexTable(lextable, line, LEX_SEMICOLON);
		return true;
	case 13:
		inputToLexTable(lextable, line, LEX_COMMA);
		return true;
	case 14:
		inputToLexTable(lextable, line, LEX_LEFTHESIS);
		return true;
	case 15:
		inputToLexTable(lextable, line, LEX_REIGHTHESIS);
		return true;
	case 16:
		inputToLexTable(lextable, line, LEX_PLUS);
		return true;
	case 17:
		inputToLexTable(lextable, line, LEX_MINUS);
		return true;
	case 18:
		inputToLexTable(lextable, line, LEX_STAR);
		return true;
	case 19:
		inputToLexTable(lextable, line, LEX_DIRSLASH);
		return true;
	case 20:
		inputToLexTable(lextable, line, LEX_EQUALS);
		return true;
	default:
		throw ERROR_THROW_IN(124, line.lines, line.size);
		break;
	}
}