#pragma once
#include "Q.h"
class Doch2 : protected Q {
public:
	void push(int data);
	int pop();
	void show();
	Q* copy();
	int GetSize();
	static Q* merge(Q* first, Q* second);
	int fun();
};