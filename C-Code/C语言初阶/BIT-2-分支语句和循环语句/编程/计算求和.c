#include<stdio.h>
//��Sn = a + aa + aaa + aaaa + aaaaa��ǰn��֮�ͣ�����a��һ�����֣�
int main()
{
	int a = 0;
	int n = 0;
	int i = 0;
	int sum = 0;
	int ret = 0;
	scanf_s("%d %d", &a, &n);
	for (i = 0; i < n; i++)
	{
		if (i == 0)
		{
			ret = a;
		}
		else
		{
			ret = ret * 10 + a;
		}
		sum += ret;
	}
	printf("%d", sum);
	return 0;
}