//����� ����������� ���������� � �������

#include "String.h"
#include <iostream>
int String::count = 0;

void String::Show() // ������� ������ �� �����
{
	cout << str;
}

String& String::Add(String & c) // ������� ���������� ������� � �������
{
	char* tstr = nullptr;
	if (len + c.len > 0)
	{
		tstr = new char[len + c.len + 1];
		tstr[0] = '\0';
		if (str != nullptr)
			strcat_s(tstr, len + c.len + 1, str);
		if (c.str != nullptr)
			strcat_s(tstr, len + c.len + 1, c.str);
	}
	if (str != nullptr)
	{
		delete[]str;
	}
	str = tstr;
	len = len + c.len;

	return *this;
}

String String::operator+(String c) // ���������� ��������� +. ��� ������� Add
{
	char* new_str = nullptr;
	if ((len+c.len)>0) // ���� ������ �������� �� ������, ������� ��������� ������, ���� ���������� �� ������� ��������
	{
		new_str = new char[len + c.len + 1]; // ����� ��������� ������ ����� �����
		new_str[0] = '\0';
		if (str != nullptr)
			strcat_s(new_str, len + c.len + 1, str);
		if (c.str != nullptr)
			strcat_s(new_str, len + c.len + 1, c.str);
	}

	if (str != nullptr) // ���� ������ ���������� �� ������ ���� ������ - �����������
	{
		delete[]str;
	}

	str = new_str; // ���������� ���������
	len = len + c.len; // � �����
	return *this;
}

String String::operator=(String c) // ���������� ��������� =, �� ���� - ������� �����������
{
		if (this != &c)
		{
			if (str != nullptr)
			{
				delete[]str;
				len = 0;
				str = nullptr;
			}
			if (c.str != nullptr)
			{
				len = c.len;
				str = new char[len + 1];
				strcpy_s(str, len + 1, c.str);
			}
		}
	return *this;
}

String& String::operator()(const char* c)
{
	if (str != nullptr)
	{
		delete[]str;
	}
	len = 0;
	str = nullptr;
	if (c != nullptr)
	{
		len = strlen(c);
		str = new char[len + 1];
		strcpy_s(str, len + 1, c);
	}
	return *this;
}

int String::Get_count()
{
	return count;
}

ostream& operator<<(ostream& t, const String& c)
{
	{
		if (c.len > 0)
		{
			t << c.str;
		}

		else
		{
			t << "Empty";
		}

		return t;
	}
}


