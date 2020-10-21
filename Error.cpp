#include "Error.h"
namespace Error
{
	// 0-99 - ��������� ������
	// 100-109 - ������ ����������
	// 110-119 - ������ �������� � ������ ������
	ERROR errors[ERROR_MAX_ENTRY] =
	{
		ERROR_ENTRY(0,"������������ ��� ������"),ERROR_ENTRY(1, "��������� ����"),ERROR_ENTRY_NODEF(2), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10), ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40), ERROR_ENTRY_NODEF10(50), ERROR_ENTRY_NODEF10(60), ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80), ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100,"�������� -in ������ ���� �����"),
		ERROR_ENTRY_NODEF(101), ERROR_ENTRY_NODEF(102), ERROR_ENTRY_NODEF(103),
		ERROR_ENTRY(104,"��������� ����� �������� ���������"),
		ERROR_ENTRY_NODEF(105), ERROR_ENTRY_NODEF(106), ERROR_ENTRY_NODEF(107), ERROR_ENTRY_NODEF(108), ERROR_ENTRY_NODEF(109),
		ERROR_ENTRY(110,"������ ��� �������� ����� � �������� ����� (-in)"),
		ERROR_ENTRY(111,"������������ ������ � �������� ����� (-in)"),
		ERROR_ENTRY(112,"������ ��� �������� ����� ��������� (-log)"),
		ERROR_ENTRY(113,"������ ��� �������� ����� ������� ������"), ERROR_ENTRY(114,"������ ��� �������� ����� ������� ���������������"), ERROR_ENTRY(115,"�������� ������ �������"),
		ERROR_ENTRY(116,"������� ������� �� ������� ����������� ����� �������"), ERROR_ENTRY_NODEF(117), ERROR_ENTRY_NODEF(118),ERROR_ENTRY_NODEF(119),
		ERROR_ENTRY(120,"����������� ����������� �������"),ERROR_ENTRY(121,"�������� ������������ ������ ������� ���������������"), ERROR_ENTRY(122, "�������� ������������ ������ ������� ������"), ERROR_ENTRY(123, "������������ ������ ������ ��������������"),\
		ERROR_ENTRY(124,"���������� ���������� ���������"),ERROR_ENTRY(126,"������� ������� �������������� ��� ������"),ERROR_ENTRY(127,"������� ������� �������������� ��� ��������������"), ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
		ERROR_ENTRY_NODEF100(200), ERROR_ENTRY_NODEF100(300), ERROR_ENTRY_NODEF100(400), ERROR_ENTRY_NODEF100(500), ERROR_ENTRY_NODEF100(600), ERROR_ENTRY_NODEF100(700), ERROR_ENTRY_NODEF100(800), ERROR_ENTRY_NODEF100(900)
	};
}
using namespace Error;
ERROR Error::geterror(int id)
{
	return (id<0 || id>ERROR_MAX_ENTRY) ? errors[0] : errors[id];
}
ERROR Error::geterrorin(int id, int line = -1, int col = -1)
{
	if (id<0 || id>ERROR_MAX_ENTRY)
		return errors[0];
	ERROR result{ id,"",line,col };//"" - message
	int index = 0;
	while (errors[id].message[index] != '\0')
		result.message[index] = errors[id].message[index++];
	result.message[index] = '\0';
	return result;
}
