#include "Array.h"
#include <iostream>

using namespace std;

int Array::count = 0;

void Array::Show()
{
	if (m_ptr != nullptr) // проверка что не пустой
	{
		for (int i = 0; i < len; i++)
		{
			cout << m_ptr[i] <<"; ";
		}
		cout << "\n";
	}
	else
	{
		cout << "Empty\n";
	}
}

void Array::Init_random()
{
	if (m_ptr != nullptr)
	{
		for (int i = 0; i < len; i++)
		{
			m_ptr[i] = rand()%100;
		}
	}
}

void Array::Init_user()
{
	if (m_ptr != nullptr)
	{
		for (int i = 0; i < len; i++)
		{
			int temp;
			cout << "Enter element " << i <<"\n";
			cin >> temp;
			m_ptr[i] = temp;
		}
	}
}

Array Array::Add(Array& a) // функция слияния двух массивов
{
	int* m_temp = nullptr; // новый указатель
	if ((len + a.len) > 0) // если массивы не пустые
	{
		m_temp = new int[len + a.len];
		if (m_ptr != nullptr) // если исходный указатель на массив не пустой, то копируем
		{
			for (int i = 0; i < len; i++)
			{
				m_temp[i] = m_ptr[i]; // копируем по элементам с начала
			}
		}
		if (a.m_ptr != nullptr) // если указатель на второй массив не пустой
		{
			for (int i = len, j=0; i < (len+a.len); i++, j++)
			{
				m_temp[i] = a.m_ptr[j]; // копируем в конец первого массива элементы второго
			}
		}
	}
	
	if (m_ptr != nullptr)
	{
		delete[]m_ptr;
	}
	
	m_ptr = m_temp;
	len =len+ a.len;
	return *this;
}

void Array::Append(int a)
{
	int* m_temp = nullptr; // новый указатель
	if (m_ptr != nullptr) // проверка что массив существует
	{
		m_temp = new int[len + 1]; // выделяем паямть на 1 больше
		for (int i = 0; i < len; i++)
		{
			m_temp[i] = m_ptr[i]; // копируем по элементам с начала
		}
		m_temp[len] = a; // Записываем новый элемент в конец
	}
	if (m_ptr != nullptr)
	{
		delete[]m_ptr; // освобождаем старую память
	}
	m_ptr = m_temp; // записываем новый указатель в старый
	len++; // длина увеличилась
}

int Array::GetCount() // показать сколько создали массивов
{
	return count;
}



Array Array::operator=(Array c) // так как отдельной функции копирования у нас нет, напишем ее здесь
{
	if (this != &c) // если операдны не указывают на один и тот же объект, то копируем
	{
		if (m_ptr != nullptr) // если указатель занят - очищаем
		{
			delete[]m_ptr;
			len = 0;
			m_ptr = nullptr;
		}
		if (c.m_ptr != nullptr) // если то, что копируем - не пустое, то копируем
		{
			len = c.len;
			m_ptr = new int[len];
			for (int i = 0; i < len; i++)
			{
				m_ptr[i] = c.m_ptr[i]; // копируем по элементам с начала
			}
		}
	}
	return *this;
}


//дружественные функции вне класса Array

Array operator+(Array a,Array c) // здесь можно написать сокращенно, так как метод добавления мы уже написали выше
{
	a.Add(c);
	return a;
}

Array operator+(int a, Array b) // дружественная функция перегрузки оператора + тоже пишем сокращенно, так как подобный метод мы уже создали
{
	b.Append(a);
	return b;
}
