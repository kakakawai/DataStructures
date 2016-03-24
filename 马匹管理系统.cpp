# include<stdio.h>
# include<ctype.h>

int NO(int);

int main(void)
{
	struct horse
	{
		int age;
		int height;
		char name[20];
		char father[20];
		char mother[20];
	};

	struct horse My_Horse[50];
	int hcount = 0;
	char text;

	for(;hcount < 50; hcount++)
	{
		
		printf("Do you want to enter details of a%s horse (Y or N)? \n",hcount ? " ":"nother");
		scanf(" %c",&text);
		if(tolower(text) == 'n')
		{
			break;
		}
		else if(tolower(text) == 'y')
		{
			printf("Now you enther details for NO.%d\n",NO(hcount));
		}
		else
		{
			printf("You can only choose one between 'Y' or 'N'.relax and try again.\n");
		}

		printf("Enter the name of the horse:");
		scanf("%s",My_Horse[hcount].name);

		printf("\nEnter the age of the horse:");
		scanf("%d",&My_Horse[hcount].age);

		printf("\nEnter the height of the horse:");
		scanf("%d",&My_Horse[hcount].height);

		printf("\nEnter the name of %s's father:",My_Horse[hcount].name);
		scanf("%s",My_Horse[hcount].father);

		printf("\nEnter the name of %s's mother:",My_Horse[hcount].name);
		scanf("%s",My_Horse[hcount].mother);
	}

	for(int i = 0; i<hcount; i++)
	{
		printf("\n=================\n");
		printf("%s is %d years old, %d hands height,and has %s and %s as parents.",My_Horse[i].name,My_Horse[i].age,My_Horse[i].height,My_Horse[i].father,My_Horse[i].mother);
	}
	printf("\n=================\n");
	return 0;
}

int NO(int n)
{
	return ++n;
}