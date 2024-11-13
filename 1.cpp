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

class Person
{
public:
    string m_Name;
    int m_Score;
    Person(string name, int score)
    {
        this->m_Name = name;
        this->m_Score = score;
    }
};

//打印deque
void printDeque(const deque<int>& d)
{
    for(deque<int>::const_iterator it = d.begin(); it != d.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}


//添加选手
void addPerson(vector<Person>& v)
{
    string nameside = "ABCDE";
    for(int i = 0; i < 5; ++i)
    {
        string name = "选手_";
        name += nameside[i];
        Person p(name, 0);
        v.push_back(p);
    }
}

//打分
void setScore(vector<Person>& v)
{
    srand((unsigned)time(NULL));
    for(vector<Person>::iterator it = v.begin(); it != v.end(); ++it)
    {
        deque<int> d;
        int score = 60 + rand() % 41;
        for(int i = 0; i < 10; ++i)
        {
            int score = 60 + rand() % 41;
            d.push_back(score);
        }
        cout << it->m_Name << "得分排序前: " << endl;
        printDeque(d);
        //排序
        sort(d.begin(), d.end());
        cout << it->m_Name << "得分排序后: " << endl;
        printDeque(d);

        d.pop_back(); //去掉最高分
        d.pop_front(); //去掉最低分
        cout << it->m_Name << "去掉最高分和最低分后: " << endl;
        printDeque(d);

        int res = 0;
        for(deque<int>::iterator dit = d.begin(); dit != d.end(); ++dit)
        {
            res += *dit;
        }
        res /= d.size(); //算出平均分
        it->m_Score = res;
        cout << it->m_Name << "的最终得分是: " << it->m_Score << endl;
    }
}



int main()
{
    //添加选手
    vector<Person> v;
    addPerson(v);

    //打分
    deque<int> d;
    setScore(v);
}