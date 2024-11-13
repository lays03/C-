#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

void myPrint(int val)
{
    cout << val << " ";
}

void test01()
{
    vector<int>v1;
    for(int i = 0; i < 10; ++i)
    {
        v1.push_back(i);
    }

    vector<int>v2;
    for(int i = 11; i < 15; ++i)
    {
        v2.push_back(i);
    }

    vector<int>v3;

    v3.resize(max(v1.size(), v2.size()));
    set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    for_each(v3.begin(), v3.end(), myPrint); //1 2 3 4 11 12 13 14 
    cout << endl;
}

int main()
{
    test01();
}

