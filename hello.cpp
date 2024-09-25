#include<iostream>
#include<string>
using namespace std;

//1、引用作为重载条件
void func(int &a){
    cout << "func(int &a)调用" << endl;
}

void func(const int &a){
    cout << "func(const int &a)调用" << endl;
}


//2、函数重载碰到函数默认参数
void func2(int a){
    cout << "func(int a)调用" << endl;
}

void func2(int a, int b = 20){
    cout << "func2(int a, int b = 20)调用" << endl;
}


int main(){
    func2(10, 20);
    return 0;
}