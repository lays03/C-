#include<iostream>
#include<string>
using namespace std;

/*
两种分类方式：<br>
- 按参数分为：有参构造和无参构造
- 按类型分为：普通构造和拷贝构造
*/
class Person
{
private:
    /* data */

public:
    int age;
    //构造函数
    Person() //无参构造（默认构造）
    {
        cout << "Person的无参构造函数调用" << endl;
    }
    Person(int a)
    {
        age = a;
        cout << "Person的有参构造函数调用" << endl;
    }
    //拷贝构造函数 
    //因为需要拷贝传进来的数据，因此改数据不能更改，因此加上const，并以引用的方式
    Person(const Person &p){
        //将传入的人身上的属性，拷贝到我身上
        age = p.age;
        cout << "Person的拷贝构造函数调用" << endl;
    }

    ~Person()
    {
        cout << "Person的析构函数调用" << endl;
    }
};

//调用
void test01(){
    //1、括号法
    // Person p1; //默认构造函数调用
    // Person p2(10);
    // Person p3(p2);
    // // cout << "p1的年龄为：" << p1.age << endl;
    // // cout << "p2的年龄为：" << p2.age << endl;
    // // cout << "p2的年龄为：" << p3.age << endl;
    // //注意事项
    // //调用默认构造函数时候，不要加()
    // Person P(); //不会调用构造函数，因为编译器会认为是一个函数的声明
    
    //2、显示法
    // Person p1;
    // Person p2 = Person(10); //有参构造
    // //拷贝构造函数
    // Person p3 = Person(p2);
    // //等号的右边 Person(10); 被叫做“匿名对象”，
    // //特点：当前行执行结束后，系统会立即回收掉匿名对象
    // Person(10); //匿名对象
    // cout << "aaa" << endl;
/*
可以看到，Person(10)调用的是有参构造函数，并且执行完这一行之后，立马调用析构函数
Person的无参构造函数调用
Person的有参构造函数调用
Person的拷贝构造函数调用
Person的有参构造函数调用
Person的析构函数调用
aaa
Person的析构函数调用
Person的析构函数调用
Person的析构函数调用
*/
    //注意事项
    //不要利用拷贝构造函数 初始化匿名对象
    // Person(p3); 错误，编译器会认为Person(p3) === Person p3，会导致p3重定义

    //3、隐式转换法
    Person p4 = 10; //相当于Person p4 = Person(10);
    Person p5 = p4; //隐式转换法的拷贝构造函数调用
}

int main(){
    test01();
}
