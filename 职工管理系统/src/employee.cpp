#include "employee.h"

void Employee::showInfo()
{
    cout << "该职工的信息如下：" << endl;
    cout << "职工编号：" << m_id 
        << "\t姓名：" << m_name
        << "\t部门编号：" << m_deptid
        << "\t岗位职责：完成经理交给的任务" << endl;

}

string Employee::getDeptname()
{
    return("普通员工");
}

Employee::Employee(string id, string name, int deptid)
{
    m_id = id;
    m_name = name;
    m_deptid = deptid;
}