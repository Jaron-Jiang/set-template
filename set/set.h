#pragma once

template<class T>
class set
{
private:
	struct Data
	{
		//存储数据
		T data;
		//指向下一个结点
		Data* next;
		//指向前一个结点
		Data* ahead;
	};
	//指向链表的第一个数据元素的地址
	Data* head;

	//指向链表的最后一个数据元素的地址
	Data* rear;

	//记录链表的长度
	int length;

	//比较a和b的大小，如果a<=b返回true，反之返回false
	static bool compare(T a, T b);

	//指向set需要的比较大小的函数
	bool(*cmp)(T a, T b);

	//比较a和b元素是否相同，相同返回true，反之返回false
	static bool judge_repeat(T a, T b);

	//集合具有互异性，因此需要函数来比较集合中的元素是否相同，该函数指针就是指向用来判断元素是否相同的函数
	bool(*repeat)(T a, T b);

	//指向对输入集合进行禁止的函数，如果指向NULL，表示对输入内容无要求
	bool(*ban)(T a);

	//内置输出函数
	static void Show(T a);

	//用来交换a和b的数据
	void swap(Data& a, Data& b);

	//在链表头部添加数据a
	bool push_front(T& a);

	//在链表尾部添加数据a
	bool push_back(T& a);

	//删除第一个结点
	bool pop_front();

	//删除最后一个结点
	bool pop_back();

	//在p结点处插入数据val
	void insert(Data* p, T& val);

	//删除p结点
	void erase(Data* p);

	//寻找结点p及以后是否存在元素val，如果存在返回指向其的指针，如果不存在则返回NULL
	Data* find(Data* p, T& val);

public:
	//构造函数，f指向判断元素是否重复的函数，ff指向比较元素大小的函数，fff指向判断不可加入的元素的判断
	set(bool(*Repeat)(T, T) = judge_repeat, bool(*Compare)(T, T) = compare,bool(*Ban)(T) = NULL);

	//构造函数,将集合a复制到当前集合中
	set(set& a);

	//析构函数（没啥好讲的）
	~set();

	//插入数据val
	void insert(T val);

	//删除数据val
	bool erase(T val);

	//判断集合是否为空，如果是返回true，反之返回false
	bool empty();

	//返回集合中有多少个数据
	int size();

	//清空集合中的数据
	void clean();

	//对=的重载
	const void operator=(const set& a);

	//对-的重载
	const set operator-(const set& a)const;

	//对()的重载
	const set operator[](const set& a)const;

	const set operator^(const set& a)const;

	const set operator+(const set& a)const;

	//f指向输出元素的函数
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