#include<stdio.h>
int main()
{
	const int num = 10;
	// num = 20;    //���ܸ��ı�const���εı���
	
	int* p = &num;
	*p = 20;      ////���Ը���const���εı���
	
	const int* p1 = &num;
	// *p1 = 20;      //err 
	
	int ret = 0;
	p1 = &ret;   //p1���Ը���

	int* const p2 = &num;
	//p2 = &ret;   //p2��const����  ���ܸ���      

	int const* const p3 = &num;   //���Ĳ���
	//*num = 10;
	//pe = &ret;
	printf("%d\n", num);   //20
	return 0;
}

//const����ָ�룬����*����ߣ���ʾ��ָ��ָ������ݲ���ͨ��ָ�����޸ģ�����ָ�����������޸�
//*p=20  err 

//const����ָ��ʱ������*���ұߣ���ʾָ������������޸ģ�����ָ��ָ������ݿ���ͨ��ָ�����޸�

