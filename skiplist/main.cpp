#include <iostream>
#include "skiplist.h"
using namespace std;
int main()
{
	srand(time(0));
	
	skiplist sklist;
	/*sklist.insert(5);
	sklist.insert(78.6);
	sklist.insert(3.7);

	sklist.search(3.7);
	sklist.search(3.8);
	sklist.show_list();*/

	while (true)
	{
		char choice;
		cout << "输入1,依次打印跳表的每一行：" << endl;
		cout << "输入2,向跳表中插入节点" << endl;
		cout << "输入3,查询某个节点" << endl;
		cout << "输入4,删除某个节点" << endl;
		cout << "输入q退出程序：" << endl;
		cin >> choice;
		switch (choice)
		{
		case '1':
			//cout << "请输入源点：" << endl;
			sklist.show_list();
			break;
		case '2':
			double ik;
			cin >> ik;
			sklist.insert(ik);
			break;
		case '3':
			//cout << "请输入目标节点的标号" << endl;
			double sk;
			cin >> sk;
			sklist.search(sk);
			break;
		case '4':
			double rk;
			cin >> rk;
			sklist.remove(rk);
			break;
		case 'q':cout << "感谢使用！" << endl; return 0;
		default:
			cout << "invalid input!" << endl;
		}
	}

	return 0;
}