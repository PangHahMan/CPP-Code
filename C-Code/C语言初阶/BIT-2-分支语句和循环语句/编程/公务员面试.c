#include<stdio.h>
//����Ա�����ֳ���֡���7λ���٣��Ӽ�������������ɼ���ÿ��7���������ٷ��ƣ���
//ȥ��һ����߷ֺ�һ����ͷ֣����ÿ���ƽ���ɼ���
int main() {
    int score = 0;
    int sum = 0.0;
    int min = 100;
    int max = 0;
    int count = 0;
    while (scanf_s("%d", &score) != EOF) {
        if (score < min)
            min = score;
        if (score > max)
            max = score;
        sum += score;
        count++;
        if (count == 7) {
            printf("%.2f\n", (sum - min - max) / 5.0);
            count = 0;
            min = 100;
            max = 0;
            sum = 0;
        }

    }

    return 0;
}