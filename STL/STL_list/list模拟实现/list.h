#pragma once
// list - �ײ���һ��˫���ͷѭ������
template <class T>
struct list_node
{
	list_node* next;
	list_node* prev;
	T data; // ģ��T���ͣ������κ�����
	// ���캯����ʼ���б�
	// T()��������ʼ��list_node���data��Ա��������ȷ��ÿ���´�����list_node������һ�����ʵ�T���͵�Ĭ��ֵ��
	list_node(const T& x = T()) // T()�������Զ������͵���Ĭ�Ϲ��캯������ʼ��x
		: next(nullptr), prev(nullptr), data(x)
	{
	}
};

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

// ���������
template <class T, class Ref, class Ptr>
struct list_reverse_iterator
{
	typedef list_node<T> node;					 // ����
	typedef list_reverse_iterator<T, Ref, Ptr> reverse_iterator; // ������
	node* _node;								 // ��������Ψһ�ĳ�Ա����:����ָ��
	// ������Ĭ�Ϲ��캯���������ǵ���������ָ��
	list_reverse_iterator(node* n)
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
	reverse_iterator& operator++()
	{
		_node = _node->prev;
		return *this;
	}

	// ����++  �ȷ��� ��++
	reverse_iterator operator++(int)
	{
		reverse_iterator tmp = *this; // ע�⣺��ʱ�������������÷���
		_node = _node->prev;
		return tmp; // tmp��һ���࣬�������÷��أ����ص�ʱ��ᴴ��һ����ʱ��
	}

	// ǰ��-- ��--���ڷ����Լ�
	reverse_iterator& operator--()
	{
		_node = _node->next;
		return *this;
	}

	// ��-- �ڷ��أ���--
	reverse_iterator operator--(int)
	{
		reverse_iterator tmp = *this;
		_node = _node->next;
		return tmp;
	}

	// pos��ַ++
	reverse_iterator& operator+(int x)
	{
		while (x--)
		{
			//*this��ʾ���������ָ�룬++����ǰ������أ���ʾָ��++
			*this = -- * this;
		}
		return *this;
	}

	reverse_iterator& operator-(int x)
	{
		while (x--)
		{
			*this = ++ * this;
		}
		return *this;
	}

	// this->_node �����ڲ���_node
	bool operator!=(const reverse_iterator& it)
	{
		return _node != it._node;
	}
};

// list��
template <class T>
class list
{
public:
	typedef list_node<T> node;					 // ����
	typedef list_iterator<T, T&, T*> iterator; // ������
	// const������ ͨ��const T& ����Ref ��const T* ����Ptr
	typedef list_iterator<T, const T&, const T*> const_iterator; // const������ - ͨ��const���������ʵ������޷����޸�
	typedef list_reverse_iterator<T, T&, T*> reverse_iterator;
	// �ڵ��ʼ��
	void empty_init()
	{
		head = new node;
		head->next = head;
		head->prev = head;
	}
	// listĬ�Ϲ��캯��
	list()
	{
		empty_init();
	}

	// ���õ��������캯��
	template <class iterator>
	list(iterator first, iterator last)
	{
		empty_init();
		while (first != last)
		{
			push_back(*first);
			++first;
		}
	}


	//��������  lt2(lt1)  �Ϸ���
	/*
	list(const list<T>& lt)
	{
		empty_init();
		for (auto e : lt)
		{
			push_back(e);  //��lt��Ԫ�ظ��Ƶ����ڵ�list��
		}
	}
	*/

	void swap(list<T>& tmp)
	{
		std::swap(head, tmp.head);  //����ͷָ��
	}

	// ��������-�ִ�����
	list(const list<T>& lt)
	{
		empty_init(); // �����У���Ȼ)_head���ǿ�ָ��
		list<T> tmp(lt.begin(), lt.end());  //��lt�ĵ������������һ��tmp
		swap(tmp);   //����tmp��this->head��ָ��
	}

	// ��ֵ lt1 = lt3                ����lt����lt3�Ŀ�����lt1��this
	list<T>& operator=(list<T> lt)
	{
		swap(lt);	  // ���� lt��this����
		return *this; // �����Լ����Ƿ���lt����ֵ����Ķ���
	}

	// ������ͨ�����齫��������Ϊֵ���ݣ���������Ϊ���ô��ݡ����ûᵼ�µ�����ʧЧ
	iterator begin()
	{
		return iterator(head->next); // ����Ĭ�Ϲ��캯����node��ʼ��
	}

	const_iterator begin() const  // const���εĺ������޷��ı��Ա����
	{
		return const_iterator(head->next);  // ָ�벻�ܸı䣬�����Ը�ֵ������
	}

	reverse_iterator rbegin()
	{
		return reverse_iterator(head->prev);  //rbegin �����һ����
	}

	reverse_iterator rend()
	{
		return reverse_iterator(head); //rend��ͷָ��
	}

	iterator end()
	{
		// ˫���ͷѭ����β��ͷ�ڵ�head
		return iterator(head);
	}

	const_iterator end() const
	{
		return const_iterator(head);
	}

	// pos����������ʧЧ�������posλ����Զ����䣬��ַ����
	void insert(iterator pos, const T& x)
	{
		// pos��һ����
		node* cur = pos._node;		// ��ȡposλ�õĽڵ��ַ
		node* prevnode = cur->prev; // ��¼posλ�õ�ǰ�ڵ�

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
			// �ȼ�¼ǰ�ڵ� ��ڵ�
			node* prevnode = pos._node->prev;
			node* nextnode = pos._node->next;

			prevnode->next = nextnode;
			nextnode->prev = prevnode;
			delete pos._node;
			// ������һ����ַ
			return iterator(nextnode); 
		}
		else
		{
			perror("erase fail");
			exit(-1);
		}
	}

	void push_back(const T& x)
	{
		insert(end(), x); // ����
	}

	void pop_back()
	{
		erase(end()--); // end()��ͷָ�룬ͷָ���prev��β�ڵ�
	}

	void push_front(const T& x)
	{
		insert(begin(), x);
	}

	void pop_front()
	{
		erase(begin());
	}

	void clear()
	{
		// �����ڴ� - ������ͷ�ڵ�
		iterator it = begin();
		while (it != end())
		{
			erase(it);
			it++;
		}
	}

	~list()
	{
		clear();
		delete head;
		head = nullptr;
	}

private:
	node* head; // ͷ�ڵ� - listֻ��һ�����ݳ�Ա��ͷ�ڵ�
};