#include<stdio.h>
#define N 3
//KiKi��֪��һ��n�׷����Ƿ�Ϊ�����Ǿ������������ж���
//�����Ǿ������Խ������µ�Ԫ�ض�Ϊ0�ľ������Խ���Ϊ�Ӿ�������Ͻ������½ǵ����ߡ�
int main()
{
	int arr[N][N];
	int i = 0;
	int j = 0;
	//����
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf_s("%d", &arr[i][j]);
		}
	}
	//�ж�
	int flag = 1;  //�����������Ǿ���
	for (i = 0; i < N; i++)
	{
		for (j = 0; j<i; j++)   //�����ǵ��ж���j<i��
		{
			if (arr[i][j] != 0)
			{
				flag = 0;
				// break;   //break�޷���ȫ�������ѭ��
				goto end;
			}
		}
	}
end:
	if (flag == 0)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}