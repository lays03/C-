#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
using namespace std;

void printList(const list<int>& L)
{
    for(list<int>::const_iterator it = L.begin(); it != L.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

bool myCompare(int v1, int v2)
{
    //降序 就让第一个数 > 第二个数
    return v1 > v2;
}

void test01()
{
    list<int> L;
    L.push_back(10);
    L.push_back(50);
    L.push_back(30);
    L.push_back(20);
    L.push_back(40);

    cout << "排序前: ";
    printList(L);

    cout << "排序后:";
    L.sort();
    printList(L);

    cout << "排序后:";
    L.sort(myCompare);
    printList(L);
/*
排序前: 10 50 30 20 40 
排序后:10 20 30 40 50 
排序后:50 40 30 20 10 
*/
}

int main()
{
    test01();
}