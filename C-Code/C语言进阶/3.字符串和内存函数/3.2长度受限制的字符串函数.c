#include<stdio.h>
#include<string.h>
//1.strncpy
/*
char * strncpy ( char * destination, const char * source, size_t num );
������num���ַ���Դ�ַ�����Ŀ��ռ䡣
�����Դ�ַ����ĳ���С��num���򿽱���Դ�ַ���֮����Ŀ��ĺ��׷��0��ֱ��num����
int main()
{
	char arr1[20] = "abcdef";
	char arr2[] = "xxxx";
	strncpy(arr1, arr2, 2);  //xxcdef  ֻ����2���ַ�
	//strncpy(arr1, arr2, 8);  //xxxx
	printf("%s\n", arr1);
	return 0;
}
*/


//2.strncat 
//char * strncat ( char * destination, const char * source, size_t num );
/*
int main()
{
	char arr1[20] = "abcdef";
	char arr2[] = "xyz";
	strncat(arr1, arr2, 2);  //2��ʾ׷��2���ַ�
	printf("%s\n", arr1);  //abcdefxy
	return 0;
}
*/

//�Լ�׷���Լ�
/*
int main()
{
	char arr1[20] = "abc";
	char arr2[] = "xyz";
	strncat(arr1, arr1, 3);  //2��ʾ׷��2���ַ�
	printf("%s\n", arr1);  //abcabc
	return 0;
}
*/


//strncmp
//int strncmp ( const char * str1, const char * str2, size_t num );
/*
int main()
{
	int ret = strncmp("abcdef", "abc", 3);  //3��ʾ�Ƚ�ǰ����
	printf("%d\n", ret);  //0

	ret = strncmp("abcdef", "abc", 4);
	printf("%d\n", ret);  //1
	return 0;
}
*/
