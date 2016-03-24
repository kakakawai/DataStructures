# include<stdio.h>
# include<ctype.h>
# include<stdlib.h>

int main(void)
{
	struct horse
	{
		int age;
		int height;
		char name[20];
		char father[20];
		char mother[20];
		struct horse *next;
	};
	
    struct horse *first = NULL;//第一个结构
	struct horse *current = NULL;//当前结构
	struct horse *previous = NULL;//上一个结构
	char test = '\0';
	
	for(;;)
	{
		printf("\nDo you want to enter details of a%s horse (Y or N)?",first ? "nother":"");
		scanf(" %c",&test);
		if(tolower(test) == 'n')
			break;
		else if(tolower(test) == 'y'){}
		else
		{
			break;
		}
		
		current = (struct horse*) malloc(sizeof(struct horse));
		
		if(first == NULL)
		{
			first = current;
		}
		if(previous != NULL)
		{
			previous->next = current;
		}
		
		printf("\nEnter the name of the horse:");
		scanf("%s",current->name);
		
		printf("\nHow old is %s:",current->name);
		scanf("%d",&current->age);
		
		printf("\nHow high is %s:",current->name);
		scanf("%d",&current->height);
		
		printf("\nWho is %s's father:",current->name);
		scanf("%s",current->father);
		
		printf("\nWho is %s's mother:",current->name);
		scanf("%s",current->mother);

		current->next = NULL;
		previous = current;
	}
	
	current = first;
//==========================================
//	          遍历链表
//==========================================
	while(current != NULL)//当current为NULL时，表示链表到达最后，此时跳出
	{
		printf("\n====================\n");
		printf("%s is %d years old, %d hands high, and has %s and %s as parents.\n",current->name,current->age,current->height,current->father,current->mother);
		previous = current;//把“当前结构”复制给“上一个结构”（为了后面释放内存）
		current = current->next;//把“下一个结构”复制给“当前结构”
		free(previous);//释放上一个结构（此时的“上一个结构”表示的是复制过来的“当前结构”）

	}
	printf("\n====================\n");
	
	return 0;
}