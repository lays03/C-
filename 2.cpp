#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <map>

#include <ctime>

using namespace std;

#define CEHUA 1
#define MEISHU 2
#define YANFA 3



class Person
{
public:
    string m_Name;
    int m_Salary;
public:
    Person(string name, int salary)
    {
        this->m_Name = name;
        this->m_Salary = salary;
    }
};

//打印员工
void printVector(vector<Person>& v)
{
    for(vector<Person>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << "姓名: " << it->m_Name << "\t工资: " << it->m_Salary << endl;
    }
}

//添加员工
void addPerson(vector<Person>& v)
{
    srand((unsigned)time(0));
    string nameside = "ABCDEFGHIJ";
    for(int i = 0; i < 10; ++i)
    {
        int salary = 1000 + rand() % 1001;
        string name = "员工-";
        name += nameside[i];
        Person p(name, salary);
        v.push_back(p);
    }
}

//分配部门
void setGroup(vector<Person>& v, multimap<int, Person>& mm)
{
    srand((unsigned)time(NULL));
    for(vector<Person>::iterator it = v.begin(); it != v.end(); ++it)
    {
        int group = 1 + rand() % 3;
        mm.insert(make_pair(group, *it));
    }
}

//显示员工信息
void showPerson(multimap<int, Person>& mm)
{
    cout << "策划部门: " << endl;
    multimap<int, Person>::iterator pos = mm.find(1);
    int count = mm.count(1); //统计策划部门人数
    int index = 0;
    for(; pos != mm.end() && index < count; ++pos, ++index)
    {
        cout << "部门: " << pos->first << "\t员工姓名: " << pos->second.m_Name 
            << "\t工资: " << pos->second.m_Salary << endl;
    }

    cout << "----------" << endl;
    cout << "美术部门: " << endl;
    pos = mm.find(2);
    count = mm.count(2); 
    index = 0;
    for(; pos != mm.end() && index < count; ++pos, ++index)
    {
        cout << "部门: " << pos->first << "\t员工姓名: " << pos->second.m_Name 
            << "\t工资: " << pos->second.m_Salary << endl;
    }

    cout << "----------" << endl;
    cout << "研发部门: " << endl;
    pos = mm.find(3);
    count = mm.count(3);
    index = 0;
    for(; pos != mm.end() && index < count; ++pos, ++index)
    {
        cout << "部门: " << pos->first << "\t员工姓名: " << pos->second.m_Name 
            << "\t工资: " << pos->second.m_Salary << endl;
    }
}


int main()
{
    //添加员工
    vector<Person> v;
    addPerson(v);

    //打印员工信息
    printVector(v);

    //分配部门
    multimap<int, Person> mm;
    setGroup(v, mm);

    //显示员工信息
    showPerson(mm);
}