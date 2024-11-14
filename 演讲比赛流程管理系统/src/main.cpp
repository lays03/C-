#include <iostream>
#include <vector>
#include "speechManager.h"
#include "player.h"
using namespace std;


int main()
{
    vector<Player>v1; //第一轮比赛选手
    vector<Player>v2; //第二轮比赛选手 获胜选手也保存在v2中
    string nameside = "ABCDEFGHIJKL";
    int index = 10001;
    for(int i = 0; i < 12; ++i)
    {
        string name = "选手";
        name += nameside[i];
        Player p(index, name, 0);
        v1.push_back(p);
        index++;
    }
    SpeechManager s;
    while(1)
    {
        s.show_Menu();
        cout << "请输入您的选择: ";
        int choice = 0;
        cin >> choice;
        switch(choice){
            case 0:
                cout << "成功退出!" << endl;
                exit(0);
                break;

            case 1:
            {
                s.first_Chouqian(v1); //第一轮抽签
                s.SetScore(v1); //打分
                s.MySort(v1); //分组 排序
                s.show_first_result(v1, v2); //第一轮比赛结果

                s.second_Chouqian(v2); //第二轮抽签
                s.SetScore(v2); //打分
                s.show_second_result(v2); //第二轮比赛结果
                s.Save(v2); //保存文件
            }
                break;

            case 2:
                s.Output();
                break;

            
            case 3:
                s.Clear();
                break;

            default:
                break;

        }
    }
}
