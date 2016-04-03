// ConsoleApplication18.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//


#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

bool _home = false; //íà÷àëî êîììåíòàðèÿ
bool _end = false; // êîíåö
int inner = 1; //ïîðÿäêîâûé íîìåð ôóíêöèè
void output(char str[256])
{
	char outstr[256];
	char outbuf[256];
	int p = 256;
	if (strstr(str, "/**") != NULL)
	{
		_home = true;//âõîä â êîììåíòàðèé îñóùåñòâëåí
		_end = false;//âûõîä èç êîììåíòàðèÿ íå îñóùåñòâëåí
	}
	if ((_home == true) && (_end == false)) //âíóòðè êîììåíòàðèÿ
	{
		if (strstr(str, "\\func") != NULL) //íàëè÷èå /func
		{

			for (int j = 0; j < 256; j++)
			{
				outbuf[j] = *(strstr(str, "func") + 5+j);// 5 - äëèíà "/func"
			}
			p = strcspn(outbuf, ")");//êîëè÷åñòâî ñèìâîëîâ äî âõîæäåíèÿ ")" â outbuf
			for (int j = p + 1; j < 256; j++)
			{
				outbuf[j] = 0;
			}
			cout << endl;
			cout << inner << ") " << outbuf << endl;//âûâîä êîììåíòàðèÿ
			inner++;
			cout << endl;
		}
	}
	if (strstr(str, "*/") != NULL)
	{
		_end = true;//âûõîä èç òåêóùåãî êîììåíòàðèÿ
	}
}





int main()
{
	setlocale(LC_CTYPE, "rus");
	char path[256];
	char buffstr[256];
	fstream fin;
	cout << "Ââåäèòå èìÿ ôàéëà" << endl;
	cin >> path;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "                           Âûâîä êîììåíòàðèåâ:" << endl;
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
