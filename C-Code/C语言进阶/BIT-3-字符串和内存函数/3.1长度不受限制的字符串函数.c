#include<stdio.h>
#include<string.h>
#include<assert.h>
//C�����ж��ַ����ַ����Ĵ������Ƶ��������C���Ա�����û���ַ������͵ģ�
//�ַ���ͨ�����ڳ����ַ��� �л��� �ַ����� �С�
//�ַ������� ��������Щ���������޸ĵ��ַ�������.
//1.strlen - strint lenth - ���ַ������ȵģ�ͳ�Ƶ����ַ�����\0֮ǰ���ַ�����
//����ָ����ַ�������Ҫ�� '\0' ������
//ע�⺯���ķ���ֵΪsize_t�����޷��ŵģ� �״� ��
//size_t strlen ( const char * str );
/*
int main()
{
	//a b c d e f \0
	char arr[] = "abcdef";
	//char arr[] = { 'a','b','c' };  //err  ���������
	printf("%d", strlen(arr)); //6
	return 0;
}
*/

/*
int main()
{
	if (strlen("abc") - strlen("abcdef") > 0)  //strlen���ص����޷������ͣ�������ָ���
		printf(">");
	else
		printf("<");
	return 0;
}
*/


//ģ��strlen ����ֵsize_t
/*
size_t my_strlen(const char* str)
{
	assert(str); //str!=NU;LL
	const char* start = str;
	const char* end = str;
	while (*end != '\0')
	{
		end++;
	}
	return end - start;
}


int main()
{
	char arr[] = "abcdef";
	size_t len = my_strlen(arr);
	printf("%zu\n", len);
	return 0;
}
*/


//2.strcpy
//char* strcpy(char * destination, const char * source );
/*
��Դ�ַ��������� '\0' ������
���ὫԴ�ַ����е� '\0' ������Ŀ��ռ䡣
��Ŀ��ռ�����㹻����ȷ���ܴ��Դ�ַ�����
��Ŀ��ռ����ɱ䡣
*/
/*
int main()
{
	char arr[10] = "xxxxxxxxxx";
	//char arr[3]={ 0 };  //����ռ�̫С
	//char* p = "hello world"; //err �����ַ�����ַ
	const char* p = "abcdef";
	strcpy(arr, p);
	printf("%s\n", arr);
	return 0;
}
*/

//ģ��strcpy��ʵ��
/*
char* my_strcpy(char* dest, const char* src)
{
	assert(dest);  //dest��=NULL
	assert(src);
	char* ret = dest;   //dest��������ѭ��ʱ��ı� ���Ե�ַ�����ret��
	while (*dest++ = *src++)   //ֱ��\0 ��ֵ��ȥ ���ʽΪ��
	{
		;
	}
	return ret;
}

int main()
{
	char arr1[20] = "abc";
	char arr2[] = "hello bit";
	printf("%s\n", my_strcpy(arr1, arr2));
	return 0;
}
*/


//3.strcat - �ַ���׷�Ӻ���ģ��
//char * strcat ( char * destination, const char * source );
/*
char* my_strcat(char* dest, const char* src)
{
	//1.��Ŀ��ռ��\0
	char* cur = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	//2.����Դͷ���ݵ�\0֮��Ŀռ�
	while (*dest++ = *src++);
	return cur;
}

int main()
{
	char arr1[20] = "hello \0xxxxx";
	char arr2[] = "world";
	printf("%s\n", my_strcat(arr1, arr2));
	return 0;
}
*/


//4.strcmp - �ַ����Ƚ�
/* ��׼�涨
��һ���ַ������ڵڶ����ַ������򷵻ش���0������
��һ���ַ������ڵڶ����ַ������򷵻�0
��һ���ַ���С�ڵڶ����ַ������򷵻�С��0������
strcmp�Ƚϵ��Ƕ�Ӧλ�����ַ��Ĵ�С�����ǳ���
int strcmp ( const char * str1, const char * str2 );
*/
//ģ��ʵ��strcmp
/*
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return 0;
		}
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "abcdef";
	int ret = my_strcmp(arr1, arr2);
	if (ret < 0)
		printf("arr1<arr2\n");
	else if (ret > 0)
		printf("arr1>arr2\n");
	else
		printf("arr1==arr2\n");
	return 0;
}
*/
