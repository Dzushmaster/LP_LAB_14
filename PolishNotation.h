#pragma once
#include "LT.h"
#include "IT.h"
#include <stack>
struct elemPolishNotation
{
	char outputString[TI_STR_MAXSIZE];
	int size = 0;
	int amountOfParametrs = 0;
	std::stack <char> steck;
};
bool CreatingPolishNotation(int lextable_pos,							//������� ��������� � lextable
	LT::LexTable& lextable, IT::IdTable idtable);
void workWithPolishNotation(LT::LexTable& lextable, IT::IdTable& idtable);
void printPolishNotation(char* outputString);
void inputToString(LT::LexTable lextable, elemPolishNotation& outputString);
//����� PolishNotation �� ������ ������� c ������� �������
//���� ����� �� =, �� ��������� �������� ������. � ������� ���������� ����� �������, ��� ��������� '='� �������
//� ���� ������� ���� �� while(lextable.table[i].lexema!=';')
//���������� ������ ������,
//���� �� ����� v ��� ������, �� ���������� �������������� ������ � ����, ���� �� �����, �� � ������
//���� � ����� ���� ������ � ����� �� �����������, �� ������ ��� � �������� ������
//���� � ����������� ����, �� ������ ���������� �����
//���� � ����������� ������, �� ����� ������ � ������


//��� ������ � ��������� ���� ������ � ������� ������ ������� �� @
//� ����������� ���������� � ���, ��������� ������� ����� @, ���������� �����