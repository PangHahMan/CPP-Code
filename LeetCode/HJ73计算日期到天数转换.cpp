#include <iostream>
using namespace std;
// ������������ڣ���������һ��ĵڼ��졣
/*
 *˼·��
 * 1. ͨ��ö��ÿ���µ�1������һ��ĵڼ��죬�Ӷ������ۼ���ͼ��ɣ�����ע������Ĵ���
 */

int main()
{

    int year, month, day;
    while (cin >> year >> month >> day)
    {
        int monthDays[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
        int nday = monthDays[month - 1] + day;
        if (month > 2 &&
            ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
        {
            nday += 1;
        }
        cout << nday << endl;
    }

    return 0;
}
// https://www.nowcoder.com/practice/769d45d455fe40b385ba32f97e7bcded?tpId=37&&tqId=21296&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking