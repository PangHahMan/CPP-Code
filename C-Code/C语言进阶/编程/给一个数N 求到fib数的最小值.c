#include <stdio.h>
#include <math.h> //abs�Ŀ⺯��
//��һ����N ��fib������Сֵ
int main()
{
    int n = 0;
    scanf("%d", &n);
    int f1 = 0;
    int f2 = 1;
    int f3 = f1 + f2;
    while (1)
    {
        if (n == f2)
        {
            printf("0\n");
            break;
        }
        else if (n < f2)
        {
            if (abs(f1 - n) < abs(f2 - n)) //�����ֵ
            {
                printf("%d\n", abs(f1 - n));
            }
            else
            {
                printf("%d\n", abs(f2 - n));
            }
            break;
        }

        f1 = f2;
        f2 = f3;
        f3 = f1 + f2;
    }
    return 0;
}