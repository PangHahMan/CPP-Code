#include<stdio.h>
int my_strlen(char* str)
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
	}
	return count;
}


void reverse_string(char* str)
{
	int len = my_strlen(str);
	//1.a��f����
	char tmp = *str;
	*str = *(str + len - 1);    //-1����Ϊ������±��0��ʼ
	//2.��bcde�����һ���ַ���Ϊ\0 �����޷�������һ�εݹ�
	*(str + len - 1) = '\0';
	//3.����bcde�ĵݹ�
	if (*(str + 1) != '\0')
	{
		reverse_string(str + 1);
	}
	//�����н���
	*(str + len - 1) = tmp;   //��󽻻���ԭ������*(str+len-1)���û���\0
}


int main()
{
	char arr[] = "abcdef";   //a��f���� +bcde�ĵݹ�
	reverse_string(arr);
	puts(arr);
	return 0;
}