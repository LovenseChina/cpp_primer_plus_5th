#include <iostream>
using std::cout;
using std::endl;

// 1. 前向声明类模板
//template <typename TT> class HasFriend;

// 2. 前向声明函数模板（参数类型必须与定义一致）
template <typename T> void counts();
//template <typename T> void report(HasFriend<T> &);   // 注意参数是 HasFriend<T>&
template <typename T> void report(T &);

// 3. 定义类模板
template <typename TT>
class HasFriend {
private:
    TT item;
    static int ct;
public:
    HasFriend(const TT & i) : item(i) { ++ct; }
    ~HasFriend() { --ct; }

    // 4. 友元声明：指定函数模板的特定实例为友元
    friend void counts<TT>();                    // counts<int>() 等
    friend void report<>(HasFriend<TT> &);        // report<int>(HasFriend<int>&) 等
};

// 5. 静态成员初始化
template <typename TT>
int HasFriend<TT>::ct = 0;

// 6. 定义函数模板
template <typename T>
void counts() {
    cout << "template size: " << sizeof(HasFriend<T>) << "; ";
    cout << "template counts(): " << HasFriend<T>::ct << endl;
}

template <typename T>
void report(T &hf) {
    cout << hf.item << endl;   // 现在可以访问私有成员
}

int main() {
    counts<int>();
    HasFriend<int> hfi1(10);
    HasFriend<int> hfi2(20);
    HasFriend<double> hfdb(10.5);
    report(hfi1);
    report(hfi2);
    report(hfdb);
    cout << "counts<int>() output:\n";
    counts<int>();
    cout << "counts<double>() output:\n";
    counts<double>();
    return 0;
}
