#include<iostream>
#include<string>
#include<conio.h>
#include"set.h"
#include"CUI.h"

struct person
{
	double age;
	char name;
};

bool repeat(person x, person y)
{
	return x.age == y.age;
}

bool cmp(person x, person y)
{
	return x.age < y.age;
}

void show(person x)
{
	std::cout << x.age << std::endl;
}
void print(std::string str)
{
	int L = (120 - str.size())/2;
	for (int i = 1; i <= L; i++)
	{
		std::cout << " ";
	}
	std::cout << str << std::endl;
}
void fun()
{
	for (int i = 1; i <= 120; i++)
	{
		std::cout << "*";
	}
	std::cout << std::endl << std::endl << std::endl;
	std::string str = "��Ŀ��Ա";
	print(str);
	str = "ţ��Ȩ ��˼� ����԰ ������ ��� ����";
	print(str);
	std::cout << std::endl << std::endl << std::endl;
	str = "����";
	print(str);
	str = "1. ͨ��ʹ�ò���������Զ�char��int��float��double�ļ��ϣ����л������";
	print(str);
	str = "2. ͨ�������޸ģ����Զ��������ͽ��л������                            ";
	print(str);
	std::cout << std::endl << std::endl << std::endl;
	str = "��������";
	print(str);
	str = "-clean       -assign       -show  ";
	print(str);
	str = "-erase       -size         -quit()";
	print(str);
	str = "-com         -insert       -ls    ";
	print(str);
	str = "-delete      -help                ";
	print(str);
	std::cout << std::endl << std::endl << std::endl;
	str = "���������ʹ��";
	print(str);
	str = "1. ʹ��help --all�ɲ鿴���������˵��                                               ";
	print(str);
	str = "2. ʹ��help - <name>�ɲ鿴name����, ����ʹ��help -clean������Բ鿴clean�����˵��";
	print(str);
	std::cout << std::endl << std::endl;
	str = "���������ʼʹ��������";
	std::cout << str << std::endl;
	for (int i = 1; i <= 120; i++)
	{
		std::cout << "*";
	}
	std::cout << std::endl;
}
int main()
{
	fun();
	_getch();
	system("cls");
	CUI<float>a;
	a.run();
	/*int x, y;
	std::cin >> x >> y;
	system("cls");
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	getchar();
	getchar();*/
	/*set<person>a(NULL,cmp,NULL);
	for (int i = 1; i <= 10; i++)
	{
		person p;
		p.age = i % 2;
		a.insert(p);
	}
	a.show(show);*/
	/*set<int>a;
	a.insert(3);
	a.insert(2);
	a.insert(1);
	a.insert(5);
	a.insert(4);
	a.insert(7);
	a.insert(6);
	set<int>b;
	b.insert(3);
	b.insert(2);
	set<int>c;
	c.insert(5);
	c.insert(4);
	set<int>f;
	f.insert(7);
	set<int>d;
	d = a - b + f ^ c;
	d.show();*/
	/*while (true)
	{
		std::cout << ">>>>";
		std::string str;
		getline(std::cin, str, '\n');
		std::cout << str << std::endl;
	}*/
	return 0;
}