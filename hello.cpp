#include<iostream>
#include<string>
using namespace std;

//成员属性设置为私有
//1、可以自己控制读写权限
//2、对于写可以检测数据有效性
class Person{
//用公有的方法对私有变量进行可读可写
public:
//设置姓名
    void setName(string name){
        m_Name = name;
    }
//获取姓名
    string getName(){
        return m_Name;
    }
//获取年龄
    int getAge(){
        return m_Age;
    }
//设置偶像
    void setIdol(string idol){
        m_Idol = idol;
    }

private:
    string m_Name; //姓名 可读可写

    int m_Age = 18; //年龄 只读

    string m_Idol; //偶像 只写

};

int main(){
    //实例化具体对象
    Person p1;
    p1.setName("lays");
    cout << "姓名为：" << p1.getName() << endl;
    cout << "年龄为：" << p1.getAge() << endl;

    return 0;
}