#include <stdio.h>
int main()
{
    int ch = 0;
    while ((ch = getchar()) != EOF)
    {
        //�ж���ĸ
        if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z'))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        //�����\n
        int b = getchar();   //��Ҫ����������getchar�ķ���ֵ
    }
    return 0;
}