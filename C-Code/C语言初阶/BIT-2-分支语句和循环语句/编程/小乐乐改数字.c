#include<stdio.h>
#include<math.h>
//С����ϲ�����֣�����ϲ��0��1�������ڵõ���һ���������ÿλ�������0��1��
//���ĳһλ���������Ͱ������1�������ż������ô�Ͱ������0��
//����ش������õ������Ƕ��١�
int main() {
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	int sum = 0;
	while (n) {
		int bit = n % 10;
		if (bit % 2 == 1) {
			sum += 1 * pow(10, i);
		}
		i++;
		n /= 10;
	}
	printf("%d\n", sum);
	return 0;
}