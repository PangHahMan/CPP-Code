#include <stdio.h>
#include <assert.h>
#include<string.h>
/* �ڴ溯��
memcpy - �ڴ濽��
memmove
memcmp
memset -
*/

// 1.memcpy - �ڴ濽��
// void * memcpy ( void * destination, const void * source, size_t num );
// ����memcpy��source��λ�ÿ�ʼ�����num���ֽڵ����ݵ�destination���ڴ�λ�á�
// ������������� '\0' ��ʱ�򲢲���ͣ������
// ���source��destination���κε��ص������ƵĽ������δ����ġ�

/*
int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[10] = {0};
    memcpy(arr2, arr1, 20); // 20��ʾ�ֽ� ����5����������

    float arr3[] = {1.0f, 2.0f, 3.0f, 4.0f};
    float arr4[] = {0.0};
    memcpy(arr4, arr3, 8); // 8��ʾ����2������������
    return 0;
}
*/

//ģ��ʵ��my_memcpy
//С�ˣ�
/*
void *my_memcpy(void *dest, void *src, size_t num) //��Ҫ��void* �ĵ�ַ   num�ĵ�λ���ֽ�
{
    assert(dest && src);
    void *ret = dest;
    while (num--) //����num���ֽڵ����� һ�ν���һ���ֽ�
    {
        *(char *)dest = *(char *)src;
        dest = (char *)dest + 1;
        src = (char *)src + 1;
    }
    return ret;
}



int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[10] = {0};
    my_memcpy(arr2, arr1, 20);
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr2[i]);
    }

    printf("\n");

    float arr3[] = {1.0f, 2.0f, 3.0f, 4.0f};
    float arr4[] = {0.0};
    my_memcpy(arr4, arr3, 8);
    for (i = 0; i < 10; i++)
    {
        printf("%f ", arr4[i]);
    }
    return 0;
} */


//2.����mommove������ģ��ʵ��   C�������ص��ڴ�ĺ�����mommove��ʵ��
/*
void *my_memmove(void *dest, void *src, size_t num) //��Ҫ��void* �ĵ�ַ   num�ĵ�λ���ֽ�
{
    assert(dest && src);
    void* ret =dest;
    if (dest < src)
    {
        while (num--) //����num���ֽڵ����� һ�ν���һ���ֽ�
        {
            *(char *)dest = *(char *)src;
            dest = (char *)dest + 1;
            src = (char *)src + 1;
        }
    }
    else
    {
        while (num--)
        {
            *((char *)dest + num) = ((char *)src + num);   //��������� ����ǰ�����
        }
    }

    return ret;
} */
//��memcpy�Ĳ�����memmove���������Դ�ڴ���Ŀ���ڴ���ǿ����ص��ġ�
//���Դ�ռ��Ŀ��ռ�����ص����͵�ʹ��memmove��������
// 
//memcpyֻ��Ҫʵ�ֲ��ص��Ŀ����Ϳ�����    VS�е�memcpy��mommoveʵ�ַ�ʽ��� �������
//memmove����Ҫʵ���ص��ڴ�Ŀ���



//3.memcmp
//void * memcpy ( void * destination, const void * source, size_t num );
/*
����memcpy��source��λ�ÿ�ʼ�����num���ֽڵ����ݵ�destination���ڴ�λ�á�
������������� '\0' ��ʱ�򲢲���ͣ������
���source��destination���κε��ص������ƵĽ������δ����ġ�
*/

/*
int main()
{
    int arr1[] = { 1,2,3,4,5 }; //01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00
    int arr2[] = { 1,2,3,0,0 }; //01 00 00 00 02 00 00 00 03 00 00 00 00 00 00 00
    int ret = memcmp(arr1, arr2, 12);
    printf("%d\n", ret); //0

    ret = memcmp(arr1, arr2, 13);
    printf("%d\n", ret);  //1
    return 0;
}
*/


//4.memset
/*
int main()
{
    int arr[] = { 1,2,3,4,5 };
    memset(arr, 0, 8);  //8���ֽ�
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);  // 0 0 3 4 5
    }
    return 0;
}
*/

