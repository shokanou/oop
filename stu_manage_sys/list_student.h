#ifndef STRING_H
#define STRING_H
#include<string>
#endif

#ifndef STD
#define STD
using namespace std;
#endif

enum StudentType{DOCTOR=3, MASTER=2, BACHELOR=1};

class Course
{
private:
	string Name, Num;     //课程名称，编号
	double Grade, Credit; //百分制成绩，五分制学分
	Course *Next;
public:
	Course();
	~Course();
	void Update(string NewName, string NewNum, double NewGrade, double NewCredit);//修改
	Course* Find(string NewNum);//返回NULL表示失败
	Course* Add(Course* NewCourse);
	Course* Delete(string NewNum);

	string GetName() const;  //获得信息
	string GetNum() const;
	double GetGrade() const;
	double GetCredit() const;
	Course* GetNext() const;
};

class Student
{
private:
	string Name, Num, Major;  //学生姓名，学号，专业
	StudentType Type;         //本科，硕士，博士
	Course *CourseList;       //课程队列
	Student *Next;
public:
	Student();
	~Student();
	void Update(string NewName, string NewNum, string NewMajor, StudentType NewType);
	Student* Find(string NewNum);//返回NULL表示失败
	Student* Add(Student* NewStudent);
	Student* Delete(string NewNum);
	int DeleteCourse(string CourseNum);//返回0表示删除失败
	void UpdateCourse(Course *NewCourse);

	string GetName() const;//获得信息
	string GetNum() const;
	string GetMajor() const;
	StudentType GetType() const;
	Course* GetCourseList() const;
	Student* GetNext() const;
};