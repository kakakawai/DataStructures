# include <stdio.h>
# include <stdlib.h>
# include <windows.h>

int main (void)
{
	unsigned long *primes = NULL;
	unsigned long trial = 0;
	bool found = false;
	size_t total = 0;
	size_t count = 0;

	printf("输入需要的质数个数：\n");
	scanf("%d",&total);
	total = total < 4U ? 4U:total;

	primes = (unsigned long *)malloc(total*sizeof(unsigned long));
	if(primes == NULL)
	{
		printf("\n内存不够\n");
		return 0;
	}
    *primes = 2UL;
	*(primes+1) = 3UL;
	*(primes+2) = 5UL;
	count = 3U;
	trial = 5U;

	while(count<total)
	{
		
		trial +=2UL;
		for(size_t i = 0;i<total;i++)
		{
         if(!(found = trial % *(primes + i)))
		 {
			 break;
		 }
		 if(found)
		 {
			 *(primes + count) = trial;
			 count++;
		 }
		}
		for(i = 0;i<total;i++)
		{
			if(!(i % 5))
			{
				printf("\n");

			}
			printf("%lu",*(primes+i));
		}
		printf("\n");
	}

	return 0;
}