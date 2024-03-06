#include <stdio.h>
// feof - �μǣ����ļ���ȡ�����У�������feof�����ķ���ֱֵ�������ж��ļ����Ƿ������
//����Ӧ���ڵ��ļ���ȡ������ʱ���ж��Ƕ�ȡʧ�ܽ���������ֵΪ�٣������������ļ�β����������ֵΪ�棩��

/*
1. �ı��ļ���ȡ�Ƿ�������жϷ���ֵ�Ƿ�Ϊ EOF �� fgetc �������� NULL �� fgets ��
���磺
fgetc �ж��Ƿ�ΪEOF
fgets �жϷ���ֵ�Ƿ�ΪNULL */

// fgetc - �����ȡ�������᷵�ض�ȡ�����ַ���ascll��ֵ�������ȡʧ�ܻ᷵��EOF

// fgets - �����ȡ���������ص��Ƕ�ȡ�������ݵĵ�ַ�������ȡʧ�ܣ����ص���NULL

// fscanf - �����ȡ���������ص��Ǹ�ʽ����ָ�������ݵĸ����������ȡʧ�ܣ����ص���С�ڸ�ʽ����ָ�������ݵĸ���

/*
2. �������ļ��Ķ�ȡ�����жϣ��жϷ���ֵ�Ƿ�С��ʵ��Ҫ���ĸ�����
���磺
fread�жϷ���ֵ�Ƿ�С��ʵ��Ҫ���ĸ����� */

/* �ı��ļ������ӣ�
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int c; // ע�⣺int����char��Ҫ����EOF
    FILE *fp = fopen("test.txt", "r");
    if (!fp)
    {
        perror("File opening failed");
        return EXIT_FAILURE;
    }
    // fgetc ����ȡʧ�ܵ�ʱ����������ļ�������ʱ�򣬶��᷵��EOF
    while ((c = fgetc(fp)) != EOF) // ��׼C I/O��ȡ�ļ�ѭ��
    {
        putchar(c);
    }
    //�ж���ʲôԭ�������
    if (ferror(fp))
        puts("I/O error when reading");
    else if (feof(fp))
        puts("End of file reached successfully");
    fclose(fp);
} */

//�������ļ�
/*
#include <stdio.h>
enum
{
    SIZE = 5
};

int main(void)
{
    double a[SIZE] = {1., 2., 3., 4., 5.};
    FILE *fp = fopen("test.bin", "wb"); // �����ö�����ģʽ
    fwrite(a, sizeof *a, SIZE, fp);     // д double ������
    fclose(fp);
    double b[SIZE];
    fp = fopen("test.bin", "rb");
    size_t ret_code = fread(b, sizeof *b, SIZE, fp); // �� double ������
    if (ret_code == SIZE)
    {
        puts("Array read successfully, contents: ");
        for (int n = 0; n < SIZE; ++n)
            printf("%f ", b[n]);
        putchar('\n');
    }
    else
    { // error handling
        if (feof(fp))
            printf("Error reading test.bin: unexpected end of file\n");
        else if (ferror(fp))
        {
            perror("Error reading test.bin");
        }
    }
    fclose(fp);
} */

//������
/* 
#include <stdio.h>
#include <windows.h>
// VS2013 WIN10��������
int main()
{
    FILE *pf = fopen("test.txt", "w");
    fputs("abcdef", pf); //�Ƚ�����������������
    printf("˯��10��-�Ѿ�д�����ˣ���test.txt�ļ��������ļ�û������\n");
    Sleep(10000);
    printf("ˢ�»�����\n");
    fflush(pf); //ˢ�»�����ʱ���Ž����������������д���ļ������̣�
    //ע��fflush �ڸ߰汾��VS�ϲ���ʹ����
    printf("��˯��10��-��ʱ���ٴδ�test.txt�ļ����ļ���������\n");
    Sleep(10000);
    fclose(pf);
    //ע��fclose�ڹر��ļ���ʱ��Ҳ��ˢ�»�����
    pf = NULL;
    return 0;
} */

/* ������Եó�һ�����ۣ�
��Ϊ�л������Ĵ��ڣ�C�����ڲ����ļ���ʱ����Ҫ��ˢ�»������������ļ�����������ʱ��ر���
����
������������ܵ��¶�д�ļ������⡣ */