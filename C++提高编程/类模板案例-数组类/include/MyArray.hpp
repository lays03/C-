#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>
class MyArray
{
public:
    //构造函数
    MyArray(int size);

    //拷贝构造函数
    MyArray(const MyArray<T>& myarr);

    //析构函数
    ~MyArray();

    //重载=
    MyArray& operator=(MyArray &myarr);

    //尾插法
    void myAdd(T num);

    //尾删法
    void mySub();

    //通过下标访问数组中的元素
    T getNum(int index);

    //获取数组中当前元素个数
    int getNumCounter();

    //获取数组的容量
    int getArrSize();

public:
    int m_size; //数组长度
    T *m_arr; //数组
};

//构造函数
template<class T>
MyArray<T>::MyArray(int size)
{
    cout << "构造函数调用" << endl;
    this->m_size = size;
    this->m_arr = new T[size];
    for(int i = 0; i < this->m_size; ++i)
    {
        this->m_arr[i] = NULL;
    }
}

//拷贝构造函数
template<class T>
MyArray<T>::MyArray(const MyArray<T>& myarr)
{
    cout << "拷贝构造函数调用" << endl;
    this->m_size = myarr.m_size;
    this->m_arr = myarr.m_arr;
}

//析构函数
template<class T>
MyArray<T>::~MyArray()
{
    cout << this << "析构函数调用" << endl;
    if(this->m_arr != NULL)
    {
        for(int i = 0; i < this->m_size; ++i)
        {
            this->m_arr[i] = NULL;
        }
    }
    delete this->m_arr;
    cout << "析构完成" << endl;
}

//重载=
template<class T>
MyArray<T>& MyArray<T>::operator=(MyArray<T>& myarr)
{
    if(this->m_arr != NULL)
    {
        delete this->m_arr;
        this->m_arr = NULL;
    }
    this->m_arr = new T[myarr.m_size];
    for(int i = 0; i < this->m_size; ++i)
    {
        this->m_arr[i] = myarr.m_arr[i];
    }
    return *this;
}

//尾插法
template<class T>
void MyArray<T>::myAdd(T num)
{
    //判断数组里面没有填满
    bool isfull = false;
    for(int i = 0; i < this->m_size; ++i)
    {
        if(this->m_arr[i] != NULL)
        {
            continue;
        }
        else
        {
            //数组没满，把元素的地址放到里面
            isfull = false;
            this->m_arr[i] = num;
            break;
        }
    }
    //如果数组已经满了，则需要开辟新的内存空间
    if(isfull)
    {
        T *number = new T(num);
        this->m_arr[this->m_size] = *number;
        this->m_size++;
    } 
}

//尾删法
template<class T>
void MyArray<T>::mySub()
{
    //判断数组里面没有填满
    bool isfull = true;
    for(int i = 0; i < this->m_size; ++i)
    {
        if(this->m_arr[i] != NULL)
        {
            continue;
        }
        else
        {
            //数组没满，把上一个元素删掉
            isfull = false;
            delete this->m_arr[i - 1];
        }
    }
    if(isfull)
    {
        delete this->m_arr[this->m_size - 1];
        this->m_size--;
    }
}

//通过下标访问数组中的元素
template<class T>
T MyArray<T>::getNum(int index)
{
    return this->m_arr[index];
}

//获取数组中当前元素个数
template<class T>
int MyArray<T>::getNumCounter()
{
    int counter = 0;
    for(int i = 0; i < this->m_size; ++i)
    {
        if(this->m_arr[i] != NULL)
        {
            counter++;
        }
    }
    return counter;
}

//获取数组的容量
template<class T>
int MyArray<T>::getArrSize()
{
    return this->m_size;
}