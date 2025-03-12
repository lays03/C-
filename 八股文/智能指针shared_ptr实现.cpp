#include <iostream>
#include <string>
#include <memory>
using namespace std;

template<class T>
class SharedPtr
{
private:
    T* _ptr;
    int* _pcount; //指向引用计数的指针
public:
    //构造函数
    SharedPtr(T* ptr):_ptr(ptr), _pcount(new int(1))
    {

    }
    //拷贝构造函数
    SharedPtr(const SharedPtr& s):_ptr(s._ptr), _pcount(s._pcount)
    {
        (*_pcount)++;
    }
    //重载=
    SharedPtr<T>& operator=(const SharedPtr& s)
    {
        if(this != &s)
        {
            if(--(*(this->_pcount)) == 0)
            {
                delete this->_ptr;
                delete this->_pcount;
            }
            this->_ptr = s._ptr;
            this->_pcount = s._pcount;
            (*_pcount)++;
        }
    }
    T& operator*()
    {
        return *(this->_ptr);
    }
    T* operator->()
    {
        return this->_ptr;
    }

    void showPcount()
    {
        cout << *(this->_pcount) << endl;
    }

    ~SharedPtr()
    {
        --(*(this->_pcount));
        if(--(*(this->_pcount)) == 0)
        {
            delete this->_ptr;
            _ptr = NULL;
            delete this->_pcount;
            _pcount = NULL;
        }
    }
};

class Test
{
public:
    string m_name;
public:
    Test(string name):m_name(name)
    {
        cout << m_name << " constructor" << endl;
    }
    ~Test()
    {
        cout << m_name << " destructor" << endl;
    }

};


int main()
{
    SharedPtr<Test> p1 = new Test("object");
    cout << p1->m_name << endl;
    p1.showPcount();
    SharedPtr<Test> p2(p1);
    cout << p1->m_name << endl;
    cout << p2->m_name << endl;
    p1.showPcount();
    p2.showPcount();
    return 0;
}