// ���������ڣ�����������֮�������������������������������ǹ涨����֮�������Ϊ����
#include <iostream>
using namespace std;
/*
*˼·��
* 1. �ֱ����ÿһ��������0000��0��1�վ��������
* 2. ������������������ɵõ�����������������
*/

// ƽ���1�µ�n�µ�����
int mon[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

// ���������գ��������0000��0��1�յ�������
int CountDay(int y, int m, int d)
{
    // ����0-y�������
    int yearDay = y * 365 + y / 4 - y / 100 + y / 400;
    // ���㵽0-m�µ�����
    int monthDay = mon[m - 1];
    if (m > 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
        monthDay += 1;

    return yearDay + monthDay + d;
}

int main()
{
    int year1, month1, day1;
    scanf("%4d%2d%2d", &year1, &month1, &day1);
    int n1 = CountDay(year1, month1, day1);
    int year2, month2, day2;
    scanf("%4d%2d%2d", &year2, &month2, &day2);
    int n2 = CountDay(year2, month2, day2);
    cout << abs(n1 - n2) + 1 << endl;
}