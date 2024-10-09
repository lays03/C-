#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    Person(int a, int b)
    {
        m_A = a;
        m_B = b;
    }
    friend ostream &operator<<(ostream &cout ,Person &p);
private:
    int m_A;
    int m_B;
    //利用成员函数重载 左移运算符 
    //不会利用成员函数重载<<运算符，因为无法实现cout在左侧
    // void operator<<(Person &p)
    // {

    // }
    
};

//只能利用全局函数重载左移运算符
ostream &operator<<(ostream &cout ,Person &p) //本质： operator << (cout, p) 简化 cout << p
{
    cout << "m_A = " << p.m_A << " m_B = " << p.m_B;
    return cout; //返回cout就可以一直返回
}
void test01()
{
    Person p(10, 10);
    cout << p << endl << "hello world";
}


int main()
{
    test01();
}