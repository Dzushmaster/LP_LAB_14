#pragma once
#include "LT.h"
#include "IT.h"
#define IN_MAX_LEN_TEXT 1024*1024 
#define IN_CODE_ENDL '\n'
#define IN_CODE_TABLE {\
 /*0-15*/	   IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,'|', IN::F, IN::F, IN::F, IN::F, IN::F,\
 /*16-31*/	   IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,\
 /*32-47*/     IN::S, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::Q, IN::E, IN::E, IN::E, IN::E, IN::E, IN::E, IN::F, IN::E,\
 /*48-63*/     IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::F, IN::E, IN::F, IN::E, IN::F, IN::F,\
 /*64-79*/     IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,\
 /*80-95*/     IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,\
 /*96-111*/    IN::F, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::F, IN::T, IN::F, IN::F, IN::T, IN::T, IN::T, IN::T,\
 /*112-127*/   IN::T, IN::F, IN::T, IN::T, IN::T, IN::T, IN::F, IN::F, IN::T, IN::T, IN::T, IN::E,IN::F, IN::E, IN::F, IN::F,\
                                                                                                                    \
/*128-143*/    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
/*144-159*/    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
/*160-175*/    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
/*176-191*/    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
/*192-207*/    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
/*208-223*/    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
/*224-239*/    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
/*240-255*/    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F  \
};
namespace In
{
	struct IN
	{
		enum { T = 1024, F = 2048, I = 4096, E = 8192, S = 16384, Q = 32768 };
		int size = 0;
		int lines = 1;
		int ignor = 0;
		unsigned char* text;	//�������� ��� Windows-1251
		unsigned char* textAfterLex = new unsigned char();
		int sizeAfterLex = 0;
		int code[256] = IN_CODE_TABLE;			//������� ��������
	};
	IN getin(wchar_t inFile[], LT::LexTable&, IT::IdTable&);
}