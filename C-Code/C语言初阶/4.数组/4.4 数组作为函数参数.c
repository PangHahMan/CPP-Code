#include<stdio.h>
//1.ð���������Ĵ������
//����1��
//void bubble_sort(int arr[])
//{
//    int sz = sizeof(arr) / sizeof(arr[0]);//��������
//    int i = 0;
//    for (i = 0; i < sz - 1; i++)
//    {
//        int j = 0;
//        for (j = 0; j < sz - i - 1; j++)
//        {
//            if (arr[j] > arr[j + 1])
//            {
//                int tmp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = tmp;
//            }
//        }
//    }
//}
// 
//int main()
//{
//    int arr[] = { 3,1,7,5,8,9,0,2,4,6 };
//    int i = 0;
//    bubble_sort(arr);//�Ƿ������������
//    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}
//����1�������⣬��������һ�����⣬����֮����Կ��� bubble_sort �����ڲ��� sz ����1��
//�ѵ�������Ϊ����������ʱ�򣬲��ǰ���������Ĵ��ݹ�ȥ��


//2.��������ʲô��
//int main()
//{
//    int arr[10] = { 1,2,3,4,5 };
//    printf("%p\n", arr);   //000000B2383BF8F8
//    printf("%p\n", &arr[0]);   //000000B2383BF8F8
//    printf("%d\n", *arr);   //1
//    return 0;
//}
//��������������Ԫ�صĵ�ַ��


//int main()
//{
//    int arr[10] = { 0 };
//    printf("%zd\n", sizeof(arr));  //40
//    return 0;
//}
//���䣺
//1. sizeof(������)��������������Ĵ�С��sizeof�ڲ�������һ������������������ʾ�������顣
//2. &��������ȡ����������ĵ�ַ�� &����������������ʾ�������顣
//����1, 2�������֮�⣬���е�����������ʾ������Ԫ�صĵ�ַ��


//ð���������ȷ���
//�����鴫�ε�ʱ��ʵ����ֻ�ǰ��������Ԫ�صĵ�ַ���ݹ�ȥ�ˡ�
//���Լ�ʹ�ں�����������д���������ʽ�� int arr[] ��ʾ����Ȼ��һ��ָ�룺 int* arr ��
//��ô�������ڲ��� sizeof(arr) �����4��
//��� ����1 ���ˣ�����ô��ƣ�

//����2
void bubble_sort(int arr[], int sz)
{
    int i = 0;
    for (i = 0; i < sz - 1; i++)
    {
        int j = 0;
        for (j = 0; j < sz - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main()
{
    int arr[] = { 3,1,7,5,8,9,0,2,4,6 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    bubble_sort(arr, sz);//�Ƿ������������
    for (i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}