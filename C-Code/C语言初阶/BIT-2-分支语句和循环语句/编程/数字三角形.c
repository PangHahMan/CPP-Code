#include <stdio.h>
// /KiKiѧϰ��ѭ����BoBo��ʦ��������һϵ�д�ӡͼ������ϰ���������Ǵ�ӡ��������ɵ�����������ͼ����
int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF)
    {
        int i = 0;
        //��ӡ��
        for (i = 0; i < n; i++)
        {
            //��ӡһ��
            for (int j = 0; j < i + 1; j++)
            {
                printf("%d ", j + 1);
            }
            printf("\n");
        }
    }
    return 0;
}