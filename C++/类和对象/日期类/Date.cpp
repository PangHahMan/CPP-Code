#include"Date.h"
int Date::GetMonthDay(int year, int month)
{
	assert(month > 0 && month < 13);

	int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0))
	{
		return 29;
	}
	else
	{
		return monthArray[month];
	}
}

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

void Date::Print()
{
	if (_month > 0 && _month < 13
		&& (_day > 0 && _day <= GetMonthDay(_year, _month)))
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
	else
	{
		cout << "���ڷǷ�" << endl;
	}
}

bool Date::operator ==(const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator !=(const Date& d)
{
	return !(*this == d);
}

bool Date::operator <(const Date& d)
{
	return _year < d._year
		|| (_year == d._year && _month < d._month)
		|| (_year == d._year && _month == d._month && _day < d._day);
}

bool Date::operator <=(const Date& d)
{
	return *this < d || *this == d;
}

bool Date::operator >(const Date& d)
{
	return !(*this <= d);
}

bool Date::operator >=(const Date& d)
{
	return !(*this < d);
}

//d1 = d2+=100
Date& Date::operator+=(int day)
{
	//���dayΪ�����أ��Ǿ���-=day���߼���
	if (day < 0)
	{
		*this -= -day;   //dayΪ������-=day  Ҫ��dayת����-day
		return *this;
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}
	return *this;  //�����������ڿ���ʹ�����÷���
}

//Date Date::operator+(int day)
//{
//	Date tmp(*this);
//	tmp._day += day;
//	//������while��Ϊ���ܳ��ֱ��·ݴ�ü�����Ҫ���кü��ν�λ
//	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
//	{
//		tmp._day -= GetMonthDay(tmp._year, tmp._month);
//		tmp._month++;
//		if (tmp._month == 13)
//		{
//			tmp._year++;
//			tmp._month = 1;
//		}
//	}
//	return tmp; //�����������������,���������÷���
//}

//���Լ򻯣����Ե���+��������ʵ��+=
Date Date::operator+(int day)
{
	Date tmp = *this;
	tmp += day;

	return tmp;
} 
//-=  ��Ҫ��λ
Date& Date::operator-=(int day)
{
	//-=���day����Ǹ������Ǿͱ���+=
	if (day < 0)
	{
		*this += -day;  //day�Ǹ�����-day�ͱ��������
		return *this;
	}
	_day -= day;
	while (_day <= 0)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		//dayΪ���ģ��ӵ�����Ϊֹ����λ�ͽ�����
		_day += GetMonthDay(_year, _month);
	}
	return *this;
} 

Date Date::operator-(int day)
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}

//d1-d2
int Date::operator-(const Date& d)
{
	Date max = *this;
	Date min = d;
	int flag = 1;

	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}
	return n * flag;
}

//ǰ��++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

//����++
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;  //�����Ѿ�����1
	return tmp;  //���ص���tmp
}
//ǰ��--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
//����--
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "/" << d._month << "/" << d._day << endl;
	return out;
}

istream& operator>>(istream& in, Date& d)  //����ȡ
{
	in >> d._year >> d._month >> d._day;
	return in;
}