#include<stdio.h>
/*
���ʵ�֣�����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
��������:
1999 2299
�������:7
*/


/*����1  Ч�ʵ�
int main()
{
	int m = 0;
	int n = 0;
	int count = 0;
	scanf_s("%d %d", &m, &n);
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if(((m>>i)&1)!=((n>>i)&1))
			count++;
	}
	printf("%d", count);
	return 0;
}
*/


//���  ��ͬΪ1
/*
int count_diff_bit(int m, int n)
{
	int ret = m ^ n;  //��� �ж���1�����ж��ٲ�ͬ��λ  ���������1�ĸ���
	int count = 0;
	while (ret)
	{
		ret = ret & (ret - 1);
		count++;
	}
	return count;
}

int main()
{
	int m = 0;
	int n = 0;
	int count = 0;
	scanf_s("%d %d", &m, &n);
	count = count_diff_bit(m, n);
	printf("%d", count);
	return 0;
}
*/
