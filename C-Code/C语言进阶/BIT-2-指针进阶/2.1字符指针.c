#include<stdio.h>
/*
int main()
{
	char ch = 'w';
	char* pc = &ch;

	const char* ps = "abcdef";  //��abcdef�ַ����е�a��ַ�ŵ�ps��
	//*ps = 'w';    //�����ַ��������޸�

	printf("%c\n", *ps);  //a
	return 0;
}
*/


/*������
int main()
{
    char str1[] = "hello bit.";
    char str2[] = "hello bit.";
    const char* str3 = "hello bit.";
    const char* str4 = "hello bit.";
    if (str1 == str2)
        printf("str1 and str2 are same\n");
    else
        printf("str1 and str2 are not same\n");

    if (str3 == str4)    //str3 �� str4�ǳ����ַ��� �����ַ�ͬ���Ļ���ַ��ͬ
        printf("str3 and str4 are same\n");
    else
        printf("str3 and str4 are not same\n");
    //str1 and str2 are not same
    //str3 and str4 are same
    return 0;
}
����str3��str4ָ�����һ��ͬһ�������ַ�����C/C++��ѳ����ַ����洢��������һ���ڴ����򣬵�����ָ�롣
ָ��ͬһ���ַ�����ʱ������ʵ�ʻ�ָ��ͬһ���ڴ档��������ͬ�ĳ����ַ���ȥ��ʼ����ͬ�������ʱ��ͻῪ�ٳ���ͬ���ڴ�顣
����str1��str2��ͬ��str3��str4��ͬ��
*/
//���Ҫ�Ƚ��ַ��������� Ҫʹ����strcmp����