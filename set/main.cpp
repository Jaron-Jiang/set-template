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
	//�����ظ��жϺ���
	static bool repeat(std::string a,std::string b)
	{
		return a == b;

	}

	//���ڱȽ�int���͵Ĵ�С
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

	//���ڱȽ�double���͵Ĵ�С
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

	//���ڱȽ�char��string���͵Ĵ�С
	static bool cmp3(std::string a, std::string b)
	{
		return a < b;

	}

	//�õ�һ�����չʾ
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
		str = "1. ͨ��ʹ�ò���������Զ�char��int��double��string�ļ��ϣ����л�ϱ��ʽ����";
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

	//���ڵڶ��������չʾ
	void second()
	{
		for (int i = 1; i <= 9; i++)
		{
			printf("\n");
		}
		std::string str = "��ѡ��Ҫʹ�õ������������͵ļ���";
		print(str);
		str = "1. int               2. double";
		print(str);
		str = "3. char              4. string";
		print(str);
		str = "5. back              6. exit  "; 
		print(str);
	}

	//��ӡ����
	void print(std::string str)
	{
		int L = (120 - str.size()) / 2;
		for (int i = 1; i <= L; i++)
		{
			std::cout << " ";
		}
		std::cout << str << std::endl;
	}

	//���ƹ��,���ڵڶ��������������͵�ѡȡ
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
	//��������к������൱��main����
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
