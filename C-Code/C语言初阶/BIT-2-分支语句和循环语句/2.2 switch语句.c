#include<stdio.h>
//2.2.1 switch���
//����
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//		printf("����һ\n");
//		break;
//	case 2:
//		printf("���ڶ�\n");
//		break;
//	case 3:
//		printf("������\n");
//		break;
//	case 4:
//		printf("������\n");
//		break;
//	case 5:
//		printf("������\n");
//		break;
//	case 6:
//		printf("������\n");
//		break;
//	case 7:
//		printf("������\n");
//		break;
//	}
//	return 0;
//}


//��������1-5���������"weekday"   ����6-7�����"weekend"
//int main()
//{
//	int day = 0;
//	switch (day)
//	{
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("weekday\n");
//		break;
//	case 6:
//	case 7:
//		printf("weekend\n");
//		break;
//	}
//	return 0;
//}
//break����ʵ��Ч���ǰ�����б���Ϊ��ͬ�ķ�֧����
//��̺�ϰ�ߡ�
//�����һ��case���ĺ����һ��break���(�����������break)


//2.2.2 default�Ӿ�
//deafult�Ӿ�����������������û���������Ϣ�д��󣬾��棬���Է���switch�����κ�λ��
//��switch���ʽ��ֵ����ƥ������case��ǩ��ֵʱ�����default�Ӿ��������ͻ�ִ�С�
//����ÿ��switch�����ֻ�ܳ���һ��default�Ӿ䡣
//��̺�ϰ�ߡ�
//��ÿ��switch����ж���һ��default�Ӿ��Ǹ���ϰ�ߣ����������ں����ټ�һ��break


//2.2.3 ��ϰ
int main()
{
	int n = 1;    //1 2 3
	int m = 2;    //3 4 5
	switch (n)
	{
	case 1:
		m++;
	case 2:
		n++;
	case 3:
		switch (n)
		{
			//switch����Ƕ��ʹ��
		case 1:
			n++;
		case 2:
			m++;
			n++;
			break;
		}
	case 4:
		m++;
		break;
	default:
		break;
	}
	printf("m=%d,n=%d\n", m, n);
	return 0;
}