#include<iostream>
#include<string>
using namespace std;

//函数的默认参数
//如果我们自己传入数据，就用自己的数据，如果没有，那么用默认值
int func(int a , int b, int c = 30){
    return a + b + c;
}
/*
注意事项：
1、如果某个位置已经有了默认参数，那么从这个位置往后，从左往右都必须有默认值
比如上述函数b给了默认值，那么c必须要有默认值
int func(int a , int b = 10, int c){
    return a + b + c;
}
2、如果函数声明有默认参数，函数实现就不能有默认参数
int func2(int a = 10, int b = 10);
int func2(int a = 10, int b = 10){
    return a + b;
}
调用func2的时候就会报错，func2重定义默认参数
*/

int main(){
    cout << func(10, 30) << endl;
    return 0;
}