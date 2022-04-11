#pragma once
#include <iostream>
using namespace std;

class String // �������� ����� � ������� ��������� ��� ������ �� ��������
{
	int len; // ����� ������
	char* str; // ��������� �� ������ ������
	int static count; // ������� ��������� �����

public:
	String() :len{ 0 }, str{ nullptr }{ count++;} // ����������� �� ��������� ��� ����������, ��� �������� ������� ����������� ������� �� 1
	String(const char* input) :String() // ����������� ����������� ������, � �������������� ������������ �� ���������
	{
		if (input != nullptr) // ���� ������� ������ ��������
		{
			len = strlen(input); // ���������� ����� ������
			str = new char[len + 1]; // �������� ������ ��� �������� ������
			strcpy_s(str, len + 1, input); // ���������� ������
		}
	}
	
	String(const String& c) // ����������� �����������
	{
		count++; // ����������� �������
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

	String(String&& c) // ����������� ��������
		noexcept 
	{
		len = c.len;
		str = c.str;
		c.len = 0;
		c.str = nullptr;

	}

	~String() //����������
	{
		if (str != nullptr)
		{
			delete[]str;
		}
	}

	//������� ������ � ����������� ������
	void Show();
	String& Add(String& c);

	//���������� ����������
	String operator+(String c);
	String operator=(String c);
	String& operator()(const char* c); // ���������� ��������� ()
	friend istream& operator>>(istream& t, const String& m); // ���������� �����
	friend ostream& operator<<(ostream& t, const String& c); // ���������� ������



};

