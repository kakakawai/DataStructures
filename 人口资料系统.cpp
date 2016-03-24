# include<stdio.h>
# include<ctype.h>
# include<stdlib.h>
# include<windows.h>

struct Family *get_person(void);

bool related (struct Family *,struct Family *);
bool parents(struct Family *,struct Family *);

struct data
{
	int day;
	int month;
	int year;
};

struct Family
{
	struct data dob;
	char name[20];
	char father[20];
	char mother[20];
	struct Family *pfather;
	struct Family *pmother;
	struct Family *next;
	struct Family *previous;
};

int main (void)
{
	struct Family *first = NULL;
	struct Family *current = NULL;
	struct Family *last = NULL;
	
	char test = '\0';
	
	for(;;)
	{
		printf("\nDo you want to enter details of a%s person(Y or N)?",first ? "":"nother");
		scanf(" %c",&test);
		
		if(tolower(test) == 'y'){}
		else if(tolower(test) == 'n')
		{
			break;
		}
		
		current = get_person();
		
		if(first == NULL)
		{
			first = current;
			last = current;
		}
		else
		{
			last->next = current;
			current->previous = last;
			last = current;
		}
		
	}
	
	current = first;
	while(current->next != NULL)
	{
		int parent = 0;
		last = current;
		
		while(last != NULL)
		{
			if(related(current,last))
			{
				if(++parent == 2)
					break;
			}
			last = last->next;
		}
		current = current->next;
	}
	
	while(current != NULL)
	{
		printf("\n================================\n");
		printf("\n%s was born %d/%d/%d, and has %s and %s as parents.",current->name,current->dob.day,current->dob.month,current->dob.year,current->father,current->mother);
		if(current->pfather != NULL)
		{
			printf("%s's father %s's birthday is %d/%d/%d,",current->name,current->father,current->pfather->dob.day,current->pfather->dob.month,current->pfather->dob.year);
		}
		if(current->mother != NULL)
		{
			printf("%s's mother %s's birthday is %d/%d/%d,",current->name,current->mother,current->pmother->dob.day,current->pmother->dob.month,current->pmother->dob.year);
		}
		last = current;
		current = current->previous;

	}
	printf("\n================================\n");

	current = first;
	while(current != NULL)
	{
		last = current;
		current = current->next;
		free(last);
	}
	return 0;
}

struct Family *get_person(void)
{
	struct Family *temp;
	
	temp = (struct Family *)malloc(sizeof(struct Family));
	
	printf("\nEnter the name of the person:");
	scanf("%s",temp->name);
	printf("\n%s's birthday is (day month year):",temp->name);
	scanf("%d %d %d",&temp->dob.day,&temp->dob.month,&temp->dob.year);
	printf("\nWho is %s's father:",temp->name);
	scanf("%s",temp->father);
	printf("\nWho is %s's mother:",temp->name);
	scanf("%s",temp->mother);
	
	temp->next = temp->previous = NULL;
	
	return temp;
}

bool related(struct Family *p1,struct Family *p2)
{
	return (parents(p1,p2)||parents(p2,p1));
}

bool parents(struct Family *p1,struct Family *p2)
{
	if(strcmp(p1->father,p2->name) == 0)
	{
		p1->pfather = p2;
		return true;
	}
	if(strcmp(p1->mother,p2->name) == 0)
	{
		p1->pmother = p2;
		return true;
	}
	else
	{
		return false;
	}
}

