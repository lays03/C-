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
    bool m_FileIsEmpty;

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

    //获取员工数量
    int get_EmpNum();

    //初始化员工数组
    void init_Emp();

    //显示职工信息
    void Show_Emp();

    //判断职工是否存在
    int IsExist(int id);

    //删除职工信息
    void Del_Emp();

    //修改职工信息
    void Mod_Emp();

    //查找职工
    void Find_Emp();

    //排序职工
    void Sort_Emp();

    //清空文件
    void Clean_File();




};