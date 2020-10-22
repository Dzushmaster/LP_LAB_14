#include "Machines.h"
#include "IT.h"
#include "LT.h"
#include "PrintTables.h"
int checkIndEntry(IT::IdTable& idtable, char* word)//во врем€ проверки этой или после вызывать таблицу
{
	for (int i = 0; i < idtable.size; i++)
	{
		if (IT::IsId(idtable.table[i], word))
			return i;
		if (IT::IsOtherFunc(idtable.table[i], word))
			return i;
	}
	return -1;
}
//bool checkRepeatedInd(bool*IntStrFuncVarMain)
//{
//	if (IntStrFuncVarMain[3] || IntStrFuncVarMain[2])
//		return true;
//	return false;
//}
void inputToIdTable(IT::IdTable& idtable,LT::LexTable& lextable,In::IN& in, IT::IDDATATYPE dataType, char* word, bool* IntStrFunVarMain)
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
	else if (IT::F != partOfTable.idtype && IT::O != partOfTable.idtype)
		partOfTable.value.vint = TI_INT_DEFAULT;
	DefineScope(partOfTable, IntStrFunVarMain);
	IT::Add(idtable, partOfTable);
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
}
void inputToIdTable(IT::IdTable& idtable, LT::LexTable& lextable, In::IN& in, IT::IDDATATYPE iddatatype, char* word, IT::IDTYPE idtype)
{
	IT::Entry partOfTable;
	if (iddatatype == IT::IDDATATYPE::STR)
	{
		partOfTable.value.vstr->ken = strlen(word);
		strncpy_s(partOfTable.value.vstr->str, word, strlen(word));
	}
	else
		partOfTable.value.vint = atoi(word);
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

void inputToLexTable(LT::LexTable& lextable, In::IN in, char lexem, int idxTI)//работает
{
	LT::Entry partOfTable;
 	partOfTable.lexema = lexem;
	partOfTable.sn = in.lines;
	partOfTable.idxTI = idxTI;
	partOfTable.arithmeticSymbol = lextable.table[lextable.size].arithmeticSymbol;
	LT::Add(lextable, partOfTable);
}


bool changingMachine(char* word, In::IN&  in, LT::LexTable& lextable, IT::IdTable& idtable, FST::FST machine, int kindOfMachine)
{
	static bool IntStrFunVarMain[5] = { false,false,false,false,false };
	if (!FST::execute(machine))
		return false;
	switch (kindOfMachine)
	{
	case 0:
		inputToLexTable(lextable, in, LEX_INTEGER, lextable.size + 1);
		IntStrFunVarMain[0]= true;
		return true;
	case 1:
		inputToLexTable(lextable, in, LEX_STRING, lextable.size + 1);
		IntStrFunVarMain[1] = true;
		return true;
	case 2:
		inputToLexTable(lextable, in, LEX_FUNCTION, lextable.size + 1);
		IntStrFunVarMain[2] = true;
		return true;
	case 3:
		inputToLexTable(lextable, in, LEX_DECLARE,lextable.size + 1);
		IntStrFunVarMain[3] = true;
		return true;
	case 4:
		inputToLexTable(lextable, in, LEX_RETURN, lextable.size + 1);
		return true;
	case 5:
		inputToLexTable(lextable, in, LEX_PRINT, lextable.size + 1);
		return true;
	case 6:
		inputToLexTable(lextable, in, LEX_MAIN, lextable.size + 1);
		IntStrFunVarMain[4] = true;
		return true;
	case 7:
		inputToIdTable(idtable,lextable,in ,IT::IDDATATYPE::INT, word, IT::IDTYPE::L);
		inputToLexTable(lextable, in, LEX_LITERAL, idtable.size);
		return true;
	case 8:
		inputToIdTable(idtable,lextable,in ,IT::IDDATATYPE::STR, word, IT::IDTYPE::L);
		return true;
	case 9:
		if (IntStrFunVarMain[0])
		{
			inputToIdTable(idtable,lextable,in ,IT::IDDATATYPE::INT, word, IntStrFunVarMain);
			IntStrFunVarMain[0] = false;
			IntStrFunVarMain[2] = false;
			IntStrFunVarMain[3] = false;
		}
		else if (IntStrFunVarMain[1])
		{
			inputToIdTable(idtable,lextable,in ,IT::IDDATATYPE::STR, word, IntStrFunVarMain);
			IntStrFunVarMain[1] = false;
			IntStrFunVarMain[2] = false;
			IntStrFunVarMain[3] = false;
		}
		lextable.table[lextable.size].idxTI = checkIndEntry(idtable, word);
		if (lextable.table[lextable.size].idxTI != -1)
		{
			//if (checkRepeatedInd(IntStrFunVarMain))
			//	throw ERROR_THROW_IN(125, in.lines, in.size);
			inputToLexTable(lextable, in, LEX_ID, lextable.table[lextable.size].idxTI);
			return true;
		}
		return false;
	case 10:
		inputToLexTable(lextable, in, LEX_BRACELEFT, lextable.size + 1);
		return true;
	case 11:
		inputToLexTable(lextable, in, LEX_LEFTBRACE, lextable.size + 1);
		return true;
	case 12:
		inputToLexTable(lextable, in, LEX_SEMICOLON, lextable.size + 1);
		return true;
	case 13:
		inputToLexTable(lextable, in, LEX_COMMA, lextable.size + 1);
		return true;
	case 14:
		lextable.table[lextable.size].arithmeticSymbol = LEX_LEFTHESIS;
		inputToLexTable(lextable, in, LEX_LEFTHESIS, lextable.size + 1);
		return true;
	case 15:
		lextable.table[lextable.size].arithmeticSymbol = LEX_REIGHTHESIS;
		inputToLexTable(lextable, in, LEX_REIGHTHESIS, lextable.size + 1);
		return true;
	case 16:
		lextable.table[lextable.size].arithmeticSymbol = '+';
		inputToLexTable(lextable, in, LEX_PLUS, lextable.size + 1);
		return true;
	case 17:
		lextable.table[lextable.size].arithmeticSymbol = '-';
		inputToLexTable(lextable, in, LEX_MINUS,lextable.size + 1);
		return true;
	case 18:
		lextable.table[lextable.size].arithmeticSymbol = '*';
		inputToLexTable(lextable, in, LEX_STAR, lextable.size + 1);
		return true;
	case 19:
		lextable.table[lextable.size].arithmeticSymbol = '/';
		inputToLexTable(lextable, in, LEX_DIRSLASH, lextable.size + 1);
		return true;
	case 20:
		inputToLexTable(lextable, in, LEX_EQUALS, lextable.size + 1);
		return true;
	}
}