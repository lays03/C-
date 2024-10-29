#include <iostream>
#include <time.h>
#include "MyArray.hpp"

template<class T>
void printArray(MyArray<T> &arr)
{
    for(int i = 0; i < arr.getSize(); ++i)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}
//测试内置数组类型
void test01()
{
    MyArray<int>arr1(100);
    for(int i = 0; i < 10; ++i)
    {
        arr1.Push_Back(i);
    }
    cout << "arr1的打印输出为: " << endl;
    printArray(arr1);

    for(int i = 0; i < 5; ++i)
    {
        arr1.Pop_Back();
    }
    cout << "arr1尾删后的打印输出为: " << endl;
    printArray(arr1);

    // MyArray<string>arr2(100);
    // arr2.Push_Back("hello");
    // arr2.Push_Back("world");
    // arr2.Push_Back("Beijing");
    // arr2.Push_Back("Anhui");
    // printArray(arr2);
}

class Person
{
public:
    string m_name;
    int m_age;
    Person()
    {

    }
    Person(string name, int age)
    {
        m_name = name;
        m_age = age; 
    }
};


void printPersonArray(MyArray<Person>& arr)
{
    for(int i = 0; i < arr.getSize(); ++i)
    {
        cout << "姓名: " << arr[i].m_name << " 年龄: " << arr[i].m_age << endl;
    }
}

//测试自定义数据类型
void test02()
{
    MyArray<Person>arr1(100);
    Person p1("妲己", 20);
    Person p2("昭君", 18);
    Person p3("韩信", 30);
    Person p4("李白", 28);
    Person p5("赵云", 25);
    arr1.Push_Back(p1);
    arr1.Push_Back(p2);
    arr1.Push_Back(p3);
    arr1.Push_Back(p4);
    arr1.Push_Back(p5);

    //打印数组
    printPersonArray(arr1);

    //输出容量和大小
    cout << "arr1数组的容量为: " << arr1.getCapacity() << endl;
    cout << "arr1数组的大小为: " << arr1.getSize() << endl;
    
}

int main()
{
    // test01();
    test02();
}
