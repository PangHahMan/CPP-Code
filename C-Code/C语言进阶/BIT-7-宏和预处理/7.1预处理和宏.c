#include <stdio.h>
/* 1.Ԥ�������
__FILE__      //���б����Դ�ļ�
__LINE__     //�ļ���ǰ���к�
__DATE__    //�ļ������������
__TIME__    //�ļ��������ʱ��
__STDC__    //�����������ѭANSI C����ֵΪ1������δ����
��ЩԤ������Ŷ����������õġ�
�ٸ����ӣ�
int main()
{
    printf("%s\n", __FILE__); //�磺1.c
    printf("%d\n", __LINE__); // 16
    printf("%s\n", __DATE__); // Oct 15 2022
    printf("%s\n", __TIME__); // 17:26:06  ��¼��ʱ���Ǳ����ʱ��
    //printf("%d\n", __STDC__);   //δ����  ����ѭANSI C
    return 0;
}

*/

// 2.#define

// 2.1 #define �����ʶ��

/*
#define MAX 100
#define STR "bitejiujiuyeke"
#define do_forever for(;;)
int main()
{
    printf("%d\n",MAX);   //100
    printf(STR);   //bitejiujiuyeke
    do_forever;   //��ѭ��
    return 0;
}
 */

/* //#define���治Ҫ�ӷֺ�
#define MAX 1000;
int main()
{
    int max = 0;
    if (3 > 5)
        //max = MAX;   //����  ��ΪMAX ==1000; �����������ֺ�
        max = MAX    //��ȷ
    else
        max = 0;
    return 0;
}
 */

// 2.2 #define����� - #define ���ư�����һ���涨������Ѳ����滻���ı��У�����ʵ��ͨ����Ϊ�꣨macro������꣨define macro����

/*
//�������
int Max_hanshu(int x, int y)
{
    return x > y ? x : y;
}
//����
#define MAX(x, y) (x > y ? x : y)
int main()
{
    int a = 10;
    int b = 20;
    int max = Max_hanshu(a, b);
    int m = MAX(a, b);
    printf("%d\n", max);
    printf("%d\n", m);
    return 0;
} */

// define��һЩ����
/*
#define SQUARE(X) X *X
#define SQUARE1(X) (X) * (X)
#define DOUBLE(X) (X) + (X)
#define DOUBLE1(X) ((X) + (X))
int main()
{
    printf("%d\n", SQUARE(5));      // 25
    printf("%d\n", SQUARE(5 + 1));  // 5+1*5+1 == 11
    printf("%d\n", SQUARE1(5 + 1)); // 36

    printf("%d\n", DOUBLE(6));      // 12
    printf("%d\n", DOUBLE(6 + 1));  // 14
    printf("%d\n", 10 * DOUBLE(6)); // 66  10*(6)+(6) ==66
    printf("%d\n", 10 * DOUBLE1(6));   //120
    return 0;
} */

// 2.3#define���滻����
//�ڳ�������չ #define������źͺ�ʱ����Ҫ�漰�������衣
// 1. �ڵ��ú�ʱ�����ȶԲ������м�飬�����Ƿ�����κ��� #define����ķ��š�����ǣ��������ȱ��滻��
/*
#define M 10
#define MAX(x, y) ((x) > (y) ? (x) : (y))
int main()
{
    int m = MAX(2 + 3, M); //�����Mֱ���滻��10
    return 0;
} */
// 2. �滻�ı���󱻲��뵽������ԭ���ı���λ�á����ں꣬�����������ǵ�ֵ���滻��
// 3. ����ٴζԽ���ļ�����ɨ�裬�������Ƿ�����κ��� #define����ķ��š�����ǣ����ظ��� ��������̡�

/* ע�⣺
1. �������#define �����п��Գ�������#define����ķ��š����Ƕ��ں꣬���ܳ��ֵݹ顣
2. ��Ԥ����������#define����ķ��ŵ�ʱ���ַ������������ݲ����������� */

// 2.4#��##
//��ΰѲ������뵽�ַ����У�
/*
int main()
{
    printf("Hello World\n");
    printf("Hello " "World\n");
    return 0;
} */

//ʹ�� # ����һ���������ɶ�Ӧ���ַ�����
/*
#define PRINT(val,format) printf("the value of "#val" is "format"\n",val)
int main()
{
    //���´���Ƚ�����
    int a = 10;
    PRINT(a,"%d");


    int b = 20;
    PRINT(b,"%d");

    float f = 3.5f;
    PRINT(f,"%f");
    return 0;
} */

//## - ##���԰�λ�������ߵķ��źϳ�һ�����š� ������궨��ӷ�����ı�Ƭ�δ�����ʶ����
/*
#define CAT(A,B) A##B
int main()
{
    int Class107 = 100;
    printf("%d\n",CAT(Class,107));   //100   Class107
    return 0;
} */

// 2.5�и����õĺ����
//���ӣ��и����õĴ���
/*
int main()
{
    int a = 1;
    int b = a + 1; // b=2,a=1

    a = 1;
    b = ++a; // b=2,a=2  ���и����õĴ���

    int ch = getchar();  //��һ���ַ�����������һ���ַ�

    return 0;
} */

//�и����õĺ����
/*
#define MAX(x, y) ((x) > (y) ? (x) : (y))
int main()
{
    int a = 3;
    int b = 4;
    int m = MAX(++a, ++b);
    //int m = ((++a) > (++b) ? (++a) : (++b));   4>5   a=4  b =6
    printf("m=%d a=%d b=%d\n", m, a, b); // 6 4 6
    return 0;
} */

// 2.6��ͺ����Ա�
/*
int Max(int x, int y)
{
    return x > y ? x : y;
}

#define MAX(x, y) ((x) > (y) ? (x) : (y))
int main()
{
    int a = 10;
    int b = 20;
    //�����ķ�ʽ
    int m1 = Max(a, b);
    printf("%d\n", m1);

    //��ķ�ʽ
    int m2 = MAX(a, b);
    printf("%d\n", m2);
    return 0;
} */

//��ͨ����Ӧ����ִ�м򵥵����㡣���������������ҳ��ϴ��һ����
/* ��Ϊʲô���ú���������������
ԭ���ж���
1. ���ڵ��ú����ʹӺ������صĴ�����ܱ�ʵ��ִ�����С�ͼ��㹤������Ҫ��ʱ����ࡣ
���Ժ�Ⱥ����ڳ���Ĺ�ģ���ٶȷ����ʤһ�
2. ��Ϊ��Ҫ���Ǻ����Ĳ�����������Ϊ�ض������͡�
���Ժ���ֻ�������ͺ��ʵı��ʽ��ʹ�á���֮��������������������Ρ������͡������͵ȿ�������>���Ƚϵ����͡�
���������޹صġ�

���ȱ�㣺��Ȼ�ͺ�����Ⱥ�Ҳ�����Ƶĵط���
1. ÿ��ʹ�ú��ʱ��һ�ݺ궨��Ĵ��뽫���뵽�����С����Ǻ�Ƚ϶̣�������ܴ�������ӳ���ĳ��ȡ�
2. ����û�����Եġ�
3. �����������޹أ�Ҳ�Ͳ����Ͻ���
4. ����ܻ������������ȼ������⣬���³����׳��ִ�

 */

//����ʱ����������������������顣���磺��Ĳ������Գ������ͣ����Ǻ�����������
/* 
#define MALLOC(num, type) (type *)malloc(num * sizeof(type))
int main()
{
    int *p = malloc(10, sizeof(int));
    MALLOC(10, int);  //������Ϊ����
    return 0;
} */


//#undef - ����ָ�������Ƴ�һ���궨�塣
/* 
#define M 100
int main()
{
    printf("%d\n");
    #undef M
    printf("%d\n",M);  //����
    return 0;
} */
