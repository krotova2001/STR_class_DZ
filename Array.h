#pragma once
class Array
{
	int len; // длина массива
	int* m_ptr; //указатель на начало массива
	int static count; // счетчик созданных массивов
public:
	Array() :len{ 0 }, m_ptr{ nullptr } { count++; }; // конструктор по умолчанию
	Array(int dlina):Array() // конструктор с длинной массива
	{
		len = dlina; // определяем длинну
		m_ptr = new int[len]; // выделяем память
	}
	
	Array(const Array& m) // конструктор копирования
	{
		count++; // увеличиваем счетчик
		len = m.len; // копируем длину
		if (m.m_ptr!=nullptr)
		{
			for (int i = 0; i < len; i++)
				{
					m_ptr[i] = m.m_ptr[i]; // копируем по элементно
				}
		}
		else
		{
			m_ptr = nullptr;
		}
	}
	
	~Array()
	{
		if (m_ptr !=nullptr)
		{
			delete[]m_ptr;
		}
	}
};

