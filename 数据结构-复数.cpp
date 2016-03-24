//数据结构——1.3复数及其基本运算

//复数结构
typedef struct 
{
	float realpart;
	float imagepart;
}complex;

//复数声明
void creat( &complex C, float x, float y)
{
	C.realpart = x;
	C.imagepart = y;
}

//取实部
float getreal(complex C)
{
	return C.realpart;
}

//取虚部
float getimage(complex C)
{
	return C.imagepart;
}

//复数相加
void complex_add(complex C1, complex C2)
{
	complex sum;
	sum.realpart = C1.realpart + C2.realpart;
	sum.imagepart = C1.imagepart + C2.imagepart;
	return sum;
}

//复数相减
void complex_sub(complex C1, complex C2)
{
	complex different;
	different.realpart = C1.realpart - C2.realpart;
	different.imagepart = C1.imagepart - C2.imagepart;
	return different;
}