#ifndef STRING_H
#define STRING_H
#include<string>
#endif

#ifndef STD
#define STD
using namespace std;
#endif

class Teacher
{
private:
	string Name, Num;
	Teacher* Next;
public:
	Teacher();
	~Teacher();
	void Update(string NewName, string NweNum);
	Teacher* Find(string NewNum);
	Teacher* Add(Teacher* NewTeacher);
	Teacher* Delete(string NewNum);
	string GetNum() const;
	string GetName() const;
	Teacher* GetNext() const;
};