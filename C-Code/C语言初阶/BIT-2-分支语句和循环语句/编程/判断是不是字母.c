#include<stdio.h>

int main()
{
    int ch = 0;
    while ((ch = getchar()) != EOF)
    {
       
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            printf("����ĸ\n");
        }
        else
        {
            printf("������ĸ\n");
        }
        //�����\n
        getchar();
    }
    return 0;
}
