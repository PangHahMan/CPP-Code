#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 1.��Ŀ1
/*
void GetMemory(char *p)
{
    p = (char *)malloc(100);   //�����p�����˿ռ䣬��strû�п���  Ҳû��free P
}

void Test(void)
{
    char *str = NULL;
    GetMemory(str);
    strcpy(str, "hello world");
    printf(str);   //����д��û������
}

int main()
{
    Test();
    return 0;
} */

//��д1
/*
void GetMemory(char **p)
{
    *p = (char *)malloc(100); //�����p�����˿ռ䣬��strû�п���  Ҳû��free P
}

void Test(void)
{
    char *str = NULL;
    GetMemory(&str);
    strcpy(str, "hello world");
    printf(str); //����д��û������
    //�ͷ�
    free(str);
    str = NULL;
}

int main()
{
    Test();
    return 0;
} */

//��д2
/*
char *GetMemory()
{
    char *p = (char *)malloc(100); //�����p�����˿ռ䣬��strû�п���  Ҳû��free P
    return p;
}

void Test(void)
{
    char *str = NULL;
    str = GetMemory();
    strcpy(str, "hello world");
    printf(str); //����д��û������
}

int main()
{
    Test();
    return 0;
} */


// 2.��Ŀ2
//����ջ�ռ��ַ�����⣡����
/*
char *GetMemory(void)
{
    char p[] = "hello world";   //�����������������������ˣ����ǵ�ַ���ڣ����˷��������ַ��ʱ�򣬾��Ƿ���Ұָ����
    return p;
}


void Test(void)
{
    char *str = NULL;
    str = GetMemory();  //str�ҵ���p�ĵ�ַ������p�ĵ�ַ�Ѿ�������
    printf(str);    //��ӡ��ֵ�ǲ���Ԥ֪��
}

int main()
{
    Test();
    return 0;
} */


// 3.��Ŀ
/*
void GetMemory(char **p, int num)
{
    *p = (char *)malloc(num);
}

void Test(void)
{
    char *str = NULL;
    GetMemory(&str, 100);
    strcpy(str, "hello");
    printf(str);
    //��������
    free(str);
    str = NULL;
}
//�ڴ�й©����
int main()
{
    Test();
    return 0;
}
*/


// 4.��Ŀ4
/*
void Test(void)
{
    char *str = (char *)malloc(100);
    strcpy(str, "hello");
    free(str);
    if (str != NULL)   //free��� str������ΪNULL  ��ߵ��ж�û������
    {
        //str��Ұָ�룬�Ƿ�����
        strcpy(str, "world");
        printf(str);
    }
}

int main()
{
    Test();
    return 0;
} */

//��д
/*
void Test(void)
{
    char *str = (char *)malloc(100);
    strcpy(str, "hello");
    free(str);
    str = NULL;
    if (str != NULL)
    {
        // str��Ұָ�룬�Ƿ�����
        strcpy(str, "world");
        printf(str);
    }
}

int main()
{
    Test();
    return 0;
} */

int main()
{
    printf("hehe");
    return 0;
}