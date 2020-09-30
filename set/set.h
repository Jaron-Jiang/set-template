#pragma once

template<class T>
class set
{
private:
	struct Data
	{
		//�洢����
		T data;
		//ָ����һ�����
		Data* next;
		//ָ��ǰһ�����
		Data* ahead;
	};
	//ָ������ĵ�һ������Ԫ�صĵ�ַ
	Data* head;

	//ָ����������һ������Ԫ�صĵ�ַ
	Data* rear;

	//��¼����ĳ���
	int length;

	//�Ƚ�a��b�Ĵ�С�����a<=b����true����֮����false
	static bool compare(T a, T b);

	bool(*cmp)(T a, T b);

	//�Ƚ�a��bԪ���Ƿ���ͬ����ͬ����true����֮����false
	static bool judge_repeat(T a, T b);

	//���Ͼ��л����ԣ������Ҫ�������Ƚϼ����е�Ԫ���Ƿ���ͬ���ú���ָ�����ָ�������ж�Ԫ���Ƿ���ͬ�ĺ���
	bool(*repeat)(T a, T b);

	static void Show(T a);
	//��������a��b������
	void swap(Data& a, Data& b);

	bool push_front(T a);

	bool push_back(T a);

	bool pop_front();

	bool pop_back();

	void insert(Data* p, T val);

public:
	set(bool(*f)(T, T) = judge_repeat, bool(*ff)(T, T) = compare);
	set(set& a, bool(*f)(T, T) = judge_repeat, bool(*ff)(T, T) = compare);
	~set();
	void insert(T val);
	bool empty();
	int size();
	void clear();
	void operator=(set& a);
	void show(void(*f)(T) = Show);
	void merge(set& a);
};

template<class T>
bool set<T>::compare(T a, T b)
{
	return a <= b;
}

template<class T>
set<T>::~set()
{
	clear();
}

template<class T>
bool set<T>::judge_repeat(T a, T b)
{
	return a == b ? true : false;
}

template<class T>
void set<T>::Show(T a)
{
	std::cout << a << " ";
}

template<class T>
void set<T>::show(void(*f)(T))
{
	Data* p = head;
	while (p)
	{
		f(p->data);
		p = p->next;
	}
	std::cout << std::endl;
}

template<class T>
set<T>::set(bool(*f)(T, T), bool(*ff)(T, T))
{
	repeat = f;
	cmp = ff;
	head = rear = NULL;
	length = 0;
}

template<class T>
set<T>::set(set& a, bool(*f)(T, T), bool(*ff)(T, T))
{
	head = rear = NULL;
	length = 0;
	repeat = f;
	cmp = ff;
	Data* p = a.head;
	while (p)
	{
		push_back(p->data);
		p = p->next;
	}
}

template<class T>
void set<T>::swap(Data& a, Data& b)
{
	T s = a.data;
	a.data = b.data;
	b.data = s;
}

template<class T>
bool set<T>::push_front(T a)
{
	try
	{
		if (length == 0)
		{
			return push_back(a);
		}
		else
		{
			Data* s = new Data;
			s->data = a;
			s->next = head;
			s->ahead = NULL;
			head->ahead = s;
			head = s;
			length++;
		}
	}
	catch (const std::exception&)
	{
		return false;
	}
	return true;
}

template<class T>
bool set<T>::push_back(T a)
{
	try
	{
		if (length == 0)
		{
			Data* s = new Data;
			s->data = a;
			s->next = s->ahead = NULL;
			length++;
			head = rear = s;
		}
		else
		{
			Data* s = new Data;
			s->data = a;
			s->next = NULL;
			rear->next = s;
			s->ahead = rear;
			rear = s;
			length++;
		}
	}
	catch (const std::exception&)
	{
		return false;
	}
	return true;
}

template<class T>
bool set<T>::pop_front()
{
	try
	{
		if (length == 1)
		{
			delete head;
			head = rear;
		}
		else
		{
			Data* p = head;
			head = head->next;
			head->ahead = NULL;
			delete p;
		}
		length--;
	}
	catch (const std::exception&)
	{
		return false;
	}
	return true;
}

template<class T>
bool set<T>::pop_back()
{
	try
	{
		if (length == 1)
		{
			delete rear;
			head = rear = NULL;
		}
		else
		{
			Data* p = rear;
			rear = rear->ahead;
			rear->next = NULL;
			delete p;
		}
		length--;
	}
	catch (const std::exception&)
	{
		return false;
	}
	return true;
}

template<class T>
void set<T>::insert(Data* p, T val)
{
	if (p->ahead == NULL)
	{
		push_front(val);
	}
	else
	{
		Data* s = new Data;
		s->data = val;
		s->next = p;
		s->ahead = p->ahead;
		p->ahead->next = s;
		p->ahead = s;
		length++;
	}
}

template<class T>
void set<T>::insert(T val)
{
	Data* p = head;
	while (p)
	{
		if (repeat(p->data, val))
		{
			return;
		}
		if (!cmp(p->data, val))
		{
			insert(p, val);
			return;
		}
		p = p->next;
	}
	push_back(val);
}

template<class T>
bool set<T>::empty()
{
	return length == 0 ? true : false;
}

template<class T>
int set<T>::size()
{
	return length;
}

template<class T>
void set<T>::clear()
{
	Data* p = head;
	while (head)
	{
		head = head->next;
		delete p;
		p = head;
		length--;
	}
}

template<class T>
void set<T>::operator=(set& a)
{
	clear();
	Data* p = a.head;
	while (p)
	{
		push_back(p->data);
		p = p->next;
	}
}

template<class T>
void set<T>::merge(set& a)
{
	Data* p1 = head;
	Data* p2 = a.head;
	while (p1&&p2)
	{
		if (repeat(p1->data, p2->data))
		{
			p2 = p2->next;
			continue;
		}
		if (!cmp(p1->data, p2->data))
		{
			insert(p1, p2->data);
			p2 = p2->next;
		}
	}
	while (p2)
	{
		push_back(p2->data);
		p2 = p2->next;
	}
}