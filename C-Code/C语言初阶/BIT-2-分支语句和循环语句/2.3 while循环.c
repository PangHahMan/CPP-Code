#include<stdio.h>
//2.3.1 whileѭ��

//����Ļ�ϴ�ӡ1-10������
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		printf("%d ", i);
//		i++;
//	}
//	return 0;
//}


//whileѭ���е�break
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//			break;     //i����5��ʱ��ֱ������ѭ��
//		printf("%d ", i);    //1 2 3 4
//		i++;
//	}
//	return 0;
//}
//�ܽ��
//while�е�break������������ֹѭ���ġ�


//whileѭ���е�continue����
//continue ����ʵ��1
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)     //��i����5ʱ��continueֱ�������������䣬i��Զ����5������ѭ��
//			continue;
//		printf("%d ", i);     //1 2 3 4 + ��ѭ������ӡ
//		i++;
//	}
//	return 0;
//}

//continue ����ʵ��2
//int main()
//{
//    int i = 1;
//    while (i <= 10)
//    {
//        i++;
//        if (i == 5)
//            continue;
//        printf("%d ", i);  //2 3 4 6 7 8 9 10
//    }
//    return 0;
//}
//���ۡ� 
//continue��������ֹ����ѭ���ģ�Ҳ���Ǳ���ѭ����continue��ߵĴ��벻����ִ��
//����ֱ����ת��while�����жϲ��֡�������һ��ѭ��������жϡ�