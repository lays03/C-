### 3.8.1 set基本概念
简介：
- 所有元素都会在插入时自动被排序

本质：
- set/multiset属于关联式容器，底层结构是用二叉树实现

set和multiset区别：
- set不允许容器中有重复的元素
- multiset允许容器中有重复的元素

### 3.8.2 set构造和赋值
构造：
- set<T> st;
- set(const set &st);

赋值：
- set& operator(const set &st);
```cpp
void printSet(const set<int>& s)
{
    for(set<int>::const_iterator it = s.begin(); it != s.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    set<int> s1;
    //插入数据 只有insert方式
    s1.insert(10);
    s1.insert(40);
    s1.insert(30);
    s1.insert(20);
    s1.insert(30);

    //遍历容器
    //set容器特点：所有元素插入时候自动被排序
    //set容器不允许插入重复值
    printSet(s1); //10 20 30 40

    //拷贝构造
    set<int>s2(s1);
    printSet(s2);

    //赋值
    set<int>s3;
    s3 = s2;
    printSet(s3);
}
```

### 3.8.3 set大小和交换
函数原型：
- size();
- empty();
- swap(st);

### 3.8.4 set插入和删除
函数原型：
- insert(elem);
- clear();
- erase(pos);
- erase(beg, end);
- erase(elem); //删除容器中值为elem的元素

### 3.8.5 set查找和统计
函数原型：
- find(key); //查找key是否存在，若存在，返回该键的元素的迭代器；若不存在，返回set.end();
- count(key); //统计key元素的个数 (对于set而言，要么是0，要么是1)
```cpp
void test01()
{
    set<int> s1;

    //插入
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);

    //查找
    set<int>::iterator pos1 = s1.find(30);
    if(pos1 != s1.end())
    {
        cout << "找到元素: " << *pos1 << endl;
    }
    else
    {
        cout << "未找到元素" << endl;
    }

    set<int>::iterator pos2 = s1.find(100);
    if(pos2 != s1.end())
    {
        cout << "找到元素: " << *pos2 << endl;
    }
    else
    {
        cout << "未找到元素" << endl;
    }

    //统计
    cout << "元素40的个数为: " << s1.count(40) << endl;
    cout << "元素50的个数为: " << s1.count(50) << endl;
/*
找到元素: 30
未找到元素
元素40的个数为: 1
元素50的个数为: 0
*/
}
```

### 3.8.6 set和multiset区别
区别：
- set不可以插入重复数据，而multiset可以
- set插入数据的同时会返回插入结果，表示插入是否成功
- multiset不会检测数据，因此可以插入重复数据