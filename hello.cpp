#include<iostream>
#include<string>
using namespace std;

class Phone{
public:
    string m_pname; //手机名字
    Phone(string name){
        cout << "Phone的构造函数调用" << endl;
        m_pname = name;
    }
    ~Phone(){
        cout << "Phone的析构函数调用" << endl;
    }
};

class Person{
public:
    //姓名
    string m_name;
    //手机
    Phone m_phone;
    
    //这里的m_phone(name) 相当于 Phone m_phone = pname 隐式转换法
    Person(string name, string pname):m_name(name), m_phone(pname){
        cout << "Person的构造函数调用" << endl;
    }
    ~Person(){
        cout << "Person的析构函数调用" << endl;
    }

};
//当其他类对象作为本类成员，构造时候先构造类对象，再构造自身
//析构的顺序与之相反
void test01(){
    Person p1("liujing", "iphone15");
    cout << p1.m_name << "的手机是" << p1.m_phone.m_pname << endl;
}

int main(){
    test01();
}