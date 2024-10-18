#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "workerManage.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

// void test01()
// {
//     Worker *wk1 = new Employee("001", "刘静", 1);
//     cout << "职工编号：" << wk1->m_id
//          << "\t姓名: " << wk1->m_name
//          << "\t部门编号: " << wk1->m_deptid << endl;
//     delete wk1;

//     Worker *wk2 = new Manager("002", "方清", 2);
//     cout << "职工编号：" << wk2->m_id
//          << "\t姓名: " << wk2->m_name
//          << "\t部门编号: " << wk2->m_deptid << endl;
//     delete wk2;
// }

int main()
{
    // test01();
    WorkerManager wm;
    int choice = 0;

    while (true)
    {
        //展示菜单
        wm.Show_Menu();
        cout << "请输入您的选择：";
        cin >> choice;
        switch (choice)
        {
        case 0: //退出系统
            wm.exitSystem();
            break;
        case 1:
        {
            //添加职工信息
            wm.addEmp();
        }
            break;
        case 2:
        {
            //显示职工信息
            wm.Show_Emp();
        }
            break;
        case 3:
        {
            //删除离职职工
            wm.Del_Emp();
        }
            break;
        case 4:
        {
            //修改职工信息
            wm.Mod_Emp();
        }
            break;
        case 5:
        {
            //查找职工信息
            wm.Find_Emp();
        }
            break;
        case 6:
        {
            //按照编号排序
            wm.Sort_Emp();
        }
            break;
        case 7:
        {
            //清空所有文档
            wm.Clean_File();
        }
            break;
        default:
            break;
        }
    }
    
}
