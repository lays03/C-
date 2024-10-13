#include <iostream>
#include <string>
using namespace std;

/*
案例描述：
电脑主要组成部件为CPU(用于计算)，显卡(用于显示)，内存条(用于存储)
将每个零件封装出抽象基类，并且提供不同的厂商生产不同的零件，例如Intel厂商和Lenovo厂商
创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口
测试时组装三台不同的电脑进行工作
*/

//抽象的CPU类
class CPU
{
public:
    virtual void calculator() = 0;
};

//抽象的显卡类
class VideoCard
{
public:
    virtual void display() = 0;
};

//抽象的内存条类
class MemoryCard
{
public:
    virtual void storage() = 0;
};

//电脑类 电脑需要三个零件，因此在构造的时候需要传入参数
class Computer
{
private:
    CPU *m_cpu;
    VideoCard *m_vc;
    MemoryCard *m_mem;
public:
    Computer(CPU *cpu, VideoCard *vc, MemoryCard *mem)
    {
        m_cpu = cpu;
        m_vc = vc;
        m_mem = mem;
    }
    void work()
    {
        m_cpu->calculator();
        m_vc->display();
        m_mem->storage();
    }
    ~Computer()
    {
        if(m_cpu != NULL)
        {
            delete m_cpu;
        }
        if(m_vc != NULL)
        {
            delete m_vc;
        }
        if(m_mem != NULL)
        {
            delete m_mem;
        }
    }
};

//Intel厂商
class IntelCPU : public CPU
{
public:
    void calculator()
    {
        cout << "Intel的CPU开始计算了" << endl;
    }
};

class IntelVideoCard : public VideoCard
{
public:
    void display()
    {
        cout << "Intel的显卡开始工作了" << endl;
    }
};

class IntelMemoryCard : public MemoryCard
{
public:
    void storage()
    {
        cout << "Intel的内存条开始存储了" << endl;
    }
};

//Lenovo厂商
class LenovoCPU : public CPU
{
public:
    void calculator()
    {
        cout << "Lenovo的CPU开始计算了" << endl;
    }
};

class LenovoVideoCard : public VideoCard
{
public:
    void display()
    {
        cout << "Lenovo的显卡开始工作了" << endl;
    }
};

class LenovoMemoryCard : public MemoryCard
{
public:
    void storage()
    {
        cout << "Lenovo的内存条开始存储了" << endl;
    }
};

void test01()
{
    //父类的指针指向子类的对象
    CPU *cpu = new IntelCPU;
    VideoCard *vc = new IntelVideoCard;
    MemoryCard *mem = new IntelMemoryCard;

    cout << "------------------" << endl;
    cout << "第一台电脑开始工作了" << endl;
    //computer的构造函数，传进去的其实是子类的对象，因此调用各自子类的函数
    Computer * c1 = new Computer(cpu, vc, mem);
    c1->work();

    cout << "------------------" << endl;
    cout << "第二台电脑开始工作了" << endl;
    //computer的构造函数，传进去的其实是子类的对象，因此调用各自子类的函数
    Computer * c2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemoryCard);
    c2->work();

    cout << "------------------" << endl;
    cout << "第三台电脑开始工作了" << endl;
    //computer的构造函数，传进去的其实是子类的对象，因此调用各自子类的函数
    Computer * c3 = new Computer(new IntelCPU, new LenovoVideoCard, new IntelMemoryCard);
    c3->work();


}


int main()
{
    test01();
}