# include <stdio.h>
int main (void)
{
int n;
int f1,f2,f3;

f1 = 1;
f2 = 1;

printf("输入想要得到的数列的项,最多到48位：");
scanf("%d",&n);
if(n == 1)
{
    f3 = f1;
}
else if(n == 2)
{
    f3 = f2;
}
else
{
    for(int i = 2;i<n;++i)
    {
         f3 = f1 + f2;
         f1 = f2;
         f2 = f3; 
    }
}
printf("%d\n",f3);

return 0;
}