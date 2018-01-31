#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;


typedef struct  StackNode *StN;

struct StackNode
{
	char data;
	struct StackNode *next;
};


class Stack
{
public:
	void push(char n);
	void pop();
	char top();
	int is_empty();
	Stack();
	~Stack();

private:
	StN m;
};