#ifndef TEACHER_H
#define TEACHER_H
#include "list_teacher.h"
#endif

Teacher::Teacher()
{
	Next=NULL;
}

Teacher::~Teacher()
{
	Teacher *now=this, *next;
	while(now)
	{
		next=now->Next;
		delete now;
		now=next;
	}
}

void Teacher::Update(string NewName, string NewNum)//修改
{
	Name=NewName;
	Num=NewNum;
}

Teacher* Teacher::Find(string NewNum)//返回NULL表示失败
{
	Teacher *temp=this;
	while(temp)
	{
		if(temp->Num==NewNum) break;
		temp=temp->Next;
	}
	return temp;
}

Teacher* Teacher::Add(Teacher* NewTeacher)
{
	NewTeacher->Next=this;
	return NewTeacher;
}

Teacher* Teacher::Delete(string NewNum)
{
	Teacher* temp;
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

string Teacher::GetName() const  //获得信息
{
	return Name;
}

string Teacher::GetNum() const
{
	return Num;
}

Teacher* Teacher::GetNext() const
{
	return Next;
}
