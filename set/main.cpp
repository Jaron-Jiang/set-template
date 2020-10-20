#include<iostream>
#include<string>
#include<conio.h>
#include"set.h"
#include"CUI.h"
#include <windows.h>
#define x1 45
#define y1 10
bool ban(char val)
{
	if ('a' <= val && val <= 'z')
		return true;
	return false;
}

class Object
{
private:
	//内置重复判断函数
	static bool repeat(std::string a,std::string b)
	{
		return a == b;

	}

	//用于比较int类型的大小
	static bool cmp1(std::string a, std::string b)
	{
		if (a[0] == '-'&&b[0] != '-')
		{
			return true;
		}
		if (b[0] == '-'&&a[0] != '-')
		{
			return false;
		}
		if (a.size() < b.size())
		{
			return a[0] == '-' ? false : true;
		}
		else if (a.size() > b.size())
		{
			return a[0] == '-' ? true : false;
		}
		unsigned int index = 0;
		while (index < a.size())
		{
			if (a[index] < b[index])
			{
				return a[0] == '-' ? false : true;
			}	
			else if (a[index] > b[index])
			{
				return a[0] == '-' ? true : false;
			}
			index++;
		}
		return a[0] == '-' ? true : false;
	}

	//用于比较double类型的大小
	static bool cmp2(std::string a, std::string b)
	{
		if (a[0] == '-'&&b[0] != '-')
		{
			return true;
		}
		if (b[0] == '-'&&a[0] != '-')
		{
			return false;
		}
		unsigned int num1 = 0, num2 = 0;
		while (num1 < a.size()&&a[num1] != '.')
		{
			num1++;
		}
		while (num2 < b.size() && b[num2] != '.')
		{
			num2++;
		}
		if (num1 != num2)
		{
			if (a[0] == '-')
			{
				return num2 < num1;
			}
			return num1 < num2;
		}
		num1 = 0;
		while (true)
		{
			if (a[num1] != b[num1])
			{
				if (a[0] == '-')
				{
					return b[num1] < a[num1];
				}
				else
				{
					return a[num1] < b[num1];
				}
			}
			num1++;
			if (num1 >= a.size())
			{
				return a[0] == '-' ? false : true;
			}
			if (num2 >= b.size())
			{
				return a[0] == '-' ? true : false;
			}
				
		}
		return a[0] == '-' ? true : false;
	}

	//用于比较char和string类型的大小
	static bool cmp3(std::string a, std::string b)
	{
		return a < b;

	}

	//用第一界面的展示
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
		str = "1. 通过使用操作命令，可以对char，int，double，string的集合，进行混合表达式运算";
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

	//用于第二个界面的展示
	void second()
	{
		for (int i = 1; i <= 9; i++)
		{
			printf("\n");
		}
		std::string str = "请选择要使用的那种数据类型的集合";
		print(str);
		str = "1. int               2. double";
		print(str);
		str = "3. char              4. string";
		print(str);
		str = "5. back              6. exit  "; 
		print(str);
	}

	//打印函数
	void print(std::string str)
	{
		int L = (120 - str.size()) / 2;
		for (int i = 1; i <= L; i++)
		{
			std::cout << " ";
		}
		std::cout << str << std::endl;
	}

	//控制光标,用于第二界面中数据类型的选取
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
				xx = (xx + 21) % 42;
				setps.X = x1 + xx;
				break;
			case 77:
				xx = (xx + 21) %42;
				setps.X = x1 + xx;
				break;
			case 49:
				setps.Y = y1;
				setps.X = x1;
				flag = false;
				break;
			case 50:
				setps.Y = y1;
				setps.X = x1+21;
				flag = false;
				break;
			case 51:
				setps.Y = y1+1;
				setps.X = x1;
				flag = false;
				break;
			case 52:
				setps.Y = y1+1;
				setps.X = x1+21;
				flag = false;
				break;
			case 53:
				setps.Y = y1 + 2;
				setps.X = x1;
				flag = false;
				break;
			case 54:
				setps.Y = y1 + 2;
				setps.X = x1 + 21;
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
	//该类的运行函数，相当于main函数
	void run()
	{
		bool one = true;
		bool flag = true;
		while (flag)
		{
			if (one)
			{
				first();
				if (_getch() == 27)
				{
					break;
				}
			}
			system("cls");
			second();
			int x = 0, y = 0;
			change(x, y);
			system("cls");
			
			if (x == x1 && y == y1)
			{
				CUI<std::string>a(repeat,cmp1);
				flag = a.run("int");
				one = false;
			}
			else if (x == x1 + 21 && y == y1)
			{
				CUI<std::string>a(repeat,cmp2);
				flag = a.run("double");
				one = false;
			}
			else if (x == x1 && y == y1 + 1)
			{
				CUI<std::string>a(repeat,cmp3);
				flag = a.run("char");
				one = false;
			}
			else if (x == x1 + 21 && y == y1 + 1)
			{
				CUI<std::string>a(repeat,cmp3);
				flag = a.run("string");
				one = false;
			}
			else if(x == x1 +21 && y == y1 + 2)
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
