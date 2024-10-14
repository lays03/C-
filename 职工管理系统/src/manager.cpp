#include "manager.h"

void Manager::showInfo()
{
    cout << "该职工的信息如下：" << endl;
    cout << "职工编号：" << m_id 
        << "\t姓名：" << m_name
        << "\t部门编号：" << m_deptid 
        << "\t岗位职责：完成老板交给的任务，并下发任务给员工 " << endl;

}

string Manager::getDeptname()
{
    return("经理");
}

Manager::Manager(string id, string name, int deptid)
{
    m_id = id;
    m_name = name;
    m_deptid = deptid;
}