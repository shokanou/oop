#include "Stack.h"

void Stack::push(char n)
{
	StN temp = (StN)malloc(sizeof(struct StackNode));
	temp->data = n;
	temp->next = m;
	m = temp;
}

void Stack::pop()
{
	if(m==NULL)
		printf("Empty Stack!\n");
	m = m->next;
}

char Stack::top()
{
	return m->data;
}

int Stack::is_empty()
{
	if(m==NULL)
		return 1;

	return 0;
}
Stack::Stack()
{
    m = NULL;              
}

Stack::~Stack()
{
	StN temp;
	while(m)
	{
		temp=m->next;
		free(m);
		m = temp;
	}
}
