#include <stdio.h>
#include <string.h>
/*
дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
���磺����s1 =AABCD��s2 = BCDAA������1
����s1=abcd��s2=ACBD������0.
AABCD����һ���ַ��õ�ABCDA
AABCD���������ַ��õ�BCDAA
AABCD����һ���ַ��õ�DAABC
 */
/*  ˼·1 Ч�ʲ���
int is_left_move(char *arr1, char *arr2)
{
    int len = strlen(arr1);
    int i = 0;
    for (i = 0; i < len; i++)
    {
        char tmp = arr1[0];
        int j = 0;
        for (j = 0; j < len - 1; j++)
        {
            arr1[j] = arr1[j + 1];
        }
        arr1[len - 1] = tmp;
        if (strcmp(arr1, arr2) == 0)
        {
            return 1;
        }
    }
}
*/

//��arr1������׷��һ��arr1  ABCDEFABCDEF ����strstr
int is_left_move(char *arr1, char *arr2)
{
    int len1 = strlen(arr1);
    int len2 = strlen(arr2);
    if (len1 != len2) //������Ȳ�ͬ ��������
        return 0;
    strncat(arr1, arr2, len1); // arr1�Ŀռ��㹻��
    char *ret = strstr(arr1, arr2);
    if (ret == NULL)
        return 0;
    else
        return 1;
}

int main()
{
    char arr1[20] = "ABCDEF";
    char arr2[] = "CDEFAB";
    int ret = is_left_move(arr1, arr2); //�ж�arr2�Ƿ���arr1��ת������
    if (ret == 1)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}