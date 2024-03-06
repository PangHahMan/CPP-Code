#include<stdio.h>
/*
����һ���������飬��ɶ�����Ĳ���
ʵ�ֺ���init() ��ʼ������Ϊȫ0
ʵ��print()  ��ӡ�����ÿ��Ԫ��
ʵ��reverse()  �����������Ԫ�ص����á�*/
void init(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = 0;
	}
}

void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void reverse(int arr[], int sz) // 1 2 3 4 5 6 7 8 9 10
{
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}

}

int main()
{
	int arr[10];
	int sz = sizeof(arr) / sizeof(arr[0]);
	init(arr,sz);
	int i = 0;
	
	for (i = 0; i < sz; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("����ǰ\n");
	print(arr, sz); 
	
	
	reverse(arr, sz);
	printf("���ú�\n");
    print(arr, sz);

	return 0;
}