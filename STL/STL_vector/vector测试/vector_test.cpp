#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void test_vector1() {
    // 1.vector()   �޲ι���
    vector<int> v1;
    // 2.vector��size_type n, const value_type& val = value_type())   ���첢��ʼ��n��val
    vector<int> v2(4, 100);
    // 3.vector (const vector& x)   ��������
    vector<int> v3(v2);
    // 4.vector (InputIterator first, InputIterator last)   ʹ�õ��������г�ʼ������
    vector<int> v4(v3.begin(), v3.end());
}

void PrintVector(const vector<int> &v) {
    // const����ʹ��const���������б�����ӡ
    // vector<int>::iterator it = v.begin();   //err ����const_������
    vector<int>::const_iterator it = v.begin();
    while (it != v.end()) {
        cout << *it << " ";
        it++;
    }
    cout << endl;
}

// vector�ĵ���������
void test_vector2() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";// 1 2 3 4 5
    }
    cout << endl;

    vector<int>::iterator it = v.begin();
    while (it != v.end()) {
        cout << *it << " ";// 1 2 3 4 5
        it++;
    }
    cout << endl;
    // C++11 ��Χfor���ײ����ɵ�����ʵ�ֵ�
    for (auto e: v) {
        cout << e << " ";// 1 2 3 4 5
    }
    cout << endl;

    // ʹ�õ����������޸�
    it = v.begin();
    while (it != v.end()) {
        (*it) *= 2;
        it++;
    }

    for (auto e: v) {
        cout << e << " ";// 2 4 6 8 10
    }
    cout << endl;

    // ʹ�÷�����������б�����ӡ
    vector<int>::reverse_iterator rit = v.rbegin();
    while (rit != v.rend()) {
        cout << *rit << " ";// 10 8 6 4 2
        rit++;
    }
    cout << endl;

    PrintVector(v);// 2 4 6 8 10
}

void TestVectorExpand() {
    size_t sz;
    vector<int> v;
    sz = v.capacity();
    v.reserve(100);// ��ǰ���������úã����Ա���һ�����һ������
    cout << "making v grow:\n";
    for (int i = 0; i < 100; ++i) {
        v.push_back(i);
        if (sz != v.capacity()) {
            sz = v.capacity();
            cout << "capacity changed: " << sz << '\n';
        }
    }
}

// vector��resize��reserve
//  reisze(size_t n, const T& data = T())
//  ����ЧԪ�ظ�������Ϊn�������ʱ����ʱ�������Ԫ��ʹ��data�������
//  ע�⣺resize������Ԫ�ظ���ʱ���ܻ�����

void test_vector3() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    v.resize(5);
    v.resize(8, 100);
    v.resize(12);
    // vector<int> v2(10,0);  //��Ҳ���� �����쿪�ռ䣬���Ƽ�����Щ���������
    cout << "v contains:";
    for (size_t i = 0; i < v.size(); i++) {
        cout << ' ' << v[i];// 0 1 2 3 4 100 100 100 0 0 0 0
    }
    cout << endl;

    cout << v.size() << endl;    // 12
    cout << v.capacity() << endl;// 16
    cout << v.empty() << endl;   // 0
}

// vector Element access
void test_vector4() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    cout << v[1] << endl;// 2
    // cout<<v[7]<<endl;  //Խ�粻����,��ӡ0
    cout << v.at(1) << endl;// 2
    // cout<<v.at(7)<<endl;   // Խ�籨��
    cout << v.data() << endl; // ����C��ʽ��ַ��0xec1740
    cout << v.front() << endl;// 1
    cout << v.back() << endl; // 5
}

// vector��ɾ���
void test_vector5() {
    vector<int> v;
    // vector<int> v{1,2,3,4};  //C++11֧��
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.pop_back();
    auto it = v.begin();
    while (it != v.end()) {
        cout << *it << " ";// 1 2 3
        it++;
    }
    cout << endl;

    // ��ָ��λ��ǰ����ֵΪval��Ԫ�أ����磺3֮ǰ����30,���û���򲻲���
    // 1. ��ʹ��find����3����λ��
    // ע�⣺vectorû���ṩfind���������Ҫ����ֻ��ʹ��STL�ṩ��ȫ��find
    auto pos = find(v.begin(), v.end(), 3);
    if (pos != v.end()) {
        v.insert(pos, 30);
    }

    for (auto e: v) {
        cout << e << " ";// 1 2 30 3
    }
    cout << endl;

    // ɾ��posλ�õ����� ,����ɾ��30
    pos = find(v.begin(), v.end(), 30);
    v.erase(pos);
    for (auto e: v) {
        cout << e << " ";// 1 2 3
    }
    cout << endl;
}

// assign/clear/swap�ӿڲ���
void test_vector6() {
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v2 = {11, 12, 13, 14, 15};
    v1.assign(v2.begin(), v2.end());
    for (auto e: v1) {
        cout << e << " ";// 11 12 13 14 15
    }
    cout << endl;

    vector<int> v3 = {1, 2, 3, 4, 5};
    v3.assign(5, 0);
    for (auto e: v3) {
        cout << e << " ";// 0 0 0 0 0
    }
    cout << endl;

    // clear����
    v1.clear();
    for (auto e: v1) {
        cout << e << " ";// ʲô��û�д�ӡ
    }
    cout << endl;
    cout << v1.capacity() << endl;// 10;
    cout << v1.size() << endl;    // 0

    // ����v2��v3  v2Ϊ11 12 13 14 15  v3Ϊ0 0 0 0 0
    v2.swap(v3);
    for (auto e: v3) {
        cout << e << " ";// 11 12 13 14 15
    }
    cout << endl;
}

int main() {
    test_vector6();
    return 0;
}