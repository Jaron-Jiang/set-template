#include<iostream>
#include<string>
#include<conio.h>
#include"set.h"
#include"CUI.h"
#include <windows.h>
#define x1 10
#define y1 45
#define x2 11
#define y2 67
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
	str = "1. 通过使用操作命令，可以对char，int，float，double的集合，进行混合表达式运算";
	print(str);
	str = "2. 通过代码修改，可以对任意类型进行混合运算                                  ";
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

bool ban(char val)
{
	if ('a' <= val && val <= 'z')
		return true;
	return false;
}
void fun1()
{
	for (int i = 1; i <= 9; i++)
	{
		printf("\n");
	}
	std::string str = "请选择要使用的那种数据类型的集合";
	print(str);
	str = "1. int                2. float";
	print(str);
	str = "3. double             4. char ";
	print(str);
}
int main()
{
	system("color F0");
	fun();
	_getch();
	system("cls");
	fun1();
	int ch;
	bool flag = true;
	HANDLE   hCon;//定义一个句柄 
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);   //获得输出设备的句柄 
	COORD   setps; //定义结构体变量 
	setps.X = y1;
	setps.Y = x1;
	while (flag)
	{
		SetConsoleCursorPosition(hCon, setps);
		ch = _getch();
		switch (ch)
		{
		case 13:
			flag = false;
			break;
		case 72:
			setps.Y = (setps.Y == x1 ? x2 : x1);
			break;
		case 80:
			setps.Y = (setps.Y == x1 ? x2 : x1);
			break;
		case 75:
			setps.X = (setps.X == y1 ? y2 : y1);
			break;
		case 77:
			setps.X = (setps.X == y1 ? y2 : y1);
			break;
		case 49:
			setps.Y = x1;
			setps.X = y1;
			flag = false;
			break;
		case 50:
			setps.Y = x1;
			setps.X = y2;
			flag = false;
			break;
		case 51:
			setps.Y = x2;
			setps.X = y1;
			flag = false;
			break;
		case 52:
			setps.Y = x2;
			setps.X = y2;
			flag = false;
			break;
		default:
			break;
		}
	}
	system("cls");
	if (setps.Y == x1 && setps.X == y1)
	{
		CUI<int>a;
		a.run();
	}
	else if (setps.Y == x1 && setps.X == y2)
	{
		CUI<float>a;
		a.run();
	}
	else if (setps.Y == x2 && setps.X == y1)
	{
		CUI<double>a;
		a.run();
	}
	else if (setps.Y == x2 && setps.X == y2)
	{
		CUI<char>a(ban);
		a.run();
	}
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