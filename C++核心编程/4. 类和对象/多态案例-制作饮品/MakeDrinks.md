案例描述：<br>
制作饮品的大致流程为：煮水 - 冲泡 - 倒入杯中 - 加入辅料

利用多态技术实现本案例，提供抽象制作饮品基类，提供子类制作咖啡和茶叶

```cpp
#include <iostream>
#include <string>
using namespace std;

class Drinks
{
public:
    //煮水
    virtual void boilwater() = 0;

    //冲泡
    virtual void brew() = 0;

    //倒入杯中
    virtual void pourintocup() = 0;

    //加入辅料
    virtual void AddAccessories() = 0;

    void makeDrink()
    {
        boilwater();
        brew();
        pourintocup();
        AddAccessories();
    }
};

class Coffee : public Drinks
{
public:
    void boilwater()
    {
        cout << "煮水" << endl;
    }
    void brew()
    {
        cout << "冲泡咖啡" << endl;
    }
    void pourintocup()
    {
        cout << "倒入杯中" << endl;
    }
    void AddAccessories()
    {
        cout << "加糖和牛奶" << endl;
    }
};

class Tea : public Drinks
{
public:
    void boilwater()
    {
        cout << "煮水" << endl;
    }
    void brew()
    {
        cout << "冲泡茶叶" << endl;
    }
    void pourintocup()
    {
        cout << "倒入杯中" << endl;
    }
    void AddAccessories()
    {
        cout << "加柠檬" << endl;
    }
};

void doWork(Drinks * drink)
{
    drink->makeDrink();
    delete drink;
}

void test01()
{
    doWork(new Coffee);

    cout << "--------------" << endl;

    doWork(new Tea);

}

int main()
{
    test01();
}
```