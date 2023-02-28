#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
// �������С�������ʺ��������ĺ�����ֱ���������涨�塣
class Date
{
public:
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
	Date(int year = 1900, int month = 1, int day = 1);
	void Print();
	int GetMonthDay(int year, int month);
	bool operator ==(const Date& d);
	bool operator !=(const Date& d);
	bool operator <(const Date& d);
	bool operator <=(const Date& d);
	bool operator >(const Date& d);
	bool operator >=(const Date& d);
	Date& operator+=(int day);
	Date operator+(int day);
	Date& operator-=(int day);
	//d1-100
	Date operator-(int day);
	//d1-d2
	int operator-(const Date& d);
	//ǰ��++
	Date& operator++();
	//����++
	Date operator++(int);
	//ǰ��--    --d -> d.operator--()
	Date& operator--();
	//����--    d--  -> d.operator--(int)
	Date operator--(int);
	
private:
	int _year = 1900;
	int _month = 1;
	int _day = 1;
};

ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in, Date& d);