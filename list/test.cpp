#include "clist.cpp"
int main()
{
	cList list1;
    list1.insert(23);
    list1.insert(43.45);
    list1.insert("hello");
    list1.output();
    system("pause");
}
