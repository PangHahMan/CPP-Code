#pragma once
#include<iostream>
#include<assert.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

//list - �ײ���һ��˫���ͷѭ������
template<class T>
struct list_node
{
	list_node* next;
	list_node* prev;
	T data;  //ģ��T���ͣ������κ�����
	//���캯����ʼ���б�
	//T()��������ʼ��list_node���data��Ա��������ȷ��ÿ���´�����list_node������һ�����ʵ�T���͵�Ĭ��ֵ��
	list_node(const T& x = T())   //T()�������Զ������͵���Ĭ�Ϲ��캯������ʼ��x
		:next(nullptr), prev(nullptr), data(x)
	{}
};

//list������
template<class T, class Ref, class Ptr>
struct list_iterator
{
	typedef list_node<T> node;  //����
	typedef list_iterator<T, Ref, Ptr> iterator;   //������
	node* _node;  //��������Ψһ�ĳ�Ա����:����ָ��
	//������Ĭ�Ϲ��캯���������ǵ���������ָ��
	list_iterator(node* n)
		:_node(n)
	{}

	//������ - ���ص��������ֵ  Refͨ�����Σ�T��const T ��������const���ͺͷ�const����
	Ref& operator*()
	{
		return _node->data;
	}

	//-> ���ص�������data�ĵ�ַ   Ptrͨ�����Σ�T��const T ��������const���ͺͷ�const����
	Ptr operator->()
	{
		return &_node->data;
	}

	//ǰ��++ ��++���ڷ����Լ�
	iterator& operator++()
	{
		_node = _node->next;
		return *this;
	}

	//����++  �ȷ��� ��++
	iterator operator++(int)
	{
		iterator tmp = *this;  //ע�⣺��ʱ�������������÷���
		_node = _node->next;
		return tmp;   //tmp��һ���࣬�������÷��أ����ص�ʱ��ᴴ��һ����ʱ��
	}

	//ǰ��-- ��--���ڷ����Լ�
	iterator& operator--()
	{
		_node = _node->prev;
		return *this;
	}

	//��-- �ڷ��أ���--
	iterator& operator--(int)
	{
		iterator tmp = *this;
		_node = _node->prev;
		return tmp;
	}

	//this->_node �����ڲ���_node
	bool operator!=(const iterator& it)
	{
		return _node != it._node;
	}
};

//list��
template<class T>
class list
{
public:
	typedef list_node<T> node;   //����
	typedef list_iterator<T, T&, T*> iterator;  //������
	//const������ ͨ��const T& ����Ref ��const T* ����Ptr 
	typedef list_iterator<T, const T&, const T*> const_iterator;  //const������ - ͨ��const���������ʵ������޷����޸�
	//�ڵ��ʼ��
	void empty_init()
	{
		head = new node;
		head->next = head;
		head->prev = head;
	}
	//listĬ�Ϲ��캯��
	list()
	{
		empty_init();
	}

	iterator begin()
	{
		return iterator(head->next);   //����Ĭ�Ϲ��캯����node��ʼ��
	}

	const_iterator begin() const
	{
		return const_iterator(head->next);
	}

	iterator end()
	{
		return iterator(head);
	}

	const_iterator end() const
	{
		return const_iterator(head);
	}

	void insert(iterator pos, const T& x)
	{
		//pos��һ����
		node* cur = pos._node;  //��ȡposλ�õĽڵ��ַ
		node* prevnode = cur->prev;  //��¼posλ�õ�ǰ�ڵ�

		node* newnode = new node(x);
		prevnode->next = newnode;
		newnode->prev = prevnode;
		newnode->next = cur;
		cur->prev = newnode;
	}

	iterator erase(iterator pos)
	{
		if (pos != end())
		{
			//�ȼ�¼ǰ�ڵ� ��ڵ�
			node* prevnode = pos._node->prev;
			node* nextnode = pos._node->next;

			prevnode->next = nextnode;
			nextnode->prev = prevnode;
			delete pos._node;
			// ������һ����ַ
			return iterator(next);
		}
		else
		{
			perror("erase fail");
			exit(-1);
		}
	}

	void push_back(const T& x)
	{
		node* tail = head->prev;  //β������ͷ�ڵ��ǰ���
		node* newnode = new node(x);
		//������β����
		tail->next = newnode;
		newnode->prev = tail;
		newnode->next = head;
		head->prev = newnode;
	}

	/*void pop_back()
	{

	}*/
private:
	node* head;  //ͷ�ڵ� - listֻ��һ�����ݳ�Ա��ͷ�ڵ�
};