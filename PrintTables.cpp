#include "PrintTables.h"
std::ofstream CreateFileForLT()
{
	std::ofstream stream;
	stream.open("Table_Of_Lexem.txt");
	if (!stream.is_open())
		throw ERROR_THROW(114);
	return stream;
}
std::ofstream CreateFileForID()
{
	std::ofstream stream;
	stream.open("Table_Of_Identificators.txt");
	if (!stream.is_open())
		throw ERROR_THROW(114);
	return stream;
}

std::ofstream CreateFileForText()
{
	std::ofstream Filestream;
	Filestream.open("Text_After_Lex.txt");
	if (!Filestream.is_open())
		throw ERROR_THROW(114);
	return Filestream;
}

void PrintText(In::IN in)
{
	std::ofstream stream = CreateFileForText();
	//вывод id из таблицы идентификаторов
}
void PrintLTTable(LT::LexTable lextable)
{
	std::ofstream stream = CreateFileForLT();
	stream << "Размер таблицы лексем: ";
	stream << lextable.size;
	stream << "\nНомер лексемы -> Лексема -> Номер строки в исходном тексте\n";
	for (int i = 0; i < lextable.size; i++)
	{
		stream.width(6);
		stream << lextable.table[i].idxTI;
		stream.width(15);
		stream << lextable.table[i].lexema;
		stream.width(12);
		stream << lextable.table[i].sn;
		stream << '\n';
	}
}
void PrintIDTable(IT::IdTable idtable)
{
	std::ofstream stream = CreateFileForID();
	stream << "Размер таблицы идентификаторов: ";
	stream << idtable.size;
	stream << "\n";
	stream << "Номер идентификатора -> Идентификатор -> Тип данных -> Тип идентификатора -> Нечто -> Значение\n";
	for (int i = 0; i < idtable.size; i++)//исправить вывод в файл(если нет id, не выводить id)
	{
		stream.width(5);
		stream << i + 1;
		stream.width(25);
		/*stream << idtable.table[i].prefix;//подумать, как возвращать с ::
		stream << "::";*/
		stream << idtable.table[i].id;
		stream.width(20);
		stream << ReturnIddatatype(idtable.table[i].iddatatype);
		stream.width(20);
		stream << ReturnIdType(idtable.table[i].idtype);
		stream.width(10);
		stream << idtable.table[i].idxfirstLE;
		stream.width(10);
		stream << ReturnValue(idtable.table[i]);
		stream << '\n';
	}
}
//const char* PrintPrefix(IT::IdTable idtable)
//{
//	if (idtable.table->prefix == NULL)
//		return "";
//	
//	return ;
//}
const char* ReturnIddatatype(IT::IDDATATYPE datatype)
{
	if (datatype == IT::IDDATATYPE::INT)
		return "integer";
	if (datatype == IT::IDDATATYPE::STR)
		return "string";
}
const char* ReturnIdType(IT::IDTYPE idtype)
{
	switch (idtype)
	{
	case 1:
		return "variable";
	case 2:
		return "function";
	case 3:
		return "parameter";
	case 4:
		return "literal";
	case 5:
		return "outside function";
	}
}
bool checkFunc_Par(IT::Entry value)
{
	return (IT::F == value.idtype || IT::P == value.idtype || IT::O == value.idtype);
}
const char* ReturnValue(IT::Entry value)
{
	if (IT::F != value.idtype)
	{
		if (value.value.vint == TI_INT_DEFAULT)
			return "0";
		if (value.value.vint != TI_INT_DEFAULT)//проверить
		{
			char symb[11];
			_itoa_s(value.value.vint, symb, 10);
			return symb;
		}
		if (strcmp(value.value.vstr->str,NULL) == 0)
			return "0";
		return value.value.vstr->str;
	}
	return "";
}