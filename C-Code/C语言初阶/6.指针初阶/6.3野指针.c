#include<stdio.h>
// ��� Ұָ�����ָ��ָ���λ���ǲ���֪�ģ�����ġ�����ȷ�ġ�û����ȷ���Ƶģ�

//1.Ұָ�����
//��ָ��δ��ʼ��
/*
int main()
{
	int* p;       //�ֲ�����ָ��δ��ʼ����Ĭ��Ϊ���ֵ p����Ұָ��
	*p = 20;
	return 0;
}
*/


//��ָ��Խ�����
/*
int main()
{
	int arr[10] = { 0 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int* p = arr;
	for (i = 0; i <= sz; i++)    //ָ��Խ�� sz
	{
	    //��ָ��ָ��ķ�Χ��������arr�ķ�Χʱ��p����Ұָ��
		*p = i;
		p++;
	}
}
*/


//��ָ��ָ��Ŀռ��ͷ�
/*
int* test()
{
	int num = 100;
	return &num;
}

int main()
{
	int* p = test();
	*p = 200;   //Ұָ�룬ָ��ĵ�ַ�Ѿ��ͷ�
	return 0;
}
*/


//2.��α���Ұָ��
/*
1. ָ���ʼ��
int main()
{
	int a = 10;
	int* pa = &a;   //��ȷ��ʼ��
	int* p = NULL;   //NULL��0  NULL����Ϊ�˳�ʼ��ָ���
	return 0;
}

2. С��ָ��Խ��

3. ָ��ָ��ռ��ͷţ���ʱ��NULL     
//��̬�ڴ����  ����ռ�int *p = malloc(40)
//�ͷſռ�  free(p)  p=NULL

4. ���ⷵ�ؾֲ������ĵ�ַ    -  ���ⷵ��ջ�ռ�ĵ�ַ

5. ָ��ʹ��֮ǰ�����Ч��
int main()
{
	int* p = NULL;
	if (p != NULL)   //p������Чָ���ʱ���ʹ��
	{
		printf("%d\n", *p);
	}
	return 0;
}
*/


