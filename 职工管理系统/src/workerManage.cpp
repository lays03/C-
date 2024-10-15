#include "workerManage.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include <fstream>
#include<iostream>
#include<string>


WorkerManager::WorkerManager()
{
    this->m_EmpNum = 0;
    this->m_EmpArray = NULL;
}

WorkerManager::~WorkerManager()
{
    if(this->m_EmpArray != NULL)
    {
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}

void WorkerManager::Show_Menu()
{
    cout << "----------------------------------" << endl;
    cout << "------ 欢迎使用职工管理系统 ------" << endl;
    cout << "--------- 0.退出管理程序 ---------" << endl;
    cout << "--------- 1.增加职工信息 ---------" << endl;
    cout << "--------- 2.显示职工信息 ---------" << endl;
    cout << "--------- 3.删除离职职工 ---------" << endl;
    cout << "--------- 4.修改职工信息 ---------" << endl;
    cout << "--------- 5.查找职工信息 ---------" << endl;
    cout << "--------- 6.按照编号排序 ---------" << endl;
    cout << "--------- 7.清空所有文档 ---------" << endl;
    cout << "----------------------------------" << endl;
    cout << endl;
}

//文件存储
void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::app);
    cout << "一共有" << this->m_EmpNum << "名员工" << endl;
    for(int i = 0; i < this->m_EmpNum; ++i)
    {
        
        ofs << this->m_EmpArray[i]->m_id << "\t"
            << this->m_EmpArray[i]->m_name << "\t"
            << this->m_EmpArray[i]->m_deptid << endl;
    }
    ofs.close();
}

//退出程序
void WorkerManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}

//添加职工
void WorkerManager::addEmp()
{
    cout << "请输入需要添加职工的数量：";
    int addnum = 0; //保存用户的输入数量
    cin >> addnum;
    if(addnum > 0) //添加
    {
        //计算添加新空间大小
        int newsize = this->m_EmpNum + addnum;

        //开辟新的空间
        Worker ** newSpace = new Worker*[newsize];

        //将原来空间下数据，拷贝到新空间下
        //判断一下员工数组一开始是不是为空，如果不为空，需要把旧的数据移过来
        if(this->m_EmpArray != NULL)
        {
            for(int i = 0; i < this->m_EmpNum; ++i)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        //批量添加新的数据
        for(int i = 0; i < addnum; ++i)
        {
            
            int id; //职工编号
            string name; //职工姓名
            int deptid; //部门编号

            cout << "请输入第" << i + 1 << "个新职工编号：";
            cin >> id;

            cout << "请输入第" << i + 1 << "个新职工姓名：";
            cin >> name;

            cout << "-------------" << endl;
            cout << "请选择该职工岗位：" << endl;
            cout << "-------------" << endl;
            cout << "1、普通员工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cout << "-------------" << endl;
            cin >> deptid;

            Worker * worker = NULL;
            switch (deptid)
            {
            case 1:
                {
                    worker = new Employee(id, name, deptid);
                }
                
                break;
            case 2:
                {
                    worker = new Manager(id, name, deptid);
                }
                break;
            case 3:
                {
                    worker = new Boss(id, name, deptid);
                }
                break;
            default:
                break;
            }
            //将创建的worker *添加到数组中
            newSpace[this->m_EmpNum + i] = worker;
            worker->showInfo();
            
        }
        //释放原有的空间
        delete[] this->m_EmpArray;

        //更改新空间的指向
        this->m_EmpArray = newSpace;

        //更新新的个数
        this->m_EmpNum = newsize;

        //提示信息
        cout << "成功添加" << addnum << "名新职工！" << endl;
        //保存文件
        this->save();

        //输出文件
        this->showfile();
    }
    else
    {
        cout << "输入有误" << endl;
    }
    system("pause");
    system("cls");
}