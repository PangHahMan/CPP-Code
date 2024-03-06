#include <stdio.h>
#include <string.h>
#include <assert.h>
//�ַ�������
/*
ʵ��һ�����������������ַ����е�k���ַ���
���磺
ABCD����һ���ַ��õ�BCDA
ABCD���������ַ��õ�CDAB */
/*
void left_move(char *arr, int k)
{
    //ÿһ��ֻ��תһ���ַ������������ִ��k��
    int i = 0;
    int len = strlen(arr);
    k %= len; //��k����len��ʱ�� Ҳ���������˺ܶ�� �������ַ�������û�������ˣ��ضϵ�û�������
    for (i = 0; i < k; i++)
    {
        char tmp = arr[0]; // 1
        // 2.�Ѻ�ߵ��ַ�ȫ����ǰŲ��һ��λ��
        int j = 0;
        for (j = 0; j < len - 1; j++)
        {
            arr[j] = arr[j + 1];
        }
        // 3.
        arr[len - 1] = tmp;
    }
} */

//�����Ż� ������� �ұ�����  �������� �ʹﵽ������
void reverse(char *left, char *right)
{
    assert(left && right);
    while (left < right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}

void left_move(char *arr, int k)
{
    int i = 0;
    int len = strlen(arr);
    k %= len;
    reverse(arr, arr + k - 1);       //�������
    reverse(arr + k, arr + len - 1); //�ұ�����
    reverse(arr, arr + len - 1);     //��������
}

int main()
{
    char arr[] = "abcdefghi";
    int k = 0;
    scanf("%d", &k);
    left_move(arr, k);
    printf("%s", arr);
    return 0;
}