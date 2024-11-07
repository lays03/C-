#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <set>
using namespace std;

void printSet(const set<int>& s)
{
    for(set<int>::const_iterator it = s.begin(); it != s.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    set<int> s;
    pair<set<int>::iterator, bool> ret = s.insert(10);

}

int main()
{
    test01();
}