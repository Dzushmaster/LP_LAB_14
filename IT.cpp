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
	idtable.table[idtable.size++] = entry;
	if (idtable.size > TI_MAXSIZE)
		throw ERROR_THROW(121);
}
Entry IT::GetEntry(IdTable& idtable, int n)
{
	if (n > idtable.size)
		throw ERROR_THROW(116);
	return idtable.table[n];
}
int IT::IsId(IdTable& idtable, char id[ID_MAXSIZE])
{
	if (strcmp(idtable.table->id, id) == 0)
		return (int)id;
	return LT_TI_NULLIDX;
}
void IT::Delete(IdTable& idtable)
{
	delete[] idtable.table;
}


