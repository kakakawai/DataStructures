# include<stdio.h>
# include<stdlib.h>

int main (void)
{
	long num1 = 234567L;
	long num2 = 345123L;
	long num3 = 789234L;
	long num4 = 0;
	long num5 = 0;
	long num6 = 0;
	float fnum = 0.0f;
	int ival[6] = { 0 };
	FILE *pfile = NULL;
	char *filename = "D:\\myfile.txt";

	if(!(pfile = fopen(filename,"w")))
	{
		printf("Error openong %s for writing. Program terminated.",filename);
		exit(1);
	}
	fprintf(pfile,"%ld%ld%ld",num1,num2,num3);
	fclose(pfile);
	printf("%ld %ld %ld",num1,num2,num3);

	if(!(pfile = fopen(filename,"r")))
	{
		printf("Error opening %s for writing. Program terminated.",filename);
		exit(1);
	}
	fscanf(pfile,"%6ld%6ld%6ld",&num4,&num5,&num6);
	printf("\n%ld %ld %ld",num4,num5,num6);
	
	rewind(pfile);
	fscanf(pfile,"%2d%3d%3d%3d%2d%2d%3f",&ival[0],&ival[1],&ival[2],&ival[3],&ival[4],&ival[5],&fnum);
	fclose(pfile);

	printf("\n");
	for(int i = 0; i < 6; i++)
	{
		printf("%sival[%d] = %d", i == 4 ?"\n\t":"\t",i,ival[i]);
	}
	printf("\nfnum = %f\n",fnum);

	return 0;
}