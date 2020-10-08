#pragma once
#include<iostream>
class instruction
{
private:
	void _clean();
	void _assign();
	void _show();
	void _erase();
	void _size();
	void _quit();
	void _com();
	void _insert();
	void _ls();
	void _delete();
public:
	void run();
};

void instruction::_clean()
{
	printf("使用方法:\n\t直接输入clean(),删除定义的所有集合，慎用！！！\n");
}
void instruction::_assign()
{
	printf("使用方法:\n\t输入assign name，声明一个集合变量name\n\t注意:这里的name为要定义的集合变量名，此外一次只能定义一个变量,如果该变量已经存在，则覆盖\n");
}
void instruction::_show()
{
	printf("使用方法:\n\t1. 输入show --all，显示所有定义但未删除的集合的名字和集合元素\n\t2. 输入show name，显示集合name的所有元素\n\t注意:这里的name为集合变量名，此外一次只能写一个变量名\n");
}
void instruction::_erase()
{
	printf("使用方法:\n\t输入erase name val，删除集合name中的元素val\n\t注意:这里的name为集合变量名，此外一次只能删除一个元素\n");
}
void instruction::_size()
{
	printf("使用方法:\n\t输入size name，显示集合name的元素个数\n");
}
void instruction::_quit()
{
	printf("使用方法:\n\t输入quit()，程序结束运行\n");
}
void instruction::_com()
{
	printf("使用方法:\n\t输入com <表达式>，运算表达式，如果该表达不是赋值运算，则会输出，反之则不会输出\n");
	printf("\t例如:a+b-c这个表达式为非赋值表达式；a=b+(c-d)+d[p]为赋值表达式\n");
	printf("\t符号+表示并集运算，符号-表示差集运算，符号^表示交集运算，符号[]表示补集运算(例如A[B]表示全集B下A的补集)，可以使用符号()进行优先级运算\n");
}
void instruction::_insert()
{
	printf("使用方法:\n\t输入insert name val，向集合name中加入元素val\n");
	printf("注意:\n\t1. 如果集合是char，则将val中的字符单个加入集合\n");
	printf("\t2. 如果集合是整数或者浮点数类型，则将val转换成数字加入集合，同时可以进行insert name val1 val2 val3...valn,即将val1，val2，val3...valn分别加入集合\n");
}
void instruction::_ls()
{
	printf("使用方法:\n\t输入ls,显示所有定义且未删除的变量名和集合中的元素个数\n");
}
void instruction::_delete()
{
	printf("使用方法:\n\t输入delete name,删除变量name，name为定义的一个变量名\n");
}
void instruction::run()
{
	char command[100];
	std::cin >> command;
	if (strcmp(command, "--all") == 0)
	{
		printf("clean:\n\n");
		_clean();
		printf("\nassign:\n\n");
		_assign();
		printf("\nshow:\n\n");
		_show();
		printf("\nerase:\n\n");
		_erase();
		printf("\nsize:\n\n");
		_size();
		printf("\nquit:\n\n");
		_quit();
		printf("\ncom:\n\n");
		_com();
		printf("\ninsert:\n\n");
		_insert();
		printf("\nls:\n\n");
		_ls();
		printf("\ndelete:\n\n");
		_delete();
	}
	else if(strcmp(command, "-clean") == 0)
	{
		_clean();
	}
	else if (strcmp(command, "-assign") == 0)
	{
		_assign();
	}
	else if (strcmp(command, "-show") == 0)
	{
		_show();
	}
	else if (strcmp(command, "-quit") == 0)
	{
		_quit();
	}
	else if (strcmp(command, "-com") == 0)
	{
		_com();
	}
	else if (strcmp(command, "-erase") == 0)
	{
		_erase();
	}
	else if (strcmp(command, "-size") == 0)
	{
		_size();
	}
	else if (strcmp(command, "-insert") == 0)
	{
		_insert();
	}
	else if (strcmp(command, "-ls") == 0)
	{
		_ls();
	}
	else if (strcmp(command, "-delete") == 0)
	{
		_delete();
	}
	else 
	{
		printf("NameError:\"%s\" is not define\n",command);
	}
}