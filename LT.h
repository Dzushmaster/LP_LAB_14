#pragma once
#include <fstream>
#include <string>
#define LEXEMA_FIXSIZE 1				//������������� ������ �������
#define LT_MAXSIZE 4096					//������������ ���������� ����� � ������� ������
#define LT_TI_NULLIDX 0xffffffff		//��� �������� ������� ���������������
#define AMOUNTEXPRESSIONS 10
#define LEX_INTEGER 't'					
#define LEX_STRING 't'
#define LEX_ID 'i'
#define LEX_LITERAL 'l'
#define LEX_FUNCTION 'f'
#define LEX_DECLARE 'd'
#define LEX_RETURN 'r'
#define LEX_PRINT 'p'
#define LEX_SEMICOLON ';'
#define LEX_COMMA ','
#define LEX_LEFTBRACE '{'
#define LEX_BRACELEFT '}'
#define LEX_LEFTHESIS '('
#define LEX_REIGHTHESIS ')'
#define LEX_PLUS '+'
#define LEX_MINUS '-'
#define LEX_STAR '*'
#define LEX_DIRSLASH '/'
#define LEX_EQUALS '='
#define LEX_MAIN 'm'
//#define LEX_PLUS 'v'
//#define LEX_MINUS 'v'
//#define LEX_STAR 'v'
//#define LEX_DIRSLASH 'v'				//������� ��� /
//#define LEX_EQUALS 'v'

//���������� � in ��� ���������� � ���� ������ �� ����� ���������, �� ������ �������� ��� �������
namespace LT//������� ������
{
	struct Entry//������ ������� ������
	{
		char lexema;//�������
		int sn;						//����� ������ � �������� ������
		int idxTI;					//������ � ������� ��������������� ��� LT_TI_NULLIDX
	};
	struct LexTable//��������� ������� ������
	{
		int maxsize;//������� ������� ������ < LT_MAXSIZE 
		int size;//������� ������ ������� ������ <maxsize
		Entry* table;//������ ����� ������� ������
	};

	LexTable Create(//������� ������� ������
		int size//������� ������� ������ < LT_MAXSIZE
	);
	void Add(		//�������� ������ � ������� ������
		LexTable& lextable, //��������� ������� ������
		Entry entry			//������ ������� ������
	);
	Entry GetEntry(//�������� ������ ������� ������
		LexTable& lextable,//��������� ������� ������
		int n//����� ���������� ������
	);
	void Delete(LexTable& lextable);//������� ������� ������(���������� ������)
};
