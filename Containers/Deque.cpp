//
// Created by lcx on 2020/9/8.
//
#include <iostream>
#include <deque>//双端数组
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//选手类
class player
{
public:
    string m_name;
    int m_score;
};

void create_players( vector<player> &v)
{
    string s1 = "ABCDE";
    string s2 = "The player ";
    int i = 0;
    for(auto it = v.begin(); it != v.end(); it++)
    {
        it->m_name = s2 + s1[i];//为选手创建名字
        i++;
    }
}


void scored_players(vector<player> &v) {
    int n_teacher = 10;

    //注意auto m: v 改变m不会改变v的内容， auto &m: v 改变m会改变v的内容
    for (auto it = v.begin(); it != v.end(); it++)
    {
        deque<int> t_score;
        for(int i = 0; i < n_teacher; i++)
        {
            int rand_score = rand()%40 + 60;//随机打分
            t_score.push_back(rand_score);
        }
        sort(t_score.begin(), t_score.end());//打分排序
        //去除最高分和最低分
        t_score.pop_back();
        t_score.pop_front();

        int total_score = 0;
        //算平均分
        for( auto n : t_score)
        {
            total_score += n;
        }
        int average_score = total_score / t_score.size();

        it->m_score = average_score;
    }


}

bool comp( player &p1, player &p2)
{
    return p1.m_score > p2.m_score;
}

void sort_players(vector<player> &v)
{
    //分数排序用
    sort(v.begin(), v.end(), comp);

    //输出最终结果
    for( auto n : v)
    {
        cout<<"The score of "<<n.m_name<<" is "<<n.m_score<<endl;
    }
    cout<<endl;

}
int main()
{
    vector<player> v_p(5);
    create_players(v_p);
    scored_players(v_p);
    sort_players(v_p);

    return 0;
}
