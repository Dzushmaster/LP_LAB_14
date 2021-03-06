#include "FST.h"
#include "Machines.h"
namespace FST
{
	RELATION::RELATION(char c, short nn)
	{
		symbol = c;
		nnode = nn;
	}
	NODE::NODE()
	{
		n_relation = 0;
		RELATION* realtions = NULL;
	}
	NODE::NODE(short n, RELATION rel, ...)
	{
		n_relation = n;
		RELATION* p = &rel;
		relations = new RELATION[n];
		for (short i = 0; i < n; i++)
			relations[i] = p[i];
	}
	FST::FST(char* s, short ns, NODE n, ...)
	{
		string = s;
		nstates = ns;
		nodes = new NODE[ns];
		NODE* p = &n;
		for (int k = 0; k < ns; k++)
			nodes[k] = p[k];
		rstates = new short[nstates];
		memset(rstates, 0xff, sizeof(short) * nstates);
		rstates[0] = 0;
		position = -1;
	}
	bool step(FST& fst, short*& rstates)
	{
		bool rc = false;
		std::swap(rstates, fst.rstates);
		for (short i = 0; i < fst.nstates; i++)
		{
			if (rstates[i] == fst.position)
				for (short j = 0; j < fst.nodes[i].n_relation; j++)
				{
					if (fst.nodes[i].relations[j].symbol == fst.string[fst.position])
					{
						fst.rstates[fst.nodes[i].relations[j].nnode] = fst.position + 1;
						rc = true;
					};
				};
		};
		return rc;
	};
	bool execute(FST& fst)
	{
		short* rstates = new short[fst.nstates];
		memset(rstates, 0xff, sizeof(short) * fst.nstates);
		short lstring = strlen(fst.string);
		bool rc = true;
		for (short i = 0; i < lstring && rc; i++)
		{
			fst.position++;
			rc = step(fst, rstates);
		};
		delete[] rstates;
		return (rc ? (fst.rstates[fst.nstates - 1] == lstring) : rc);
	}
}
void choiceOfMachines(int wordSize, In::IN& in, LT::LexTable& lextable, IT::IdTable& idtable)//������������ �������
{
	bool Disassembled = false;
	char* word = new char[wordSize+1];
	short sizeofText = in.size - wordSize-1;
	for (int i = 0; i <= wordSize; i++)
		word[i] = in.text[sizeofText + i];
	if (word[wordSize] == '\'')
		word[wordSize+1] = '\0';
	word[wordSize] = '\0';
	if (!word[0])
		return;
	ALL_MACHINES;
	for (int kindOfMachine = 0; kindOfMachine < AMOUNTLEXEM && !Disassembled; kindOfMachine++)
	{
		Disassembled = changingMachine(word,in,lextable,idtable,CHOOSINGMACHINE[kindOfMachine],kindOfMachine);
	}
	if (!Disassembled)
		throw ERROR_THROW_IN(124,in.currentPosition , in.lines);
}
void choiceOfMachines(char symbol, In::IN& in, LT::LexTable& lextable, IT::IdTable& idtable)
{
	char word[2];
	word[0] = symbol; word[1] = '\0';
	bool Disassembled = false;
	OPERATIONS_MACHINES;
	for (int kindOfExpression = 0; kindOfExpression < AMOUNT_OPERATIONS && !Disassembled; kindOfExpression++)
	{
		Disassembled = changingMachine(word, in, lextable, idtable, CHOOSING_OPERATION[kindOfExpression], kindOfExpression + AMOUNTLEXEM);
	}
	if (!Disassembled)
		throw ERROR_THROW_IN(124,in.currentPosition,in.lines);
}