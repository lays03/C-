#include "employee.h"

void Employee::showInfo()
{
    cout << "该职工的信息如下：" << endl;
    cout << "职工编号：" << this->m_id 
        << "\t姓名: " << this->m_name
        << "\t部门编号: " << this->m_deptid
        << "\t岗位职责: 完成经理交给的任务" << endl;

}

string Employee::getDeptname()
{
    return("普通员工");
}

Employee::Employee(int id, string name, int deptid)
{
    this->m_id = id;
    this->m_name = name;
    this->m_deptid = deptid;
}