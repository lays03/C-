#include "boss.h"

void Boss::showInfo()
{
    cout << "该职工的信息如下：" << endl;
    cout << "职工编号：" << m_id 
        << "\t姓名：" << m_name
        << "\t部门编号：" << m_deptid
        << "\t岗位职责：管理公司所有事务" << endl;

}

string Boss::getDeptname()
{
    return("老板");
}

Boss::Boss(string id, string name, int deptid)
{
    m_id = id;
    m_name = name;
    m_deptid = deptid;
}