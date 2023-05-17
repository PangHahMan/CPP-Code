#pragma once
#include<utility>
#include<cassert>
#include<iostream>
using namespace std;

//红黑树节点颜色
enum Colour
{
	RED,
	BLACK,
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	T _data;
	Colour _col;
	//在单参数构造函数中使用 explicit 关键字是一种好的编程习惯，可以提高代码的可读性和健壮性。
	//加上 explicit 关键字，以避免出现不必要的隐式类型转换。如果没有加上 explicit 关键字，那么可以使用该构造函数创建一个 RBTreeNode 对象时，会发生隐式类型转换，将一个 pair<K, V> 类型的对象转换为 RBTreeNode 对象，这可能导致程序行为出现意外的结果。
	explicit RBTreeNode(const T& data)
		: _left(nullptr), _right(nullptr), _parent(nullptr), _data(data), _col(RED)
	{
	}
};

//迭代器
template<class T, class Ref, class Ptr>
struct __RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef __RBTreeIterator<T, Ref, Ptr> Self;

	Node* _node;   //成员变量

	__RBTreeIterator(Node* node)
		:_node(node)
	{}


	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}

	Self& operator++()
	{
		if (_node->_right)
		{
			// 1、右不为空，下一个就是右子树的最左节点
			Node* subLeft = _node->_right;
			while (subLeft->_left)
			{
				subLeft = subLeft->_left;
			}

			_node = subLeft;
		}
		else
		{
			//2、右为空，沿着到根的路径，找孩子是父亲左的那个祖先
			Node* cur = _node;
			Node* parent = cur->_parent;
			//如果parent不为NULL，或者cur是parent的右子树
			while(parent && cur==parent->_right)
			{
				//继续走
				cur = parent;
				parent = parent->_parent;
			}
			_node = parent;   //下一个节点就是parent
		}
		return *this;
	}

	//反向 右子树 根 左子树
	Self& operator--()
	{
		//++找左子树，--找右子树
		if(_node->_left)
		{
			//1、左不为空，找左子树的最右节点
			Node* subRight = _node->_left;
			while (subRight->_right)
			{
				subRight = subRight->_right;
			}
			_node = subRight;
		}
		else
		{
			//2、左为空，找孩子是父亲右的祖先
			Node* cur = _node;
			Node* parent = cur->_parent;
			//如果parent！=null ，cur==parent的左就继续走
			while(parent && cur == parent->_left)
			{
				cur = parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;
	}
};




//仿函数，用于pair的比较
template<class K, class T, class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	//析构函数
	~RBTree()
	{
		Destroy(this->_root);
		this->_root = nullptr;
	}
public:  //迭代器相关
	typedef __RBTreeIterator<T,T&,T*> iterator;
	typedef __RBTreeIterator<T,const T&,const T*> const_iterator;
	//迭代器最开始应该是树的最左边(中序)
	iterator begin()
	{
		Node* cur = this->_root;
		while(cur&&cur->_left)
		{
			cur = cur->_left;
		}

		return iterator(cur);
	}

	iterator end()
	{
		return iterator(nullptr);
	}
public:
	Node* find(const T& data)
	{
		Node* cur = this->_root;
		KeyOfT kot;
		while (cur)
		{
			if (kot(data) > kot(cur->_data))
			{
				cur = cur->_right;
			}
			else if (kot(data) < kot(cur->_data))
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}

	bool Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return true;
		}

		KeyOfT kot;  //用于map和set的比较方式，KeyOft在上层传值，一个是key，一个是pair
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (kot(data) > kot(cur->_data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(data) < kot(cur->_data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				// 相等则不插入
				return false;
			}
		}
		// cur走到了合适的位置
		cur = new Node(data);
		// 选择插入到parent的左边还是右边
		if (kot(cur->_data) < kot(parent->_data))
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		// cur链接parent
		cur->_parent = parent;
		//parent存在且parent的节点为红色的(意味着，循环往上调整到parent不存在或者parent为黑就不用调整了)
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			//如果爷爷的左边是父亲，那么爷爷的右边就是叔叔
			if (grandfather->_left == parent)
			{
				Node* uncle = grandfather->_right;
				//情况1：u存在且为红，变色处理，并继续往上处理
				if (uncle && uncle->_col == RED)
				{
					//调整parent变黑，uncle变黑，grandfather变红
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					//继续网上调整
					//重置parent，先将grandfather位置看成新增结点cur
					cur = grandfather;
					parent = cur->_parent;
				}
				else  //情况2+3  u不存在/u存在且为黑，旋转+变色
				{
					if (cur == parent->_left)
					{
						//     g
						//   p   u
						// c
						//如果cur在parent的左边，需要右旋+变色,右旋后parent成为根，需要变黑，grandfather变为parent的孩子，需要变红
						RotateRight(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//     g
						//   p   u
						//     c
						//当cur为parent的右边时，需要左旋+右旋+变色
						RotateLeft(parent);
						RotateRight(grandfather);   //右旋cur成为新的根,变为黑色，grandfather变为cur孩子，变为红色
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
			else  //(grandfather->_right == parent)  如果爷爷的右边是父亲，那么爷爷的左边就是叔叔
			{
				//    g
				//  u   p
				//        c
				Node* uncle = grandfather->_left;
				// 情况1：u存在且为红，变色处理，并继续往上处理
				if (uncle && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					// 继续往上调整
					cur = grandfather;
					parent = cur->_parent;
				}
				else // 情况2+3：u不存在/u存在且为黑，旋转+变色
				{
					//    g
					//  u   p
					//        c
					if (cur == parent->_right)
					{
						RotateLeft(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//    g
						//  u   p
						//    c
						RotateRight(parent);
						RotateLeft(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}

		}
		//最后的根变为黑节点
		_root->_col = BLACK;
		return true;
	}

	void InOrder()
	{
		_InOrder(this->_root);
	}

	bool IsBalance()
	{
		if (_root && _root->_col == RED)
		{
			cout << "根节点颜色是红色" << endl;
			return false;
		}

		int benchmark = 0;   //基准值，任选一条做，用于比较每条节点黑色节点相同，如果不相同则说明不平衡
		Node* cur = this->_root;
		while (cur)
		{
			if (cur->_col == BLACK)
				benchmark++;
			cur = cur->_left;
		}
		//连续红色节点
		return check(this->_root, 0, benchmark);
	}

	int Height()
	{
		return Height(this->_root);
	}
private:
	void Destroy(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		//后序销毁
		Destroy(root->_left);
		Destroy(root->_right);
		delete root;
	}

	int Height(Node* root)
	{
		if (root == nullptr)
			return 0;

		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	bool check(Node* root, int BlackNum, int benchmark)
	{
		//检查不能存在连续的红色节点
		//benchmark基准值
		if (root == nullptr)
		{
			if (benchmark != BlackNum)
			{
				cout << "某条路径黑色节点的数量不相等" << endl;
				return false;
			}

			return true;
		}

		if (root->_col == BLACK)
		{
			BlackNum++;
		}

		if (root->_col == RED && root->_parent && root->_parent->_col == RED)
		{
			cout << "存在连续的红色节点" << endl;
			return false;
		}

		return check(root->_left, BlackNum, benchmark) && check(root->_right, BlackNum, benchmark);
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		KeyOfT kot;
		_InOrder(root->_left);
		cout << kot(root->_data) << " ";
		_InOrder(root->_right);
	}

	// 左单旋
	void RotateLeft(Node* parent)
	{
		Node* subR = parent->_right; // 要旋转的parent的右子树
		Node* subRL = subR->_left;     // 子树的左子树

		// 旋转链接
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		// 需要记录要旋转的树还有没有父亲
		Node* ppnode = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR;

		// 如果ppnode为nullptr，说明parent一开始为根，旋转后subR为根
		if (ppnode == nullptr)
		{
			// 更新根节点
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = subR;
			}
			else
			{
				ppnode->_right = subR;
			}
			subR->_parent = ppnode;
		}
	}

	// 右单旋
	void RotateRight(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* ppnode = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (ppnode == nullptr)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = subL;
			}
			else
			{
				ppnode->_right = subL;
			}
			subL->_parent = ppnode;
		}
	}
private:
	Node* _root;
};