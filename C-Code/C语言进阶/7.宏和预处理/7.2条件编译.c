#include <stdio.h>
// 1.�����ж���
/*
���C �ı������ṩ��һ���������������������ж�����š���������������̡�
���磺�����Ǹ���ͬһ��Դ�ļ�Ҫ�����һ������Ĳ�ͬ�汾��ʱ����������е��ô������ٶ�ĳ��
������������һ��ĳ�����ȵ����飬��������ڴ����ޣ�������Ҫһ����С�����飬��������һ������
�ڴ��Щ��������Ҫһ�������ܹ���Щ����
����ָ�
gcc -D ARRAY_SIZE=10 programe.c */

//��������
//���ڱ���һ�������ʱ���������Ҫ��һ����䣨һ����䣩������߷����Ǻܷ���ġ���Ϊ��������������ָ�
/*
#define __DEBUG__
#include <stdio.h>
#define __DEBUG__
int main()
{
    int i = 0;
    int arr[10] = {0};
    for (i = 0; i < 10; i++)
    {
        arr[i] = i;
#ifdef __DEBUG__
        printf("%d\n", arr[i]); //Ϊ�˹۲������Ƿ�ֵ�ɹ���
#endif                          //__DEBUG__
    }
    return 0;
} */

//��������������ָ�

// 1.

/*
int main()
{
    #if 1
    printf("hehe\n");   //�������������  ��Ԥ�����ʱ��ͻ�ɾ������
    #endif
}*/

// 2.�����֧����������
/*
int main()
{
#if 1 > 2
    printf("hehe\n");
#elif 2 > 3
    printf("haha\n");
#else
    printf("heihei\n");
#endif
    return 0;
} */

// 3.�ж��Ƿ񱻶���
/*
#define MAX
int main()
{
#if defined(MAX)  //Ҳ����д�� #ifdef MAX
    printf("hehe\n");
#endif

#if !defined(MAX)  //Ҳ����д��#ifndef MAX
    printf("haha\n");
#endif
    return 0;
} */

// 4.Ƕ����������
/* 
#if defined(OS_UNIX)
#ifdef OPTION1
unix_version_option1();
#endif
#ifdef OPTION2
unix_version_option2();
#endif
#elif defined(OS_MSDOS)
#ifdef OPTION2
msdos_version_option2();
#endif
#endif */
