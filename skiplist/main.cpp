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
		cout << "����1,���δ�ӡ�����ÿһ�У�" << endl;
		cout << "����2,�������в���ڵ�" << endl;
		cout << "����3,��ѯĳ���ڵ�" << endl;
		cout << "����4,ɾ��ĳ���ڵ�" << endl;
		cout << "����q�˳�����" << endl;
		cin >> choice;
		switch (choice)
		{
		case '1':
			//cout << "������Դ�㣺" << endl;
			sklist.show_list();
			break;
		case '2':
			double ik;
			cin >> ik;
			sklist.insert(ik);
			break;
		case '3':
			//cout << "������Ŀ��ڵ�ı��" << endl;
			double sk;
			cin >> sk;
			sklist.search(sk);
			break;
		case '4':
			double rk;
			cin >> rk;
			sklist.remove(rk);
			break;
		case 'q':cout << "��лʹ�ã�" << endl; return 0;
		default:
			cout << "invalid input!" << endl;
		}
	}

	return 0;
}