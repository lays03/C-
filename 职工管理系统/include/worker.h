#pragma once
#include<iostream>
using namespace std;

class Worker
{
public:
    //显示个人信息
    virtual void showInfo() = 0;

    //获取岗位名称
    virtual string getDeptname() = 0;

    string m_id; //职工编号
    string m_name; //职工姓名
    int m_deptid; //职工所在部门编号
};
