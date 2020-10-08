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
	std::string str = "项目成员";
	print(str);
	str = "牛振权 余思睿 吴松园 廖明月 熊睿杰 蒋杰";
	print(str);
	std::cout << std::endl << std::endl << std::endl;
	str = "功能";
	print(str);
	str = "1. 通过使用操作命令，可以对char，int，float，double的集合，进行混合运算";
	print(str);
	str = "2. 通过代码修改，可以对任意类型进行混合运算                            ";
	print(str);
	std::cout << std::endl << std::endl << std::endl;
	str = "操作命令";
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
	str = "操作命令的使用";
	print(str);
	str = "1. 使用help --all可查看所有命令的说明                                               ";
	print(str);
	str = "2. 使用help - <name>可查看name命令, 例如使用help -clean命令，可以查看clean命令的说明";
	print(str);
	std::cout << std::endl << std::endl;
	str = "按任意键开始使用命令行";
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