#include <stdio.h>
#include <string.h>
// 1.strstr
//��һ���ַ�������һ���ַ����Ƿ����
//���ڣ����ص��ִ����ڵĵ�һ�γ��ֵ���ʼ��ַ(һ���ַ���str1���ܳ���2�����ϵ�str2)
//�����ڣ�����NULL
//��abcdefabcdef Ѱ��fab
// char * strstr ( const char *str1, const char * str2);
/*
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "bcd";
	char* p = strstr(arr1, arr2);
	if (p == NULL)
		printf("������\n");
	else
		printf("����λ�ã�%s\n", p);
	return 0;
}
*/

//ģ��ʵ��strstr �������
/*
char* my_strstr(const char* str1, const char* str2)
{
	const char* s1 = str1;
	const char* s2 = str2;
	char* p = str1;
	while (*p!='\0')  //p��str1�����е�λ�� ֻҪλ��û�е�\0 �ͼ���Ѱ��
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

//���б���㷨 KMP�㷨 �ѶȽϴ�
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "bcd";
	char* p = my_strstr(arr1, arr2);
	if (p == NULL)
		printf("������\n");
	else
		printf("����λ�ã�%s\n", p);
	return 0;
}
*/

// 2.strtok
// char * strtok ( char * str, const char * sep );
/*
sep�����Ǹ��ַ����������������ָ������ַ�����  sepָ���˷ָ���
��һ������ָ��һ���ַ�������������0�����߶����sep�ַ�����һ�����߶���ָ����ָ�ı�ǡ�
strtok�����ҵ�str�е���һ����ǣ��������� \0 ��β������һ��ָ�������ǵ�ָ�롣
��ע��strtok������ı䱻�������ַ�����������ʹ��strtok�����зֵ��ַ���һ�㶼����ʱ���������ݲ��ҿ��޸ġ���
strtok�����ĵ�һ��������Ϊ NULL ���������ҵ�str�е�һ����ǣ�strtok���������������ַ����е�λ�á�
strtok�����ĵ�һ������Ϊ NULL ����������ͬһ���ַ����б������λ�ÿ�ʼ��������һ����ǡ�
����ַ����в����ڸ���ı�ǣ��򷵻� NULL ָ�롣
*/

/* һ�㲻��ôд
int main()
{
	char arr[] = "zpengwei@bitedu.com"; //@ ��. �Ƿָ���
	char buf[200] = {0};  //zpengwei@bitedu.com
	strcpy(buf, arr);
	// zpengwei   bitedu  com  ��ȡ���������ַ��� ʹ��strtok
	const char *p = "@.";
	char* str = strtok(buf, p);
	puts(str);

	str = strtok(NULL,p);
	puts(str);

	str = strtok(NULL,p);
	puts(str);
	return 0;
}
*/

/*��д����
int main()
{
	char arr[] = "zpengwei@bitedu.com";
	char buf[200] = {0};
	strcpy(buf, arr);
	const char *p = "@.";
	char *str = NULL;
	for (str = strtok(buf, p); str != NULL; str = strtok(NULL, p))
	{
		puts(str);
	}
	return 0;
}
*/
