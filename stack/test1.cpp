
#include "Stack.cpp"

int main()
{
	Stack S;
	char c[100];
	int i;


	gets(c);
	for(i = 0;i<strlen(c);i++)
	{
		if(c[i]=='('||c[i]=='[')
			S.push(c[i]);
		else if(c[i]==')')
		{
			if(S.top()=='(')
				S.pop();
			else
			{
				cout<<"Brackets don't match!"<<endl;
				break;
			}
		}
		else if(c[i]==']')
		{
			if(S.top()=='[')
				S.pop();
			else 
			{
				cout<<"Brackets don't match!"<<endl;
				break;
			}
		}
	}

	if(i==strlen(c))
        if(!S.is_empty())
			cout<<"Brackets don't match!"<<endl;
		else
			cout<<"Brackets match!"<<endl;
	
    system("pause");	

}
