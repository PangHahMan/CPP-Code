#include<stdio.h>
#include<string.h>
//����������
//��������������Ԫ�صĵ�ַ
//�������������⣺
//1.sizeof(������) - ��������ʾ�������飬���������������Ĵ�С����λ���ֽ�
//2.&������ - ������Ҳ��ʾ�������飬ȡ��������������ĵ�ַ
//������2�����⣬����������е�����������ʾ��Ԫ�صĵ�ַ

//1.һά����
/*
int main()
{
	int a[] = { 1,2,3,4 };
	//a - int*
	//&a - int (*)[4]
	printf("%d\n", sizeof(a));    //16��a��Ϊ��������������sizeof�ڲ����������������ܴ�С����λ���ֽ�
	printf("%d\n", sizeof(a + 0)); //4 ���ǵ�������sizeof�ڲ���Ҳû��&������������a����������Ԫ�صĵ�ַ
	printf("%d\n", sizeof(*a));    //4  a����Ԫ�صĵ�ַ��*a������Ԫ��1
	printf("%d\n", sizeof(a + 1)); //4  a����Ԫ�صĵ�ַ��a+1 ����һ��int �ڶ���Ԫ�صĵ�ַ
	printf("%d\n", sizeof(a[1]));  //4  a[1]��������ĵڶ���Ԫ��
	printf("%d\n", sizeof(&a));    //4  ȡ����������ĵ�ַ������ĵ�ַ��Ҳ�ǵ�ַ
	printf("%d\n", sizeof(*&a));   //�� 16 - &a������ĵ�ַ��������ָ�����͡�*&a�Ƕ�һ������ָ������ã����ʵ�����������
	printf("%d\n", sizeof(&a + 1)); //4 &a����ĵ�ַ��&a+1�������������飬���Ǹ���ַ
	printf("%d\n", sizeof(&a[0]));   //4  a[0]������ĵ�һ��Ԫ�أ�&a[0]���ǵ�һ��Ԫ�صĵ�ַ
	printf("%d\n", sizeof(&a[0] + 1));  //4  a[0]+1������ĵڶ���Ԫ�أ�&a[0]+1���ǵڶ���Ԫ�صĵ�ַ
	return 0;
}
*/


//2.�ַ�����
//sizeof�Ǽ������������ʹ����Ķ�����ռ���ڴ�ռ�Ĵ�С����λΪ�ֽ�
//sizeof�ǲ����������Ǻ���

//strlen���ַ������ȵģ���������ַ���\0֮ǰ���ֵ��ַ��ĸ���
//ͳ�Ƶ�\0Ϊֹ�����û�п���\0,�����������
//srtlen�ǿ⺯��
/*2.1
int main()
{
	char arr[] = { 'a','b','c','d','e','f' };

	printf("%d\n", sizeof(arr));  //6 arr���������������ǵ�������sizeof�ڲ��������������Ĵ�С
	printf("%d\n", sizeof(arr + 0)); //4 arr�������������ǵ�������sizeof�ڲ���arr��������ʾ��Ԫ�صĵ�ַ��arr+0������Ԫ�صĵ�ַ
	printf("%d\n", sizeof(*arr)); //1 arr����Ԫ�ص�ַ������Ԫ�ص�ַ�����ã�*arr������Ԫ�صĴ�С
	printf("%d\n", sizeof(arr[1])); //1 arr[1]������ĵڶ���Ԫ�أ����ǵڶ���Ԫ�صĴ�С
	printf("%d\n", sizeof(&arr));  //4 &arr - ȡ����������ĵ�ַ�����������ĵ�ַ�Ĵ�С
	printf("%d\n", sizeof(&arr + 1)); //4 ������������ĵ�ַ�������ϻ��ǵ�ַ
	printf("%d\n", sizeof(&arr[0] + 1)); //4 arr[0]��a�ĵ�ַ��&arr[0]+1��b�ĵ�ַ

	printf("%d\n", strlen(arr)); //���ֵ arr��������������û�з���sizeof�ڲ���Ҳû��&��arr������Ԫ�صĵ�ַ
	//strlen�õ�arr�󣬴�arr������Ԫ�صĵ�ַ����ʼ�����ַ��ĳ��ȣ�ֱ���ҵ�\0������arr�����ڴ���û��\0,arr�ڴ����û��\0���ǲ�ȷ���ģ������������
	printf("%d\n", strlen(arr + 0)); //���ֵ arr��������Ԫ�ص�ַ��arr+0������Ԫ�صĵ�ַ
	printf("%d\n", strlen(*arr)); //err ��Ƿ������ڴ� arr��������Ԫ�ص�ַ *arr����Ԫ�أ������ַ�'a' - 97
	//strlen�Ͱ�'a'��ASCLL��ֵ97�����˵�ַ �ڴ���û��97��ַ�����ԷǷ������ڴ�
	printf("%d\n", strlen(arr[1])); //err  ���arr[1]�ǵڶ���Ԫ�� ������һ��
	printf("%d\n", strlen(&arr)); //���ֵ &arr������ĵ�ַ������ĵ�ַҲ��ָ��������ʼλ�ã��͵�һ��һ��
	printf("%d\n", strlen(&arr + 1)); //���ֵ ��arr�������ʼ��
	printf("%d\n", strlen(&arr[0] + 1)); //���ֵ ��arr�����һ��Ԫ�ؿ�ʼ��
	return 0;
}
*/

/*2.2
int main()
{
	char arr[] = "abcdef";
	printf("%d\n", sizeof(arr)); //7
	printf("%d\n", sizeof(arr + 0)); //7
	printf("%d\n", sizeof(*arr)); //1  �õ��˵�һ����ַ��Ԫ��
	printf("%d\n", sizeof(arr[1])); //1  �õ�������ڶ���Ԫ��
	printf("%d\n", sizeof(&arr)); //4
	printf("%d\n", sizeof(&arr + 1)); //4
	printf("%d\n", sizeof(&arr[0] + 1));  //4

	printf("%d\n", strlen(arr));  //6
	printf("%d\n", strlen(arr + 0)); //6
	printf("%d\n", strlen(*arr)); //err  Ԫ�ص���ַ
	printf("%d\n", strlen(arr[1])); //err  Ԫ�ص���ַ
	printf("%d\n", strlen(&arr));  //6
	printf("%d\n", strlen(&arr + 1));  //���ֵ
	printf("%d\n", strlen(&arr[0] + 1)); //5

	return 0;
}
*/

/*2.3
int main()
{
	char* p = "abcdef";
	printf("%d\n", sizeof(p));  //4 - һ��ָ������Ĵ�С
	printf("%d\n", sizeof(p + 1));  //4
	printf("%d\n", sizeof(*p)); //1
	printf("%d\n", sizeof(p[0]));  //1
	printf("%d\n", sizeof(&p)); //4
	printf("%d\n", sizeof(&p + 1));  //4
	printf("%d\n", sizeof(&p[0] + 1)); //4

	printf("%d\n", strlen(p));  //6 - pָ���׵�ַ
	printf("%d\n", strlen(p + 1)); //5
	printf("%d\n", strlen(*p)); //err  strlen��Ҫ��ַ
	printf("%d\n", strlen(p[0])); //err
	printf("%d\n", strlen(&p)); //���ֵ  p�ĵ�ַ��֪��
	printf("%d\n", strlen(&p + 1)); //���ֵ
	printf("%d\n", strlen(&p[0] + 1)); //5  ȡ��һ����ַ�ڼ���һ����ַ ��ʱ�׵�ַΪb
	return 0;
}
*/


//3.��ά����
/*
int main()
{
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));  //48 �������������ܴ�С
	printf("%d\n", sizeof(a[0][0])); //4  ��һ�е�һ�е�Ԫ��
	printf("%d\n", sizeof(a[0])); //16  �����һ�е��������ܴ�С
	printf("%d\n", sizeof(a[0] + 1)); //4  a[0]��Ȼ�ǵ�һ�е������𣬵����ǵ�������sizeof�ڲ���
	//a[0]���Ǳ�ʾ������һ�����飬a[0]���ǵ�һ����Ԫ�ص�ַ��+1���ǵڶ�����ַ
	printf("%d\n", sizeof(*(a[0] + 1))); //4 a[0]+1���ǵڶ���Ԫ�صĵ�ַ��*���ǵڶ���Ԫ�أ�
	printf("%d\n", sizeof(a + 1)); //4 a�Ƕ�ά�������������û�е�������sizeof�ڲ���Ҳû��&������a����Ԫ�ص�ַ��
	//��ά������������1ά���飬���ĵ�һ��Ԫ�ؾ��Ƕ�ά����ĵ�һ��
	//a���ǵ�һ�еĵ�ַ��a������ - int(*)[4]  +1�ͻ�����һ�����飬�ͱ���˵ڶ��еĵ�ַ
	printf("%d\n", sizeof(*(a + 1))); //16  a+1�ǵڶ��еĵ�ַ��*(a+1) �ҵ��ľ��ǵڶ��У����Ǽ���ĵڶ��еĴ�С *(a+1) �ȼ���a[1]
	printf("%d\n", sizeof(&a[0] + 1)); //4 &a[0]+1�ǵڶ��еĵ�ַ��������ǵڶ��е�ַ��С
	printf("%d\n", sizeof(*(&a[0] + 1))); //16 �Եڶ��е�ַ�����ã��õ��ľ��ǵڶ��е�����
	printf("%d\n", sizeof(*a)); //16 a��ʾ��Ԫ�ص�ַ�����ǵ�һ�еĵ�ַ��*a�����õ�һ�е�����
	printf("%d\n", sizeof(a[3])); //16 a[3]�Ƕ�ά����ĵ�4�У���Ȼû�е����У�����������ȷ������С����ȷ���ģ�һ�еĴ�С
	//�ܹ�������a[3]�������ǣ�int[][4]
	//�κ�һ�����ʽ��2������
	//3+5 ֵ���ԣ�8  �������ԣ�int
	return 0;
}
*/



int main()
{
	short num = 20;
	int a = 1;
	printf("%d\n", sizeof(num = a + 5)); //sizeof�ڲ��ı��ʽ����������
	printf("%d\n", num);
	return 0;
}