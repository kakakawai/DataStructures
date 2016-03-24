# include<stdio.h>
# include<string.h>
# include<ctype.h>
# include<stdlib.h>

const int MAXLEN = 30;

void listfile(const char *);

int main(void)
{
	const char *filename = "D:\\mydata.bin";
	char name[MAXLEN];
	size_t length = 0;
	int age  = 0;
	char answer = 'y';

	FILE *pfile = fopen(filename,"wb+");

	do
	{
		fflush(stdin);

		printf("\nEnter a name less than %d characters:",MAXLEN);
		gets(name);

		printf("\nEnter the age of %s:",name);
		scanf(" %d",&age);

		length = strlen(name);
		fwrite(&length,sizeof(length),1,pfile);
		fwrite(name,sizeof(char),length,pfile);
		fwrite(&age,sizeof(age),1,pfile);

		printf("Do you want to enter another(Y or N)? " );
		scanf("\n%c", &answer);
	}while(tolower(answer) == 'y');

	fclose(pfile);

	listfile(filename);

	return 0;
}

void listfile(const char *filename)
{
	size_t length = 0;
	char name[MAXLEN];
	int age = 0;
	char format[20];
	FILE *pfile;

	sprintf(format,"%%-%ds Age:%%4d\n",MAXLEN);

	if(!(pfile = fopen(filename,"rb")))
	{
		printf("\nError\n");
		exit(1);
	}

	printf("\nThe contents of %s are:\n",filename);

	while(fread(&length,sizeof(length),1,pfile) == 1)
	{
		if(length+1>MAXLEN)
		{
			printf("\nName too long");
			exit(1);
		}
		fread(name,sizeof(char),length,pfile);
		name[length] = '\0';
		fread(&age,sizeof(age),1,pfile);
		printf(format,name,age);
	}
	fclose(pfile);
}