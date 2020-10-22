#include "PolishNotation.h"
void workWithPolishNotation(LT::LexTable& lextable, IT::IdTable& idtable)
{
	for (int lextable_pos = 0; lextable_pos < lextable.size;lextable_pos++)
	{
		if (lextable.table[lextable_pos].lexema == LEX_EQUALS)
			CreatingPolishNotation(++lextable_pos, lextable, idtable) ? std::cout <<" :polish notation was created\n" : std::cout << ": polish notation wasn't created\n";
	}
}
bool CreatingPolishNotation(int lextable_pos, LT::LexTable& lextable, IT::IdTable idtable)
{
	elemPolishNotation outputString;
	while (lextable.table[lextable_pos].lexema != ';')
	{
		if (lextable.table[lextable_pos].lexema == 'v' || lextable.table[lextable_pos].lexema == '(' || lextable.table[lextable_pos].lexema == ')')
		{
			outputString.steck.push(lextable.table[lextable_pos].arithmeticSymbol);
			inputToString(lextable, outputString);
			lextable_pos++;
		}
		else
			outputString.outputString[outputString.size++] = lextable.table[lextable_pos++].lexema;
	}
	if (!outputString.steck.empty())
	{
		outputString.outputString[outputString.size++] = outputString.steck.top();
		outputString.steck.pop();
	}
	//outputString.outputString[outputString.size++] = outputString.steck.top();
	outputString.outputString[outputString.size] = '\0';
	printPolishNotation(outputString.outputString);
	return true;
}
void inputToString(LT::LexTable lextable,elemPolishNotation& outputString)
{
	if (outputString.steck.size() <= 1)
		return;
	char currentSymbol = outputString.steck.top(); outputString.steck.pop();
	switch (currentSymbol)
	{
	case ')':
		while (outputString.steck.top() != '(')//сбрасывает все символы, которые хранились перед ) когда появилась (
		{
			outputString.outputString[outputString.size++] = outputString.steck.top(); outputString.steck.pop();
		}
		outputString.steck.pop();
		return;
	case '+'://независимо от символа в строке будет выполняться это
		if (outputString.steck.top() == '(')
		{
			outputString.steck.push(currentSymbol);	return;
		}
		outputString.outputString[outputString.size++] = outputString.steck.top();
		outputString.steck.push(currentSymbol);
		return;
	case '-':
		if (outputString.steck.top() == '(')
		{
			outputString.steck.push(currentSymbol);	return;
		}
		outputString.outputString[outputString.size++] = outputString.steck.top();
		outputString.steck.push(currentSymbol);
		return;
	case '*':
		if (outputString.steck.top() == '(')
		{
			outputString.steck.push(currentSymbol);	return;
		}
		if(outputString.steck.top() == '+' || outputString.steck.top() == '-')
			outputString.outputString[outputString.size++] = outputString.steck.top();
		outputString.steck.push(currentSymbol);
		return;
	case '/':
		if (outputString.steck.top() == '(')
		{
			outputString.steck.push(currentSymbol);	return;
		}
		if (outputString.steck.top() == '+' || outputString.steck.top() == '-')
			outputString.outputString[outputString.size++] = outputString.steck.top();
		outputString.steck.push(currentSymbol);
		return;
	}
	outputString.steck.push(currentSymbol);
	//arithmeticSymbol == '+' || '-' && outputString.steck хранит в себе такой же, то записываем в строку, иначе в стек
	//если хранит в себе * или / то и символ + или -, то сносим это в таблицу
}
void printPolishNotation(char* outputString)
{
	for (int i = 0; i < strlen(outputString) && outputString[i] != '\0'; i++)
		std::cout <<outputString[i] << ' ';
}
