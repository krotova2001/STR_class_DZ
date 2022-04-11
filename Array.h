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
			for (int i = 0; i < len; i++)
				{
					m_ptr[i] = m.m_ptr[i]; // �������� �� ���������
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

