#include <stdio.h>
#include <stdlib.h>
//���п��Կ�ʼ�ˣ���Ҷ���ȡ�úóɼ�������ǰ������
//�Ӽ������� n ��ѧ���ɼ������ÿ������ǰ��ߵĳɼ���
int cmp_int(const void *e1, const void *e2)
{
	return *(int *)e1 - *(int *)e2;   //����
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int arr[n];
	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	//����
	qsort(arr, n, sizeof(int), cmp_int);

	//��ӡ
	for(i=n-1;i>=n-5;i--)
	{
		printf("%d",arr[i]);
	}
	return 0;
}