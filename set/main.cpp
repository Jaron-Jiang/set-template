#include<iostream>
#include"set.h"
int main()
{
	set<int>s;
	s.insert(3);
	s.insert(4);
	s.insert(5);
	s.insert(2);
	s.insert(1);
	s.insert(0);
	s.insert(2);
	s.insert(1);
	s.insert(0);
	s.show();
	set<int>A;
	A.merge(s);
	A.show();
	return 0;
}