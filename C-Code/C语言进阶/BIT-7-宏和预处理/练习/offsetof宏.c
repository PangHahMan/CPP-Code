//дһ���꣬����ṹ����ĳ����������׵�ַ��ƫ�ƣ�������˵��
//���죺offsetof���ʵ��
#include <stdio.h>
#define OFFSETOF(s_type,m_name)
struct S
{
    char a;
    int b;
    char c;
};

#define OFFSETOF(s_type,m_name) (int)&(((s_type*)0)->m_name)
int main()
{
    printf("%d\n", OFFSETOF(struct S, a));  //0
    printf("%d\n", OFFSETOF(struct S, b));  //4
    printf("%d\n", OFFSETOF(struct S, c));  //8
    return 0;
}