#include<stdio.h>
#include<stdlib.h>
/*
�ص���������һ��ͨ������ָ����õĺ����������Ѻ�����ָ�루��ַ����Ϊ�������ݸ���һ��
�����������ָ�뱻������������ָ��ĺ���ʱ�����Ǿ�˵���ǻص��������ص����������ɸú���
��ʵ�ַ�ֱ�ӵ��ã��������ض����¼�����������ʱ�������һ�����õģ����ڶԸ��¼���������
����Ӧ��
*/


/*
int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

void menu()
{
	printf("                          \n");
	printf("       1.add  2.sub       \n");
	printf("       3.mul  4.div       \n");
	printf("       0.exit             \n");
	printf("                          \n");
}

//��ź�����ַ�ĺ���
void calc(int (*p)(int, int))
{
	int x = 0;
	int y = 0;
	int ret = 0;
	printf("����������������;>");
	scanf_s("%d %d", &x, &y);
	ret = p(x, y);   //pΪ����ָ��
	printf("%d\n", ret);
}

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			calc(Add);   //��Add������ĺ�����Ϊ����������AddΪ�ص�����
			break;
		case 2:
			calc(Sub);
			break;
		case 3:
			calc(Mul);
			break;
		case 4:
			calc(Div);
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}

	} while (input);
	return 0;
}
*/


//1.��ʾһ��qsort������ʹ�ã�
//qsort - c���Ա�׼���ṩ��������~    ���������˼��
//bubble_sort ֻ���������͵�����
//qsort���������������͵�����
/*
int cmp_int(const void* e1, const void* e2)
{
	return (*(int*)e1 - *(int*)e2);  //����
	//return (*(int*)e2 - *(int*)e1);  //����
}

void print(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

//����qsort����������������
void test()
{
	int arr[] = { 2,1,3,7,5,9,6,8,0,4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	print(arr, sz);
}

struct Stu
{
	char name[20];
	int age;
};

int cmp_stu_by_name(const void* e1,const void* e2)   //�ṹ��
{
	//��������������
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name); //strcmp����ֵΪ>0 ==0  <0
}

int cmp_stu_by_age(const void* e1, const void* e2)
{
	//������������
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

//����qsort����ṹ������
void test1()
{
	struct Stu s[] = { {"zhangsan",20},{"lisi",55},{"wangwu",40} };
	//���谴�����ֱȽ�
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
	//������������
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
}
//void qsort(void* base, size_t num, size_t size, int (*cmp)(const void*, const void*));

//base�Ǵ��������ݵ���ʼ��ַ
//num���������ݵ�Ԫ�ظ���
//size�Ǵ���������Ԫ�صĴ�С(�ֽ�)
//int (*cmp)(const void*, const void*) �Ƚ�2��Ԫ�ش�С�ĺ���ָ��
//2������ʹ�ù�ϵ������Ƚϴ�С
//2���ַ�����ʹ��strcmp�Ƚϴ�С
//2���ṹ�壬Ҳ���ƶ��ȽϷ�ʽ


int main()
{
	test();
	test1();
	char ch = 'w';
	int i = 20;
	float* pf = &i;   //���Ͳ�����
	void* p = &ch;    //û������ - ����void* ��ָ��û��������  ����ǿ������ת��������ָ�� *(int *)p
	p = &i;           //void* ָ��Ҳ����++ --
	//void* ���Խ����κ����͵ĵ�ַ  ��Ҳ������Ψһ�ŵ�
	return 0;
}
*/


//2.��дð������ʹ��ð����������������κ����ͱ���
/*
void Swap(char* buf1, char* buf2, int width)   //�����ĵ�ַ�е�����
{
	int i = 0;
	for (i = 0; i < width; i++)   //width�����ֽ���  ÿѭ��һ�� ����һ���ֽ��� ������ͬ���Ͷ��ܽ���
	{
		//����һ���ֽڵ�ֵ
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

void bubble_sort(void* base, int sz, int width, int (*cmp)(const void* e1, const void* e2))
{
	int i = 0;
	//����
	for (i = 0; i < sz - 1; i++)
	{
		//һ��ð������Ĺ���
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				//����
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}
*/
