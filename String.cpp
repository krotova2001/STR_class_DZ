//здесь определения перегрузок и функций

#include "String.h"
#include <iostream>
int String::count = 0;

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

String String::operator+(String c) // перегрузка оператора +. Как функция Add
{
	char* new_str = nullptr;
	if ((len+c.len)>0) // если строки объектов не пустые, создаем временную строку, куда записываем по очереди исходные
	{
		new_str = new char[len + c.len + 1]; // новая временная строка общей длины
		new_str[0] = '\0';
		if (str != nullptr)
			strcat_s(new_str, len + c.len + 1, str);
		if (c.str != nullptr)
			strcat_s(new_str, len + c.len + 1, c.str);
	}

	if (str != nullptr) // если память узказателя на строку была занята - освобождаем
	{
		delete[]str;
	}

	str = new_str; // записываем указатель
	len = len + c.len; // и длину
	return *this;
}

String String::operator=(String c) // перегрузка оператора =, по сути - функция копирования
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


