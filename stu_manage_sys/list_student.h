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
	string Name, Num;     //�γ����ƣ����
	double Grade, Credit; //�ٷ��Ƴɼ��������ѧ��
	Course *Next;
public:
	Course();
	~Course();
	void Update(string NewName, string NewNum, double NewGrade, double NewCredit);//�޸�
	Course* Find(string NewNum);//����NULL��ʾʧ��
	Course* Add(Course* NewCourse);
	Course* Delete(string NewNum);

	string GetName() const;  //�����Ϣ
	string GetNum() const;
	double GetGrade() const;
	double GetCredit() const;
	Course* GetNext() const;
};

class Student
{
private:
	string Name, Num, Major;  //ѧ��������ѧ�ţ�רҵ
	StudentType Type;         //���ƣ�˶ʿ����ʿ
	Course *CourseList;       //�γ̶���
	Student *Next;
public:
	Student();
	~Student();
	void Update(string NewName, string NewNum, string NewMajor, StudentType NewType);
	Student* Find(string NewNum);//����NULL��ʾʧ��
	Student* Add(Student* NewStudent);
	Student* Delete(string NewNum);
	int DeleteCourse(string CourseNum);//����0��ʾɾ��ʧ��
	void UpdateCourse(Course *NewCourse);

	string GetName() const;//�����Ϣ
	string GetNum() const;
	string GetMajor() const;
	StudentType GetType() const;
	Course* GetCourseList() const;
	Student* GetNext() const;
};