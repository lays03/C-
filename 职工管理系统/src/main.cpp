#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "workerManage.h".
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

void test01()
{
    Worker *wk1 = new Employee("001", "刘静", 1);
    wk1->showInfo();
    cout << "该员工职级为：" << wk1->getDeptname() << endl;

    Worker *wk2 = new Manager("002", "刘静", 2);
    wk2->showInfo();
    cout << "该员工职级为：" << wk2->getDeptname() << endl;

    Worker *wk3 = new Boss("003", "刘静", 3);
    wk3->showInfo();
    cout << "该员工职级为：" << wk3->getDeptname() << endl;
}
int main()
{
    test01();
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
            wm.addWorker();
            //添加职工信息

        }
            break;
        case 2:
        {
            //显示职工信息

        }
            break;
        case 3:
        {
            //删除离职职工

        }
            break;
        case 4:
        {
            //修改职工信息

        }
            break;
        case 5:
        {
            //查找职工信息

        }
            break;
        case 6:
        {
            //按照编号排序

        }
        case 7:
        {
            //清空所有文档

        }
            break;
            break;
        default:
            break;
        }
    }
    
}
