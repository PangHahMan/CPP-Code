#include<stdio.h>
//1.һά���鴫��
/*
void test(int arr[])//ok?  ��
{}
void test(int arr[10])//ok?  ��
{}
void test(int* arr)//ok?  ��
{}
void test2(int* arr[20])//ok?  �� 20Ҳ����ʡ��
{}
void test2(int** arr)//ok?   ��
{}
int main()
{
	int arr[10] = { 0 };
	int* arr2[20] = { 0 };   //ָ������
	test(arr);
	test2(arr2);
}
*/


//2.��ά���鴫��
/*
void test(int arr[3][5])//ok�� ��
{}
void test(int arr[][])//ok�� ��
{}
void test(int arr[][5])//ok�� ��
{}
//�ܽ᣺��ά���鴫�Σ������βε����ֻ��ʡ�Ե�һ��[]�����֡�
//��Ϊ��һ����ά���飬���Բ�֪���ж����У����Ǳ���֪��һ�ж���Ԫ�ء�
//�����ŷ������㡣
void test(int* arr)//ok��  ��
{}
void test(int* arr[5])//ok�� ��
{}
void test(int(*arr)[5])//ok�� ��
{}
void test(int** arr)//ok�� ��
{}
int main()
{
	int arr[3][5] = { 0 };
	test(arr);
}
*/


//3.һ��ָ�봫��
/*
void print(int* p, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d\n", *(p + i));
	}
}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9 };
	int* p = arr;
	int sz = sizeof(arr) / sizeof(arr[0]);
	//һ��ָ��p����������
	print(p, sz);
	return 0;
}

*/


//4.����ָ�봫��
/*
void test(int** ptr)
{
	printf("num = %d\n", **ptr);
}
int main()
{
	int n = 10;
	int* p = &n;
	int** pp = &p;
	test(pp);
	test(&p);
	return 0;
}
�������Ĳ���Ϊ����ָ���ʱ�򣬿��Խ���ʲô������
void test(int **p)
{}

int** ptr = ;
test(ptr);   //ok;

int* p2 = ;
test(&p2);  //ok

int* arr[10];   //����ָ���������
test(arr);  //ok
*/
