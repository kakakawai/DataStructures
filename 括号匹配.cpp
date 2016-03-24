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
	printf("ÊäÈë×Ö·û´®(ÒÔ#ºÅ½áÊø):");
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
					if(!StackEmpty(S) && x == '(')      ////´íÎó£ºÊä³öX=£¨£¬µ«ÊÇifÓï¾äÖĞ¡¾x == '('¡¿ÅĞ¶Ï´íÎó
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
		printf("Æ¥Åä³É¹¦!\n");
	}
	else 
	{
		printf("Æ¥ÅäÊ§°Ü!\n");
	}
}

void InitStack(SqStack *S)
{
	S->base = S->top = SElemType;
	if(!S->base)
	{
		printf("ÄÚ´æ·ÖÅä´íÎó£¡\n");
		exit(1);
	}
	S->stacksize = MAXSIZE;
	printf("³õÊ¼»¯³É¹¦!\n");
}

void push(SqStack *S, char c)
{
	S->top++;
	if(S->top == S->base)
	{
		printf("ÈëÕ»Îª¿Õ!\n");
		exit(1);
	}
	*S->top = c;
	
	printf("ÈëÕ»³É¹¦!\n");
}

void pop(SqStack *S, char *px)
{
	if(S->top == S->base)
	{
		printf("³öÕ»Îª¿Õ!\n");
		exit(1);
	}
	
	*px = *S->top;
	S->top--;
}

void GetTop(SqStack *S,char *px)
{
	if(S->top == S->base)
	{
		printf("Õ»¶¥Îª¿Õ!\n");
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