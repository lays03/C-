#include "speechManager.h"
#include "player.h"

#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>
#include <deque>
#include <fstream>

SpeechManager::SpeechManager(){}

SpeechManager::~SpeechManager(){}

//打印菜单
void SpeechManager::show_Menu()
{
    cout << "-------------------------------" << endl;
    cout << "------- 欢迎参加演讲比赛 -------" << endl;
    cout << "------- 1. 开始演讲比赛  -------" << endl;
    cout << "------- 2. 查看往届记录  -------" << endl;
    cout << "------- 3. 清空比赛记录  -------" << endl;
    cout << "------- 0. 退出比赛程序  -------" << endl;
    cout << "-------------------------------" << endl;
}

//打印vector
void printVector(const vector<Player>& v)
{
    for(vector<Player>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << "编号" << it->m_Index << "\t姓名: " << it->m_Name
            << "\t成绩: " << it->m_Score << endl;
    }
}

//第一轮抽签
void SpeechManager::first_Chouqian(vector<Player>& v)
{
    srand((unsigned)time(NULL));
    cout << "第 << 1 >> 轮比赛选手正在抽签" << endl;
    random_shuffle(v.begin(), v.end());
    cout << "---------------------------" << endl;
    cout << "抽签后演讲顺序如下: " << endl;
    for(vector<Player>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << it->m_Index << " ";
    }
    cout << endl;
    cout << "---------------------------" << endl;
    system("pause");
}

//按照成绩降序排列
class MyCompare
{
public:
    bool operator()(Player &p1, Player &p2)
    {
        return p1.m_Score > p2.m_Score;
    }
};

//打分
void SpeechManager::SetScore(vector<Player>& v)
{
    srand((unsigned)time(NULL));
    
    int temp_score = 0; //打分
    
    //评委打分完毕
    for(vector<Player>::iterator it = v.begin(); it != v.end(); ++it)
    {
        deque<int> d; //用来保存10位评委的评分
        double score = 0; //最终得分
        for(int i = 0; i < 10; ++i)
        {
            temp_score = 60 + rand() % 41;
            d.push_back(temp_score);
        }
        sort(d.begin(), d.end());
        d.pop_back(); //去掉一个最高分
        d.pop_front(); //去掉一个最低分
        for(deque<int>::iterator dit = d.begin(); dit != d.end(); ++dit)
        {
            score += *dit;
        }
        score /= 8;
        it->m_Score = score;
    }
}

//分组  排序
void SpeechManager::MySort(vector<Player>& v)
{
    //对结果需要进行排序 按照选手得分进行降序排序
    //排序之前先要将12个人分成两组，每组6个人，组内进行排序
    vector<Player>::iterator it = v.begin();
    for(int i = 0; i < 6; ++i)
    {
        it++;
    }
    sort(v.begin(), it, MyCompare()); //对1-6名进行排序
    
    sort(it, v.end(), MyCompare()); //对7-12名进行排序
}

//打印第一轮比赛结果 并淘汰每组最后三名选手
void SpeechManager::show_first_result(vector<Player>& v1, vector<Player>& v2)
{
    cout << "------- 第1轮比赛正式开始 -------" << endl;
    cout << "第1小组比赛名次: " << endl;
    vector<Player>::iterator it = v1.begin();
    for(int i = 0; i < 6; ++i)
    {
        if(i < 3) //每一组的前三名晋级
        {
            v2.push_back(*it); 
        }
        cout << "编号" << it->m_Index << "\t姓名: " << it->m_Name
            << "\t成绩: " << it->m_Score << endl;
        it++;
    }
    cout << endl;

    cout << "第2小组比赛名次: " << endl;
    for(int i = 0; i < 6; ++i)
    {
        if(i < 3) //每一组的前三名晋级
        {
            v2.push_back(*it);
        }
        cout << "编号" << it->m_Index << "\t姓名: " << it->m_Name
            << "\t成绩: " << it->m_Score << endl;
        it++;
    }
    cout << endl;
    cout << "------- 第1轮比赛完毕 -------" << endl;
    system("pause");
    cout << "------- 第1轮晋级选手信息如下: -------" << endl;
    for(vector<Player>::iterator it = v2.begin(); it != v2.end(); ++it)
    {
        cout << "编号" << it->m_Index << "\t姓名: " << it->m_Name
            << "\t成绩: " << it->m_Score << endl;
    }
    cout << endl;
    system("pause");
}

//第二轮抽签
void SpeechManager::second_Chouqian(vector<Player>& v)
{
    srand((unsigned)time(NULL));
    cout << "第 << 2 >> 轮比赛选手正在抽签" << endl;
    random_shuffle(v.begin(), v.end());
    cout << "---------------------------" << endl;
    cout << "抽签后演讲顺序如下: " << endl;
    for(vector<Player>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << it->m_Index << " ";
    }
    cout << endl;
    cout << "---------------------------" << endl;
    system("pause");
}

//打印第二轮比赛结果
void SpeechManager::show_second_result(vector<Player>& v)
{
    sort(v.begin(), v.end(), MyCompare()); 
    cout << "------- 第2轮比赛正式开始 -------" << endl;
    cout << "第1小组比赛名次: " << endl;
    printVector(v);
    cout << endl;
    cout << "------- 第2轮比赛完毕 -------" << endl;

    v.pop_back();
    v.pop_back();
    v.pop_back();
    system("pause");
    cout << "------- 第2轮晋级选手信息如下: -------" << endl;
    for(vector<Player>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << "编号" << it->m_Index << "\t姓名: " << it->m_Name
            << "\t成绩: " << it->m_Score << endl;
    }
    system("pause");
}

//保存文件
void SpeechManager::Save(const vector<Player>& v)
{
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app);
    for(vector<Player>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        ofs << it->m_Index << "," << it->m_Score << ",";
    }
    ofs << endl;
    ofs.close();
    cout << "记录已经保存" << endl;
    cout << "本届比赛完毕!" << endl;
    system("pause");
}

//读文件
void SpeechManager::Output()
{
    ifstream ifs;
    ifs.open("speech.csv", ios::in);
    if(!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
    }
    string buf;
    int counter = 1; //记录一共有多少行
    while(getline(ifs, buf))
    {
        string index;
        string score;
        for(int i = 0; i < 3; ++i)
        {
            
            int pos = buf.find(',');
            index = buf.substr(0, pos);
            buf = buf.erase(0, pos + 1);

            pos = buf.find(',');
            score = buf.substr(0, pos);
            buf = buf.erase(0, pos + 1);
            
            if(i == 0)
            {
                cout << "第" << counter << "届 冠军编号: " << index << "\t 得分: " << score << " ";
            }
            if(i == 1)
            {
                cout << "\t亚军编号: " << index << "\t 得分: " << score << " ";
            }
            if(i == 2)
            {
                cout << "\t季军编号: " << index << "\t 得分: " << score << endl;
            }
        }
        counter++;
    }
    system("pause");
    system("cls");
}

//清空比赛记录
void SpeechManager::Clear()
{
    cout << "--- 确认清空? ---" << endl;
    cout << "--- 1. 确认 ---" << endl;
    cout << "--- 2. 返回 ---" << endl;
    int choice;
    cin >> choice;
    if(choice == 1)
    {
        //打开模式 ios::trunc 如果文件存在，先删除，再重建
        ofstream ofs("speech.csv", ios::trunc);
        ofs.close();
        cout << "清空成功!" << endl;
    }
    system("pause");
    system("cls");
}