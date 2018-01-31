#include <iostream>
using namespace std;

enum type_of_data{INT,DOUBLE,STRING};

union DATA{
	int i;
	double j;
	char k[100];
};

struct NODE
{
	type_of_data type;
	union DATA data;
	struct NODE *next;

}NODE;

typedef struct NODE *PNODE;

class cList{
	PNODE head;
	PNODE tail;
public:
	void insert(int i);  //insert data
	void insert(double j);
	void insert(char k[]);
	void output();  //output list
	void delete_head();  //delete head data
	int is_empty(); //check whether the list is empty.if it is empty,return 1;otherwise return 0.
	cList();
	~cList();
};
