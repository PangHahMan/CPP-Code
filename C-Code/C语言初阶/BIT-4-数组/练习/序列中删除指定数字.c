#include<stdio.h>
//��һ���������У��������ظ�������������ɾ��ָ����ĳһ��������
//���ɾ��ָ������֮������У�������δ��ɾ�����ֵ�ǰ��λ��û�з����ı䡣
int main()
{
	int n = 0;
	scanf_s("%d", &n);
	int i = 0;
	int arr[50] = { 0 };
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	//����ɾ��������
	int del = 0;
	scanf_s("%d", &del);

	//ɾ�������е�del����
	//1 2 3 4 5 9   ɾ��4   ���1 2 3 5 9
	int j = 0;
	for (i = 0; i < n; i++)
	{
		if (arr[i] != del)
		{
			arr[j++] = arr[i];
		}
	}

	for (i = 0; i < n - 1; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}