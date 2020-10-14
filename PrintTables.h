#pragma once
#include "LT.h"
#include "IT.h"
#include "Error.h"
#include "In.h"
void PrintLTTable(LT::LexTable);
void PrintIDTable(IT::IdTable);
void PrintText(In::IN in);
const char* ReturnIdType(IT::IDTYPE idtype);
const char* ReturnIddatatype(IT::IDDATATYPE datatype);
const char* ReturnValue(IT::Entry value);
const char* PrintPrefix(IT::IdTable value);
std::ofstream CreateFileForLT();
std::ofstream CreateFileForID();
std::ofstream CreateFileForText();