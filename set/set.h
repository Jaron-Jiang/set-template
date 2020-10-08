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

	//ָ��set��Ҫ�ıȽϴ�С�ĺ���
	bool(*cmp)(T a, T b);

	//�Ƚ�a��bԪ���Ƿ���ͬ����ͬ����true����֮����false
	static bool judge_repeat(T a, T b);

	//���Ͼ��л����ԣ������Ҫ�������Ƚϼ����е�Ԫ���Ƿ���ͬ���ú���ָ�����ָ�������ж�Ԫ���Ƿ���ͬ�ĺ���
	bool(*repeat)(T a, T b);

	//ָ������뼯�Ͻ��н�ֹ�ĺ��������ָ��NULL����ʾ������������Ҫ��
	bool(*ban)(T a);

	//�����������
	static void Show(T a);

	//��������a��b������
	void swap(Data& a, Data& b);

	//������ͷ���������a
	bool push_front(T& a);

	//������β���������a
	bool push_back(T& a);

	//ɾ����һ�����
	bool pop_front();

	//ɾ�����һ�����
	bool pop_back();

	//��p��㴦��������val
	void insert(Data* p, T& val);

	//ɾ��p���
	void erase(Data* p);

	//Ѱ�ҽ��p���Ժ��Ƿ����Ԫ��val��������ڷ���ָ�����ָ�룬����������򷵻�NULL
	Data* find(Data* p, T& val);

public:
	//���캯����fָ���ж�Ԫ���Ƿ��ظ��ĺ�����ffָ��Ƚ�Ԫ�ش�С�ĺ�����fffָ���жϲ��ɼ����Ԫ�ص��ж�
	set(bool(*Repeat)(T, T) = judge_repeat, bool(*Compare)(T, T) = compare,bool(*Ban)(T) = NULL);

	//���캯��,������a���Ƶ���ǰ������
	set(set& a);

	//����������ûɶ�ý��ģ�
	~set();

	//��������val
	void insert(T val);

	//ɾ������val
	bool erase(T val);

	//�жϼ����Ƿ�Ϊ�գ�����Ƿ���true����֮����false
	bool empty();

	//���ؼ������ж��ٸ�����
	int size();

	//��ռ����е�����
	void clean();

	//��=������
	const void operator=(const set& a);

	//��-������
	const set operator-(const set& a)const;

	//��()������
	const set operator[](const set& a)const;

	const set operator^(const set& a)const;

	const set operator+(const set& a)const;

	//fָ�����Ԫ�صĺ���
	void show(void(*SHOW)(T) = Show);	
};

template<class T>
bool set<T>::compare(T a, T b)
{
	return memcmp(&a, &b, sizeof(T)) <= 0;
}

template<class T>
set<T>::~set()
{
	clean();
}

template<class T>
bool set<T>::judge_repeat(T a, T b)
{
	return memcmp(&a, &b, sizeof(T)) == 0;
}

template<class T>
void set<T>::Show(T a)
{
	std::cout << a << " ";
}

template<class T>
void set<T>::show(void(*SHOW)(T))
{
	Data* p = head;
	while (p)
	{
		SHOW(p->data);
		p = p->next;
	}
	std::cout << std::endl;
}

template<class T>
set<T>::set(bool(*Repeat)(T, T), bool(*Compare)(T, T),bool(*Ban)(T))
{
	repeat = Repeat;
	cmp = Compare;
	ban = Ban;
	head = rear = NULL;
	length = 0;
}

template<class T>
set<T>::set(set& a)
{
	head = rear = NULL;
	length = 0;
	repeat = a.repeat;
	cmp = a.cmp;
	ban = a.ban;
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
bool set<T>::push_front(T& a)
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
bool set<T>::push_back(T& a)
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
void set<T>::insert(Data* p, T& val)
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
	if (ban)
	{
		if (!ban(val))
			return;
	}
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
bool set<T>::erase(T val)
{
	Data* p = head;
	while (p)
	{
		if (repeat(p->data, val))
		{
			if (p->ahead == NULL)
			{
				pop_front();
			}
			else if (p->next == NULL)
			{
				pop_back();
			}
			else
			{
				Data* p1 = p;
				p = p->ahead;
				p->next = p1->next;
				p1->next->ahead = p;
				delete p1;
				length--;
			}
			return true;
		}
		if (!cmp(p->data, val))
		{
			return false;
		}
		p = p->next;
	}
	return false;
}

template<class T>
void set<T>::erase(Data* p)
{
	if (p->ahead == NULL)
	{
		pop_front();
	}
	else if (p->next == NULL)
	{
		pop_back();
	}
	else
	{
		Data* p1 = p;
		p = p->ahead;
		p->next = p1->next;
		p1->next->ahead = p;
		delete p1;
		length--;
	}
}

template<class T>
typename set<T>::Data* set<T>::find(Data* p, T& val)
{
	while (p)
	{
		if (repeat(p->data, val))
		{
			break;
		}
		p = p->next;
	}
	return p;
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
void set<T>::clean()
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
const void set<T>::operator=(const set& a)
{
	clean();
	Data* p = a.head;
	while (p)
	{
		push_back(p->data);
		p = p->next;
	}
}

template<class T>
const set<T> set<T>::operator-(const set& a)const
{
	set<T>s(a.repeat,a.cmp,a.ban);
	Data* p1 = head;
	Data* p2 = a.head;
	while (p1&&p2)
	{
		if (repeat(p1->data, p2->data))
		{
			p1 = p1->next;
			p2 = p2->next;
			continue;
		}
		if (cmp(p1->data, p2->data))
		{
			s.push_back(p1->data);
			p1 = p1->next;
		}
		else
		{
			p2 = p2->next;
		}
	}
	while (p1)
	{
		s.push_back(p1->data);
		p1 = p1->next;
	}
	return s;
}

template<class T>
const set<T> set<T>::operator[](const set& a)const
{
	set<T>s(repeat, cmp, ban);
	Data* p1 = a.head;
	Data* p2 = head;
	while (p1&&p2)
	{
		if (repeat(p1->data, p2->data))
		{
			p1 = p1->next;
			continue;
		}
		if (cmp(p1->data, p2->data))
		{
			s.push_back(p1->data);
			p1 = p1->next;
		}
		else
		{
			p2 = p2->next;
		}
	}
	while(p1)
	{
		s.push_back(p1->data);
		p1 = p1->next;
	}
	return s;
}\

template<class T>
const set<T> set<T>::operator^(const set& a) const
{
	set<T>s(repeat, cmp, ban);
	Data* p1 = head;
	Data* p2 = a.head;
	while (p1&&p2)
	{
		if (repeat(p1->data, p2->data))
		{
			s.push_back(p1->data);
			p1 = p1->next;
			p2 = p2->next;
			continue;
		}
		if (cmp(p1->data, p2->data))
		{
			p1 = p1->next;
		}
		else
		{
			p2 = p2->next;
		}
	}
	return s;
}

template<class T>
const set<T>  set<T>::operator+(const set& a) const
{
	set<T>s;
	s = a;
	Data* p1 = s.head;
	Data* p2 = head;
	while (p1&&p2)
	{
		if (repeat(p1->data, p2->data))
		{
			p1 = p1->next;
			p2 = p2->next;
			continue;
		}
		if (cmp(p1->data, p2->data))
		{
			p1 = p1->next;
		}
		else
		{
			s.insert(p1,p2->data);
			p2 = p2->next;
		}
	}
	while (p2)
	{
		s.push_back(p2->data);
		p2 = p2->next;
	}
	return s;
}