#include<stdio.h>
//��д����ʵ�֣�ģ���û���¼�龰������ֻ�ܵ�¼���Ρ���ֻ���������������룬���������ȷ��
//��ʾ��¼�ɣ�������ξ�����������˳�����
int main()
{
	char arr[10] = " ";
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("����������\n");
		scanf("%s", arr);
		if (strcmp(arr, "bit") == 0)
		{
			printf("������ȷ\n");
		}
		else
		{
			if (i == 2)
			{
				printf("��������˳�\n");
				break;
			}
		}
	}
	return 0;
}