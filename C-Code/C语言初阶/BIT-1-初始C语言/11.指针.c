#include<stdio.h>
//11.1ָ��
//int main()
//{
//    int num = 10;
//    &num;//ȡ��num�ĵ�ַ
//    //ע������num��4���ֽڣ�ÿ���ֽڶ��е�ַ��ȡ�����ǵ�һ���ֽڵĵ�ַ����С�ĵ�ַ��
//    printf("%p\n", &num);//��ӡ��ַ��%p���Ե�ַ����ʽ��ӡ
//    return 0;
//}


//����ָ�����
//int num = 10;
//int* p;   //pΪһ������ָ�����
//p = &num;


//ָ���ʹ��
//int main()
//{
//    int num = 10;
//    int* p = &num;
//    *p = 20;    //p�ǵ�ַ   �Ե�ַ�����ò��� ���Բ���p��ַ������  ����num������
//    printf("%d", num);
//    return 0;
//}


//����ָ������
//int main()
//{
//    char ch = 'w';
//    char* pc = &ch;    //ch�ĵ�ַ Ϊ�ַ�ָ������
//    *pc = 'q';       //���ַ�ָ��pc�����ã��ı�ch��ֵ
//    printf("%c\n", ch);
//    return 0;
//}


//11.2 ָ������Ĵ�С
//ָ������Ĵ�Сȡ���ڵ�ַ�Ĵ�С
//32λƽ̨�µ�ַ��32��bitλ����4���ֽڣ�
//64λƽ̨�µ�ַ��64��bitλ����8���ֽڣ�
//int main()
//{
//    printf("%d\n", sizeof(char*));
//    printf("%d\n", sizeof(short*));
//    printf("%d\n", sizeof(int*));
//    printf("%d\n", sizeof(double*));
//    return 0;
//}