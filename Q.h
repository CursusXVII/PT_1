#pragma once
#include <iostream>
class Q {
public:
	void push(int data);
	int pop();
	Q();
	Q(int data);
	void Qprint();
	Q* copy();
	int GetSize();
	static Q*merge(Q* first, Q* second);
	~Q();
private:
	struct Element {
		int data;
		Element* pNext;
	};
	Element *tail = nullptr;
	int size = 0;
};