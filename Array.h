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
	
	void Show();//вывод на экран
	void Init_random();//заполнение случайными числами
	void Init_user();//заполнения вручную пользователем
	Array Add(Array a); // добавление элементов в массив
	void Append(int a); // присоединение в конец элемента


	~Array()
	{
		if (m_ptr !=nullptr)
		{
			delete[]m_ptr;
		}
	}
};

