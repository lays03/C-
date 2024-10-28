#include <iostream>
#include <time.h>
#include "MyArray.hpp"

void test01()
{
    MyArray<int>arr(10);
    cout << "arr数组的长度为: " << arr.getArrSize() << endl;
    cout << "arr数组中元素个数为: " << arr.getNumCounter() << endl;

    srand((unsigned)time(NULL));
    for(int i = 0; i < 8; ++i)
    {
        arr.myAdd(rand() % 20);
    }

    cout << "尾插法后, 数组中元素个数为: " << arr.getNumCounter() << endl;
    for(int i = 0; i < arr.m_size; ++i)
    {
        if(arr.m_arr[i] != NULL)
        {
            cout << "arr[" << i << "]= " << arr.getNum(i) << endl;
        }
    }

    MyArray<char>ch(10);
    cout << "ch数组的长度为: " << ch.getArrSize() << endl;
    cout << "ch数组中元素个数为: " << ch.getNumCounter() << endl;

    ch.myAdd('a');
    ch.myAdd('b');
    ch.myAdd('c');

    cout << "尾插法后, 数组中元素个数为: " << ch.getNumCounter() << endl;
    for(int i = 0; i < ch.m_size; ++i)
    {
        cout << "ch[" << i << "]= " << ch.getNum(i) << endl;
    }

}

int main(int argc, char *argv[])
{
    test01();
}
