#include<stdio.h>
//9.1 �ؼ���typedef
//��unsigned int ������Ϊuint_32, ����uint_32Ҳ��һ��������
//typedef unsigned int uint_32;
//int main()
//{
//    //�۲�num1��num2,������������������һ����
//    unsigned int num1 = 0;
//    uint_32 num2 = 0;
//    return 0;
//}


//9.2 �ؼ���static
//static���������α����ͺ�����
//1. ���ξֲ����� - ��Ϊ��̬�ֲ�����
//2. ����ȫ�ֱ��� - ��Ϊ��̬ȫ�ֱ���
//3. ���κ��� - ��Ϊ��̬����

//9.2.1 static���ξֲ�����
//void test1()
//{
//    int i = 0;
//    i++;
//    printf("%d ", i);
//}
//
//void test2()
//{
//    static int i = 0;  //static���εľֲ�����
//    i++;
//    printf("%d ", i);
//}
//
//
//int main()
//{
//    int i = 0;
//    for (i = 0; i < 10; i++)
//    {
//        test1();
//    }
//
//    printf("\n");
//
//    for (i = 0; i < 10; i++)
//    {
//        test2();
//    }
//    return 0;
//}
//���ۣ�
//static���ξֲ������ı��˱�������������
//�þ�̬�ֲ�����������������Ȼ���ڣ�������������������ڲŽ�����


//9.2.2 static����ȫ�ֱ���
//����1
//add.c
//int g_val = 2018;
////test.c
//int main()
//{
//    printf("%d\n", g_val);
//    return 0;
//}
//
////����2
////add.c
//static int g_val = 2018;   //static����ȫ�ֱ���
////test.c
//int main()
//{
//    printf("%d\n", g_val);
//    return 0;
//}
//����1����������2�ڱ����ʱ�����������Դ���
//��һ��ȫ�ֱ�����static���Σ�ʹ�����ȫ�ֱ���ֻ���ڱ�Դ�ļ���ʹ�ã�����������Դ�ļ���ʹ�á�


//9.2.3 static���κ���
//����1
//add.c
//int Add(int x, int y)
//{
//    return x + y;
//}
////test.c
//int main()
//{
//    printf("%d\n", Add(2, 3));
//    return 0;
//}

//����2
//add.c
//static int Add(int x, int y)   //static���κ���
//{
//    return x + y;
//}
////test.c
//int main()
//{
//    printf("%d\n", Add(2, 3));
//    return 0;
//}
//����1����������2�ڱ����ʱ�����������Դ���.
//��һ��������static���Σ�ʹ���������ֻ���ڱ�Դ�ļ���ʹ�ã�����������Դ�ļ���ʹ�á�