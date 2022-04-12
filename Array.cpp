#include "Array.h"
#include <iostream>

using namespace std;

int Array::count = 0;

void Array::Show()
{
	if (m_ptr != nullptr) // �������� ��� �� ������
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

Array Array::Add(Array& a) // ������� ������� ���� ��������
{
	int* m_temp = nullptr; // ����� ���������
	if ((len + a.len) > 0) // ���� ������� �� ������
	{
		m_temp = new int[len + a.len];
		if (m_ptr != nullptr) // ���� �������� ��������� �� ������ �� ������, �� ��������
		{
			for (int i = 0; i < len; i++)
			{
				m_temp[i] = m_ptr[i]; // �������� �� ��������� � ������
			}
		}
		if (a.m_ptr != nullptr) // ���� ��������� �� ������ ������ �� ������
		{
			for (int i = len, j=0; i < (len+a.len); i++, j++)
			{
				m_temp[i] = a.m_ptr[j]; // �������� � ����� ������� ������� �������� �������
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
	int* m_temp = nullptr; // ����� ���������
	if (m_ptr != nullptr) // �������� ��� ������ ����������
	{
		m_temp = new int[len + 1]; // �������� ������ �� 1 ������
		for (int i = 0; i < len; i++)
		{
			m_temp[i] = m_ptr[i]; // �������� �� ��������� � ������
		}
		m_temp[len] = a; // ���������� ����� ������� � �����
	}
	if (m_ptr != nullptr)
	{
		delete[]m_ptr; // ����������� ������ ������
	}
	m_ptr = m_temp; // ���������� ����� ��������� � ������
	len++; // ����� �����������
}

int Array::GetCount() // �������� ������� ������� ��������
{
	return count;
}



Array Array::operator=(Array c) // ��� ��� ��������� ������� ����������� � ��� ���, ������� �� �����
{
	if (this != &c) // ���� �������� �� ��������� �� ���� � ��� �� ������, �� ��������
	{
		if (m_ptr != nullptr) // ���� ��������� ����� - �������
		{
			delete[]m_ptr;
			len = 0;
			m_ptr = nullptr;
		}
		if (c.m_ptr != nullptr) // ���� ��, ��� �������� - �� ������, �� ��������
		{
			len = c.len;
			m_ptr = new int[len];
			for (int i = 0; i < len; i++)
			{
				m_ptr[i] = c.m_ptr[i]; // �������� �� ��������� � ������
			}
		}
	}
	return *this;
}


//������������� ������� ��� ������ Array

Array operator+(Array a,Array c) // ����� ����� �������� ����������, ��� ��� ����� ���������� �� ��� �������� ����
{
	a.Add(c);
	return a;
}

Array operator+(int a, Array b) // ������������� ������� ���������� ��������� + ���� ����� ����������, ��� ��� �������� ����� �� ��� �������
{
	b.Append(a);
	return b;
}
