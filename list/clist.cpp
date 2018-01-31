#include "clist.h"

cList::cList(){
	head = tail = NULL;
}

cList::~cList(){
	PNODE temp = head;
	while(head)
	{
		temp = head->next;
		delete head;
		head = temp;
	}
	delete temp;
}

void cList::insert(int x){
	PNODE temp = new struct NODE;
	temp->type = INT;
	temp->data.i = x;
	temp->next = NULL;
	if(head==NULL)
	{
		head = temp;
		tail = head;
	}
	else
		tail = tail->next = temp;

}

void cList::insert(double y){
	PNODE temp = new struct NODE;
	temp->type = DOUBLE;
	temp->data.j = y;
	temp->next = NULL;
	if(head==NULL)
	{
		head = temp;
		tail = head;
	}
	else
		tail = tail->next = temp;
}

void cList::insert(char z[]){
	PNODE temp = new struct NODE;
	temp->type = STRING;
	strcpy(temp->data.k,z);
	temp->next = NULL;
	if(head==NULL)
	{
		head = temp;
		tail = head;
	}
	else
		tail = tail->next = temp;
}

int cList::is_empty()
{
	if(head==NULL)
		return 1;
	return 0;
}

void cList::output()
{
	if(head==NULL)
		cout<<"Empty List!"<<endl;


	while(head)
	{
		if(head->type==INT)
			cout<<head->data.i<<endl;
		else if(head->type==DOUBLE)
			cout<<head->data.j<<endl;
		else
			cout<<head->data.k<<endl;
		head = head->next;
	}
}

void cList::delete_head()
{
	if(head==0)
		cout<<"Empty List!"<<endl;
	head = head->next;
}
