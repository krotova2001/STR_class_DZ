#include "String.h"

void String::Show() // функция вывода на экран
{
	cout << str;
}

String& String::Add(String & c) // функция добавления объекта к объекту
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

String String::operator+(String c)
{
	
	return *this;
}

String String::operator=(String c)
{
	return *this;
}

String& String::operator()(const char* c)
{
	if (str != nullptr)
	{
		delete[]str;
	}
	len = 0;
	c = nullptr;
	if (str != nullptr)
	{
		len = strlen(c);
		str = new char[len + 1];
		strcpy_s(str, len + 1, c);
	}
	return *this;
}

istream& operator>>(istream& t, const String& m)
{
	// TODO: вставьте здесь оператор return
}

ostream& operator<<(ostream& t, const String& c)
{
	// TODO: вставьте здесь оператор return
}
