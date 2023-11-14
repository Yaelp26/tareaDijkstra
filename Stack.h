#ifndef STACK_H
#define STACK_H

class Stack
{
	private:
		int size, top;
		int *stack;		
	public:
		Stack(int size);
		bool isEmpty();
		bool isFull();
		int getSize();
		void push(int element);
		int pop();
		int getTop();
		void showStack();
};

#endif