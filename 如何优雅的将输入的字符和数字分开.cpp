# include <stdio.h>
# include <ctype.h>
# include <windows.h>
# include <string.h>

const size_t LENGTH = 50;

void eatspaces(void);
char *getname(char *name, size_t length);
bool getinteger(int *n);
bool isnewline(void);

int main(void)
{
	int number;
	char name[LENGTH];
	printf("Enther a sequence of integers and alphabetic names:\n");
	while(!isnewline())
	{
		if(getinteger(&number))
		{
			printf("number value = %d\n",number);
		}
		else if(strlen(getname(name,LENGTH)) > 0)
		{
			printf("name is:%s\n",name);
		}
		else
		{
			printf("Invalid input.\n");
			return 1;
		}
	}
	
	return 0;
}

void eatspaces()
{
	char temp = 0;
	while(isspace(temp = getchar()));
	ungetc(temp,stdin);
	
}

bool isnewline(void)
{
	char ch = 0;
	if((ch = getchar()) == '\n')
	{
		return true;
	}
	else
	{
		ungetc(ch,stdin);
		return false;
	}
}

bool getinteger(int *n)
{


	int value = 0;
	int sign = 1;
	char ch = 0;

	eatspaces();

	if((ch = getchar()) == '-')
	{
		sign = -1;
	}
	else if(isdigit(ch))
	{
		value = 10*value + (ch -'0');
	}
	else if(isalpha(ch))
	{
		ungetc(ch,stdin);
		return false;
	}

	while(isdigit(ch = getchar()))
	{
		value = 10 * value + (ch - '0');
	}
	ungetc(ch,stdin);
	*n = value*sign;
	return true;
}

char *getname(char *name,size_t length)
{
	eatspaces();
	size_t count = 0;
	char ch = 0;

	while(isalpha(ch = getchar()))
	{
		name[count++] = ch;
		if(count == length)
			break;
	}
	name[count] = '\0';
	if(count < length)
	{
		ungetc(ch,stdin);
	}
	return name;

}