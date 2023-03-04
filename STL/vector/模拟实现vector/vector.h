#pragma once
#include<string.h>
#include<iostream>
#include<assert.h>
using namespace std;
template<class T>
class vector
{
public:
	typedef	T* iterator;   //iteratorΪT���͵�ָ��
	typedef	const T* const_iterator;   //iteratorΪT���͵�ָ��
	vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _end_of_storage(nullptr)
	{}


	iterator begin()
	{
		return _start;
	}

	iterator end()
	{
		return _finish;
	}

	//����������const������begin������ֻ�ǲ����������Ͳ�ͬ
	//�������޷����ݺ����������������ֺ�����
	//��Ϊ�������ز����������Ϊ�������Ͳ�ͬ���������֡��⽫���±������
	//����const���η����Ա������������ȷ����������������
	const_iterator begin() const
	{
		return _start;
	}

	const_iterator end() const
	{
		return _finish;
	}

	void reserve(size_t n)
	{
		//n>capacity����Ҫ����,����n<capacity���ܻ�����
		if (n > capacity())
		{
			size_t sz = size();  //��ǰ��¼sz��С
			T* tmp = new T[n];

			if (_start)
			{
				//��_start���ڴ棬���Ƶ�tmp��
				memcpy(tmp, _start, sizeof(T) * size());
				delete[] _start;
			}
			_start = tmp;
			_finish = _start + sz;   //size() _finish - _start  
			//����start�����ˣ���finishû�и��� start����tmp   _start + _finish - _start  ����ԭ����_finish��finishΪ0���ͻ���ɿ�ָ�������
			//������Ҫ��ǰ��¼sz�Ĵ�С,��������Ҳ������_finishһ��ʼ���ڿյ����
			_end_of_storage = _start + n;   //���ﲻ�ܹ�дn  _end_of_storage��ָ��
		}

	}

	void resize(size_t n,T val = T())  //T()Ĭ�Ϲ��죬�������󣬶����Զ������ͣ����������ͱ���int�����ʼ��
	{
		if (n < size())
		{
			_finish = _start + n;
		}
		else
		{
			if (n > capacity())
			{
				reserve(n);
			}
			while (_finish != _start + n)
			{
				*_finish = val;
				_finish++;
			}
		}
	}

	void push_back(const T& x)
	{

		if (_finish == _end_of_storage)
		{
			//����  һ����һ��ʼ��ΪNULL����һ������Ҫ����
			reserve(capacity() == 0 ? 4 : capacity() * 2);
		}

		*_finish = x; //���ܷ�����ָ�������
		_finish++;

	}

	void pop_back()
	{
		//����Ϊ�ղ�-- _finish
		if (!empty())
			_finish--;
	}

	void insert(iterator pos, const T& val)
	{
		assert(pos >= _start);
		assert(pos <= _finish);
		
		if (_finish == _end_of_storage)
		{
			//������ʧЧ���⣡
			//reserve���ݣ����ͷŵ��ɿռ䣬��ôposλ��Ҳ�ᱻ�ͷţ���Ҫ����pos�����posʧЧ������
			//��ôpos��λ����ô���أ����λ�ã� ���pos֮ǰ�����_start�����λ��
			size_t len = pos - _start;
			reserve(capacity() == 0 ? 4 : capacity() * 2);
			//����pos,_start + len( û���ͷ�ǰ�����λ��)
			pos = _start + len;
		}

		iterator end = _finish - 1;
		while (end >= pos)
		{
			*(end+1) = *end;
			end--;
		}
		*pos = val;
		_finish++;
	}

	void erase(iterator pos)
	{
		assert(pos >= _start);
		assert(pos < _finish);
		iterator start = pos + 1;
		while (start != _finish)
		{
			*(start - 1) = *(start);
			++start;
		}
		_finish--;
	}
	

	bool empty()
	{
		return _start == _finish;
	}

	size_t capacity()  const
	{
		return _end_of_storage - _start;
	}

	size_t size() const
	{
		return _finish - _start;
	}

	T& operator[](size_t pos) const
	{
		return _start[pos];
	}

	const T& operator[](size_t pos)
	{
		return _start[pos];
	}

private:
	iterator _start;
	iterator _finish;
	iterator _end_of_storage;

};