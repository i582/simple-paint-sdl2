#include "DEC_String.h"

unsigned int DEC_String::calls = 0;

// ���������� ������, ����������� �� ���� ��-������
DEC_String::DEC_String(char* _str) : String(_str)
{
	if (!isCorrect(_str)) {
		str = nullptr;
		length = 0;
	}

	cout << "����������� ����� '���������� ������'. �������� ����������� � ��-�������" << endl;
}

// ����������� ��� � ���������� ������ ��������� ��� ����� -> "������"
DEC_String::DEC_String(const char* _str) : String(_str)
{
	if (!isCorrect((char*)_str)) {
		str = nullptr;
		length = 0;
	}

	cout << "����������� ����� '���������� ������'. �������� ����������� � ����������� ��-�������" << endl;
}

DEC_String::~DEC_String()
{
	cout << "����������� ����� '���������� ������'. �������� ����������" << endl;
}

// ����������� �����������
DEC_String::DEC_String(const DEC_String& obj) : String(obj.str)
{
	if (!isCorrect(obj.str)) {
		str = nullptr;
		length = 0;
	}

	calls++;

	cout << "����������� ����� '���������� ������'. ����������� ����������� �������� " << calls << "-���" << endl;
}

bool DEC_String::isCorrect(char* str)
{
	cout << "����������� ����� '���������� ������'. ��������� ������� �������� ������������ ������" << endl;

	if (isdigit(str[0]) || str[0] == '+' || str[0] == '-')
		// ���� �� ���� �������� ������
		for (int i = 1; i < length; i++)
			// � ��� ������, ���� �� ���������� �� ������������ ������ �� �������
			if (!isdigit(str[i]))
				return false; 

	return true;
}

bool DEC_String::isUnsignedInt()
{
	cout << "����������� ����� '���������� ������'. ��������� ������� �������� ������ �� ����������� ������ � unsigned int" << endl;
	const char* STR_MAX_UINT = { "4294967295" };
	unsigned int temp_length = length;

	if (str[0] == '0') 
		for (size_t i = 0; i < length; i++, temp_length--)
			if (str[i] != '0')
				break;

	if (str[0] == '-' || temp_length > 10)
		return false;
	if (temp_length < 10 || !strcmp(str, STR_MAX_UINT))
		return true;

	for (size_t i = length - temp_length, j = 0; i < length; i++, j++) {
		const char symbol_str = str[i];
		const char symbol_max = STR_MAX_UINT[j];
		if (atoi(&symbol_max) > atoi(&symbol_str))
			return true;		
	}

	return str[length - 1] == STR_MAX_UINT[9];
}

int DEC_String::operator-(DEC_String& obj)
{
	cout << "����������� ����� '���������� ������'. ��������� ���������� ��������� '-'" << endl;

	return atoi((const char*)str) - atoi((const char*)obj.str);
}