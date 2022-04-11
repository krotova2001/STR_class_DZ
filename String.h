#pragma once
#include <iostream>
using namespace std;

class String // создадим класс с простым названием для работы со строками
{
	int len; // длина строки
	char* str; // указатель на начало строки
	int static count; // считчик созданных строк

public:
	String() :len{ 0 }, str{ nullptr }{ count++;} // конструктор по умолчанию без параметров, при создании объекта увеличиваем счетчик на 1
	String(const char* input) :String() // конструктор принимающий строку, с делегированием конструктору по умолчанию
	{
		if (input != nullptr) // если область памяти свободна
		{
			len = strlen(input); // записываем длина строки
			str = new char[len + 1]; // выделяем память для хранения строки
			strcpy_s(str, len + 1, input); // записываем строку
		}
	}
	
	String(const String& c) // конструктор копирования
	{
		count++; // увеличиваем счетчик
		len = c.len;
		if (c.str != nullptr)
		{
			str = new char[len + 1];
			strcpy_s(str, len + 1, c.str);
		}
		else
		{
			str = nullptr;
		}
	}

	String(String&& c) // конструктор переноса
		noexcept 
	{
		len = c.len;
		str = c.str;
		c.len = 0;
		c.str = nullptr;

	}

	~String() //деструктор
	{
		if (str != nullptr)
		{
			delete[]str;
		}
	}

	//функции вывода и добалвления строки
	void Show();
	String& Add(String& c);

	//перегрузки операторов
	String operator+(String c);
	String operator=(String c);
	String& operator()(const char* c); // перегрузка оператора ()
	friend istream& operator>>(istream& t, const String& m); // перегрузка ввода
	friend ostream& operator<<(ostream& t, const String& c); // перегрузка вывода



};

