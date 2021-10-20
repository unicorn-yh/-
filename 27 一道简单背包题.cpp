/*Description
龙神有很多背包，每一个背包都有一个容积。但是这些背包的容积都恰好是一个数字V的整数倍，比如 V,2V，等等。
并且对于任意k 大於等於 1，容积为k 乘號 V的背包都存在。
龙神有一些物品要装进背包，第i个物品占据 p_i的体积。
现在，龙神想选出一些物品，使得存在一个背包可以恰好放下这些物品，并且这个背包放满。
龙神想知道这样的取法有多少个，请你帮他算一算吧？由于取法很多，你只需要输出取法的末七位数，
没有前导零，即可（即对10000000取模）。

Input
第一行两个数n 逗號 V，分别表示物品数和背包体积的基数。
第二行n个数，分别表示每个物品的体积 p_i。

Output
输出一行一个数，表示取法总数的末七位。

Note
数据保证1 <= n , V <= 2000 , 1 <= p_i <= 100000。*/

#include<bits/stdc++.h>
using namespace std;
long long p,temp[4005];  //p表示物品占据的体积 
int main(){
    int n,v;          //n表示物品数，v表示背包体积
    temp[0]=1;        //temp是用来干嘛的呢
    scanf("%d%d",&n,&v);
    for(int i=0;i<n;i++){
        scanf("%lld",&p);
        p=p%v;
        if(!p)p=v;
        for(int k=2*v;k>=p;k--) temp[k]=(temp[k]+temp[k-p])%10000000;
        for(int k=2*v;k>=p;k--){
            if(k>v){
                temp[k-v]=(temp[k-v]+temp[k])%10000000;
                temp[k]=0;
            }
        }
    }
    printf("%lld\n",temp[v]%10000000);
    return 0;
}