#include "workerManage.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include <fstream>

WorkerManager::WorkerManager()
{
    this->m_EmpNum = 0;
    this->m_EmpArray = NULL;
}

WorkerManager::~WorkerManager()
{
    
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

//退出程序
void WorkerManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}

//添加职工
void WorkerManager::addWorker()
{
    cout << "请输入需要添加职工的数量：";
    int addnum = 0;
    cin >> addnum;
    if(addnum > 0)
    {
        ofstream ofs;
        ofs.open("./Worker.txt", ios::out | ios::binary);
        //计算一下新的内存大小
        int newsize = this->m_EmpNum + addnum;

        //开辟新的空间
        Worker ** newSpace = new Worker*[newsize];

        //判断一下员工数组一开始是不是为空，如果不为空，需要把旧的数据移过来
        if(this->m_EmpArray != NULL)
        {
            for(int i = 0; i < this->m_EmpNum; ++i)
            {
                newSpace[i] = this->m_EmpArray[i];
                ofs.write((const char *)&*this->m_EmpArray[i], sizeof(*this->m_EmpArray[i]));
            }
        }
        //输入新的数据
        for(int i = 0; i < addnum; ++i)
        {
            Worker *wk = NULL;
            string id;
            string name;
            int deptid;
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
            switch (deptid)
            {
            case 1:
                wk = new Employee(id, name, deptid);
                break;
            case 2:
                wk = new Manager(id, name, deptid);
                break;
            case 3:
                wk = new Boss(id, name, deptid);
                break;

            default:
                break;
            }
            newSpace[this->m_EmpNum + i] = wk;
            ofs.write((const char *)&wk, sizeof(wk));
        }
        //释放原有的空间
        delete[] this->m_EmpArray;

        //更改新空间的指向
        this->m_EmpArray = newSpace;

        //更新新的个数
        this->m_EmpNum = newsize;

        //提示信息
        cout << "成功添加" << addnum << "名新职工！" << endl;
        ofs.close();
    }
    else
    {
        cout << "输入有误" << endl;
    }

    system("pause");
    system("cls");
}