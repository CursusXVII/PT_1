#pragma once
#include "Q.h"
class Doch3 : private Q {
public:
	int fun();
	void push(int data);
	int pop();
	void show();
	Q* copy();
	int GetSize();
	static Q* merge(Q* first, Q* second);
};