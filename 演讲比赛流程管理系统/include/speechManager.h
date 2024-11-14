#pragma once
#include <iostream>
#include <vector>
#include "player.h"
using namespace std;

class SpeechManager
{
public:
    //构造函数
    SpeechManager();
    //析构函数
    ~SpeechManager();

public:
    //展示菜单
    void show_Menu();

    //第一轮抽签
    void first_Chouqian(vector<Player>& v);

    //打分
    void SetScore(vector<Player>& v);

    //分组 排序
    void MySort(vector<Player>& v);

    //打印第一轮比赛结果
    void show_first_result(vector<Player>& v1, vector<Player>& v2);

    //第二轮抽签
    void second_Chouqian(vector<Player>& v);

    //打印第二轮比赛结果
    void show_second_result(vector<Player>& v);

    //写文件
    void Save(const vector<Player>& v2);

    //读文件
    void Output();

    //清空比赛记录
    void Clear();
};