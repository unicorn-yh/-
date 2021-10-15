/*Description
小张非常喜欢与朋友们玩成语接龙的游戏，但是作为“文化沙漠”的小张，成语的储备量有些不足。
现在他的大脑中存储了 m 个成语，成语中的四个汉字都用一个1000000以内的正整数来表示。
现在小张的同学为了考验他给出了他一个成语做开头和一个成语做结尾，如果小张能通过成语接龙的方式说到结尾的成语，
他就能够成功完成游戏。他想知道最少能说几个成语能够成功完成游戏。

Input
第一行一个数 m(1 <= m <= 300000 ) 。接下来 m 行，每行4个1000000以内的正整数，表示一个成语。
下一行4个1000000以内的正整数，表示开始成语。下一行4个1000000以内的正整数，表示结束成语。
保证开始成语和结束成语在小张的成语储备之中。

Output
一行一个整数，表示最少说几个成语能够完成游戏。如果无法完成输出-1。

Notes
三个成语分别是(1,2,3,4)(4,5,6,7)(7,8,9,10)*/

#include <bits/stdc++.h>
using namespace std;
#define MAXLEN 300010

struct tag{
    public:
    long word;
    bool isUsed;
    tag(long w,bool i):word(w),isUsed(i){}
};
vector <tag> t[MAXLEN];

struct word{
    public:
    long a,b,c,d;
}w;

struct Count{
    public:
    long index,step;
    Count (long i,long s):index(i),step(s){}
};
queue <Count> q;

int main(){
    long m,i;
    scanf("%ld",&m);
    for(i=0;i<m;i++){
        scanf("%ld %ld %ld %ld",&w.a,&w.b,&w.c,&w.d);
        t[w.a].push_back(tag(w.d,0));
    }
    word start,end;
    scanf("%ld %ld %ld %ld",&start.a,&start.b,&start.c,&start.d);
    scanf("%ld %ld %ld %ld",&end.a,&end.b,&end.c,&end.d);
    if(start.a==end.a && start.b==end.b && start.c==end.c && start.d==end.d){
        printf("1\n");
        return 0;
    }
    if (end.a==start.d){
        printf("2\n");
        return 0;
    }
    Count c1(start.d,0);
    q.push(c1);
    long MINSTEP=300010;
    while(!q.empty()){
        Count tmp=q.front();
        for(i=0;i<t[tmp.index].size();i++){
            if(t[tmp.index][i].isUsed==0){
                if(t[tmp.index][i].word==end.a){
                    if(tmp.step+3<=MINSTEP) MINSTEP=tmp.step+3;
                }
                t[tmp.index][i].isUsed=1;
                Count c2(t[tmp.index][i].word,tmp.step+1);
                q.push(c2);
            }
        }
        q.pop();
    }
    if(MINSTEP!=300010)printf("%ld\n",MINSTEP);
    else printf("-1\n");
    return 0;
}