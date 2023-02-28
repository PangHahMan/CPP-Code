#pragma once
#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;

//namespace phw
//{
//	class string
//	{
//	public:
//		//�޲ι��캯��
//		string()
//			:_str(nullptr),
//			_size(0),
//			_capacity(0)
//		{}
//
//		//���ι��캯��
//		string(const char* str)
//			:_str(str)
//			, _size(strlen(str))
//			, _capacity(strlen(str))
//		{}
//
//		//��ȡ�ַ���
//		const char* c_str()
//		{
//			return _str;
//		}
//
//		char& operator[](size_t pos)
//		{
//			return _str[pos];
//		}
//
//		size_t size()
//		{
//			return _size;
//		}
//	private:
//		const char* _str;
//		size_t _size;
//		size_t _capacity;
//	};
//
//	void test_string1()
//	{
//		string s1;
//		string s2("Hello World\n");
//		cout << s1.c_str() << endl;  //s1Ϊ��ָ�룬cout�Կ�ָ������ã�����
//		cout << s2.c_str() << endl;
//	}
//}

//2
//namespace phw
//{
//	class string
//	{
//	public:
//		//�޲ι��캯��
//		string()
//			:_str(new char[1]),  //newһ��char
//			_size(0),
//			_capacity(0)
//		{
//			_str[0] = '\0';
//		}
//
//		//���ι��캯��
//		string(const char* str)
//			:_size(strlen(str))
//		{
//			_capacity = _size;
//			_str = new char[_capacity + 1];   //new _capacity+1  capacity���ַ�����������ŵ���Ч�ַ���С�����ǿռ䣬�ռ仹��һ��|0
//			strcpy(_str, str);
//		}
//
//		//��ȡ�ַ���
//		const char* c_str()
//		{
//			return _str;
//		}
//
//		char& operator[](size_t pos)
//		{
//			return _str[pos];
//		}
//
//		size_t size()
//		{
//			return _size;
//		}
//
//		~string()
//		{
//			delete[] _str;
//			_size = 0;
//			_capacity = 0;
//		}
//
//		void test_string1()
//		{
//			string s1;
//			string s2("Hello World\n");
//			cout << s1.c_str() << endl;
//			cout << s2.c_str() << endl;  // Hello World
//
//			s2[0]++;
//			cout << s2.c_str() << endl;   //Iello World
//		}
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity;
//	};
//}


//3   2���Ż�
namespace phw
{
	class string
	{
	public:
		friend ostream& operator<<(ostream& out, const phw::string& s);
		friend istream& operator>>(istream& in, phw::string& s);
		//���ι��캯��
		//string(const char* str = nullptr)  //������ ����ָ�룬strlen�ᱨ��
		//string(const char* str = '\0')  //\0 charת����ָ�룬Ҳ�ǿ�ָ��
		//string(const char* str = "\0")   //����,�������ַ�����strlen���ᱨ��
		string(const char* str = "")    //���ַ���Ĭ����\0
			:_size(strlen(str))
		{
			_capacity = _size == 0 ? 3 : _size;  //���ٸ�3���ֽڿռ�
			_str = new char[_capacity + 1];   //new _capacity+1  capacity���ַ�����������ŵ���Ч�ַ���С�����ǿռ䣬�ռ仹��һ��|0
			strcpy(_str, str);
		}
		//�������� 
		string(const string& s)
			:_size(s._size)
			, _capacity(s._capacity)
		{
			//_str�Լ����ռ�
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
		}
		//��ֵ�Ƕ��Ѿ�����Ķ�����и�ֵ
		//��һ������ǣ�ԭ����Ŀռ�Զ����Ҫ��ֵ�Ķ�����ô�ͻ���ֿռ��˷�
		//��������Ӧ��delete��ԭ�ռ���ڴ棬�ڽ��и�ֵ
		string& operator =(const string& s)
		{
			if (this != &s)
			{
				//delete[]_str;  //��ֵ��ǰ�Ѿɿռ��ͷţ���ֹ�˷ѿռ�
				//_str = new char[s._capacity + 1];
				//strcpy(_str, s._str);
				//_size = s._size;
				//_capacity = s._capacity;
				char* tmp = new char[s._capacity + 1];
				strcpy(tmp, s._str);
				delete[] _str;
				_str = tmp;
				_size = s._size;
				_capacity = s._capacity;
			}

			return *this;
		}

		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin()
		{
			return _str;
		}

		const_iterator begin() const
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		//��ȡ�ַ���
		const char* c_str()
		{
			return _str;
		}
		//[]ͨ���±��������ַ�
		char& operator[](size_t pos)
		{
			return _str[pos];
		}
		//����const���͵�����
		const char& operator[](size_t pos) const
		{
			return _str[pos];
		}

		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		~string()
		{
			delete[] _str;
			_size = 0;
			_capacity = 0;
		}

		void Print(const string& s)
		{
			for (size_t i = 0; i < s.size(); i++)
			{
				cout << s._str[i] << " ";
			}
			cout << endl;
			//���ﲻ֧�ַ�Χfor�ˣ�Ϊʲô��  ��Ϊ����s��const����ֻ�ܵ���const������
			string::const_iterator it = s.begin();
			while (it != s.end())
			{
				//(*it)++;  //err. const������ָ������ݲ����޸�
				it++;
			}
			//����û�ж���const���������ͻᱨ����Χfor�ĵײ���ǵ�����
			for (auto ch : s)
			{
				cout << ch << " ";
			}
			cout << endl;
		}
		// ���޸ĳ�Ա�������ݵĺ�������ü���const
		bool operator>(const string& s) const
		{
			return strcmp(_str, s._str) > 0;
		}

		bool operator==(const string& s) const
		{
			return strcmp(_str, s._str) == 0;
		}

		bool operator>=(const string& s) const
		{
			return *this > s || *this == s;
		}

		bool operator<(const string& s) const
		{
			return !(*this >= s);
		}

		bool operator <= (const string& s) const
		{
			return !(*this > s);
		}

		//���ݵ�ʱ�򣬲��ҳ�ʼ�� 
		void resize(size_t n, char ch = '\0')
		{
			//��nС��_size��ʱ�򣬲���Ҫ���ݣ�Ҳ����Ҫ����
			//n����_size��ʱ�򣬲��ҵ�n>capacit��ʱ����Ҫ���ݣ���ֱ�ӵ���reserve
			if (n < _size)
			{
				//����ǰn��
				_size = n;
				_str[_size] = '\0';
			}
			else
			{
				if (n > _capacity)
				{
					reserve(n);
				}
				//��_size��ʼ ����Ҫ����n��ʼ����ʼ��\0
				size_t i = _size;
				while (i < n)
				{
					_str[i] = ch;
					++i;
				}
				_size = n;
				_str[_size] = '\0';
			}
		}

		//����n
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size + 1 >= _capacity)
			{
				reserve(_capacity * 2);
			}
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
		}

		//β���ַ���
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);  //��_str+_size��ʼ����
			//strcat(_str, str);     //strcat����\0��Ч�ʵ���
			_size += len;
			_str[_size] = '\0';
		}

		string& operator +=(const char* str)
		{
			append(str);
			return *this;
		}

		string& operator +=(const char ch)
		{
			push_back(ch);
			return *this;
		}

		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size + 1 > _capacity)
			{
				reserve(2 * _capacity);
			}
			int end = _size;
			//�����pos��Ҫ�ĳ�int pos���޷������ͣ���end�Աȣ�end��ת�����޷�������
			//��pos��λ����0ʱ��endΪ�޷������ͽ���Զ����С��0����������ѭ����
			//��Ҫ��posת����int����ôend��Ϊint����
			while (end >= (int)pos)
			{
				_str[end + 1] = _str[end];
				end--;
			}
			_str[pos] = ch;
			_size++;

			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			int len = strlen(str);
			int end = _size + len;
			if (_size + len > _capacity)
			{
				reserve(2 * _capacity);
			}

			while (end > pos + len - 1)
			{
				_str[end] = _str[end - len];
				end--;
			}
			strncpy(_str + pos, str, len);
			_size += len;
			return *this;
		}

		string& erase(size_t pos, size_t len = npos)
		{
			//���Ҫɾ�ĸ���Զ����ʣ��ĸ���������posλ�ú���ȫ��ɾ����ֱ����posλ�ú�����\0����
			// len == npos������ϣ�npos�����ֵ
			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
			return *this;
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);

		}

		size_t find(char ch, size_t pos = 0)
		{
			assert(pos < _size);
			for (size_t i = 0; i < _size; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
		}


		size_t find(const char* str, size_t pos = 0)
		{
			assert(pos < _size);

			char* p = strstr(_str + pos, str);
			if (p == nullptr)
			{
				return npos;
			}
			else
			{
				return p - str;
			}
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		static const size_t npos;  //��̬��Ա�������ܸ�ȱʡֵ��
		//static const size_t npos = -1;  //����const���ԣ�ֻ�������

		//static const size_t N = 10;
		//int _a[N];
	};
}

const size_t phw::string::npos = -1;

ostream& phw::operator<<(ostream& out, const phw::string& s)
{
	for (size_t i = 0; i < s.size(); i++)
	{
		out << s[i];
	}
	return out;
}

istream& phw::operator>>(istream& in, phw::string& s)
{
	s.clear();  //һ��ʼ����������
	char ch = in.get();
	char buff[128];
	size_t i = 0;
	while (ch != ' ' && ch != '\n')
	{
		//s += ch;  //�ַ���̫�����ܻ���������,��reserve��ο������ݣ� ���ݻ�Ƶ������
		buff[i++] = ch;
		if (i == 127)
		{
			buff[127] = '\0';
			s += buff;
			i = 0;
		}
		ch = in.get();
	}

	if (i != 0)
	{
		buff[i] = '\0';
		s += buff;
	}
	//getlineʵ��
	/*while (ch != '\n')
	{
		s += ch;
		ch = in.get();
	}*/

	return in;
}

void test_string1()
{
	phw::string s1;
	phw::string s2("Hello World\n");
	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;  // Hello World
}

void test_string2()
{
	phw::string s1;
	phw::string s2("hello world");
	phw::string s3(s2);   //������Ĭ�ϵĹ��캯����ǳ����,s2��s3��strָ����ͬһ���ռ䣬�����������
	cout << s2.c_str() << endl;   //hello world
	cout << s3.c_str() << endl;   //hello world

	//���Լ�д������������s2�䣬s3���ű䣬��Ϊs2��s3ָ��ͬһ���ռ�
	//s2[0]++;
	//cout << s2.c_str() << endl;   //iello world
	//cout << s3.c_str() << endl;   //iello world

	s2[0]++;
	cout << s2.c_str() << endl;   //iello world
	cout << s3.c_str() << endl;   //hello world

	s1 = s3;  //�Լ���д���ǻᱨ����Ϊ����ǳ����
	cout << s1.c_str() << endl;   //hello world
	cout << s3.c_str() << endl;   //hello world
	s1 = s1;
}

//�����ַ���
void test_string3()
{
	phw::string s1("Hello World");
	for (size_t i = 0; i < s1.size(); i++)
	{
		s1[i]++;
	}

	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	s1.Print(s1);

	phw::string::iterator it = s1.begin();
	while (it != s1.end())
	{
		(*it)--;
		it++;
	}

	it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (auto ch : s1)  //�ײ���ǽ�*it�滻��ch
	{
		cout << ch << " ";
	}
	cout << endl;
}

//string�Ƚϴ�С
void test_string4()
{
	phw::string s1("hello world");
	phw::string s2("hello world");
	phw::string s3("xx");

	cout << (s1 < s2) << endl;
	cout << (s1 == s2) << endl;
	cout << (s1 > s2) << endl;
}

void test_string5()
{
	phw::string s1("Hello World");
	s1.push_back('a');
	s1.append("xxxxxxxxxx");
	s1 += 'W';
	s1 += "!!!!!!!!!!!!";
	cout << s1.c_str() << endl;

	phw::string s2 = "Hello World";
	s2.insert(5,'X');
	cout << s2.c_str() << endl;
	s2.insert(0,'A');
	cout << s2.c_str() << endl;
	s2.insert(0, "PHW");
	cout << s2.c_str() << endl;
	s2.erase(0, 3);
	cout << s2.c_str() << endl;
	s2.erase(5, 10);
	cout << s2.c_str() << endl;
}

//���������ر���ʵ�ֳ���Ԫ������  ����
void test_string6()
{
	std::string s1("0123456789");
	phw::string s2("0123456789");
	s1 += '\0';
	s2 += '\0';
	s1 += "xxxx";
	s2 += "xxxx";
	cout << s1 << endl;   //0123456789xxxx
	cout << s2.c_str() << endl;  //0123456789  ����\0��ֹ
	cout << s2 << endl;   //0123456789xxxxs
	
	phw::string s3;
	cin >> s3;
	cout << s3 << endl;
	
}

void test_string7()
{
	phw::string s1;
	std::string s2;
	cout << sizeof(s1) << endl;  //12
	cout << sizeof(s2) << endl;  //28

	s1 = "hello";
	s2 = "hello";
	cout << sizeof(s1) << endl;  //12
	cout << sizeof(s2) << endl;  //28

	//g++ ��x86  4�ֽ�   x64  8�ֽ�
	//g++�д����ָ��
}