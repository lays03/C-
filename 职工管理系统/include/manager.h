#pragma once
#include<iostream>
using namespace std;

#include "worker.h"

class Manager : public Worker
{
public:
    //显示个人信息
    void showInfo();

    //获取岗位名称
    string getDeptname();

    Manager(int id, string name, int deptid);
};