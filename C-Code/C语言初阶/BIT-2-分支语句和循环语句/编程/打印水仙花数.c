#include<stdio.h>
#include<math.h>
int main()
{
	int i = 0;
	for (i = 0; i <= 100000; i++)
	{
		//�ж�һ������λ��
		int count = 0;
		int tmp = i;
		int sum = 0;
		while (tmp)
		{
			tmp /= 10;
			count++;
		}
		//����ÿһλ��������
		tmp = i;
		while (tmp)
		{
			sum += pow(tmp % 10, count);
			tmp /= 10;
		}
		//�ж�
		if (sum == i && count >= 3)
		{
			printf("%d ",i);
		}
	}
	return 0;
}