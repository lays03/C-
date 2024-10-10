#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
    int m_A;
    Base()
    {
        m_A = 100;
    }
    void func()
    {
        cout << "Base - func()调用" << endl;
    }
    void func(int a)
    {
        cout << "Base - func(int a)调用  a = " << a << endl;
    }
};

class Son: public Base{
public:
    int m_A;
    Son()
    {
        m_A = 200;
    }
    void func()
    {
        cout << "Son - func()调用" << endl;
    }
};
void test01()
{
    Son s1;
    s1.func(); //直接访问即可
    s1.Base::func(); //需要加作用域
    cout << "s1.m_A = " << s1.m_A << endl; //直接访问即可  200
    cout << "s1.Base.m_A = " << s1.Base::m_A << endl; //需要加作用域  100

    s1.Base::func(1000);
}

int main()
{
    test01();
}