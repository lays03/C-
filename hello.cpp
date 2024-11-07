#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>

#include <ctime>
using namespace std;


class Person
{
public:
    string m_Name;
    int m_Salary;
    Person(string name, int money)
    {
        this->m_Name = name;
        this->m_Salary = money;
    }
};

//添加员工
void addEmployee(vector<Person>& v)
{
    string nameside = "ABCDEFGHIJ";
    for(int i = 0; i < 10; ++i)
    {
        string name = "员工_";
        name += nameside[i];
        int money = 10000 + rand() % 10000;
        Person p(name, money);
        v.push_back(p);
    }
}

//员工分组
void setGroup(vector<Person>& v, multimap<int, Person>& mm)
{
    srand((unsigned)time(NULL));
    for(vector<Person>::iterator it = v.begin(); it != v.end(); ++it)
    {
        int index = 1 + rand() % 3;
        mm.insert(make_pair(index, *it));
    }
}

void showInfoByGroup(multimap<int, Person>& mm, map<int, string>& m)
{
    for(multimap<int, Person>::iterator it = mm.begin(); it != mm.end(); ++it)
    {
        cout << "key = " << m[(*it).first] << " 姓名: " << (*it).second.m_Name
            << " 工资: " << (*it).second.m_Salary << endl;
    }

    cout << "策划部门: " << endl;
    multimap<int, Person>::iterator pos = mm.find(1);
    //统计策划部门具体人数
    int count = mm.count(1);
    int index = 0;
    for(; pos != mm.end() && index < count; ++pos, ++index)
    {
        cout << "姓名: " << pos->second.m_Name
            << " 工资: " << pos->second.m_Salary << endl;
    }

    cout << "---------" << endl;
    cout << "美术部门: " << endl;
    pos = mm.find(2);
    //统计美术部门具体人数
    count = mm.count(2);
    index = 0;
    for(; pos != mm.end() && index < count; ++pos, ++index)
    {
        cout << "姓名: " << pos->second.m_Name
            << " 工资: " << pos->second.m_Salary << endl;
    }

    cout << "---------" << endl;
    cout << "研发部门: " << endl;
    pos = mm.find(3);
    //统计研发部门具体人数
    count = mm.count(3);
    index = 0;
    for(; pos != mm.end() && index < count; ++pos, ++index)
    {
        cout << "姓名: " << pos->second.m_Name
            << " 工资: " << pos->second.m_Salary << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    //1、添加员工
    vector<Person> v;
    addEmployee(v);

    //2、给员工分组
    multimap<int, Person> mm;
    setGroup(v, mm);

    //3、部门编号和部门名称对应
    map<int, string> m;
    m.insert(make_pair(1, "策划"));
    m.insert(make_pair(2, "美术"));
    m.insert(make_pair(3, "研发"));

    //4、分部门显示
    showInfoByGroup(mm, m);

}
/*
key = 策划 姓名: 员工_A 工资: 18602
key = 策划 姓名: 员工_C 工资: 15865
key = 策划 姓名: 员工_G 工资: 16480
key = 策划 姓名: 员工_H 工资: 17313
key = 美术 姓名: 员工_B 工资: 11057
key = 美术 姓名: 员工_I 工资: 15871
key = 研发 姓名: 员工_D 工资: 18201
key = 研发 姓名: 员工_E 工资: 17635
key = 研发 姓名: 员工_F 工资: 13908
key = 研发 姓名: 员工_J 工资: 10979
策划部门:
姓名: 员工_A 工资: 18602
姓名: 员工_C 工资: 15865
姓名: 员工_G 工资: 16480
姓名: 员工_H 工资: 17313
---------
美术部门:
姓名: 员工_B 工资: 11057
姓名: 员工_I 工资: 15871
---------
研发部门:
姓名: 员工_D 工资: 18201
姓名: 员工_E 工资: 17635
姓名: 员工_F 工资: 13908
姓名: 员工_J 工资: 10979
*/