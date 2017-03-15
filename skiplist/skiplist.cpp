#include "skiplist.h"

skiplist::~skiplist()
{
	skipnode * p = head;
	skipnode * q;
	while (p)                                        //依次删除每个节点
	{
		q = p;
		p = p->next_nodes[0];
		delete q;
	}
}

skipnode * skiplist::search(double k)
{
	cout << "跳表的内容：" << endl;
	show_list();
	skipnode * p, *q = nullptr;
	p = head;
	int i;
	for (i = num_floor; i >= 0; i--)                   //找到每一层的插入位置
	{
		cout << "在第" << i << "层查找的过程";
		while ((q = p->next_nodes[i]) && q->key < k)        //节点p值始终小于k，q为节点p这一层上的下一个节点
		{
			p = q;
			cout << p->key << "   ";
		}
		cout << endl;
		if (q && q->key == k)                         //一轮查找结束后检查查找是否成功
		{
			cout << "查找成功! "<< k << "所在节点存在的最高层数是：" << i << endl << endl;
			return q;
		}
	}
	cout << "查找失败！" << endl << endl;
	return nullptr;
}

skipnode * position[MAX_FLOOR];
bool skiplist::insert(double k)
{
	int i, num_f = random_floor();                      //num_f为随机生成的要插入节点的层数
	skipnode * node_insert = new skipnode(k);
	if (!node_insert) return false;
	if (num_f > num_floor)                              //插入节点的层数大于跳表当前层数,直接插入到head后边
	{
		for (i = num_floor + 1; i <= num_f; i++)
		{
			position[i] = head;
		}
	}
	skipnode * p = head;
	skipnode * q;
	for (i = num_floor ; i >= 0; i--)                   //找到每一层的插入位置
	{
		while ((q = p->next_nodes[i]) && q->key < k)        //节点p值始终小于k，q为节点p这一层上的下一个节点
		{
			p = q;
		}
		position[i] = p;
	}                                                       //for循环结束后p指向第零层节点应该插入的位置
	if (num_f > num_floor)                                  //更新跳表层数
	{
		num_floor = num_f;
	}
	for (i = 0; i <= num_f; i++)
	{
		node_insert->next_nodes[i] = position[i]->next_nodes[i];
		position[i]->next_nodes[i] = node_insert;
	}
	
	return true;
}

skipnode * remove_position[MAX_FLOOR];
bool skiplist::remove(double k)
{
	cout << "删除前跳表的内容：" << endl;
	show_list();

	int i;
	for (i = 0; i < MAX_FLOOR; i++)
	{
		remove_position[i] = nullptr;
	}
	skipnode * p, *q = nullptr;
	p = head;
	/*查找的过程*/
	for (i = num_floor; i >= 0; i--)                   //找到节点在每一层的位置
	{
		//cout << "在第" << i << "层查找的过程";
		while ((q = p->next_nodes[i]) && q->key < k)        //节点p值始终小于k，q为节点p这一层上的下一个节点
		{
			p = q;
		}
		remove_position[i] = p;
	}
	if (!q || (q->key != k))                             //跳表中没有k
	{
		cout << "删除失败，跳表中没有该元素" << endl;
		return false;
	}

	/*删除的过程*/
	for (i = num_floor; i >= 0; i--)                   //找到节点在每一层的位置
	{
		if (remove_position[i]->next_nodes[i]->key == k)
		{
			remove_position[i]->next_nodes[i] = q->next_nodes[i];
		}
		if (!head->next_nodes[i])
		{
			num_floor--;
		}
	}

	delete q;
	cout << "删除后跳表的内容：" << endl;
	show_list();
	return true;
}

void skiplist::show_list()
{
	if (!(head->next_nodes[0]))
	{
		cout << "Skiplist is empty!" << endl;
		return;
	}
	skipnode * p;
	skipnode * q;
	int i;
	for (i = 0; i <= num_floor; i++, cout << endl)
	{
		p = head;
		cout << "第" << i << "层：" << "	";
		while (q = p->next_nodes[i])        //遍历第i层
		{
			cout << "   " << q->key  << "   ";
			p = q;
		}
		
	}
}
