#include<stdio.h>
//ָ��ĵ�ַռ���ֽڶ�һ�� 32λ4�ֽ�  64λ8�ֽ�
/*
int main()
{
	int* pa;
	int* pc;
	float* pf;
	printf("%zu\n", sizeof(pa));  //8
	printf("%zu\n", sizeof(pc));  //8
	printf("%zu\n", sizeof(pf));  //8
	return 0;
}
*/


//1.ָ��Ľ�����
//��ָ�����;�����ָ����н����ò���ʱ���Ȩ��
//char*��ָ������÷���1���ֽ�  int*��ָ������÷���4���ֽ�   double*��ָ������÷���8���ֽ�

/*
int main()
{
	int a = 0x11223344;
	//int* pa = &a;
	//*pa = 0;   //�ı�4���ֽڵ�ֵ
	char* pc = &a;
	*pc = 0;    //ֻ��ı��1���ֽ�
	return 0;
}
*/



//2.ָ��+-����
/*
��ָ�����;�����ָ��Ĳ���(��ǰ/��� ��һ������ֽ�)
 int* ָ��+1����˼������һ�����ͣ�Ҳ���������4���ֽ�
 char*ָ��+1����˼������һ���ַ���Ҳ���������1���ֽ�
 double*ָ��+1����˼������һ��double��Ҳ���������8���ֽ�

 int main()
{
	int a = 0x11223344;
	int* pa = &a;
	char* pc = &a;
	printf("pa=%p\n", pa);   //pa=0000005CE4DBFB54
	printf("pc=%p\n", pc);   //pc=0000005CE4DBFB54

	printf("pa+1=%p\n", pa + 1);   //pa+1=0000005CE4DBFB58 ����4���ֽ�
	printf("pc+1=%p\n", pc + 1);   //pc+1=0000005CE4DBFB55 ����1���ֽ�

	return 0;
}
*/


/*ָ�뷽����ֵ������
//д��1
int main()
{
	int arr[10] = { 0 };
	//1~10
	int* p = arr;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		*p = i + 1;
		p++;
	}
	return 0;
}
*/

/*
//д��2
int main()
{
	int arr[10] = { 0 };
	//1~10
	int* p = arr;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		*(p + i) = i + 1��
	}
	return 0;
}
*/
