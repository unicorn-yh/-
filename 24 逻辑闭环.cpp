/*Description
小张是一位推理迷，他非常喜欢看侦探小说与侦探电影。
同时他也会玩一些推理游戏，在侦探游戏中，小张需要发掘事件之间的联系。
通过一条线索，他能够通过事件A推理出事件B。如果通过某一个事件A能够推出事件A本身，那么他就能够完成推理。
现在按照顺序给出 m 条线索，请你算出他最少能够用前几条线索能够形成逻辑闭环完成推理。

Input
第一行 n,m(1 <= n,m <= 300000 ) 两个数，表示事件数和线索数。
接下来 m 行，每行两个数 A,B(1 <= A,B <= n ) ，表示事件A能够推出事件B。

Output
一行一个数，表示最少能够用前几条线索形成逻辑闭环完成推理。若无法完成输出-1。*/

#include <bits/stdc++.h>
using namespace std;
#define MAXLEN 300010
struct tag{
    public:
    int endtime;
    bool isUsed;
    tag(int e,bool i):endtime(e),isUsed(i){}
};
vector <tag> t[MAXLEN];
struct endtime{
    public:
    int a,b;
};
queue <int> q;
bool bfs(int a,int b){
    q.push(b);
    while(!q.empty()){
        int temp=q.front();
        for(long i=0;i<t[temp].size();i++){
            if(t[temp][i].isUsed==0){
                if(t[temp][i].endtime==a) return true;
                t[temp][i].isUsed=1;
                q.push(t[temp][i].endtime);
            }
        }
        q.pop();
    }
    return false;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        endtime e;
        scanf("%d%d",&e.a,&e.b);
        t[e.a].push_back(tag(e.b,0));
        bool result=bfs(e.a,e.b);
        if(result){
            printf("%d\n",i+1);
            return 0;
        }
    }
    printf("-1\n");
}