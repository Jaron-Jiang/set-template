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
		std::string str = "��Ŀ��Ա";
		print(str);
		str = "ţ��Ȩ ��˼� ����԰ ������ ��� ����";
		print(str);
		std::cout << std::endl << std::endl << std::endl;
		str = "����";
		print(str);
		str = "1. ͨ��ʹ�ò���������Զ�char��int��float��double�ļ��ϣ����л�ϱ��ʽ����";
		print(str);
		str = "2. ͨ�������޸ģ����Զ��������ͽ��л������                                  ";
		print(str);
		std::cout << std::endl << std::endl << std::endl;
		str = "��������";
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

	void second()
	{
		for (int i = 1; i <= 9; i++)
		{
			printf("\n");
		}
		std::string str = "��ѡ��Ҫʹ�õ������������͵ļ���";
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
		HANDLE   hCon;//����һ����� 
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);   //�������豸�ľ�� 
		COORD   setps; //����ṹ����� 
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