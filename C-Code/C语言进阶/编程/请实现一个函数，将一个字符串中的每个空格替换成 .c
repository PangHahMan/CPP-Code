#include <stdio.h>
#include<string.h>
//��ʵ��һ����������һ���ַ����е�ÿ���ո��滻��%20
void replaceSpace(char *str, int length)
{
    //ͳ�ƿո�ĸ���
    int space_count = 0;
    char *cur = str;
    while (*cur)
    {
        if (*cur == ' ')
        {
            space_count++;
        }
        cur++;
    }
    //����end1,end2
    char *end1 = str + length - 1; //����Ҳ���Բ�-1  ���ǰ�\0Ҳ������end2
    char *end2 = str + length - 1 + 2 * space_count;
    while ((end1 != end2))
    {
        if (*end1 != ' ')
        {
            *end2 = *end1;
        }
        else
        {
            *end2 = '0';
            end2--;
            *end2 = '2';
            end2--;
            *end2 = '%';
            end2--;
            end1--;
        }
    }
}

int main()
{
    char arr[40]="we are happy";
    int len = strlen(arr);
    replaceSpace(arr,len);
    printf("%s\n",arr);
    return 0;
}