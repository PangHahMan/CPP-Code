#include<stdio.h>
#define N_VALUES 5
/*
��ָ�� + -����
��ָ�� - ָ��
��ָ��Ĺ�ϵ����
*/


//1.ָ�� + -����
/*
int main()
{
	double arr[5] = { 0 };
	double* p = arr;
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		printf("%lf \n", *(p + i));
	}
	return 0;
}
*/


/*
int main()
{
	float values[N_VALUES];
	float* vp;
	//ָ��+-������ָ��Ĺ�ϵ����
	for (vp = &values[0]; vp < &values[N_VALUES];)
	{
		*vp++ = 0;
		//*vp++  == *(vp++)   ����ǵ�ַ++
		//(*vp++)  ��ͬ�������ֵ++
	}
	return 0;
}
*/


//2.ָ��-ָ��
/*
ָ��+ָ�룿����  ������
����-����  = ����     ����+���ڣ���
int main()
{
	//����ָ�������ǰ���ǣ�ָ��ָ�����ͬһ�������Ŀռ�
	int arr[10] = { 0 };
	printf("%d\n", &arr[9] - &arr[0]);  //9
	printf("%d\n", &arr[0] - &arr[9]);  //-9

	int a = 10;
	char c = 'w';
	printf("%d\n", &a - &c);   //���󣬲�ͬ���͵ĵ�ַ
	return 0;
}
*/

//1.������
/*
int my_strlen(char* str)
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
*/

//2.�ݹ�

//3.ָ��-ָ��
/*
int my_strlen(char* str)
{
	char* start = str;
	while (*str)     //*str != '\0' == *str     \0 ==0
	{
		str++;
	}
	return str - start;
}

int main()
{
	char arr[] = "abcdef";
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}
*/


//3.ָ��Ĺ�ϵ����
/*
int main()
{
	float values[N_VALUES];
	float* vp;
	for (vp = &values[N_VALUES]; vp > &values[0];)
	{
		*--vp = 0;
	}
	//�����
	//for (vp = &values[N_VALUES - 1]; vp >= &values[0]; vp--)
	//{
	//	*vp = 0;
	//}

	//ʵ���ھ��󲿷ֵı��������ǿ���˳���������ģ�Ȼ�����ǻ���Ӧ�ñ�������д����Ϊ��׼������֤�����С�
	//��׼�涨��
	//����ָ������Ԫ�ص�ָ����ָ���������һ��Ԫ�غ�����Ǹ��ڴ�λ�õ�ָ��Ƚϣ����ǲ�������ָ���һ��Ԫ��֮ǰ���Ǹ��ڴ�λ�õ�ָ����бȽϡ�(��ǰԽ��)
	return 0;
}
*/
