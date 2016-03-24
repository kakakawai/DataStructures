# include<stdio.h>
# include<stdlib.h>
# include<windows.h>

# define MAXSIZE 100

typedef struct
{
	char *base;
	char *top;
	int stacksize;
}SqStack;

char SElemType[MAXSIZE];
void Matching(SqStack *S);
void InitStack(SqStack *S);
void push(SqStack *S,char c);
void pop(SqStack *S,char *px);
void GetTop(SqStack *S,char *px);
bool StackEmpty(SqStack *S);

int main(void)
{
	SqStack S;
	InitStack(&S);
	Matching(&S);
	

	return 0;
}

void Matching(SqStack *S)
{
	char c,x;
	char *px = &x;
	int i = 1;
	int flag = 1;
	char buffer[MAXSIZE];
	printf("�����ַ���(��#�Ž���):");
	gets(buffer);
	c = buffer[0];

/*	while(c != '#')
	{
		printf("\n%c",c); 
		i++;
		c = buffer[i];
	}
	c = buffer[0];
*/
	while(c != '#' && flag)
	{
		printf("\n2");
		switch(c)
		{
			case '(':
				{
					printf("\n3\n");
					push(S,c);
					break;
				}
			case ')':
				{
					GetTop(S,px);
					printf("x== %c",x);
					if(!StackEmpty(S) && x == '(')      ////�������X=��������if����С�x == '('���жϴ���
					{
						pop(S,px);
					}
					else
					{
						
						flag = 0;
					}
					break;
				}
			case ']':
				{
					GetTop(S,px);
					if((!StackEmpty(S)) && x == '[')
					{
						pop(S,px);
					}
					else
					{
						flag = 0;
					}
					break;
				}
		}
		c = buffer[i];
		i++;
		printf("c= %c",c);
	}
	if(!StackEmpty(S) && flag)
	{
		printf("ƥ��ɹ�!\n");
	}
	else 
	{
		printf("ƥ��ʧ��!\n");
	}
}

void InitStack(SqStack *S)
{
	S->base = S->top = SElemType;
	if(!S->base)
	{
		printf("�ڴ�������\n");
		exit(1);
	}
	S->stacksize = MAXSIZE;
	printf("��ʼ���ɹ�!\n");
}

void push(SqStack *S, char c)
{
	S->top++;
	if(S->top == S->base)
	{
		printf("��ջΪ��!\n");
		exit(1);
	}
	*S->top = c;
	
	printf("��ջ�ɹ�!\n");
}

void pop(SqStack *S, char *px)
{
	if(S->top == S->base)
	{
		printf("��ջΪ��!\n");
		exit(1);
	}
	
	*px = *S->top;
	S->top--;
}

void GetTop(SqStack *S,char *px)
{
	if(S->top == S->base)
	{
		printf("ջ��Ϊ��!\n");
		exit(1);
	}
	*px = *S->top;
	printf("x = %c",*px);
}

bool StackEmpty(SqStack *S)
{
	if(S->top == S->base)
	{
		return true;
	}
	else
	{
		return false;
	}
}