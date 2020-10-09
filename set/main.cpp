#include<iostream>
#include<string>
#include<conio.h>
#include"set.h"
#include"CUI.h"
#include <windows.h>
#define x1 45
#define y1 10
#define y2 67
bool ban(char val)
{
	if ('a' <= val && val <= 'z')
		return true;
	return false;
}
class Object
{
private:
	static bool ban(char val)
	{
		if ('a' <= val && val <= 'z')
			return true;
		return false;
	}

	void first()
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
		str = "-erase       -size         -quit  ";
		print(str);
		str = "-com         -insert       -ls    ";
		print(str);
		str = "-delete      -help         -find  ";
		print(str);
		str = "-subset      -back                ";
		print(str);
		std::cout << std::endl << std::endl;
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

	void second()
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
		str = "5. back               6. exit ";
		print(str);
	}

	void print(std::string str)
	{
		int L = (120 - str.size()) / 2;
		for (int i = 1; i <= L; i++)
		{
			std::cout << " ";
		}
		std::cout << str << std::endl;
	}

	void change(int& x,int& y)
	{
		int ch;
		bool flag = true;
		HANDLE   hCon;//定义一个句柄 
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);   //获得输出设备的句柄 
		COORD   setps; //定义结构体变量 
		setps.X = x1;
		setps.Y = y1;
		int xx = 0, yy = 0;
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
				yy = (yy + 2) % 3;
				setps.Y = y1 + yy;
				break;
			case 80:
				yy = (yy + 1) % 3;
				setps.Y = y1 + yy;
				break;
			case 75:
				xx = (xx + 22) % 44;
				setps.X = x1 + xx;
				break;
			case 77:
				xx = (xx + 22) %44;
				setps.X = x1 + xx;
				break;
			case 49:
				setps.Y = y1;
				setps.X = x1;
				flag = false;
				break;
			case 50:
				setps.Y = y1;
				setps.X = x1+22;
				flag = false;
				break;
			case 51:
				setps.Y = y1+1;
				setps.X = x1;
				flag = false;
				break;
			case 52:
				setps.Y = y1+1;
				setps.X = x1+22;
				flag = false;
				break;
			case 53:
				setps.Y = y1 + 2;
				setps.X = x1;
				flag = false;
				break;
			case 54:
				setps.Y = y1 + 2;
				setps.X = x1 + 22;
				flag = false;
				break;
			default:
				break;
			}
		}
		y = setps.Y;
		x = setps.X;
	}

public:
	void run()
	{
		bool one = true;
		bool flag = true;
		while (flag)
		{
			if (one)
			{
				first();
				getchar();
			}
			system("cls");
			second();
			int x = 0, y = 0;
			change(x, y);
			system("cls");
			if (x == x1 && y == y1)
			{
				CUI<int>a;
				flag = a.run();
				one = false;
			}
			else if (x == x1 + 22 && y == y1)
			{
				CUI<float>a;
				flag = a.run();
				one = false;
			}
			else if (x == x1 && y == y1 + 1)
			{
				CUI<double>a;
				flag = a.run();
				one = false;
			}
			else if (x == x1 + 22 && y == y1 + 1)
			{
				CUI<char>a(ban);
				flag = a.run();
				one = false;
			}
			else if(x == x1 +22 && y == y1 + 2)
			{
				flag = false;
			}
			else
			{
				one = true;
			}
		}
	}
};
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

int main()
{
	Object m;
	m.run();
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