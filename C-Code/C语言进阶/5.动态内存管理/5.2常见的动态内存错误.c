#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// 1.��NULLָ��Ľ����ò���
/*
int main()
{
    int *p = (int *)malloc(20);
    //Ϊ�˲��Կ�ָ�������  ��Ҫ�����ж�
    if (p == NULL)
    {
        perror("malloc");
        return 1;
    }
    else
    {
        *p = 5;
    }
    free(p);
    p = NULL;
    return 0;
} */


// 2.�Զ�̬���ٿռ��Խ�����
/*
int main()
{
    int *p = (int *)malloc(20);
    if (p == NULL)
        return 1;
    int i = 0;
    for (i = 0; i < 20; i++) //Խ�����    20���ֽ� ֻ�ܷ���5������
    {
        *(p + i) = i;
    }

    free(p);
    p = NULL;
    return 0;
}
*/


// 3.�ԷǶ�̬�����ڴ�ʹ��free�ͷ�
/*
void test()
{
    int a = 10;
    int *p = &a;
    free(p); // ok?
}
*/


// 4.ʹ��free�ͷ�һ�鶯̬�����ڴ��һ����
/*
int main()
{
    int *p = (int *)malloc(40);
    if (p = NULL)
        return 1;
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        *p = i;
        p++;
    }
    //�ͷ�
    //���ͷŵ�ʱ��pָ��Ĳ����Ƕ�̬�ڴ�ռ����ʼλ��
    free(p); // p����ָ��̬�ڴ����ʼλ��
    p++;
    return 0;
}
*/


// 5.��ͬһ�鶯̬�ڴ����ͷ�
/*
int main()
{
    int *p = (int *)malloc(40);
    if (p = NULL)
        return 1;
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        *(p + i) = i;
    }
    //�ظ�free
    free(p);
    p = NULL //�����p��ֵΪNULL  �Ϳ�����free
        free(p);

    return 0;
}
*/


// 6.��̬�����ڴ������ͷţ��ڴ�й©��
//�����᷵�ض�̬���ٿռ�ĵ�ַ���ǵ���ʹ��֮�󷵻�
/*
int* get_memory()
{
    int*p=(int*)malloc(40);

    return p;
}

int main()
{
    int *ptr=get_memory();
    //ʹ��

    //�ͷ�  ������ͷ� �ͻᵼ���ڴ�й©
    free(ptr);
    return 0;
} */
//�����ͷŲ���ʹ�õĶ�̬���ٵĿռ������ڴ�й©��
//�мǣ�
//��̬���ٵĿռ�һ��Ҫ�ͷţ�������ȷ�ͷ� ��
