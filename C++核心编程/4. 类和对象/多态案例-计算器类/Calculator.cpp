#include <iostream>
#include <string>
using namespace std;
//利用多态实现计算器
class AbstractCalculator
{
public:
    virtual int getResult()
    {
        return 0;
    }
    int m_Num1;
    int m_Num2;
};

//加法
class AddCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 + m_Num2;
    }
};

//减法
class SubCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 - m_Num2;
    }
};

//乘法
class MulCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 * m_Num2;
    }
};

//除法
class DivCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        if(m_Num2 != 0)
        {
            return m_Num1 / m_Num2;
        }
        return 0;
    }
};

int dogetResult(AbstractCalculator &abc)
{
    return abc.getResult();
}

void test01()
{
    //多态使用条件
    //父类指针或者引用指向子类对象

    //加法运算
    AbstractCalculator * abc = new AddCalculator; //创建父类的指针指向子类的对象
    abc->m_Num1 = 10;
    abc->m_Num2 = 20;
    cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
    //用完后记得销毁
    delete abc;

    //减法运算
    abc = new SubCalculator; //创建父类的指针指向子类的对象
    abc->m_Num1 = 10;
    abc->m_Num2 = 20;
    cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
    //用完后记得销毁
    delete abc;

    //乘法运算
    abc = new MulCalculator; //创建父类的指针指向子类的对象
    abc->m_Num1 = 10;
    abc->m_Num2 = 20;
    cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
    //用完后记得销毁
    delete abc;

    //除法运算
    abc = new DivCalculator; //创建父类的指针指向子类的对象
    abc->m_Num1 = 100;
    abc->m_Num2 = 20;
    cout << abc->m_Num1 << " / " << abc->m_Num2 << " = " << abc->getResult() << endl;
    //用完后记得销毁
    delete abc;

}

int main()
{
    test01();

}