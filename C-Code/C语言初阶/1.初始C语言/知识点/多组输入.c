#include <stdio.h>
int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF)   //EOF����-1  �ļ�������־ ���ڶ�������
    {
        if (n >= 140)
            printf("Genius");
    }
    return 0;
}