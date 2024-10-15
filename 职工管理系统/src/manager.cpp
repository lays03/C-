#include "manager.h"

void Manager::showInfo()
{
    cout << "该职工的信息如下：" << endl;
    cout << "职工编号：" << this->m_id 
        << "\t姓名: " << this->m_name
        << "\t部门编号: " << this->m_deptid 
        << "\t岗位职责: 完成老板交给的任务，并下发任务给员工 " << endl;

}

string Manager::getDeptname()
{
    return("经理");
}

Manager::Manager(int id, string name, int deptid)
{
    this->m_id = id;
    this->m_name = name;
    this->m_deptid = deptid;
}