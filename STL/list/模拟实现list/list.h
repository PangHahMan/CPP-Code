#pragma once
#include<assert.h>
//list  ��ͷ˫��ѭ������
template<class T>
struct list_node
{
	list_node<T>* _next;
	list_node<T>* _prev;
	T _data;
	//���캯����ʼ���б�
	list_node(const T& x = T())  //T()Ĭ�Ϲ��캯��������ʼ��x
		:_next(nullptr)
		, _prev(nullptr)
		, _data(x)
	{}
};

//list������
template<class T, class Ref, class Ptr >
struct _list_iterator
{
	typedef list_node<T> node;
	typedef _list_iterator<T, Ref, Ptr> iterator;
	node* _node;   //��������Ψһ�ĳ�Ա����
	//���������캯��
	_list_iterator(node* n)
		:_node(n)
	{}

	//���ؽ�����
	Ref operator*()
	{
		return _node->_data;
	}

	//����->
	Ptr operator->()
	{
		return &_node->_data;  //->  ��ȡ��ַ
	}

	//ǰ��++  �����Լ�
	iterator& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	//����++  �����Լ�
	iterator& operator++(int)
	{
		iterator tmp = *this;
		_node = _node->_next;
		return tmp;
	}

	iterator& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	iterator& operator--(int)
	{
		iterator tmp = *this;
		_node = _node->_prev;
		return tmp;
	}

	bool operator != (const iterator& s)
	{
		return _node != s._node;
	}
};

//const_list������
//template<class T>
//struct _list_const_iterator
//{
//	typedef list_node<T> node;
//	typedef _list_const_iterator<T> iterator;
//	node* _node;   //��������Ψһ�ĳ�Ա����
//	//���������캯��
//	_list_const_iterator(node* n)
//		:_node(n)
//	{}
//
//	//���ؽ�����- ����const�Ͳ����޸���
//	const T& operator*()
//	{
//		return _node->_data;
//	}
//
//	//ǰ��++  �����Լ�
//	iterator& operator++()
//	{
//		_node = _node->_next;
//		return *this;
//	}
//
//	//����++  �����Լ�
//	iterator& operator++(int)
//	{
//		iterator tmp = *this;
//		_node = _node->_next;
//		return tmp;
//	}
//
//	bool operator != (const iterator& s)
//	{
//		return _node != s._node;
//	}
//};

template<class T>
class list
{
	typedef list_node<T> node;
public:
	//������������
	typedef _list_iterator<T, T&, T*> iterator;
	typedef _list_iterator<T, const T&, const T*> const_iterator;
	//typedef _list_const_iterator<T> const_iterator;
	list()
	{
		_head = new node;
		_head->_next = _head;
		_head->_prev = _head;
	}

	iterator begin()
	{
		//iterator it(_head->_next);
		//return it;
		//���ص������࣬Ȼ����������node ��_head->_next��ʼ��
		return iterator(_head->_next);
	}

	const_iterator begin() const  //const���εĺ������޷��ı��Ա����
	{
		return const_iterator(_head->_next);   //ָ�벻�ܸı䣬�����Ը�ֵ������
	}

	iterator end()
	{
		//˫���ͷѭ����β��ͷ�ڵ�head
		return iterator(_head);
	}

	const_iterator end() const
	{
		return const_iterator(_head);
	}


	void push_back(const T& x)
	{
		/*node* tail = _head->_prev;
		node* new_node = new node(x);

		tail->_next = new_node;
		new_node->_prev = tail;
		new_node->_next = _head;
		_head->_prev = new_node;*/
		//����
		insert(end(), x);
	}

	void push_front(const T& x)
	{
		insert(begin(), x);
	}

	//pos����������ʧЧ�������posλ����Զ����䣬��ַ����
	void insert(iterator pos, const T& x)
	{
		//pos��һ����
		node* cur = pos._node;
		node* prev = cur->_prev;

		node* new_node = new node(x);
		prev->_next = new_node;
		new_node->_prev = prev;
		new_node->_next = cur;
		cur->_prev = new_node;
	}
	
	void pop_back()
	{
		erase(--end());
	}

	void pop_front()
	{
		erase(begin());
	}

	void erase(iterator pos)
	{
		assert(pos != end());
		node* prev = pos._node->_prev;
		node* next = pos._node->_next;

		prev->_next = next;
		next->_prev = prev;
		delete pos._node;
	}
private:
	node* _head;  //ͷ�ڵ�
};

