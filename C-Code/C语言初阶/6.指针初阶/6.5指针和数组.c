#include<stdio.h>
/*
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	printf("%p\n", arr);  //000000A27759FB68
	printf("%p\n", &arr[0]);   //000000A27759FB68
	//���ۣ���������ʾ����������Ԫ�صĵ�ַ��
	return 0;
}
*/


//��Ȼ���԰����������ɵ�ַ��ŵ�һ��ָ���У�����ʹ��ָ��������һ���ͳ�Ϊ���ܡ�
/*
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	int* p = arr; //ָ����������Ԫ�صĵ�ַ
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("&arr[%d] = %p   <====> p+%d = %p\n", i, &arr[i], i, p + i);
	}
	return 0;
}
*/

//���� p+i ��ʵ����������� arr �±�Ϊi�ĵ�ַ��
//�����ǾͿ���ֱ��ͨ��ָ�����������顣


/*
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int* p = arr; //ָ����������Ԫ�صĵ�ַ
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(p + i));
	}
	return 0;
}
*/
