#pragma once
#include<iostream>
#include<cstring>


using namespace std;

class Player
{
public:
    int m_Index; //选手编号
    string m_Name; //选手姓名
    double m_Score; //选手得分
public:
    Player(int index, string name, double score);
    ~Player();
};