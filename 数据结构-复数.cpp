//���ݽṹ����1.3���������������

//�����ṹ
typedef struct 
{
	float realpart;
	float imagepart;
}complex;

//��������
void creat( &complex C, float x, float y)
{
	C.realpart = x;
	C.imagepart = y;
}

//ȡʵ��
float getreal(complex C)
{
	return C.realpart;
}

//ȡ�鲿
float getimage(complex C)
{
	return C.imagepart;
}

//�������
void complex_add(complex C1, complex C2)
{
	complex sum;
	sum.realpart = C1.realpart + C2.realpart;
	sum.imagepart = C1.imagepart + C2.imagepart;
	return sum;
}

//�������
void complex_sub(complex C1, complex C2)
{
	complex different;
	different.realpart = C1.realpart - C2.realpart;
	different.imagepart = C1.imagepart - C2.imagepart;
	return different;
}