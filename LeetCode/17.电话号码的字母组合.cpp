// ����һ������������2-9���ַ����������������ܱ�ʾ����ĸ��ϡ��𰸿��԰�����˳�򷵻ء�
// 2 - abc   3 - def  4 - ghi  5 - jkl  6 - mno  7 - pqrs  8 - tuv  9 - wxyz
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
    // �����ֶ�Ӧ�ĵ绰����д��������
    string _numTostr[10] = {"", "", "abc", "def", "ghi", "jki", "mno", "pqrs", "tuv", "wxyz"};

public:
    void Combinations(const string &digits, size_t di, string combineStr, vector<string> &strV)
    {
        //��di����digits�����ַ��Ĵ�С��˵�����Ѿ��ߵ����ˣ�����β���ַ�����strv���ˣ�Ȼ�󷵻أ������ݹ�
        if (di == digits.size())
        {
            strV.push_back(combineStr);
            return;
        }
        // ���ȣ���ȡ���֣����ִ����digits�У���di-'0'��ȡ�ַ���digits��������ַ�
        int num = digits[di] - '0';
        // ȡ��ǰ���str��,num�Ǽ�����ȡ_numTostr��Ӧ�±�Ĵ�
        string str = _numTostr[num];
        //��ʼѭ���ݹ鴮����һ���м����ַ�����ѭ������
        for (auto ch : str)
        {
            Combinations(digits, di + 1, combineStr + ch, strV);
        }
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string> strV;
        if (digits == "")
        {
            return strV;
        }
        Combinations(digits, 0, "", strV);
        return strV;
    }
};

// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/submissions/