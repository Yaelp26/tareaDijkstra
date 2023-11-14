#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack(int size)
{
	this->size = size;
	top = -1;
	stack = new int[size];
}

bool Stack::isEmpty()
{
	return top==-1;
}

bool Stack::isFull()
{
	return top==size-1;
}

int Stack::getSize()
{
	return size;
}

void Stack::push(int element)
{
	if(!isFull())
		stack[++top]= element;
	else
		cout << "The stack is full" << endl;
}

int Stack:: pop()
{
	if(!isEmpty())
		return stack[top--];
	else
		cout << "The stack is empty" << endl;
		return -200000;
}

int Stack::getTop()
{
	return stack[top];
}

void Stack::showStack()
{
	if(!isEmpty())
	{
		cout << "Stack content: " << endl;
		for(int i=top; i>-1 ;i--)
			cout << stack[i] << endl;
		cout << endl;
	}
	else
		cout << "The stack is empty"<< endl;
}