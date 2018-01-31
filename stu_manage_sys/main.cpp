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
const string ManagerCommand="Arashi";//����Ա�����Ϊ����Ա��֤ʹ��

void GotoStudent();//ѧ����½���棬�����Բ鿴�Լ������гɼ�
void GotoTeacher();//��ʦ��½����
void GotoManager();//����Ա��½����
void AddTeacher();//�����µ���ʦ
void AddStudent();//�����µ�ѧ��
void AddCourse();//�����µĿγ�
void ShowStudent(Student *CurStu);//��ʾѧ��CurStu�����гɼ�
void SearchStudent();//����ѧ�������ض�ѧ��������Ϣ�޸ģ��ɼ�ɾ�����ɼ��޸�
void SearchTeacher();//������ʦ�����ض���ʦ������Ϣ�޸�
void ShowAllStudent();//��ʾ����ѧ��������ѧ��
void ShowAllTeacher();//��ʾ���н�ʦ����������

Student *StudentList=NULL;
Teacher *TeacherList=NULL;

int main()
{
	int Req;

	cout<<"******************************************************************************"<<endl;
	cout<<"***************************��ӭ��½ѧ���ɼ�����ϵͳ***************************"<<endl;

	while(1)
	{
		cout<<"******************************************************************************"<<endl;
		cout<<"    1��ѧ����½          2����ʦ��½          3�������½          4���˳�"<<endl;
		cin>>Req;
		if(Req==4) break;
		switch(Req)
		{
			case 1:GotoStudent();break;
			case 2:GotoTeacher();break;
			case 3:GotoManager();break;
			default:cout<<"������Ч"<<endl; break;
		}

	}

	cout<<"******************************************************************************"<<endl;
	cout<<"***************************��лʹ��ѧ���ɼ�����ϵͳ***************************"<<endl;
	cout<<"******************************************************************************"<<endl;

	return 0;
}

void GotoStudent()
{
	string Command1, Command2;
	Student *temp;
	while(1)
	{
		cout<<"***********************************ѧ����½***********************************"<<endl;
		cout<<"������������������return���������棺";
		cin>>Command1;
		if(Command1=="return") return;
		cout<<"������ѧ�ţ�";
		cin>>Command2;
		temp=StudentList->Find(Command2);
		if(temp==NULL) cout<<"��ѧ�Ų����ڣ�"<<endl;
		else if(temp->GetName()!=Command1) cout<<"��Ϣ��ƥ��"<<endl;
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
		cout<<"***********************************��ʦ��½***********************************"<<endl;
		cout<<"������������������return���������棺";
		cin>>Command1;
		if(Command1=="return") return;
		cout<<"�����빤�ţ�";
		cin>>Command2;
		temp=TeacherList->Find(Command2);
		if(temp==NULL) cout<<"������Ч"<<endl;
		else if(temp->GetName()!=Command1) cout<<"��Ϣ��ƥ��"<<endl;
		else break;
	}
	int Req;
	while(1)
	{
		cout<<"***********************************��ʦ����***********************************"<<endl;
		cout<<"������"<<temp->GetName()<<"  ���ţ�"<<temp->GetNum()<<endl;
		cout<<"1������ѧ��  2���޸�����  3����ӳɼ�  4�����ѧ��  5����ʾ����ѧ��  6���˳�"<<endl;
		cin>>Req;
		if(Req==6) return;
		switch(Req)
		{
			case 1: SearchStudent(); break;
			case 2: cout<<"�������µ�������";
					cin>>Command1;
					temp->Update(Command1, temp->GetNum());
					cout<<"�޸ĳɹ�"<<endl;
					break;
			case 3: AddCourse(); break;
			case 4: AddStudent(); break;
			case 5: ShowAllStudent(); break;
			default: cout<<"������Ч"<<endl;
		}
	}
}

void GotoManager()
{
	string Command;
	while(1)
	{
		cout<<"*********************��������������return����������***********************"<<endl;
		cin>>Command;
		if(Command=="return") return;
		if(Command==ManagerCommand) break;
		else cout<<"�������"<<endl;
	}
	int Req;
	while(1)
	{
		cout<<"*********************************����Աģʽ***********************************"<<endl;
		cout<<"       1������ѧ��  2�����ҽ�ʦ  3����ӳɼ�  4�����ѧ��  5����ӽ�ʦ"<<endl;
		cout<<"     6������ѧ����Ϣ  7�����н�ʦ��Ϣ  8��ɾ��ѧ��  9��ɾ����ʦ  10���˳�"<<endl;
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
			case 8: cout<<"������ѧ��ѧ�ţ�";
					cin>>Command;
					StudentList=StudentList->Delete(Command);
			case 9: cout<<"�������ʦ����";
					cin>>Command;
					TeacherList=TeacherList->Delete(Command);
			default: cout<<"������Ч"<<endl;
		}
	}
}

void ShowStudent(Student *CurStu)//��ʾѧ��CurStu�����гɼ�
{
	double TotalCredit=0, GPA=0;
	Course *CurCourse;
	
	cout<<"*******************************ѧ����Ϣ***************************************"<<endl;
	cout<<"ѧ��������"<<CurStu->GetName()<<endl;
	cout<<"ѧ��ѧ�ţ�"<<CurStu->GetNum()<<endl;
	cout<<"ѧ��רҵ��"<<CurStu->GetMajor()<<endl;
	switch(CurStu->GetType())
	{
		case BACHELOR:cout<<"ѧ����𣺱�����"<<endl; break;
		case MASTER:cout<<"ѧ�����˶ʿ�о���"<<endl; break;
		case DOCTOR:cout<<"ѧ����𣺲�ʿ��"<<endl; break;
	}
	CurCourse=CurStu->GetCourseList();
	while(CurCourse)
	{
		cout<<"�γ̴��룺"<<CurCourse->GetNum()<<"  �γ����ƣ�"<<CurCourse->GetName()<<"  "<<setprecision(1)<<CurCourse->GetCredit()<<"ѧ��  �ɼ���"<<setprecision(0)<<CurCourse->GetGrade()<<endl;
		if(CurCourse->GetGrade()>=60)
		{
			TotalCredit+=CurCourse->GetCredit();
			GPA+=CurCourse->GetGrade()*CurCourse->GetCredit();
		}
		CurCourse=CurCourse->GetNext();
	}
	if(TotalCredit>0) GPA=(GPA/TotalCredit-45)/10;
	cout<<setiosflags(ios::fixed)<<setprecision(1)<<"��ѧ�֣�"<<TotalCredit<<"  ������"<<setiosflags(ios::fixed)<<setprecision(2)<<GPA<<endl;
}

void AddTeacher()//�����µ���ʦ
{
	cout<<"******************************************************************************"<<endl;
	string Command1, Command2;
	Teacher *temp;
	while(1)
	{
		cout<<"�������½�ʦ�Ĺ��ţ�������returnѡ���˻���һ���棺";
		cin>>Command1;
		if(Command1=="return") return;
		temp=TeacherList->Find(Command1);
		if(temp)
		{
			cout<<"�ý�ʦ�Ѵ��ڣ�"<<endl;
			continue;
		}
		cout<<"�������½�ʦ��������";
		cin>>Command2;
		temp=new Teacher;
		if(temp)
		{
			temp->Update(Command2, Command1);
			TeacherList=TeacherList->Add(temp);
			cout<<"�����ɹ���"<<endl;
			return;
		}
		else cout<<"�ڴ����ʧ�ܣ�"<<endl;
	}
}

void AddStudent()//�����µ�ѧ��
{
	cout<<"*********************************���ѧ��*************************************"<<endl;
	string Command1, Command2, Command3;
	int Command4;
	Student *temp;
	while(1)
	{
		cout<<"��������ѧ����ѧ�ţ�������returnѡ���˻���һ���棺";
		cin>>Command1;
		if(Command1=="return") return;
		temp=StudentList->Find(Command1);
		if(temp)
		{
			cout<<"��ѧ���Ѵ��ڣ�"<<endl;
			continue;
		}
		cout<<"��������ѧ����������";
		cin>>Command2;
		cout<<"��������ѧ����רҵ��";
		cin>>Command3;
		while(1)
		{
			cout<<"��ѧ������Ϊ��1��������  2��˶ʿ�о���  3����ʿ��  ";
			cin>>Command4;
			if(Command4<1 || Command4>3) cout<<"������Ч"<<endl;
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
			cout<<"�����ɹ���"<<endl;
			return;
		}
		else cout<<"�ڴ����ʧ�ܣ�"<<endl;
	}
}

void AddCourse()//�����µĿγ�
{
	string NewName, NewNum, NewStuNum;
	Course *NewCourse;
	Student *CurStu;
	double NewCredit, NewGrade;  
	while(1)
	{
		cout<<"**********************************����¿γ�**********************************"<<endl;
		cout<<"�¿γ̵����ƣ�������return�˻���һ���棺";
		cin>>NewName;
		if(NewName=="return") return;
		cout<<"�¿γ̵ı�ţ�";
		cin>>NewNum;
		cout<<"�¿γ̵�ѧ�֣�";
		cin>>NewCredit;

		NewCourse=new Course;
		if(NewCourse==NULL)
		{
			cout<<"�ڴ����ʧ�ܣ�"<<endl;
			continue;
		}
		while(1)
		{
			cout<<"����ѧ��ѧ�ţ�������return��ʾ������ɣ�";
			cin>>NewStuNum;
			if(NewStuNum=="return") break;
			CurStu=StudentList->Find(NewStuNum);
			if(CurStu==NULL)
			{
				cout<<"ѧ�������ڣ�"<<endl;
				continue;
			}
			cout<<"����ѧ���ɼ���";
			cin>>NewGrade;
			NewCourse=new Course;
			NewCourse->Update(NewName, NewNum, NewGrade, NewCredit);
			CurStu->UpdateCourse(NewCourse);
		}
	}
}

void SearchStudent()//����ѧ��
{
	string name, num, major;
	int Req;
	Student *CurStu;
	Course *CurCourse;
	string CourseNum;
	int NewGrade, type;
	while(1)
	{
		cout<<"***********************************����ѧ��***********************************"<<endl;
		cout<<"������ѧ��ѧ�ţ�������return������һ���棺";
		cin>>num;
		if(num=="return") return;
		CurStu=StudentList->Find(num);
		if(CurStu==NULL)
		{
			cout<<"��ѧ�Ų����ڣ�"<<endl;
			continue;
		}
		ShowStudent(CurStu);
		while(1)
		{
			cout<<"*******************************�޸�ѧ��***************************************"<<endl;
			cout<<"               1���޸ĳɼ�  2��ɾ���ɼ�  3���޸���Ϣ  4������"<<endl;
			cin>>Req;
			if(Req==4) break;
			switch(Req)
			{
				case 1:	cout<<"�����޸ĵĿγ̱�ţ�";
						cin>>CourseNum;
						CurCourse=CurStu->GetCourseList()->Find(CourseNum);
						if(CurCourse)
						{
							cout<<"�����µĳɼ�";
							cin>>NewGrade;
							CurCourse->Update(CurCourse->GetName(), CurCourse->GetNum(), NewGrade, CurCourse->GetCredit());
							cout<<"�޸ĳɹ���"<<endl;
						}
						else cout<<"��ѧ��û�и��ųɼ���"<<endl;
						break;
				case 2:	cout<<"����ɾ���Ŀγ̱�ţ�";
						cin>>CourseNum;
						if(CurStu->DeleteCourse(CourseNum))
							cout<<"ɾ���ɹ���"<<endl;
						else cout<<"ɾ��ʧ�ܣ�"<<endl;
						break;
				case 3:	cout<<"����ѧ���µ�������";
						cin>>name;
						cout<<"����ѧ���µ�רҵ��";
						cin>>major;
						while(1)
						{
							cout<<"����ѧ���µ����1������  2��˶ʿ�о���  3����ʿ��  ";
							cin>>type;
							if(type<1 || type>3)
								cout<<"������Ч��"<<endl;
							else break;
						}
						switch(type)
						{
							case 1:CurStu->Update(name, num, major, BACHELOR); break;
							case 2:CurStu->Update(name, num, major, MASTER); break;
							case 3:CurStu->Update(name, num, major, DOCTOR); break;
						}
						cout<<"�޸ĳɹ���"<<endl;
						break;
				default:cout<<"������Ч��"<<endl;
						break;
			}
		}
	}
}

void SearchTeacher()//���ҽ�ʦ
{
	string name, num;
	Teacher *CurTch;
	while(1)
	{
		cout<<"******************************************************************************"<<endl;
		cout<<"�������ʦ���ţ�������return������һ���棺";
		cin>>num;
		if(num=="return") return;
		CurTch=TeacherList->Find(num);
		if(CurTch==NULL)
		{
			cout<<"�ù��Ų����ڣ�"<<endl;
			continue;
		}
		cout<<"�������ʦ������";
		cin>>name;
		CurTch->Update(name, num);
		cout<<"�޸ĳɹ���"<<endl;
		break;
	}
}

void ShowAllStudent()//��ʾ����ѧ��
{
	Student *temp=StudentList;
	cout<<"*********************************ѧ���б�*************************************"<<endl;
	while(temp)
	{
		cout<<temp->GetName()<<"  "<<temp->GetNum()<<endl;
		temp=temp->GetNext();
	}
}

void ShowAllTeacher()//��ʾ����ѧ��
{
	Teacher *temp=TeacherList;
	cout<<"*********************************��ʦ�б�*************************************"<<endl;
	while(temp)
	{
		cout<<temp->GetName()<<"  "<<temp->GetNum()<<endl;
		temp=temp->GetNext();
	}
}
