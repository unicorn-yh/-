/*Description
龙神觉得无聊于是来到了地下城，这里是一个巨大的迷宫，有一些可以通行的路、一些不可以通行的墙，还有一些怪物。
虽然龙神可以轻易地干掉这些怪物，但他觉得这样就太没意思了，他观察到这些怪物每 k 秒会消失一次
（例如 k = 3 时，则第 3,6,9,...... 秒怪物是消失的），每一秒龙神可以选择向上下左右行走一步（不能在原地不动）。
龙神想知道在避开全部怪物的条件下，到达出口所需要的最短时间。

Input
第一行输入一个整数 T 空格 左括号 1 小於等於 T 小於等於 10 右括号，代表用例组数。
每组用例的第一行包括三个整数 n,m (1 <= n,m <= 100) 和 ，k (1 <= k <= 50) 分别表示地下城迷宫的行数、
列数、怪物的消失间隔。接下来的 n 行代表迷宫，.表示可以通行的路，#表示墙，*表示怪物，S表示起点，E代表出口。

Output
输出一个整数，表示龙神走出地下城迷宫的最短时间，如果龙神不能走出迷宫则输出-1。

Source
BITACM2018第一轮积分赛（三）- Problem J*/

#include<bits/stdc++.h>
using namespace std;
struct maze{
    int x,y,z,step;    //z代表时间
    maze(int a,int b,int c,int s):x(a),y(b),z(c),step(s){} 
};
queue <maze> q;
const int MAX=105；
const int xchange[]={0,0,1,-1}, ychange[]={1,-1,0,0};  // x上下 y左右
int v[MAX][MAX][55];    //记录是否被访问过
char func[MAX][MAX];    //输入符号
int main(){
    int n,m,k,T,xstart,ystart;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);      //n行 m列 k代表怪物消失的间隔
        for(int i=0;i<n;i++){
            scanf("%s",&func[i]);
            for(int j=0;j<m;j++){
                if(func[i][j]=='S'){    // S代表迷宫起点
                    xstart=i;
                    ystart=j;
                }
            }
        }
        memset(v,0,sizeof(v));
        q.push(maze(xstart,ystart,0,0));       //时间和步数=0
        int result,flag=0;
        v[xstart][ystart][0]=1;               //更新访问记录
        while(!q.empty()){
            maze temp=q.front();             //temp 用来存储当前坐标
            q.pop();
            if(func[temp.x][temp.y]=='E'){   //E代表出口
                result=temp.step;
                flag=1;
                break;
            }
            for(int j=0;j<4;j++){
                int a=xchange[j]+temp.x;
                int b=ychange[j]+temp.y;
                if((temp.z+1)%k){                  //#表示墙，*表示怪物，k代表怪物消失的间隔
                    if(a<0||a>=n||b<0||b>=m||func[a][b]=='#'||func[a][b]=='*'||v[a][b][(temp.z+1)%k]==1) continue;
                }   //坐标超出范围、遇到墙、遇到怪物、坐标被访问过：跳出循环，不计步
                else if(a<0||a>=n||b<0||b>=m||func[a][b]=='#'||v[a][b][(temp.z+1)%k]==1) continue;
                q.push(maze(a,b,temp.z+1,temp.step+1));
                v[a][b][(temp.z+1)%k]=1;
            }
        }
        if(flag)printf("%d\n",result);
        else printf("-1\n");
        while(!q.empty())q.pop(); 
    }
    return 0;
}
