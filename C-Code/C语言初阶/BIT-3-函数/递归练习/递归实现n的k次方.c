#include<stdio.h>
int Pow(int n, int k)
{
	if (k == 0)
	{
		return 1;
	}
	else if (k == 1)
	{
		return n;
	}
	else
	{
		return n * Pow(n, k - 1);
	}
	//2��2�η�  n*n    Pow(n,?)=n    k==1��ʱ�� ����n      ��K==2   k-1==1 ==n
}


int main()
{
	int n = 0;
	int k = 0;
	scanf("%d %d", &n, &k);
	int ret = Pow(n, k);
	return 0;
}