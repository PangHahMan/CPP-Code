/*
˼·��
1. ����ѭ���ķ�ʽ����һ������
2. ʹ��max��������е����ֵ������ѭ���ķ�ʽ���λ�ȡ�����е�ÿ��Ԫ�أ���max���бȽϣ����arr[i]����    max������max��ǵ����ֵ���������������max�б���ļ�Ϊ�����е����ֵ��
*/
int main()
{
	int arr[10] = { 0 };
	int i = 0;
	int max = 0;

	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	//
	max = arr[0];
	for (i = 1; i < 10; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	printf("max = %d\n", max);
	return 0;
}