// ConsoleApplication23.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//

#include "stdafx.h"
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

/** \func struct Node */
struct Node //îïèñàíèå óçëà ñïèñêà
{
	int data; //èíôîðìàöèîííîå ïîëå
	Node *next; //óêàçàòåëü íà ñëåäóþùèé ýëåìåíò
};

/** \func struct Queue */
struct Queue //îïèñàíèå î÷åðåäè
{
	int size; //ñ÷åò÷èê ðàçìåðà î÷åðåäè
	Node *first; //óêàçàòåëü íà íà÷àëî î÷åðåäè
	Node *last; //óêàçàòåëü íà êîíåö î÷åðåäè
};

/** \func void Create(Queue *_queue) */
void Create(Queue *_queue) //ñîçäàíèå î÷åðåäè
{
	_queue->first = new Node;
	_queue->first->next = NULL;
	_queue->last = _queue->first;
	_queue->size = 0;
}

/** \func int Top(Queue *_queue) */
int Top(Queue *_queue)
{
	return _queue->first->next->data;
}

/** \func void Add(Queue *_queue, int newvalue) */
void Add(Queue *_queue, int newvalue) //äîáàâëåíèå ýëåìåíòà
{
	_queue->last->next = new Node;
	_queue->last = _queue->last->next;
	_queue->last->data = newvalue; //äîáàâëåíèå ýëåìåíòà â êîíåö
	_queue->last->next = NULL; //îáíóëåíèå óêàçàòåëÿ íà ñëåäóþùèé ýëåìåíò
	_queue->size++;
}

/** \func void Delete(Queue *_queue) */
void Delete(Queue *_queue)
{
	_queue->first = _queue->first->next; //ñìåùåíèå óêàçàòåëÿ
	_queue->size--;
}

/** \func int main() */
int main()
{
	setlocale(LC_CTYPE, "rus");
	int num, val, m = 0;
	int exit[20];
	char str[64];
	char *act = new char[64];
	char strvyvod[256];
	Queue Q;
	Create(&Q);
	cout << "Î÷åðåäü :" << endl;
	cout << "Âõîä :" << endl;
	fstream fin;
	fin.open("text.txt", ios::in);
	if (fin.is_open())
	{
		fin.getline(str, 64);
		cout << str << endl;
		num = atoi(str);
		for (int i = 0; i < num; i++)
		{
			fin.getline(str, 64);
			cout << str << endl;
			act = strtok(str, " ");
			if (!strcmp(act, "add"))
			{
				val = atoi(strtok(NULL, " "));
				Add(&Q, val);
			}
			if (!strcmp(str, "del"))
			{
				Delete(&Q);
			}
			if (!strcmp(str, "get"))
			{
				exit[m] = Top(&Q);
				m++;
			}
		}
	}
	fin.close();
	cout << endl;
	cout << "âûõîä :" << endl;
	for (int i = 0; i < m; i++)
		cout << exit[i] << endl;
	system("pause");
	return 0;
	return 0;
}
