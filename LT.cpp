#include "LT.h"
#include "Error.h"

using namespace LT;
LexTable LT::Create(int size)//лексемы t, i, f и т.д.
{
	LexTable lextable;
	lextable.table = new Entry[size];
	lextable.size = 0;
	lextable.maxsize = size;
	return lextable;
}
void LT::Add(LexTable& lextable, Entry entry)
{
	lextable.table[lextable.size++] = entry;
	if (lextable.size > LT_MAXSIZE)
		throw ERROR_THROW(122);
}
Entry LT::GetEntry(LexTable& lextable, int n)
{
	if (n > lextable.size)
		throw ERROR_THROW(116);
	return lextable.table[n];
}
void LT::Delete(LexTable& lextable)
{
	delete[] lextable.table;
}
