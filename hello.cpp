#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//string获取子串
void test01()
{
    string str = "abcdef";
    string subStr = str.substr(1, 3);
    cout << "subStr = " << subStr << endl;
    //subStr = bcd
}

//实用操作
void test02()
{
    string email = "zhangsan@sina.com";

    //从邮件中 获取 用户名信息
    int pos = email.find("@");
    cout << "pos = " << pos << endl;
    //pos = 8

    string usrName = email.substr(0, pos);
    cout << "usrName = " << usrName << endl;
    //usrName = zhangsan
}

int main()
{
    test01();
    test02();
}