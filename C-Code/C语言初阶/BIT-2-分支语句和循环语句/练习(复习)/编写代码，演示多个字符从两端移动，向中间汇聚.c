#include<stdio.h>
#include<windows.h>
int main()
{
    char arr1[] = "welcome to bit!!!";
    char arr2[] = "                 ";
    int left = 0;
    int right = strlen(arr1) - 1;       //�ַ�������
    //int right = sizeof(arr1) / sizeof(arr1[0]) - 1;       //��������ĳ��ȣ��������û����ȫ��ʼ�����ʹ���
    printf("%s\n", arr2);
    //whileѭ��ʵ��
    while (left <= right)
    {
        Sleep(500);      //sleep������ͷ�ļ�windows.h
        arr2[left] = arr1[left];
        arr2[right] = arr1[right];
        left++;
        right--;
        printf("%s\n", arr2);
    }
    return 0;
}