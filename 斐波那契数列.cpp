# include <stdio.h>
int main (void)
{
int n;
int f1,f2,f3;

f1 = 1;
f2 = 1;

printf("������Ҫ�õ������е���,��ൽ48λ��");
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