#include<stdio.h>
//int main()
//{
//	int ch = 0;    //getchar�ķ���ֵΪint
//	while ((ch = getchar()) != EOF)   //EOF��ֵΪ-1
//	{
//		putchar(ch);
//	}
//	return 0;
//}
//����Ĵ����ʵ����޸��ǿ�����������������

//
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0' || ch > '9')
//			continue;
//		putchar(ch);
//	}
//	return 0;
//}
//�������������ǣ�ֻ��ӡ�����ַ������������ַ�


//int main()
//{
//	char password[20] = { 0 };
//	printf("����������:>");
//	scanf("%s", password);
//	//������̻�����\n
//	int a = getchar();    //������ƻ���������Ϊscanf�пո�Ҳ��ֱ������ ����scanf����abc def ֻ��abc
//	printf("��ȷ������Y/N��");
//	int ch = getchar();    //getchar���ȡscanf�����\n �ŵ�ch��  �ͻ�ȷ��ʧ��
//	if (ch == 'Y')
//	{
//		printf("ȷ�ϳɹ�\n");
//	}
//	else
//	{
//		printf("ȷ��ʧ��\n");
//	}
//	return 0;
//}


int main()
{
	char password[20] = { 0 };
	printf("����������:>");
	scanf("%s", password);
	while ((getchar()) != '\n')   //�����\n֮ǰ�Ļ�����
	{
		;
	}
	printf("��ȷ������Y/N��");
	int ch = getchar();    //getchar���ȡscanf�����\n �ŵ�ch��  �ͻ�ȷ��ʧ��
	if (ch == 'Y')
	{
		printf("ȷ�ϳɹ�\n");
	}
	else
	{
		printf("ȷ��ʧ��\n");
	}
	return 0;
}