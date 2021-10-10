/*Description
小张最近沉迷上一款手机游戏北理工的恶龙。在这个游戏中你通过提升攻击力击败恶龙，打败所有恶龙后你可以获得游戏的胜利。
在这款游戏中，每一条恶龙有一个难度值 xi 和一个经验值 yi 。游戏中的英雄具有攻击力 A 。
游戏一开始英雄的攻击力 A=0 。打到一条恶龙你的攻击力需要大于等于难度值 xi 。
在你击败恶龙以后，你的攻击力会增加经验值 yi 。当然，你有时需要额外提升你的攻击力，此时你只需氪金1元，
就能增长一点攻击力。小张想知道，如果他自己决定挑战恶龙的顺序，要想击败所有恶龙至少需要氪金多少钱？

Input
第一行一个数 n(1 <= n <= 200000 ) 。
接下来 n 行每行两个数 xi,yi(0 <= xi <= 1000000, -1000000 <= yi <= 1000000 ) 。

Output
一个整数，表示小张最少需要氪金多少钱。

Notes
直接打败第一条恶龙，此时 A=1 ，花费0元。
直接打败第二条恶龙，此时 A=2 ，花费0元。
氪金3元，此时 A=5 ，打败第三条恶龙，此时 A=3 。
最后直接打败第四条恶龙。*/

#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAXLEN 200010
struct dragons{
    public:
    int x,y;
}increase[MAXLEN],decrease[MAXLEN];
bool cmpx(struct dragons a,struct dragons b){
    if(a.x!=b.x) return a.x<b.x;
}
bool cmpxy(struct dragons a,struct dragons b){
    if(a.x+a.y==b.x+b.y) return a.x>b.x;
    else return a.x+a.y>b.x+b.y;
}
int main(){
    int n,i,increase_index=0,decrease_index=0;
    long long money=0, a=0;
    cin >> n;
    for(i=0;i<n;i++){
        int tmpx=0,tmpy=0;
        cin >> tmpx >> tmpy;
        if(tmpy<0){
            decrease[decrease_index].x=tmpx;
            decrease[decrease_index].y=tmpy;
            decrease_index++;
        }
        else if(tmpy>=0){
            increase[increase_index].x=tmpx;
            increase[increase_index].y=tmpy;
            increase_index++;
        }
    } 
    sort(increase,increase+increase_index,cmpx);
    sort(decrease,decrease+decrease_index,cmpxy);
    for(i=0;i<increase_index;i++){
        if(a>=increase[i].x) a+=increase[i].y;
        else {
            money+=(increase[i].x-a);
            a=increase[i].x+increase[i].y;
        }
    }
     for(i=0;i<decrease_index;i++){
        if(a>=decrease[i].x) a+=decrease[i].y;
        else {
            money+=(decrease[i].x-a);
            a=decrease[i].x+decrease[i].y;
        }
    }
    cout << money << endl;
    return 0;
}