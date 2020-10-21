#include "IT.h"
#include "LT.h"
#include "Error.h"

using namespace IT;
IdTable IT::Create(int size)
{
	if (size > TI_MAXSIZE)
		throw ERROR_THROW(121);
	IdTable idtable;
	idtable.maxsize =size;
	idtable.size = 0;
	idtable.table = new Entry[size];
	return idtable;
}
void IT::Add(IdTable& idtable, Entry entry)
{
	idtable.table[idtable.size++] = entry;//убрать ++ когда реализую функцию
	if (idtable.size > TI_MAXSIZE)
		throw ERROR_THROW(121);
}
Entry IT::GetEntry(IdTable& idtable, int n)
{
	if (n > idtable.size)
		throw ERROR_THROW(116);
	return idtable.table[n];
}
bool IT::IsId(Entry& elemOfTable, char id[ID_MAXSIZE])
{
	return strcmp(elemOfTable.id, id) == 0 ? true : false;
}
bool IT::IsOtherFunc(Entry& elemOfTable, char id[ID_MAXSIZE])
{
	return strcmp(elemOfTable.outsideFunction, id) == 0 ? true : false;
}
void IT::Delete(IdTable& idtable)
{
	delete[] idtable.table;
}


