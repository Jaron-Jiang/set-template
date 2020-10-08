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
	printf("ʹ�÷���:\n\tֱ������clean(),ɾ����������м��ϣ����ã�����\n");
}
void instruction::_assign()
{
	printf("ʹ�÷���:\n\t����assign name������һ�����ϱ���name\n\tע��:�����nameΪҪ����ļ��ϱ�����������һ��ֻ�ܶ���һ������,����ñ����Ѿ����ڣ��򸲸�\n");
}
void instruction::_show()
{
	printf("ʹ�÷���:\n\t1. ����show --all����ʾ���ж��嵫δɾ���ļ��ϵ����ֺͼ���Ԫ��\n\t2. ����show name����ʾ����name������Ԫ��\n\tע��:�����nameΪ���ϱ�����������һ��ֻ��дһ��������\n");
}
void instruction::_erase()
{
	printf("ʹ�÷���:\n\t����erase name val��ɾ������name�е�Ԫ��val\n\tע��:�����nameΪ���ϱ�����������һ��ֻ��ɾ��һ��Ԫ��\n");
}
void instruction::_size()
{
	printf("ʹ�÷���:\n\t����size name����ʾ����name��Ԫ�ظ���\n");
}
void instruction::_quit()
{
	printf("ʹ�÷���:\n\t����quit()�������������\n");
}
void instruction::_com()
{
	printf("ʹ�÷���:\n\t����com <���ʽ>��������ʽ������ñ�ﲻ�Ǹ�ֵ���㣬����������֮�򲻻����\n");
	printf("\t����:a+b-c������ʽΪ�Ǹ�ֵ���ʽ��a=b+(c-d)+d[p]Ϊ��ֵ���ʽ\n");
	printf("\t����+��ʾ�������㣬����-��ʾ����㣬����^��ʾ�������㣬����[]��ʾ��������(����A[B]��ʾȫ��B��A�Ĳ���)������ʹ�÷���()�������ȼ�����\n");
}
void instruction::_insert()
{
	printf("ʹ�÷���:\n\t����insert name val���򼯺�name�м���Ԫ��val\n");
	printf("ע��:\n\t1. ���������char����val�е��ַ��������뼯��\n");
	printf("\t2. ����������������߸��������ͣ���valת�������ּ��뼯�ϣ�ͬʱ���Խ���insert name val1 val2 val3...valn,����val1��val2��val3...valn�ֱ���뼯��\n");
}
void instruction::_ls()
{
	printf("ʹ�÷���:\n\t����ls,��ʾ���ж�����δɾ���ı������ͼ����е�Ԫ�ظ���\n");
}
void instruction::_delete()
{
	printf("ʹ�÷���:\n\t����delete name,ɾ������name��nameΪ�����һ��������\n");
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