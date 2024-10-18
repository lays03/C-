#include "workerManage.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include <fstream>
#include<iostream>
#include<string>


WorkerManager::WorkerManager()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    //1. 文件不存在
    if(!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    //2. 文件存在且数据为空
    char ch;
    ifs >> ch;
    if(ifs.eof())
    {
        cout << "文件为空!" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    //3. 文件存在且保存职工数据
    this->m_FileIsEmpty = false;
    this->m_EmpNum = this->get_EmpNum();
    this->m_EmpArray = new Worker*[this->m_EmpNum];
    this->init_Emp();
    cout << "一共有" << this->m_EmpNum << "名职工" << endl;
}

//获取员工数量
int WorkerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if(!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        ifs.close();
    }
    int num = 0;
    int id;
    string name;
    int deptid;
    while(ifs >> id && ifs >> name && ifs >> deptid)
    {
        num++;
    }
    return num;
}

//初始化
void WorkerManager::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if(!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        ifs.close();
        return;
    }
    int id;
    string name;
    int deptid;
    int index = 0;
    while(ifs >> id && ifs >> name && ifs >> deptid)
    {
        Worker *worker = NULL;
        if(deptid == 1)
        {
            worker = new Employee(id, name, deptid);
        }
        else if(deptid == 2)
        {
            worker = new Manager(id, name, deptid);
        }
        else
        {
            worker = new Boss(id, name, deptid);
        }
        this->m_EmpArray[index++] = worker;
    }
    cout << "初始化完成" << endl;
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
    ofs.open(FILENAME, ios::out);
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
            
            //职工编号为唯一的，不能重复，因此需要判断一下
            while(cin >> id)
            {
                bool IsSame = false; //判断一次输入过程中职工编号有没有重复
                for(int j = 0; j < i; ++j)
                {
                    if(newSpace[this->m_EmpNum + j]->m_id != id) //一次添加过程中，此次添加的和之前已经添加过的都没有重复的
                    {
                        continue;
                    }
                    else //重复了
                    {
                        IsSame = true;
                        break;
                    }
                }
                //表示此次添加的编号和这一轮添加的编号没有重复
                //那么就需要判断有没有和文件里面的内容重复
                if(IsSame == false)
                {
                    //返回-1表示没有跟文件里面的内容重复
                    if(IsExist(id) == -1)
                    {
                        break;
                    }
                    cout << "该编号职工文件中已存在，请重新输入" << endl;
                    cout << "请重新输入第" << i + 1 << "个新职工编号：";
                }
                else //如果此次添加的编号和这一轮之前添加的编号有重复，则直接要求重新输入
                {
                    cout << "该编号重复输入，请重新输入" << endl;
                    cout << "请重新输入第" << i + 1 << "个新职工编号：";
                }
            }

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

        this->m_FileIsEmpty = false;

        //提示信息
        cout << "成功添加" << addnum << "名新职工！" << endl;
        //保存文件
        this->save();

    }
    else
    {
        cout << "输入有误" << endl;
    }
    system("pause");
    system("cls");
}

//显示职工信息
void WorkerManager::Show_Emp()
{
    cout << "-------------------------------------------------" << endl;
    cout << "| 当前一共有" << this->m_EmpNum << "名职工" << endl;
    cout << "-------------------------------------------------" << endl;
    for(int i = 0; i < this->m_EmpNum; ++i)
    {
        cout << "| 职工号:" << this->m_EmpArray[i]->m_id
            << "\t职工姓名:" << this->m_EmpArray[i]->m_name
            << "\t部门编号: " << this->m_EmpArray[i]->m_deptid << endl;
    }
    cout << "-------------------------------------------------" << endl;
    system("pause");
    system("cls");
}

//判断职工是否存在
int WorkerManager::IsExist(int id)
{
    for(int i = 0; i < this->m_EmpNum; ++i)
    {
        if(this->m_EmpArray[i]->m_id == id)
        {
            return i;
        }
    }
    return -1;
}

//删除职工信息
void WorkerManager::Del_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout << "文件不存在或为空" << endl;
    }
    else{
        int id;
        cout << "请输入想要删除的职工的编号: " << endl;
        cin >> id;
        int index = IsExist(id); //返回想要删除的职工在员工数组中的序号
        if(index != -1) //该id存在
        {
            for(int i = index; i < this->m_EmpNum - 1; ++i)
            {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpArray[this->m_EmpNum - 1] = NULL;
            this->m_EmpNum--;
            cout << "删除完成" << endl;
            this->save();
        }
        else
        {
            cout << "该职工不存在" << endl;
        }
    }
        system("pause");
        system("cls");
}

//修改职工信息
void WorkerManager::Mod_Emp()
{
    //首选判断有没有职工
    if(this->m_FileIsEmpty)
    {
        cout << "文件不存在或为空" << endl;
    }
    else
    {
        int id = 0;
        cout << "请输入想要修改的职工的编号: " << endl;
        cin >> id;
        int index = IsExist(id); //返回想要修改的职工在员工数组中的序号
        if(index != -1) //该id存在
        {
            int new_id = 0;
            string new_name;
            int new_deptid = 0;
            while(1)
            {
                cout << "--- 请选择修改的内容 ---" << endl;
                cout << "--- 0. 退出修改 ---" << endl;
                cout << "--- 1. 职工编号 ---" << endl;
                cout << "--- 2. 职工姓名 ---" << endl;
                cout << "--- 3. 部门编号 ---" << endl;
                int choice;
                cin >> choice;
                switch (choice)
                {
                case 0:
                    {
                        cout << "退出修改" << endl;
                    }
                    break;
                case 1:
                    {
                        cout << "请输入新职工编号：" << endl;
                        //职工编号为唯一的，不能重复，因此需要判断一下
                        while(cin >> new_id)
                        {
                            //返回-1表示没有重复
                            if(IsExist(new_id) == -1) break;
                            cout << "该编号已存在，请重新输入" << endl;
                            cout << "请重新输入新职工编号：";
                        }
                        int temp = this->m_EmpArray[index]->m_id;
                        this->m_EmpArray[index]->m_id = new_id;
                        cout << "修改成功：" << temp << " ===> " << this->m_EmpArray[index]->m_id << endl;
                        this->save();
                    }
                    break;
                case 2:
                    {
                        cout << "请输入新职工姓名: " << endl;
                        cin >> new_name;
                        string temp = this->m_EmpArray[index]->m_name;
                        this->m_EmpArray[index]->m_name = new_name;
                        cout << "修改成功：" << temp << " ===> " << this->m_EmpArray[index]->m_name << endl;
                        this->save();
                    }
                    break;
                case 3:
                    {
                        cout << "请输入新部门编号: " << endl;
                        cin >> new_deptid;
                        int temp = this->m_EmpArray[index]->m_deptid;
                        this->m_EmpArray[index]->m_deptid = new_deptid;
                        cout << "修改成功：" << temp << " ===> " << this->m_EmpArray[index]->m_deptid << endl;
                        this->save();
                    }
                    break;
                default:
                    break;
                }
                break;
            }
            cout << "修改完成" << endl;
            this->save();
        }
        else
        {
            cout << "该职工不存在" << endl;
        }
    }
    system("pause");
    system("cls");
}

//查找职工
void WorkerManager::Find_Emp()
{
    //首选判断有没有职工
    if(this->m_FileIsEmpty)
    {
        cout << "文件不存在或为空" << endl;
    }
    else
    {
        while (1)
        {
            int choice = 0;
            cout << "--- 请选择查找职工的方式 ---" << endl;
            cout << "--- 0. 退出查找 ---" << endl;
            cout << "--- 1. 按照职工编号 ---" << endl;
            cout << "--- 2. 按照职工姓名 ---" << endl;
            cin >> choice;
            switch (choice)
            {
            case 0:
                {
                    cout << "退出查找" << endl;
                }
                break;
            case 1:
                {
                    int id = 0;
                    cout << "请输入职工编号, 以进行查找: " << endl;
                    cin >> id;
                    int index = IsExist(id);
                    if(index != -1) //该id存在
                    {
                        cout << "查找成功! 该职工的信息为: " << endl;
                        cout << "职工编号: " << this->m_EmpArray[index]->m_id << endl;
                        cout << "职工姓名: " << this->m_EmpArray[index]->m_name << endl;
                        cout << "部门编号: " << this->m_EmpArray[index]->m_deptid << endl;
                    }
                    else
                    {
                        cout << "查找失败, 暂无职工编号为 " << id << " 的员工" << endl;
                    }
                }
                break;
            
            case 2:
                {
                    string name;
                    cout << "请输入职工姓名, 以进行查找: " << endl;
                    cin >> name;
                    Worker *temp_worker[this->m_EmpNum];
                    int counter = 0;
                    for(int i = 0; i < this->m_EmpNum; ++i)
                    {
                        if(this->m_EmpArray[i]->m_name == name)
                        {
                            temp_worker[counter++] = this->m_EmpArray[i];
                        }
                    }
                    if(counter == 0)
                    {
                        cout << "查找失败, 暂无职工姓名为 " << name << " 的员工" << endl;
                    }
                    else
                    {
                        cout << "查找成功! 共有" << counter << "名, 名为" << name << "的员工" << endl;
                        for(int i = 0; i < counter; ++i)
                        {
                            cout << "------------------------------" << endl;
                            cout << "第" << i + 1 << "位员工信息为: " << endl;
                            cout << "职工编号: " << temp_worker[i]->m_id << endl;
                            cout << "职工姓名: " << temp_worker[i]->m_name << endl;
                            cout << "部门编号: " << temp_worker[i]->m_deptid << endl;
                            cout << "------------------------------" << endl;
                        }
                    }
                }
                break;
            default:
                break;
            }
            break;
        }
    }
    system("pause");
    system("cls");
}

//排序职工
void WorkerManager::Sort_Emp()
{
    //首选判断有没有职工
    if(this->m_FileIsEmpty)
    {
        cout << "文件不存在或为空" << endl;
    }
    else
    {
        while (1)
        {
            int choice = 0;
            cout << "--- 请选择进行排序的方式 ---" << endl;
            cout << "--- 0. 退出排序 ---" << endl;
            cout << "--- 1. 按照职工编号升序排序 ---" << endl;
            cout << "--- 2. 按照职工编号降序排序 ---" << endl;
            cin >> choice;
            switch (choice)
            {
                case 0:
                    {
                        cout << "退出排序" << endl;
                    }
                    break;
                case 1:
                    {
                        for(int i = 0; i < this->m_EmpNum - 1; ++i)
                        {
                            for(int j = 0; j < this->m_EmpNum - i - 1; ++j)
                            {
                                if(this->m_EmpArray[j]->m_id > this->m_EmpArray[j+1]->m_id)
                                {
                                    Worker *temp;
                                    temp = this->m_EmpArray[j];
                                    this->m_EmpArray[j] = this->m_EmpArray[j+1];
                                    this->m_EmpArray[j+1] = temp;
                                }
                            }
                        }
                        cout << "按照职工编号升序排序成功" << endl;
                        this->save();
                    }
                    break;
                case 2:
                    {
                        for(int i = 0; i < this->m_EmpNum - 1; ++i)
                        {
                            for(int j = 0; j < this->m_EmpNum - i - 1; ++j)
                            {
                                if(this->m_EmpArray[j]->m_id < this->m_EmpArray[j+1]->m_id)
                                {
                                    Worker *temp;
                                    temp = this->m_EmpArray[j];
                                    this->m_EmpArray[j] = this->m_EmpArray[j+1];
                                    this->m_EmpArray[j+1] = temp;
                                }
                            }
                        }
                        cout << "按照职工编号降序排序成功" << endl;
                        this->save();
                    }
                    break;
                default:
                    break;
            }
            break;
        }
    }
    system("pause");
    system("cls");
}

//清空文件
void WorkerManager::Clean_File()
{
    cout << "--- 确认清空? ---" << endl;
    cout << "--- 1. 确认 ---" << endl;
    cout << "--- 2. 返回 ---" << endl;
    int choice;
    cin >> choice;
    if(choice == 1)
    {
        //打开模式 ios::trunc 如果文件存在，先删除，再重建
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();
        if(this->m_EmpArray != NULL)
        {
            for(int i = 0; i < this->m_EmpNum; ++i)
            {
                if(this->m_EmpArray[i] != NULL)
                {
                    // delete this->m_EmpArray[i];
                    this->m_EmpArray[i] = NULL;
                }
            }
            this->m_EmpNum = 0;
            delete[] this->m_EmpArray;
            this->m_FileIsEmpty = true;
        }
        cout << "清空成功!" << endl;
    }
    system("pause");
    system("cls");
}