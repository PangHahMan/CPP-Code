#include<stdio.h>
//������������Ҫ��ѡ�糤����������ѡ�˷ֱ���A��B������ÿ��ͬѧ���벢��ֻ��ͶһƱ�����յ�Ʊ�����Ϊ�糤.
int main()
{
	int s = 0;
	int countA = 0;
	int countB = 0;
	while ((s = getchar()) != '0')
	{
		if (s == 'A')
			countA++;
		if (s == 'B')
			countB++;
	}
	if (countA > countB)
		printf("A");
	else if (countB > countA)
		printf("B");
	else
		printf("E");
	return 0;
}