#include<stdio.h>
int main()
{
	int n = 0;
	printf("������n\n");
	scanf("%d", &n);
	int i = 0;
	int ret = 1;
	for (i = 1; i <= n; i++)
	{
		ret *= i;
	}
	printf("%d", ret);
	return 0;
}