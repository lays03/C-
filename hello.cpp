#include <iostream>
#include <string>
using namespace std;
#include <fstream>

class Worker
{
public:
    string m_id; //职工编号
    string m_name; //职工姓名
    int m_deptid; //职工所在部门编号
};

void test01()
{  
    ifstream ifs;
    ifs.open("Worker.txt", ios::in | ios::binary);
    if(!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    Worker wk;
    ifs.read((char *)&wk, sizeof(wk));
    cout << "职工编号：" << wk.m_id << endl;
    cout << "姓名：" << wk.m_name << endl;
    cout << "职工所在部门编号：" << wk.m_deptid << endl;

    ifs.close();

}
int main()
{
    test01();
}