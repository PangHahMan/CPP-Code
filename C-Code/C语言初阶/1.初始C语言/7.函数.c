#include<stdio.h>
//int main()
//{
//    int num1 = 0;
//    int num2 = 0;
//    int sum = 0;
//    printf("��������������:>");
//    scanf("%d %d", &num1, &num2);
//    sum = num1 + num2;
//    printf("sum = %d\n", sum);
//	return 0;
//}


//������д��������
int Add(int x, int y)
{
    int z = x + y;
    return z;
}

int main()
{
    int num1 = 0;
    int num2 = 0;
    int sum = 0;
    printf("��������������:>");
    scanf("%d %d", &num1, &num2);
    sum = Add(num1, num2);
    printf("sum = %d\n", sum);
    return 0;
}
