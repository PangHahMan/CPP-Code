#include <stdio.h>
// KiKiѧϰ��ѭ����BoBo��ʦ��������һϵ�д�ӡͼ������ϰ���������Ǵ�ӡ�á�*����ɵ���б����ͼ����
int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF)
    {
        int i = 0;
        for (i = 0; i < n; i++)
        {
            int j = 0;
            for (j = 0; j < n; j++)
            {
                if (i + j == n - 1)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}