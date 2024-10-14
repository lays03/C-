#pragma once
#include<iostream>
using namespace std;

#include "worker.h"

class Boss : public Worker
{
public:
    //显示个人信息
    void showInfo();

    //获取岗位名称
    string getDeptname();

    string m_id; //职工编号
    string m_name; //职工姓名
    int m_deptid; //职工所在部门编号

    Boss(string id, string name, int deptid);
};