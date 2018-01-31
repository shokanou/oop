#ifndef STUDENT_H
#define STUDENT_H
#include "list_student.h"
#endif

#ifndef TEACHER_H
#define TEACHER_H
#include "list_teacher.h"
#endif

#include<iostream>
#include<iomanip>
const string ManagerCommand="Arashi";//管理员口令，作为管理员验证使用

void GotoStudent();//学生登陆界面，仅可以查看自己的所有成绩
void GotoTeacher();//教师登陆界面
void GotoManager();//管理员登陆界面
void AddTeacher();//增加新的老师
void AddStudent();//增加新的学生
void AddCourse();//增加新的课程
void ShowStudent(Student *CurStu);//显示学生CurStu的所有成绩
void SearchStudent();//查找学生，对特定学生进行信息修改，成绩删除，成绩修改
void SearchTeacher();//查找老师，对特定老师进行信息修改
void ShowAllStudent();//显示所有学生的姓名学号
void ShowAllTeacher();//显示所有教师的姓名工号

Student *StudentList=NULL;
Teacher *TeacherList=NULL;

int main()
{
	int Req;

	cout<<"******************************************************************************"<<endl;
	cout<<"***************************欢迎登陆学生成绩管理系统***************************"<<endl;

	while(1)
	{
		cout<<"******************************************************************************"<<endl;
		cout<<"    1：学生登陆          2：教师登陆          3：管理登陆          4：退出"<<endl;
		cin>>Req;
		if(Req==4) break;
		switch(Req)
		{
			case 1:GotoStudent();break;
			case 2:GotoTeacher();break;
			case 3:GotoManager();break;
			default:cout<<"输入无效"<<endl; break;
		}

	}

	cout<<"******************************************************************************"<<endl;
	cout<<"***************************感谢使用学生成绩管理系统***************************"<<endl;
	cout<<"******************************************************************************"<<endl;

	return 0;
}

void GotoStudent()
{
	string Command1, Command2;
	Student *temp;
	while(1)
	{
		cout<<"***********************************学生登陆***********************************"<<endl;
		cout<<"请输入姓名，或输入return返回主界面：";
		cin>>Command1;
		if(Command1=="return") return;
		cout<<"请输入学号：";
		cin>>Command2;
		temp=StudentList->Find(Command2);
		if(temp==NULL) cout<<"该学号不存在！"<<endl;
		else if(temp->GetName()!=Command1) cout<<"信息不匹配"<<endl;
		else break;
	}
	ShowStudent(temp);
}

void GotoTeacher()
{
	string Command1, Command2;
	Teacher *temp;
	while(1)
	{
		cout<<"***********************************教师登陆***********************************"<<endl;
		cout<<"请输入姓名，或输入return返回主界面：";
		cin>>Command1;
		if(Command1=="return") return;
		cout<<"请输入工号：";
		cin>>Command2;
		temp=TeacherList->Find(Command2);
		if(temp==NULL) cout<<"工号无效"<<endl;
		else if(temp->GetName()!=Command1) cout<<"信息不匹配"<<endl;
		else break;
	}
	int Req;
	while(1)
	{
		cout<<"***********************************教师操作***********************************"<<endl;
		cout<<"姓名："<<temp->GetName()<<"  工号："<<temp->GetNum()<<endl;
		cout<<"1：查找学生  2：修改资料  3：添加成绩  4：添加学生  5：显示所有学生  6：退出"<<endl;
		cin>>Req;
		if(Req==6) return;
		switch(Req)
		{
			case 1: SearchStudent(); break;
			case 2: cout<<"请输入新的姓名：";
					cin>>Command1;
					temp->Update(Command1, temp->GetNum());
					cout<<"修改成功"<<endl;
					break;
			case 3: AddCourse(); break;
			case 4: AddStudent(); break;
			case 5: ShowAllStudent(); break;
			default: cout<<"输入无效"<<endl;
		}
	}
}

void GotoManager()
{
	string Command;
	while(1)
	{
		cout<<"*********************请输入口令，或输入return返回主界面***********************"<<endl;
		cin>>Command;
		if(Command=="return") return;
		if(Command==ManagerCommand) break;
		else cout<<"口令错误"<<endl;
	}
	int Req;
	while(1)
	{
		cout<<"*********************************管理员模式***********************************"<<endl;
		cout<<"       1：查找学生  2：查找教师  3：添加成绩  4：添加学生  5：添加教师"<<endl;
		cout<<"     6：所有学生信息  7：所有教师信息  8：删除学生  9：删除教师  10：退出"<<endl;
		cin>>Req;
		if(Req==10) return;
		switch(Req)
		{
			case 1: SearchStudent(); break;
			case 2: SearchTeacher(); break;
			case 3: AddCourse(); break;
			case 4: AddStudent(); break;
			case 5: AddTeacher(); break;
			case 6: ShowAllStudent(); break;
			case 7: ShowAllTeacher(); break;
			case 8: cout<<"请输入学生学号：";
					cin>>Command;
					StudentList=StudentList->Delete(Command);
			case 9: cout<<"请输入教师工号";
					cin>>Command;
					TeacherList=TeacherList->Delete(Command);
			default: cout<<"输入无效"<<endl;
		}
	}
}

void ShowStudent(Student *CurStu)//显示学生CurStu的所有成绩
{
	double TotalCredit=0, GPA=0;
	Course *CurCourse;
	
	cout<<"*******************************学生信息***************************************"<<endl;
	cout<<"学生姓名："<<CurStu->GetName()<<endl;
	cout<<"学生学号："<<CurStu->GetNum()<<endl;
	cout<<"学生专业："<<CurStu->GetMajor()<<endl;
	switch(CurStu->GetType())
	{
		case BACHELOR:cout<<"学生类别：本科生"<<endl; break;
		case MASTER:cout<<"学生类别：硕士研究生"<<endl; break;
		case DOCTOR:cout<<"学生类别：博士生"<<endl; break;
	}
	CurCourse=CurStu->GetCourseList();
	while(CurCourse)
	{
		cout<<"课程代码："<<CurCourse->GetNum()<<"  课程名称："<<CurCourse->GetName()<<"  "<<setprecision(1)<<CurCourse->GetCredit()<<"学分  成绩："<<setprecision(0)<<CurCourse->GetGrade()<<endl;
		if(CurCourse->GetGrade()>=60)
		{
			TotalCredit+=CurCourse->GetCredit();
			GPA+=CurCourse->GetGrade()*CurCourse->GetCredit();
		}
		CurCourse=CurCourse->GetNext();
	}
	if(TotalCredit>0) GPA=(GPA/TotalCredit-45)/10;
	cout<<setiosflags(ios::fixed)<<setprecision(1)<<"总学分："<<TotalCredit<<"  均绩："<<setiosflags(ios::fixed)<<setprecision(2)<<GPA<<endl;
}

void AddTeacher()//增加新的老师
{
	cout<<"******************************************************************************"<<endl;
	string Command1, Command2;
	Teacher *temp;
	while(1)
	{
		cout<<"请输入新教师的工号，或输入return选择退回上一界面：";
		cin>>Command1;
		if(Command1=="return") return;
		temp=TeacherList->Find(Command1);
		if(temp)
		{
			cout<<"该教师已存在！"<<endl;
			continue;
		}
		cout<<"请输入新教师的姓名：";
		cin>>Command2;
		temp=new Teacher;
		if(temp)
		{
			temp->Update(Command2, Command1);
			TeacherList=TeacherList->Add(temp);
			cout<<"操作成功！"<<endl;
			return;
		}
		else cout<<"内存分配失败！"<<endl;
	}
}

void AddStudent()//增加新的学生
{
	cout<<"*********************************添加学生*************************************"<<endl;
	string Command1, Command2, Command3;
	int Command4;
	Student *temp;
	while(1)
	{
		cout<<"请输入新学生的学号，或输入return选择退回上一界面：";
		cin>>Command1;
		if(Command1=="return") return;
		temp=StudentList->Find(Command1);
		if(temp)
		{
			cout<<"该学生已存在！"<<endl;
			continue;
		}
		cout<<"请输入新学生的姓名：";
		cin>>Command2;
		cout<<"请输入新学生的专业：";
		cin>>Command3;
		while(1)
		{
			cout<<"该学生类型为：1：本科生  2：硕士研究生  3：博士生  ";
			cin>>Command4;
			if(Command4<1 || Command4>3) cout<<"输入无效"<<endl;
			else break;
		}
		temp=new Student;
		if(temp)
		{
			switch(Command4)
			{
				case 1:temp->Update(Command2, Command1, Command3, BACHELOR); break;
				case 2:temp->Update(Command2, Command1, Command3, MASTER); break;
				case 3:temp->Update(Command2, Command1, Command3, DOCTOR); break;
			}
			StudentList=StudentList->Add(temp);
			cout<<"操作成功！"<<endl;
			return;
		}
		else cout<<"内存分配失败！"<<endl;
	}
}

void AddCourse()//增加新的课程
{
	string NewName, NewNum, NewStuNum;
	Course *NewCourse;
	Student *CurStu;
	double NewCredit, NewGrade;  
	while(1)
	{
		cout<<"**********************************添加新课程**********************************"<<endl;
		cout<<"新课程的名称，或输入return退回上一界面：";
		cin>>NewName;
		if(NewName=="return") return;
		cout<<"新课程的编号：";
		cin>>NewNum;
		cout<<"新课程的学分：";
		cin>>NewCredit;

		NewCourse=new Course;
		if(NewCourse==NULL)
		{
			cout<<"内存分配失败！"<<endl;
			continue;
		}
		while(1)
		{
			cout<<"输入学生学号，或输入return表示输入完成：";
			cin>>NewStuNum;
			if(NewStuNum=="return") break;
			CurStu=StudentList->Find(NewStuNum);
			if(CurStu==NULL)
			{
				cout<<"学生不存在！"<<endl;
				continue;
			}
			cout<<"输入学生成绩：";
			cin>>NewGrade;
			NewCourse=new Course;
			NewCourse->Update(NewName, NewNum, NewGrade, NewCredit);
			CurStu->UpdateCourse(NewCourse);
		}
	}
}

void SearchStudent()//查找学生
{
	string name, num, major;
	int Req;
	Student *CurStu;
	Course *CurCourse;
	string CourseNum;
	int NewGrade, type;
	while(1)
	{
		cout<<"***********************************查找学生***********************************"<<endl;
		cout<<"请输入学生学号，或输入return返回上一界面：";
		cin>>num;
		if(num=="return") return;
		CurStu=StudentList->Find(num);
		if(CurStu==NULL)
		{
			cout<<"该学号不存在！"<<endl;
			continue;
		}
		ShowStudent(CurStu);
		while(1)
		{
			cout<<"*******************************修改学生***************************************"<<endl;
			cout<<"               1：修改成绩  2：删除成绩  3：修改信息  4：返回"<<endl;
			cin>>Req;
			if(Req==4) break;
			switch(Req)
			{
				case 1:	cout<<"输入修改的课程编号：";
						cin>>CourseNum;
						CurCourse=CurStu->GetCourseList()->Find(CourseNum);
						if(CurCourse)
						{
							cout<<"输入新的成绩";
							cin>>NewGrade;
							CurCourse->Update(CurCourse->GetName(), CurCourse->GetNum(), NewGrade, CurCourse->GetCredit());
							cout<<"修改成功！"<<endl;
						}
						else cout<<"该学生没有该门成绩！"<<endl;
						break;
				case 2:	cout<<"输入删除的课程编号：";
						cin>>CourseNum;
						if(CurStu->DeleteCourse(CourseNum))
							cout<<"删除成功！"<<endl;
						else cout<<"删除失败！"<<endl;
						break;
				case 3:	cout<<"输入学生新的姓名：";
						cin>>name;
						cout<<"输入学生新的专业：";
						cin>>major;
						while(1)
						{
							cout<<"输入学生新的类别：1：本科  2：硕士研究生  3：博士生  ";
							cin>>type;
							if(type<1 || type>3)
								cout<<"输入无效！"<<endl;
							else break;
						}
						switch(type)
						{
							case 1:CurStu->Update(name, num, major, BACHELOR); break;
							case 2:CurStu->Update(name, num, major, MASTER); break;
							case 3:CurStu->Update(name, num, major, DOCTOR); break;
						}
						cout<<"修改成功！"<<endl;
						break;
				default:cout<<"输入无效！"<<endl;
						break;
			}
		}
	}
}

void SearchTeacher()//查找教师
{
	string name, num;
	Teacher *CurTch;
	while(1)
	{
		cout<<"******************************************************************************"<<endl;
		cout<<"请输入教师工号，或输入return返回上一界面：";
		cin>>num;
		if(num=="return") return;
		CurTch=TeacherList->Find(num);
		if(CurTch==NULL)
		{
			cout<<"该工号不存在！"<<endl;
			continue;
		}
		cout<<"请输入教师姓名：";
		cin>>name;
		CurTch->Update(name, num);
		cout<<"修改成功！"<<endl;
		break;
	}
}

void ShowAllStudent()//显示所有学生
{
	Student *temp=StudentList;
	cout<<"*********************************学生列表*************************************"<<endl;
	while(temp)
	{
		cout<<temp->GetName()<<"  "<<temp->GetNum()<<endl;
		temp=temp->GetNext();
	}
}

void ShowAllTeacher()//显示所有学生
{
	Teacher *temp=TeacherList;
	cout<<"*********************************教师列表*************************************"<<endl;
	while(temp)
	{
		cout<<temp->GetName()<<"  "<<temp->GetNum()<<endl;
		temp=temp->GetNext();
	}
}
