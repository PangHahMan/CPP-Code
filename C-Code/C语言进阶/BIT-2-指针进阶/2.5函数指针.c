#include<stdio.h>
/*
int Add(int x, int y)
{
	return x + y;
}

int main()
{
	int (*pf)(int x, int y) = Add;  //����ָ��Ķ���
	//int sum = (*pf)(3, 5);  (*)����ʡ��   Add == pf
	int sum = pf(3, 5);
	printf("%d\n", sum);   //8
	int arr[10] = { 0 };
	printf("%p\n", &arr);  //ȡ������ĵ�ַ - 010FF8A8
	printf("%p\n", Add);   //004913B6
	printf("%p\n", &Add);   //004913B6
	//���ں�����˵Add��&Add����ͬ�� û������ ���Ǻ����ĵ�ַ
	return 0;
}
*/


//��ϰ
/*
int test(const char* str, double d)
{

}

int main()
{
	//int (*pt)(const char*, double) = &test;
	int (*pt)(const char* str, double d) = &test;
	return 0;
}
*/


//������������
/*
typedef unsigned int uint;
int main()
{
	//����1
	//0 - int
	//(void (*p)())0 - ��0����һ�������ĵ�ַ
	(*(void (*)())0)();
	//��0ֱ��ת����һ��  void(*)()�ĺ���ָ�룬Ȼ��ȥ����0��ַ�ĺ���
	//����2
	typedef void(*pf_t)(int);   //pf_t��һ������ �ŵ�*����
	//void (*signal(int, void(*)(int)))(int);  //�����Ķ��Ĵ���
	pf_t signal(int, pf_t);  //��д
	//����������һ�κ�������
	//�����ĺ�����signal
	//�����ĵ�һ��������int���͵�
	//�����ĵڶ��������Ǻ���ָ�����ͣ��ú���ָ��ָ��ĺ���������int ����������void
	//signal�����ķ�������Ҳ��һ������ָ�����ͣ��ú���ָ��ָ��ĺ���������int ����������void
	return 0;
}
*/

