#include<stdio.h>
char* my_strstr(char* str1, char* str2)
{
	const char* s1 = str1;
	const char* s2 = str2;
	char* p = str1;
	while (*p != '\0')  //p��str1�����е�λ�� ֻҪλ��û�е�\0 �ͼ���Ѱ��
	{
		s1 = p;   //ÿ��ƥ�䲻���µ��ַ�����p++ ����һ����ַ �ŵ�s1��
		s2 = str2;  //str2ÿ��ƥ�䲻����ͬ���ַ��� �ͻص���ʼλ�� �ŵ�s2��
		while (*s1 != '\0' && *s2 != '\0' && (*s1 == *s2))  //��s1��s2���ʱ�� s1��s2�Ӽ� �����ж��ַ����
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')  //���s2����\0 ˵��s2�е��ַ���s1�е��ַ������  ���ҵ��� ����ַ����p p������s1���ַ�������ʼ��ַ
		{
			return p;    //�ҵ���
		}
		p++;  //ÿ��ѭ���жϽ����󣬾�p++��ʼ����һ����ַ��ʼ��
	}
	return NULL;  //�Ҳ����ַ���
}

int main()
{
	char arr1[] = "HelloWorld";    //
	char arr2[] = "orl";
	char*p = my_strstr(arr1, arr2);
	if (p = NULL)
		printf("������\n");
	else
		printf("����\n");
	return 0;
}