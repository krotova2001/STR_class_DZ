// здесь определены полностью конструкторы
// функции перегрузки и методы - только прототипы, а определения - в .срр - файле


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
			m_ptr = new int[len]; // выделяем память нужного размера
			for (int i = 0; i < len; i++)
				{
					m_ptr[i] = m.m_ptr[i]; // копируем по элементно
				}
		}
		else // либо если пусто - не копируем
		{
			m_ptr = nullptr;
		}
	}
	
	Array(Array&& c) // конструктор переноса
		noexcept
	{
		len = c.len;
		m_ptr = c.m_ptr;
		c.len = 0;
		c.m_ptr = nullptr;
	}


	// прототипы методов и перегруженных функций
	void Show();//вывод на экран
	void Init_random();//заполнение случайными числами
	void Init_user();//заполнения вручную пользователем
	Array Add(Array& a); // добавление элементов в массив
	void Append(int a); // присоединение в конец элемента
	int GetCount(); // вывод количества объектов
	
	friend Array operator+(Array a, Array c); // обычная перегрука внутри класса
	Array operator=(Array c);// обычная перегрука внутри класса. Вне класса ее написать нельзя, оказывается
	friend Array operator+(int a, Array b); // не обычная перегрузка вне класса для правого операнда

	~Array()
	{
		if (m_ptr !=nullptr)
		{
			delete[]m_ptr;
		}
	}
};

