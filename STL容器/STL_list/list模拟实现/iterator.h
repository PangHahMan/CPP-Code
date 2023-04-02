#pragma once
template <class T>
struct list_node;   //�����ⲿ�࣬
// list������
template <class T, class Ref, class Ptr>
struct list_iterator
{
	typedef list_node<T> node;					 // ����
	typedef list_iterator<T, Ref, Ptr> iterator; // ������
	node* _node;								 // ��������Ψһ�ĳ�Ա����:����ָ��
	// ������Ĭ�Ϲ��캯���������ǵ���������ָ��
	list_iterator(node* n)
		: _node(n)
	{
	}

	// ������ - ���ص��������ֵ  Refͨ�����Σ�T��const T ��������const���ͺͷ�const����
	Ref operator*()
	{
		return _node->data;
	}

	//-> ���ص�������data�ĵ�ַ   Ptrͨ�����Σ�T��const T ��������const���ͺͷ�const����
	Ptr operator->()
	{
		return &_node->data;
	}

	// ǰ��++ ��++���ڷ����Լ�
	iterator& operator++()
	{
		_node = _node->next;
		return *this;
	}

	// ����++  �ȷ��� ��++
	iterator operator++(int)
	{
		iterator tmp = *this; // ע�⣺��ʱ�������������÷���
		_node = _node->next;
		return tmp; // tmp��һ���࣬�������÷��أ����ص�ʱ��ᴴ��һ����ʱ��
	}

	// ǰ��-- ��--���ڷ����Լ�
	iterator& operator--()
	{
		_node = _node->prev;
		return *this;
	}

	// ��-- �ڷ��أ���--
	iterator operator--(int)
	{
		iterator tmp = *this;
		_node = _node->prev;
		return tmp;
	}

	// pos��ַ++
	iterator& operator+(int x)
	{
		while (x--)
		{
			//*this��ʾ���������ָ�룬++����ǰ������أ���ʾָ��++
			*this = ++ * this;
		}
		return *this;
	}

	iterator& operator-(int x)
	{
		while (x--)
		{
			*this = -- * this;
		}
		return *this;
	}

	// this->_node �����ڲ���_node
	bool operator!=(const iterator& it)
	{
		return _node != it._node;
	}
};

//���������
template<class iterator,class Ref,class Ptr>
struct STL_reverse_iterator
{	
	iterator cur;  //���������
	typedef STL_reverse_iterator<iterator, Ref, Ptr> reverse_iterator;
	STL_reverse_iterator(iterator it)
		:cur(it)
	{}

	Ref operator*()
	{
		return *cur;  //����������������ã����Ƿ���node->data 
	}

	reverse_iterator operator++()
	{
		--cur;
		return *this;  
	}

	reverse_iterator operator--()
	{
		++cur;
		return *this;
	}

	bool operator!=(const reverse_iterator& s)
	{
		return cur != s.cur;
	}
};

// ���������  - ���Ƽ�
//template <class T, class Ref, class Ptr>
//struct list_reverse_iterator
//{
//	typedef list_node<T> node;					 // ����
//	typedef list_reverse_iterator<T, Ref, Ptr> reverse_iterator; // ������
//	node* _node;								 // ��������Ψһ�ĳ�Ա����:����ָ��
//	// ������Ĭ�Ϲ��캯���������ǵ���������ָ��
//	list_reverse_iterator(node* n)
//		: _node(n)
//	{
//	}
//
//	// ������ - ���ص��������ֵ  Refͨ�����Σ�T��const T ��������const���ͺͷ�const����
//	Ref operator*()
//	{
//		return _node->data;
//	}
//
//	//-> ���ص�������data�ĵ�ַ   Ptrͨ�����Σ�T��const T ��������const���ͺͷ�const����
//	Ptr operator->()
//	{
//		return &_node->data;
//	}
//
//	// ǰ��++ ��++���ڷ����Լ�
//	reverse_iterator& operator++()
//	{
//		_node = _node->prev;
//		return *this;
//	}
//
//	// ����++  �ȷ��� ��++
//	reverse_iterator operator++(int)
//	{
//		reverse_iterator tmp = *this; // ע�⣺��ʱ�������������÷���
//		_node = _node->prev;
//		return tmp; // tmp��һ���࣬�������÷��أ����ص�ʱ��ᴴ��һ����ʱ��
//	}
//
//	// ǰ��-- ��--���ڷ����Լ�
//	reverse_iterator& operator--()
//	{
//		_node = _node->next;
//		return *this;
//	}
//
//	// ��-- �ڷ��أ���--
//	reverse_iterator operator--(int)
//	{
//		reverse_iterator tmp = *this;
//		_node = _node->next;
//		return tmp;
//	}
//
//	// pos��ַ++
//	reverse_iterator& operator+(int x)
//	{
//		while (x--)
//		{
//			//*this��ʾ���������ָ�룬++����ǰ������أ���ʾָ��++
//			*this = -- * this;
//		}
//		return *this;
//	}
//
//	reverse_iterator& operator-(int x)
//	{
//		while (x--)
//		{
//			*this = ++ * this;
//		}
//		return *this;
//	}
//
//	// this->_node �����ڲ���_node
//	bool operator!=(const reverse_iterator& it)
//	{
//		return _node != it._node;
//	}
//};