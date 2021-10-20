#include <bits/stdc++.h>
using namespace std;
long long p[2010],dp[2005][2005];   
int main(){
    int n,v;
    scanf("%d%d",&n,&v);      //n表示物品数，v表示背包体积
    dp[0][0]=1;               //dp[i][j]代表第 i个物品，背包体积为 j的情况
    for(int i=1;i<=n;i++){
        scanf("%lld",&p[i]);    //p表示物品占据的体积 
        for(int j=0;j<v;j++)dp[i][j]=(dp[i-1][j]+dp[i][j])%10000000;  //直接转移上一个状态
        for(int j=0;j<v;j++){
            long long k=(j+p[i])%v;
            dp[i][k]=(dp[i-1][j]+dp[i][k])%10000000;
        }    
    }
    printf("%lld\n",dp[n][0]-1);
    return 0;
}