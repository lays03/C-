#include <iostream>
#include <string>
using namespace std;

//静态成员变量
class Person{
public:
    /*
    - 所有对象共享同一份数据
    - 在编译阶段分配内存
    - 类内声明，类外初始化
    */
    static int m_age;
    //静态成员变量也是有访问权限的
private:
    static int m_A;
};

//告知编译器，这是Person类作用域下的成员
//类内声明，类外初始化
int Person::m_age = 100;
int Person::m_A = 1000;

void test01(){
    Person p1;
    cout << p1.m_age << endl; //100

    Person p2;
    p2.m_age = 200;

    cout << p2.m_age << endl; //200
    //因为m_age是所有对象共享的一份数据，p2将其修改为200，p1对象的m_age同样也变成了200
}

void test02(){
    //静态成员变量 不属于某个对象上，所有对象都共享同一份数据
    //因此静态成员变量有两种访问方式
    
    //1、通过对象访问
    Person p;
    cout << p.m_age << endl;

    //2、通过类名进行访问
    cout << Person::m_age << endl;

    // cout << Person::m_A << endl; 错误，类外访问不到私有静态成员变量
}

int main(){
    // test01();
    test02();
    return 0;
}