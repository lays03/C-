#pragma once //防止头文件重复包含
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#define FILENAME "empFile.txt"

class WorkerManager
{
public:
    int m_EmpNum; //记录文件中人的个数
    Worker ** m_EmpArray; //员工数组的指针

    //构造函数
    WorkerManager();

    //析构函数
    ~WorkerManager();

    //展示菜单
    void Show_Menu();

    //退出程序
    void exitSystem();

    //添加成员
    void addEmp();

    //保存文件
    void save();

    //输出文件
    void showfile();

};