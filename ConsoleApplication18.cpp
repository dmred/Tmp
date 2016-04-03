// ConsoleApplication18.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

bool _home = false; //начало комментария
bool _end = false; // конец
int inner = 1; //порядковый номер функции
void output(char str[256])
{
	char outstr[256];
	char outbuf[256];
	int p = 256;
	if (strstr(str, "/**") != NULL)
	{
		_home = true;//вход в комментарий осуществлен
		_end = false;//выход из комментария не осуществлен
	}
	if ((_home == true) && (_end == false)) //внутри комментария
	{
		if (strstr(str, "\\func") != NULL) //наличие /func
		{

			for (int j = 0; j < 256; j++)
			{
				outbuf[j] = *(strstr(str, "func") + 5+j);// 5 - длина "/func"
			}
			p = strcspn(outbuf, ")");//количество символов до вхождения ")" в outbuf
			for (int j = p + 1; j < 256; j++)
			{
				outbuf[j] = 0;
			}
			cout << endl;
			cout << inner << ") " << outbuf << endl;//вывод комментария
			inner++;
			cout << endl;
		}
	}
	if (strstr(str, "*/") != NULL)
	{
		_end = true;//выход из текущего комментария
	}
}





int main()
{
	setlocale(LC_CTYPE, "rus");
	char path[256];
	char buffstr[256];
	fstream fin;
	cout << "Введите имя файла" << endl;
	cin >> path;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "                           Вывод комментариев:" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	fin.open(path, ios::in);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin.getline(buffstr, 256);
			output(buffstr);
		}
	}
	system("pause");
	fin.close();
	return 0;
}
