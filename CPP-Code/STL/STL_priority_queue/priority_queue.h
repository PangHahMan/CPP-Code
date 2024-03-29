// 优先级队列使用vector作为其底层存储数据的容器，priority_queue就是堆
// 默认情况是大堆

#include <iostream>
#include <vector>
using namespace std;
namespace phw {
    // 仿函数less(使内部结构为大堆)
    template<class T>
    struct less {
        bool operator()(const T &x, const T &y) {
            return x < y;
        }
    };

    // 仿函数greater(使内部结构为小堆)
    template<class T>
    struct greater {
        bool operator()(const T &x, const T &y) {
            return x > y;
        }
    };

    // 优先级队列
    template<class T, class Container = vector<T>, class Compare = greater<T>>
    class priority_queue {
    public:
        // 堆的向上调整
        void AdjustUp(int child) {
            int parent = (child - 1) / 2;
            while (child > 0) {
                // 默认less ，也就是parent<child
                if (_comp(_con[parent], _con[child]))// 通过所给比较方式确定是否需要交换结点位置
                {
                    // 将父结点与孩子结点交换
                    swap(_con[child], _con[parent]);
                    // 继续向上进行调整
                    child = parent;
                    parent = (child - 1) / 2;
                } else// 已成堆
                {
                    break;
                }
            }
        }
        // 堆的向下调整
        void AdjustDown(int n, int parent) {
            int child = 2 * parent + 1;
            while (child < n) {
                //_comp(_con[child], _con[child + 1])表示child<child+1
                if (child + 1 < n && _comp(_con[child], _con[child + 1])) {
                    child++;
                }
                // parent<child
                if (_comp(_con[parent], _con[child]))// 通过所给比较方式确定是否需要交换结点位置
                {
                    // 将父结点与孩子结点交换
                    swap(_con[child], _con[parent]);
                    // 继续向下进行调整
                    parent = child;
                    child = 2 * parent + 1;
                } else// 已成堆
                {
                    break;
                }
            }
        }

        // 插入元素到队尾（并排序）
        void push(const T &x) {
            _con.push_back(x);
            AdjustUp(_con.size() - 1);// 将最后一个元素进行一次向上调整
        }

        // 弹出队头元素（堆顶元素）
        void pop() {
            swap(_con[0], _con[_con.size() - 1]);
            _con.pop_back();
            AdjustDown(_con.size(), 0);// 将第0个元素进行一次向下调整
        }

        // 访问队头元素（堆顶元素）
        T &top() {
            return _con[0];
        }
        const T &top() const {
            return _con[0];
        }
        // 获取队列中有效元素个数
        size_t size() const {
            return _con.size();
        }
        // 判断队列是否为空
        bool empty() const {
            return _con.empty();
        }

    private:
        Container _con;// vector容器
        Compare _comp; // 比较方式
    };
}// namespace phw