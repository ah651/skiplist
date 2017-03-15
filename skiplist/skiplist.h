#pragma once
#include <iostream>
#include <time.h>
#include <stdlib.h>
#define MAX_FLOOR 12                   //��������12��

using namespace std;



struct skipnode
{
	double key;
	skipnode * next_nodes[MAX_FLOOR];

	skipnode(double k = -1) : key(k)
	{
		int i;
		for (i = 0; i < MAX_FLOOR; i++)
		{
			next_nodes[i] = nullptr;
		}
	}
};

/*�����սڵ�ؼ���ֵ�������У�head�ؼ���ֵΪ-1*/
class skiplist
{
public:
	skiplist()
	{
		num_floor = 0;
		head = new skipnode;
	}
	~skiplist();
	skipnode * search(double k);
	bool insert(double k);
	bool remove(double k);
	void show_list();
private:
	skipnode * head;
	int num_floor;
	int random_floor()
	{
		return rand() % MAX_FLOOR;
	}
};