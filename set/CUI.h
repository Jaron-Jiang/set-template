#pragma once
#include "set.h"
#include<cstdio>
#include<iostream>
#include <typeinfo>
#include"instruction.h"
#include <stdlib.h> 
template<class T>
class CUI
{
private:
	//每一个变量的信息，同时使用链表将每一个变量连接起来
	struct Data
	{
		char name[100];//记录变量名字
		set<T>s;//变量代表的集合
		Data* next;//指向下一个变量
		Data* ahead;//指向前一个变量
	};
	std::string data_type;//记录选择的数据类型
	int length;//变量个数
	Data* head;//指向变量链表中的第一个变量
	Data* rear;//指向变量链表中的最后一个变量
	void clean();//清空所有变量
	Data* find(char command[100]);//寻找名字为command中存储的字符串的变量，如果存在返回一个指向该变量的指针，否则返回NULL
	void push_back(char command[100]);//在变量链表的尾结点后添加一个新的变量结点，该变量名字为command中存储的字符串
	void show();//展示变量信息
	void erase(Data* p);//删除结点p，即删除p指向的变量
	void analysis_int();//对int类型的数据插入表达式进行分析，并进行数据插入
	void analysis_double();//对double类型的数据插入表达式进行分析，并进行数据插入
	void analysis_char();//对char类型的数据插入表达式进行分析，并进行数据插入
	void analysis_string();//对string类型的数据插入表达式进行分析，并进行数据插入
	set<T> analysis_com(int& index, int L,char command[100],bool& flag,int count = 1);//进行混合运算表达式，index表示对command中第index-1个字符操作，L表示表达式的长度即command的长度，flag记录表达式是否有误，count表示计算层级
	bool(*repeat)(T a, T b);//指向判断数据重复的函数
	bool(*cmp)(T a, T b);//指向比较数据大小的函数
	bool judge(int index, char command[100]);//用于analysis_com()函数，判断数组command中index位置以前的字符情况
	std::string change(std::string str);//用于浮点数数据插入表示式的解析，辅助analysis_double函数
	//内置默认展示函数
	static void Show(T val)
	{
		std::cout << val << std::endl;
	}  
public:
	int run(std::string str);//运行函数，相当于该类的main函数
	CUI(bool(*Repeat)(T,T),bool(*Cmp)(T,T));//构造函数
	~CUI();//析构函数
};

template<class T>
CUI<T>::CUI(bool(*Repeat)(T, T), bool(*Cmp)(T, T))
{
	repeat = Repeat;
	cmp = Cmp;
	length = 0;
	rear = head = NULL;
}

template<class T>
CUI<T>::~CUI()
{
	clean();
}

template<class T>
void CUI<T>::clean()
{
	Data* p;
	while (head)
	{
		p = head;
		head = head->next;
		length--;
		delete p;
	}
}

template<class T>
typename CUI<T>::Data* CUI<T>::find(char command[100])
{
	Data* p = head;
	while (p)
	{
		if (strcmp(p->name, command) == 0)
		{
			break;
		}
		p = p->next;
	}
	return p;
}

template<class T>
void CUI<T>::push_back(char command[100])
{
	Data* p = new Data;
	p->next = NULL;
	p->s.add1(repeat);
	p->s.add2(cmp);
	p->s.add3(NULL);
	p->s.change_data_type(data_type);
	strcpy_s(p->name, command);
	if (length == 0)
	{
		head = rear = p;
		p->ahead = NULL;
	}
	else
	{
		rear->next = p;
		p->ahead = rear;
		rear = p;
	}
	length++;
}

template<class T>
void CUI<T>::show()
{
	if (length == 0)
	{
		printf("NULL\n");
		return;
	}
	Data* p = head;
	printf("%-10s%-10s\n", "Name", "Length");
	printf("%-10s%-10s\n", "----", "------");
	while (p)
	{
		printf("%-10s%-10d\n", p->name, p->s.size());
		p = p->next;
	}
	printf("count:%-10d\n", length);
}

template<class T>
void CUI<T>::erase(Data* p)
{
	if (length == 1)
	{
		head = rear = NULL;
	}
	else if(p->ahead == NULL)
	{
		head = head->next;
		head->ahead = NULL;
	}
	else if (p->next == NULL)
	{
		p->ahead->next = NULL;
		rear = p->ahead;
	}
	else
	{
		p->ahead->next = p->next;
		p->next->ahead = p->ahead;
	}
	delete p;
	length--;
}

template<class T>
std::string CUI<T>::change(std::string str)
{
	if (str.size() == 0 || str.size() == 1 && str[0] == '-')
	{
		return "kk";
	}
	int start = 0, end = str.size() - 1;
	if (str[0] == '-')
	{
		start = 1;
	}
	int count = 0;
	for (int i = 0; i < end; i++)
	{
		if (str[i] == '.')
		{
			count++;
		}
	}
	if (count > 1)
	{
		return "kk";
	}
	while (start < end)
	{
		if (str[start] != '0'||str[start] == '.')
		{
			break;
		}
		start++;
	}
	if (count != 0 && str[end]!='.')
	{
		while (start < end)
		{
			if (str[end] != '0' || str[end] == '.')
			{
				break;
			}
			end--;
		}
	}
	if (start == end)
	{
		if (str[end] != '.'&&str[start]!='-')
			return str = str[start];
		return "0";
	}
	else
	{
		if (str[start] == '.')
		{
			std::string str1(str, start, end - start + 1);
			return '0' + str1;
		}
		else if (str[end] == '.')
		{
			std::string str1(str, start, end - start);
			if (str[0] == '-')
			{
				return '-' + str1;
			}
			return str1;
		}
		else
		{
			std::string str1(str, start, end - start+1);
			if (str[0] == '-')
			{
				return '-' + str1;
			}
			return str1;
		}
	}
}

template<class T>
void CUI<T>::analysis_int()
{
	char command[100];
	std::cin >> command;
	Data* p = find(command);
	if (p)
	{
		char ch;
		std::cin.ignore(1024, ' ');
		bool flag = true;
		bool index;
		while (flag)
		{
			T num;
			index = true;
			while (true)
			{
				ch = getchar();
				if ('0' <= ch && ch <= '9')
				{
					if (index)
					{
						if (ch != '0')
						{
							num += ch;
							index = false;
						}
					}
					else
					{
						num += ch;
					}					
				}
				else if (ch == ' ')
				{
					if (num.size() == 0 || num.size()==1&&(num[0]=='-'||num[0]=='+'))
					{
						p->s.insert("0");
					}
					else
					{
						p->s.insert(num);
					}
					break;
				}
				else if (ch == '\n')
				{
					if (num.size() == 0)
					{
						p->s.insert("0");
					}
					else
					{
						p->s.insert(num);
					}
					return;
				}
				else
				{
					if (ch == '-'&&num.size() == 0)
					{
						num += ch;
						continue;
					}
					if (ch == '+'&&num.size() == 0)
					{
						continue;
					}
					while (true)
					{
						ch = getchar();
						if (ch == ' ')
						{
							break;
						}
						else if (ch == '\n')
						{
							return;
						}
					}
					break;
				}
			}
		}
	}
	else
	{
		printf("NameError: set '%s' is not defined\n", command);
		std::cin.ignore(1024, '\n');
	}
}

template<class T>
void CUI<T>::analysis_double()
{
	char command[100];
	std::cin >> command;
	Data* p = find(command);
	if (p)
	{
		char ch;
		std::cin.ignore(1024, ' ');
		bool flag = true;
		bool index;
		while (flag)
		{
			T num;
			index = true;
			while (true)
			{
				ch = getchar();
				if ('0' <= ch && ch <= '9' || ch == '.')
				{
					num += ch;
				}
				else if (ch == ' ')
				{
					num = change(num);
					if (num == "kk")
					{				
					}
					else
					{
						p->s.insert(num);
					}
					break;
				}
				else if (ch == '\n')
				{
					num = change(num);
					if (num == "kk")
					{
					}
					else
					{
						p->s.insert(num);
					}
					flag = false;
					break;
				}
				else
				{
					if (ch == '-'&&num.size() == 0)
					{
						num += ch;
						continue;
					}
					if (ch == '+'&&num.size() == 0)
					{
						continue;
					}
					while (true)
					{
						ch = getchar();
						if (ch == ' ')
						{
							break;
						}
						else if (ch == '\n')
						{
							return;
						}
					}
					break;
				}
			}
		}
	}
	else
	{
		printf("NameError: set '%s' is not defined\n", command);
		std::cin.ignore(1024, '\n');
	}
}

template<class T>
void CUI<T>::analysis_char()
{
	char command[100];
	std::cin >> command;
	Data* p = find(command);
	if (p)
	{
		char ch;
		std::cin.ignore(1024, ' ');
		std::string str;
		while (true)
		{
			ch = getchar();
			if (ch == '\n')
			{
				break;
			}
			else if (ch == ' ' || ch<'a' || ch>'z')
			{
				continue;
			}
			else
			{
				str = ch;
				p->s.insert(str);
			}
		}
	}
	else
	{
		printf("NameError: set '%s' is not defined\n", command);
		std::cin.ignore(1024, '\n');
	}
}

template<class T>
void CUI<T>::analysis_string()
{
	char command[100];
	std::cin >> command;
	Data* p = find(command);
	if (p)
	{
		std::cin.ignore(1024, ' ');
		T str;
		getline(std::cin,str,'\n');
		p->s.insert(str);
	}
	else
	{
		printf("NameError: set '%s' is not defined\n", command);
		std::cin.ignore(1024, '\n');
	}
}

template<class T>
set<T> CUI<T>::analysis_com(int& index, int L,char command[100],bool& flag,int count)
{
	set<T>s;
	char name[100];
	int i = 0;
	while (true)
	{
		if (index > L|| flag)
		{
			break;
		}
		else if (index == L)
		{
			if (i)
			{
				name[i] = '\0';
				Data* p = find(name);
				if (p)
				{
					s = p->s;
				}
				else
				{
					flag = true;
				}
			}
			break;
		}
		else if ('a' <= command[index] && command[index] <= 'z' || 'A' <= command[index] && command[index] <= 'Z')
		{
			name[i++] = command[index++];
		}
		else if (command[index] == '+'||command[index]=='-'||command[index]=='^')
		{
			if (count != 1)
			{
				if (i)
				{
					name[i] = '\0';
					Data* p = find(name);
					if (p)
					{
						s = p->s;
					}
					else
					{
						flag = true;
					}
				}
				break;
			}
			if (i)
			{
				name[i] = '\0';
				i = 0;
				Data* p = find(name);
				if (p)
				{
					if (command[index] == '+')
					{
						s = p->s + analysis_com(++index, L, command, flag, count + 1);
					}
					else if (command[index] == '-')
					{
						s = p->s - analysis_com(++index, L, command, flag, count + 1);
					}
					else if (command[index] == '^')
					{
						s = p->s ^ analysis_com(++index, L, command, flag, count + 1);
					}
				}
				else
				{
					flag = true;
					break;
				}
			}
			else
			{
				if (command[index] == '+')
				{
					s = s + analysis_com(++index, L, command, flag, count + 1);
				}
				else if (command[index] == '-')
				{
					s = s - analysis_com(++index, L, command, flag, count + 1);
				}
				else if (command[index] == '^')
				{
					s = s ^ analysis_com(++index, L, command, flag, count + 1);
				}
			}
		}
		else if (command[index] == '[')
		{
			name[i] = '\0';
			i = 0;
			Data* p = find(name);
			if (p)
			{
				s = s + p->s[analysis_com(++index, L, command, flag, 1)];	
				index++;
			}
			else
			{
				flag = true;
			}
			if (judge(index - 1, command) && count != 1)
			{
				break;
			}
		}
		else if (command[index] == '(')
		{
			s = s + analysis_com(++index, L, command, flag, 1);
			index++;
			if (count != 1)
			{
				break;
			}
		}
		else if (command[index] == ']' || command[index] == ')')
		{
			if (i)
			{
				name[i] = '\0';
				Data* p = find(name);
				if (p)
				{
					s = s + p->s;
				}
				else
				{
					flag = true;
				}
			}
			break;
		}
		else if (command[index] == ' ')
		{
			index++;
		}
		else
		{
			flag = true;
			break;
		}
	}
	return s;
}

template<class T>
bool CUI<T>::judge(int index, char command[100])
{
	while (index >= 0)
	{
		if (command[index] == '[')
		{
			return false;
		}
		else if (command[index] == '+' || command[index] == '-' || command[index] == '^')
		{
			break;
		}
		else
		{
			index--;
		}
	}
	return true;
}

template<class T>
int CUI<T>::run(std::string str)
{
	data_type = str;
	char command[100];
	bool flag = true;
	bool is_back = false;
	while (flag)
	{
		std::cout << ">>>>";
		std::cin >> command;
		if (strcmp(command, "clean()") == 0)
		{
			clean();
		}
		else if (strcmp(command, "assign") == 0)
		{
			std::cin >> command;
			Data* p = find(command);
			if (p)
			{
				p->s.clean();
			}
			else
			{
				push_back(command);
			}
		}
		else if (strcmp(command, "show") == 0)
		{
			std::cin >> command;
			Data* p;
			if (strcmp(command, "--all") == 0)
			{
				p = head;
				while (p)
				{
					std::cout << p->name << "\t";
					if (data_type == "string")
					{
						p->s.show(Show);
					}
					else
					{
						p->s.show();
					}
					p = p->next;
				}
			}
			else
			{
				p = find(command);
				if (p)
				{
					if (data_type == "string")
					{
						p->s.show(Show);
					}
					else
					{
						p->s.show();
					}
				}
				else
				{
					printf("NameError: set '%s' is not defined\n", command);
				}
			}
		}
		else if (strcmp(command, "erase") == 0)
		{
			std::cin >> command;
			Data* p = find(command);
			if (p)
			{
				T val;
				std::cin >> val;
				p->s.erase(val);
			}
			else
			{
				printf("NameError: set '%s' is not defined\n", command);
				std::cin.ignore(1024,'\n');
			}
		}
		else if (strcmp(command, "size") == 0)
		{
			std::cin >> command;
			Data* p = find(command);
			if (p)
			{
				std::cout << p->s.size() << std::endl;
			}
			else
			{
				printf("NameError: set '%s' is not defined\n", command);
			}
		}
		else if (strcmp(command, "quit()") == 0)
		{
			flag = false;
		}
		else if (strcmp(command, "com") == 0)
		{
			scanf_s("%[^\n]", command,100);
			int i,L = strlen(command);
			for (i = 0; i < L; i++)
			{
				if (command[i] == '=')
				{
					break;
				}
			}
			if (i != L)
			{
				char str[100];
				bool flag = false;
				int k = i - 1;
				int z = 0;
				while (k >= 0 && command[k] == ' ')
				{
					k--;
				}
				while (z < L&&command[z] == ' ')
				{
					z++;
				}
				if (k < 0 || z > k)
				{
					break;
				}
				int j = 0;
				while (z <= k)
				{
					if (!('a' <= command[z] && command[z] <= 'z') && !('A' <= command[z] && command[z] <= 'Z'))
					{
						printf("ComError\n");
						flag = true;
						break;
					}
					str[j++] = command[z++];
				}
				if (flag)
				{
					break;
				}
				str[j] = '\0';
				Data* p = find(str);
				flag = false;
				k = i + 1;
				set<T>s;
				s = analysis_com(k, strlen(command), command, flag);
				if (flag || k < L)
				{
					printf("ComError\n");
				}
				if (!p)
				{
					push_back(str);
					rear->s = s;
				}
				else
				{
					p->s = s;
				}
			}
			else
			{
				bool flag = false;
				int k = 0;
				set<T>s;
				s = analysis_com(k, L, command, flag);
				if (k < L || flag)
				{
					printf("ComError\n");
				}
				else
				{
					if (data_type == "string")
					{
						s.show(Show);
					}
					else
					{
						s.show();
					}
				}
			}
		}
		else if (strcmp(command, "insert") == 0)
		{
			if (data_type == "int")
			{
				analysis_int();
			}
			else if (data_type == "double")
			{
				analysis_double();
			}
			else if (data_type == "char")
			{
				analysis_char();
			}
			else if (data_type == "string")
			{
				analysis_string();
			}
		}
		else if (strcmp(command, "ls") == 0)
		{
			show();
			std::cin.ignore(1024, '\n');
		}
		else if (strcmp(command, "delete") == 0)
		{
			std::cin >> command;
			Data* p = find(command);
			if (p)
			{
				erase(p);
			}
			else
			{
				printf("NameError: set '%s' is not defined\n", command);
			}
		}
		else if (strcmp(command, "help") == 0)
		{
			instruction a;
			a.run();

		}
		else if (strcmp(command, "find") == 0)
		{
			std::cin >> command;
			Data* p = find(command);
			if (p)
			{
				T val;
				std::cin >> val;
				if (p->s.find(val))
				{
					std::cout << "True" << std::endl;
				}
				else
				{
					std::cout << "False" << std::endl;
				}
			}
			else
			{
				printf("NameError: set '%s' is not defined\n", command);
				std::cin.ignore(1024, '\n');
			}
		}
		else if (strcmp(command, "subset") == 0)
		{
			std::cin >> command;
			Data* p1 = find(command);
			if (p1)
			{
				std::cin >> command;
				Data* p2 = find(command);
				if (p2)
				{
					if (p1->s.judge_subset(p2->s))
					{
						std::cout << "True" << std::endl;
					}
					else
					{
						std::cout << "False" << std::endl;
					}
				}
				else
				{
					printf("NameError: set '%s' is not defined\n", command);
				}
			}
			else
			{
				printf("NameError: set '%s' is not defined\n", command);
				std::cin.ignore(1024, '\n');
			}
		}
		else if (strcmp(command, "back()") == 0)
		{
			flag = false;
			is_back = true;
		}
		else
		{
			printf("NameError: name '%s' is not defined\n",command);
			std::cin.ignore(1024, '\n');
		}
	}
	return is_back;
}
