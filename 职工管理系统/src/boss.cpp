#include "boss.h"

void Boss::showInfo()
{
    cout << "该职工的信息如下：" << endl;
    cout << "职工编号：" << this->m_id 
        << "\t姓名: " << this->m_name
        << "\t部门编号: " << this->m_deptid
        << "\t岗位职责: 管理公司所有事务" << endl;

}

string Boss::getDeptname()
{
    return("老板");
}

Boss::Boss(int id, string name, int deptid)
{
    this->m_id = id;
    this->m_name = name;
    this->m_deptid = deptid;
}