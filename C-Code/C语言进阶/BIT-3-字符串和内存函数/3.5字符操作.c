#include <stdio.h>
#include <ctype.h>
/*  ������Ĳ����������������ͷ�����
iscntrl �κο����ַ�
isspace �հ��ַ����ո� ������ҳ��\f��������'\n'���س���\r�����Ʊ��'\t'���ߴ�ֱ�Ʊ��'\v'
isdigit ʮ�������� 0~9
isxdigit ʮ���������֣���������ʮ�������֣�Сд��ĸa~f����д��ĸA~F
islower Сд��ĸa~z
isupper ��д��ĸA~Z
isalpha ��ĸa~z��A~Z
isalnum ��ĸ�������֣�a~z,A~Z,0~9
ispunct �����ţ��κβ��������ֻ�����ĸ��ͼ���ַ����ɴ�ӡ��
isgraph �κ�ͼ���ַ�
isprint �κοɴ�ӡ�ַ�������ͼ���ַ��Ϳհ��ַ� */

/* ת����ĸ��Сд����toupper tolower
int main()
{
    char ch = 'w';
    printf("%c\n", toupper(ch)); // toupeer ת���ɴ�д��ĸ - W
    char ch2 = 'A';
    printf("%c\n", tolower(ch2)); // tolower ת����Сд��ĸ - a
    return 0;
}
*/


/* 
int main()
{
    char arr[] = "Are you ok?";
    char *p = arr;
    while (*p)
    {
        if (islower(*p))   //islower �ж��Ƿ���Сд��ĸ
        {
            *p = toupper(*p);
        }
        p++;
    }
    printf("%s\n", arr); // ARE YOU OK?
    return 0;
} 
*/