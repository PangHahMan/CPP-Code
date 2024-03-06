//ģ��ʵ��strcpy
#include<stdio.h>
#include<string.h>
#include<assert.h>
void my_strcpy1(char* dest, char* src)
{
	while (*src!='\0')
	{
		*dest++ = *src++;
	}
	*dest = *src;   //*src�зŵ���\0
}


//�Ż�����
void my_strcpy2(char* dest, char* src)
{
	while (*dest++ = *src++)  //��stcΪ\0ʱ�����ʽΪ0��ѭ������
	{
		;
	}	
}


//�����Ż�
void my_strcpy3(char* dest, char* src)
{
	//�������ɿ�ָ�룬�еĻ��ͱ���
	//assert(dest);   //dest��=NULL   NULLΪ0 ���Կ���ʡ�� ����
	//assert(src);    //����
	assert(dest && src); //dest��src����ΪNULL
	while (*dest++ = *src++)  //��stcΪ\0ʱ�����ʽΪ0��ѭ������
	{
		;
	}
}


//�����Ż�
char* my_strcpy(char* dest, const char* src)
{
	//����const  �������ᱨ�� ���ӵĻ� ����
	/*while (*src++ = *dest++)  
	{
		;
	}*/
	char* ret = dest;   //�������ص�ʱ��ʼ������׵�ַ ������ǰ������ret��
	assert(dest && src); //dest��src����ΪNULL
	while (*dest++ = *src++)  //��stcΪ\0ʱ�����ʽΪ0��ѭ������
	{
		;
	}
	return ret;
}


int main()
{
	char arr1[20] = "xxxxxxxx";
	//xxxxxxxxxxΪ�˹۲��Ƿ񸲸�\0
	char arr2[] = "hello";
	char* p = NULL;
	//strcpy(arr1, arr2);
	//my_strcpy1(arr1, arr2);
	//my_strcpy2(arr1, arr2);
	printf("%s\n", my_strcpy(arr1, arr2));
	return 0;
}



/*ģ��ʵ��strlen�Ż�
int my_strlen(const char* str)
{
	assert(str);
	int count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}
*/
