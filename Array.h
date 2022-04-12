// ����� ���������� ��������� ������������
// ������� ���������� � ������ - ������ ���������, � ����������� - � .��� - �����


#pragma once
class Array
{
	int len; // ����� �������
	int* m_ptr; //��������� �� ������ �������
	int static count; // ������� ��������� ��������
public:
	Array() :len{ 0 }, m_ptr{ nullptr } { count++; }; // ����������� �� ���������
	Array(int dlina):Array() // ����������� � ������� �������
	{
		len = dlina; // ���������� ������
		m_ptr = new int[len]; // �������� ������
	}
	
	Array(const Array& m) // ����������� �����������
	{
		count++; // ����������� �������
		len = m.len; // �������� �����
		if (m.m_ptr!=nullptr)
		{
			m_ptr = new int[len]; // �������� ������ ������� �������
			for (int i = 0; i < len; i++)
				{
					m_ptr[i] = m.m_ptr[i]; // �������� �� ���������
				}
		}
		else // ���� ���� ����� - �� ��������
		{
			m_ptr = nullptr;
		}
	}
	
	Array(Array&& c) // ����������� ��������
		noexcept
	{
		len = c.len;
		m_ptr = c.m_ptr;
		c.len = 0;
		c.m_ptr = nullptr;
	}


	// ��������� ������� � ������������� �������
	void Show();//����� �� �����
	void Init_random();//���������� ���������� �������
	void Init_user();//���������� ������� �������������
	Array Add(Array& a); // ���������� ��������� � ������
	void Append(int a); // ������������� � ����� ��������
	int GetCount(); // ����� ���������� ��������
	
	friend Array operator+(Array a, Array c); // ������� ��������� ������ ������
	Array operator=(Array c);// ������� ��������� ������ ������. ��� ������ �� �������� ������, �����������
	friend Array operator+(int a, Array b); // �� ������� ���������� ��� ������ ��� ������� ��������

	~Array()
	{
		if (m_ptr !=nullptr)
		{
			delete[]m_ptr;
		}
	}
};

