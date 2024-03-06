#include <stdio.h>
// 1.fseek - �����ļ�ָ���λ�ú�ƫ��������λ�ļ�ָ��
// int fseek(FILE* ,long int offset,int origin)
/* ����
FILE* stream ��ָ���Ѵ��ļ���ָ�롣
long offset ��ƫ�������������ɡ��������ƫ�ƣ�����ǰ��ƫ�ơ�
int origin ������ֵ��������
SEEK_SET �� ָ���ļ��׶ˣ�
SEEK_CUR �� ָ��ǰλ�ã�
SEEK_END �� ָ��
�ļ�β�ˡ� */

/*
int main()
{
    FILE *pf = fopen("test.txt", "r");
    if (pf == NULL)
    {
        perror("fopen()");
        return 1;
    }
    //���ļ� - �ļ��д��abcdef
    int ch = fgetc(pf);
    printf("%c\n", ch);       // a  ������ļ�ָ������+1 ָ��b

    fseek(pf, 2, SEEK_CUR); //�ӵ�ǰ�ļ�ָ������ƫ��2��  (��ǰ��b)
    ch = fgetc(pf);
    printf("%c\n", ch); // d


    fseek(pf, 3, SEEK_SET); //�ļ��ײ����ƫ������
    ch = fgetc(pf);
    printf("%c\n", ch); // d

    fseek(pf, -3, SEEK_END); //�ļ��ײ���ǰƫ������  ĩβ��ָ����f�ĺ���
    ch = fgetc(pf);
    printf("%c\n", ch); // d

    //�ر��ļ�
    fclose(pf);
    pf = NULL;
    return 0;
} */

// 2. ftell���� - ���ܣ������ļ�ָ���������ʼλ�õ�ƫ����
//  �﷨��long ftell(FILE *stream);
/*
int main()
{
    FILE *pf = fopen("test.txt", "r");
    if (pf == NULL)
    {
        perror("fopen()");
        return 1;
    }
    //���ļ� - �ļ��д��abcdef
    int ch = fgetc(pf);
    printf("%c\n", ch);       // a  ������ļ�ָ������+1 ָ��b

    fseek(pf, 2, SEEK_CUR); //�ӵ�ǰ�ļ�ָ������ƫ��2��  (��ǰ��b)
    ch = fgetc(pf);
    printf("%c\n", ch); // d

    int pos = ftell(pf);    //���ļ�ָ��d��ʱ�� �ļ�ָ������ƫ��1�� ָ����e
    printf("%d\n",pos);  //4
    //�ر��ļ�
    fclose(pf);
    pf = NULL;
    return 0;
}  */

// 3.rewind - ���ܣ����ļ�ָ���λ�ûص��ļ�����ʼλ��
//�﷨��void rewind(FILE *stream);
/* 
int main()
{
    FILE *pf = fopen("test.txt", "r");
    if (pf == NULL)
    {
        perror("fopen()");
        return 1;
    }
    //���ļ� - �ļ��д��abcdef
    int ch = fgetc(pf);
    printf("%c\n", ch); // a  ������ļ�ָ������+1 ָ��b

    fseek(pf, 2, SEEK_CUR); //�ӵ�ǰ�ļ�ָ������ƫ��2��  (��ǰ��b)
    ch = fgetc(pf);
    printf("%c\n", ch); // d
    
    //��¼��ǰƫ����
    int pos = ftell(pf); //���ļ�ָ��d��ʱ�� �ļ�ָ������ƫ��1�� ָ����e
    printf("%d\n", pos); // 4
  
    //ƫ�����ص���ʼλ��
    rewind(pf);
    ch = fgetc(pf);
    printf("%c\n", ch); // a
    //�ر��ļ�
    fclose(pf);
    pf = NULL;
    return 0;
}*/