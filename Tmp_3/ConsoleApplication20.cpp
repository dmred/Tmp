// ConsoleApplication20.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;

/** \func struct stack */
struct stack
{
	int value;
	struct stack *next;
};

stack *st;

/** \func void push(int newvalue) */
void push(int newvalue)
{
	stack *node = new stack;
	if (st == 0)
	{
		node->value = newvalue;
		node->next = 0;
		st = node;
	}
	else
	{
		node->value = newvalue;
		node->next = st;
		st = node;
	}
}

/** \func int top() */
int top()
{
	return st->value;
}

/** \func void del() */
void del()
{
	if (st == NULL)
	{
		cout << "стек пустой" << endl;
	}
	else
	{
		st = st->next;
	}

}

/** \func int main() */
int main()
{
	setlocale(LC_CTYPE, "rus");
	int num, val;
	int m = 0;
	int exit[20];
	char str[64];
	char *act = new char[64];
	char strvyvod[256];
	cout << "стэк :" << endl;
	cout << "вход :" << endl;
	fstream fin;
	fin.open("text.txt", ios::in);
	if (fin.is_open())
	{
		fin.getline(str, 64);
		cout << str << endl;;
		num = atoi(str);
		for (int i = 0; i < num; i++)
		{
			fin.getline(str, 64);
			cout << str << endl;
			act = strtok(str, " ");
			if (!strcmp(act, "add"))
			{
				val = atoi(strtok(NULL, " "));
				push(val);
			}
			if (!strcmp(str, "del"))
			{
				del();
			}
			if (!strcmp(str, "get"))
			{
				exit[m] = top();
				m++;
			}
		}
	}
	cout << "Выход :" << endl;
	for (int i = 0; i < m; i++)
		cout << exit[i] << endl;
	system("pause");
	return 0;
}