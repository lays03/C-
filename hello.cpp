#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class Person1
{
public:
    void showPerson1()
    {
        cout << "Person1 show" << endl;
    }
};

class Person2
{
public:
    void showPerson1()
    {
        cout << "Person2 show" << endl;
    }
};

//类模板
template<class T>
class MyClass
{
public:
    T obj;

    //类模板中的成员函数
    //一开始不会被创建，因为不会被调用，因此也不会报错
    void func1()
    {
        obj.showPerson1();
    }
    void func2()
    {
        obj.showPerson2();
    }

};

void test01()
{
    MyClass<Person1>m;
    m.func1(); //正确，因为Person1中没有showPerson1的成员函数
    // m.func2(); //错误，因为Person1中没有showPerson2的成员函数

}

int main()
{
    test01();
}