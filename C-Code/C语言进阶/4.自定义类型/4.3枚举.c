#include<stdio.h>
/*
enum Day
{
	//ö�ٵĿ���ȡֵ
	Mon,
	Tues,
	Wed,
	Thur,
	Fri,
	Sat,
	Sun
};

struct Stu
{
	char name[20];  //��Ա����
	int age;
};
*/


//1.ö�ٵĶ����ʹ��
/*
enum Color
{
	//ö�ٵĿ���ȡֵ
	//ÿһ�����ܵ�ȡֵ�ǳ���
	Red,  //Red = 5 Red���ܸã����ǿ��Ը�ֵ  �����ֵ�ͱ���� 6  7
	Green,
	Blue
	//Red = 5
	//Red = 9
	//Red = 10
};

int main()
{
	enum Color color = Blue;
	//enum Color color = 5;   //C����֧�֣� C++���о���
	//Red = 2;   //���������޸�
	int num = Red;
	printf("%d\n", num);    //0
	printf("%d\n", Red);    //0
	printf("%d\n", Green);  //1
	printf("%d\n", Blue);   //2
	int sum = Red + Blue;   //������ӣ�������Щ��������֧��
	printf("%d\n", sum);      //2
	printf("%d\n", sizeof(enum Color));  //VS��Ϊ4
	return 0;
}
*/


//2.ö�ٵ��ŵ�
/*
#define Red 5
#define Green 7
#define Blue 10
//defineԤ�����define�������ʧ�� �滻�������� �����������
int main()
{
	int num = Red;
	return 0;
}
*/

//1.���Ӵ���Ŀɶ��ԺͿ�ά����
//2.��#define����ı�ʶ���Ƚ�ö�������ͼ�飬�����Ͻ�
//3.���ڵ���
//4.ʹ�÷��㣬һ�ο��Զ���������
//5.��ֹ������Ⱦ(��װ)

