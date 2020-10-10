#pragma once
#include "set.h"
#include<cstdio>
#include<iostream>
#include <typeinfo>
#include"instruction.h"

template<class T>
class CUI
{
private:
	struct Data
	{
		char name[100];
		set<T>s;
		Data* next;
		Data* ahead;
	};
	int length;
	Data* head;
	Data* rear;
	void clean();
	Data* find(char command[100]);
	void push_back(char command[100]);
	void show();
	void erase(Data* p);
	void analysis_int();
	void analysis_float();
	void analysis_double();
	void analysis_char();
	set<T> analysis_com(int& index, int L,char command[100],bool& flag,int count = 1);
	bool(*ban)(T val);
	bool judge(int index, char command[100]);
public:
	int run();
	CUI();
	CUI(bool(*Ban)(T));
	~CUI();
};

template<class T>
CUI<T>::CUI()
{
	length = 0;
	rear = head = NULL;
	ban = NULL;
}

template<class T>
CUI<T>::CUI(bool(*Ban)(T))
{
	ban = Ban;
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
	p->s.add(ban);
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
void CUI<T>::analysis_int()
{
	char command[100];
	std::cin >> command;
	Data* p = find(command);
	if (p)
	{
		int num = 0;
		char ch;
		std::cin.ignore(1024, ' ');
		T sum;
		while (true)
		{
			ch = getchar();
			if ('0' <= ch && ch <= '9')
			{
				num = num * 10 + ch - '0';
			}
			else if(ch == ' ')
			{
				sum = (T)num;
				p->s.insert(sum);
				num = 0;
			}
			else if (ch == '\n')
			{
				sum = (T)num;
				p->s.insert(sum);
				break;
			}
			else
			{
				num = 0;
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
void CUI<T>::analysis_float()
{
	char command[100];
	std::cin >> command;
	Data* p = find(command);
	if (p)
	{
		float num = 0;
		char ch;
		std::cin.ignore(1024, ' ');
		float s = 1;
		T sum;
		while (true)
		{
			ch = getchar();
			if ('0' <= ch && ch <= '9')
			{
				if (s == 1)
				{
					num = num * 10 + ch - '0';
				}
				else
				{
					num += s * (ch - '0');
					s = (float)(s*0.1);
				}	
			}
			else if (ch == '.')
			{
				s = (float)(s*0.1);
			}
			else if (ch == ' ')
			{
				sum = (T)num;
				p->s.insert(sum);
				num = 0;
				s = 1;
			}
			else if (ch == '\n')
			{
				sum = (T)num;
				p->s.insert(sum);
				break;
			}
			else
			{
				num = 0;
				s = 1;
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
		double num = 0;
		char ch;
		std::cin.ignore(1024, ' ');
		double s = 1;
		T sum;
		while (true)
		{
			ch = getchar();
			if ('0' <= ch && ch <= '9')
			{
				if (s == 1)
				{
					num = num * 10 + ch - '0';
				}
				else
				{
					num += s * (ch - '0');
					s *= 0.1;
				}
			}
			else if (ch == '.')
			{
				s *= 0.1;
			}
			else if (ch == ' ')
			{
				sum = (T)num;
				p->s.insert(sum);
				num = 0;
				s = 1;
			}
			else if (ch == '\n')
			{
				sum = (T)num;
				p->s.insert(sum);
				break;
			}
			else
			{
				num = 0;
				s = 1;
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
		float s = 1;
		std::cin.ignore(1024, ' ');
		T sum;
		while (true)
		{
			ch = getchar();
			if (ch == '\n')
			{
				break;
			}
			else if (ch == ' ')
			{
				continue;
			}
			else
			{
				sum = ch;
				p->s.insert(sum);
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
int CUI<T>::run()
{
	char command[100];
	bool flag = true;
	bool is_back = false;
	while (flag)
	{
		std::cout << ">>>>";
		std::cin >> command;
		if (strcmp(command, "clean") == 0)
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
					p->s.show();
					p = p->next;
				}
			}
			else
			{
				p = find(command);
				if (p)
				{
					p->s.show();
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
					s.show();
				}
			}
		}
		else if (strcmp(command, "insert") == 0)
		{
			if (typeid(T) == typeid(int))
			{
				analysis_int();
			}
			else if (typeid(T) == typeid(float))
			{
				analysis_float();
			}
			else if (typeid(T) == typeid(double))
			{
				analysis_double();
			}
			else if (typeid(T) == typeid(char))
			{
				analysis_char();
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