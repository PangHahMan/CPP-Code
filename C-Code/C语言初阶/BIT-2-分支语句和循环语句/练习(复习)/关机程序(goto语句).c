#include<stdio.h>
//#include<Windows.h>
//goto��ʽ
//int main()
//{
//    char input[10] = { 0 };
//    system("shutdown -s -t 60");
//again:
//    printf("���Խ���1�����ڹػ���������룺��������ȡ���ػ�!\n������:>");
//    scanf("%s", input);
//    if (0 == strcmp(input, "������"))
//    {
//        system("shutdown -a");
//    }
//    else
//    {
//        goto again;
//    }
//
//    return 0;
//}


//ѭ����ʽ
int main()
{
    char input[10] = { 0 };
    system("shutdown -s -t 60");
    printf("���Խ���1�����ڹػ���������룺��������ȡ���ػ�!\n������:>");
    while (1)
    {
        scanf("%s", input);
        if (0 == strcmp(input, "������"))
        {
            system("shutdown -a");
            printf("��ȡ���ػ�\n");
            break;
        }
    }
    return 0;
}