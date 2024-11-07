#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <map>
using namespace std;

class Person
{
public:
    string m_Name;
    int m_Age;
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
};

class MyCompare
{
public:
    bool operator()(const Person &p1, const Person &p2) const
    {
        return p1.m_Age > p2.m_Age;
    }
};

void test01()
{
    map<Person, int, MyCompare> mp;
    Person p1("刘备", 24);
    Person p2("关羽", 28);
    Person p3("张飞", 25);
    Person p4("赵云", 21);
    
    //插入
    mp.insert(make_pair(p1, 10));
    mp.insert(make_pair(p2, 20));
    mp.insert(make_pair(p3, 30));
    mp.insert(make_pair(p4, 40));

    for(map<Person, int, MyCompare>::iterator it = mp.begin(); it != mp.end(); ++it)
    {
        cout << "key = " << (*it).first.m_Age << "\tvalue = " << it->second << endl;
    }
/*
key = 28        value = 20
key = 25        value = 30
key = 24        value = 10
key = 21        value = 40
*/
}
int main()
{
    test01();
}