#include <iostream>
#include <string>
using namespace std;

//动物类
class Animal
{
public:
    //纯虚函数
    virtual void speak() = 0;

    Animal()
    {
        cout << "Animal构造函数调用" << endl;
    }
    //利用虚析构可以解决 父类指针释放子类对象时不干净的问题
    // virtual ~Animal() 
    // {
    //     cout << "Animal析构函数调用" << endl;
    // }
    //纯虚析构 这个函数也需要实现 因为父类也有可能在堆区有数据需要delete
    //有了纯虚析构之后，这个类也属于抽象类，无法实例化对象
    virtual ~Animal() = 0;
};

//Animal下的纯虚析构
Animal::~Animal()
{
    cout << "Animal纯虚析构调用" <<endl;
} 

//猫类
class Cat :public Animal
{
public:
    void speak()
    {
        cout << *m_Name << "小猫在说话" << endl;
    }
    string *m_Name;
    Cat(string name)
    {
        cout << "Cat构造函数调用" << endl;
        m_Name = new string(name);
    }
    ~Cat()
    {
        if(m_Name != NULL)
        {
            cout << "Cat析构函数调用" << endl;
            delete m_Name;
        }
    }
};

//执行说话的函数
//函数地址早绑定 编译阶段就确认了函数的地址
//如果想执行让猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定
void doSpeak(Animal &animal) //Animal &animal = cat;
{
    animal.speak(); 
}

void test01()
{
    Animal * animal = new Cat("刘静");
    animal->speak();
    //父类指针在析构时候 不会调用子类中析构函数，导致子类如果有堆区属性，出现内存泄漏
    delete animal;

}

int main()
{
    test01();
}