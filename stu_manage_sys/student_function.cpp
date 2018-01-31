#ifndef STUDENT_H
#define STUDENT_H
#include "list_student.h"
#endif

Course::Course()
{
	Next=NULL;
}

Course::~Course()
{
	Course *now=this, *next;
	while(now)
	{
		next=now->Next;
		delete now;
		now=next;
	}
}

void Course::Update(string NewName, string NewNum, double NewGrade, double NewCredit)//修改
{
	Name=NewName;
	Num=NewNum;
	Grade=NewGrade;
	Credit=NewCredit;
}

Course* Course::Find(string NewNum)//返回NULL表示失败
{
	Course *temp=this;
	while(temp)
	{
		if(temp->Num==NewNum) break;
		temp=temp->Next;
	}
	return temp;
}

Course* Course::Add(Course* NewCourse)
{
	NewCourse->Next=this;
	return NewCourse;
}

Course* Course::Delete(string NewNum)
{
	Course* temp;
	if(Num==NewNum) return Next;
	temp=this;
	while(temp->Next)
	{
		if(temp->Next->GetNum()==NewNum)
		{
			temp->Next=temp->Next->Next;
			break;
		}
		temp=temp->Next;
	}
	return this;
}

string Course::GetName() const  //获得信息
{
	return Name;
}

string Course::GetNum() const
{
	return Num;
}

double Course::GetGrade() const
{
	return Grade;
}

double Course::GetCredit() const
{
	return Credit;
}

Course* Course::GetNext() const
{
	return Next;
}

Student::Student()
{
	Next=NULL;
	CourseList=NULL;
}

Student::~Student()
{
	Student *now=this, *next;
	while(now)
	{
		next=now->Next;
		delete now;
		now=next;
	}
}

void Student::Update(string NewName, string NewNum, string NewMajor, StudentType NewType)
{
	Name=NewName;
	Num=NewNum;
	Major=NewMajor;
	Type=NewType;
}

Student* Student::Find(string NewNum)//返回NULL表示失败
{
	Student *temp=this;
	while(temp)
	{
		if(temp->Num==NewNum) break;
		temp=temp->Next;
	}
	return temp;
}

Student* Student::Add(Student* NewStudent)
{
	NewStudent->Next=this;
	return NewStudent;
}

Student* Student::Delete(string NewNum)
{
	Student* temp;
	if(Num==NewNum) return Next;
	temp=this;
	while(temp->Next)
	{
		if(temp->Next->GetNum()==NewNum)
		{
			temp->Next=temp->Next->Next;
			break;
		}
		temp=temp->Next;
	}
	return this;
}

int Student::DeleteCourse(string CourseNum)
{
	if(CourseList->Find(CourseNum))
	{
		CourseList=CourseList->Delete(CourseNum);
		return 1;
	}
	return 0;
}

void Student::UpdateCourse(Course *NewCourse)
{
	Course *temp=CourseList->Find(NewCourse->GetNum());
	if(temp)
	{
		if(NewCourse->GetGrade()>temp->GetGrade())
			temp->Update(temp->GetNum(), temp->GetName(), NewCourse->GetGrade(), temp->GetCredit());
	}
	else CourseList=CourseList->Add(NewCourse);
}

string Student::GetName() const//获得信息
{
	return Name;
}

string Student::GetNum() const
{
	return Num;
}

string Student::GetMajor() const
{
	return Major;
}

StudentType Student::GetType() const
{
	return Type;
}

Course* Student::GetCourseList() const
{
	return CourseList;
}

Student* Student::GetNext() const
{
	return Next;
}