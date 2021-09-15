/*军训这么累，当然要吃瓜啦。有一个小军前来买瓜。
众所周知，YHW水果摊里的西瓜的瓜皮子和瓜粒子都是金粒子做的。小军当然想获得尽可能多的金粒子。
一共有n个瓜，每个瓜有重量w，成熟度v，金粒子数量g。
虽然小军的钱是无限的，但他的电动车载重是有限的，因此他不能买总重量超过W的瓜。
"我开水果摊的，能卖给你生瓜蛋子？ ——YHW
因此，当小军买的瓜的总成熟度小于V时，YHW并不会把瓜卖给他。
具体的：水果摊一共有n个瓜，每个瓜有重量w，成熟度v，金粒子数量g。一
共有q次询问，每次询问给出两个值W、V，小军要选取n个瓜的子集，使总重量 Σw≤W,总成熟度Σv≥V，求 ΣgΣg的最大值。

Input
第一行输入两个整数n,q(1≤n≤100,1≤q≤100)n,q(1≤n≤100,1≤q≤100)，代表瓜的数量和询问数量。
接下来n行，每行三个整数，第i行的三个整数为wi,vi,gi(1≤wi,vi,gi≤100),分别代表第i个瓜的重量，成熟度和价值。
接下来q行，输入两个整数W,V(1≤W,V≤500)W,V(1≤W,V≤500)，代表一组询问。

Output
输出一共有q行，每行一个整数，分别代表每组询问的最大金粒子数总和，若无合法的买法则输出-1。*/

#include <bits/stdc++.h>
using namespace std;
int dp[2][505][505];
int n,q,w[101],v[101],g[101],W,V;
int i,j,k;
int max(int a,int b){
    return a>b?a:b;
}
int min(int a,int b){
    return a<b?a:b;
}
void initialize(){     
    for(i=0;i<2;i++)          //初始化数组为-1
        for(j=0;j<505;j++)
            for(k=0;k<505;k++) 
                dp[i][j][k]=-1;
    dp[0][0][0]=0;
    dp[1][0][0]=0; 
}
int main(){
    initialize();
    scanf("%d%d",&n,&q);   //n个瓜，q次询问
    for(i=1;i<=n;i++){
        scanf("%d%d%d",&w[i],&v[i],&g[i]);
        for(j=0;j<=501;j++){
            for(k=0;k<=501;k++){
                if(j+w[i]<=500){
                    if(dp[0][j][k]!=-1){    //判断是否为-1，不是则更新
                        dp[1][j+w[i]][min(500,k+v[i])]=max(dp[1][j+w[i]][min(500,k+v[i])],dp[0][j][k]+g[i]);
                    }
                }
            }
        }
        for(j=0;j<501;j++){
            for(k=0;k<501;k++){
                dp[0][j][k]=dp[1][j][k];
            }
        }
    } 
    for(i=1;i<=q;i++){
        int tempmax=-1;
        scanf("%d %d",&W,&V);
        for(j=1;j<=W;j++){
            for(k=V;k<501;k++){
                if(dp[0][j][k]!=-1){ //不是-1才执行
                    tempmax=max(tempmax,dp[0][j][k]);
                }
            }
        }
        if(tempmax!=-1)printf("%d\n",tempmax);
        else printf("-1\n");
    }
    return 0;
}