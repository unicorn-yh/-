/*Description
众所周知，strawberry的妹子很多而且总数甚至是不可数的，妹子集合和阿列夫零等势。
今天strawberry把他的 n 个妹子带来，排成一排。strawberry的妹子很多，但是质量不容乐观。
每个妹子有美丽度，有正有负。strawberry想选出其中3队妹子，使得她们的美丽度之和最大。
每一队都应该是一个连续的区间，而且两队不能同时选择同一个妹子。
strawberry又去找新的妹子了，请你帮帮strawberry算算最大美丽度是多少？

Input
输入一行一个数 n，表示strawberry这次带来的妹子数。接下来一行 n 个数，分别表示每个妹子的美丽度 a 下標 i。

Output
输出一个数，表示最大美丽度。

Note
所有数据保证 3 小於等於 n 小於等於 500000 逗號 負 10 的 9 次方 小於等於 a 下標 i 小於等於 10 的 9 次方。
样例解释：取的三个不相交连续子串分别是{2,3} {1} {1}。
*/

#include <bits/stdc++.h>
using namespace std;
const int MAXLEN=500010, INF=0x3f3f3f3f;
long long n, beautylvl[MAXLEN], temp[3][MAXLEN];
long long cmp(long long a,long long b){
    if(a>b) return a;
    else return b;
}
int main(){
    scanf("%lld",&n);
    for(long i=1;i<=n;i++) scanf("%lld",&beautylvl[i]);
    for(long i=0;i<n+1;i++) {
        temp[0][i]=0;
        temp[1][i]=0;
    }
    for(long i=1;i<4;i++){
        long long tempmax=-INF;
        for(long j=i;j<=n;j++){
            if(i==j){
                temp[i][j]=temp[i-1][j-1]+beautylvl[j];
                continue;
            }
            tempmax=cmp(tempmax,temp[i-1][j-1]);
            temp[i][j]=cmp(temp[i][j-1],tempmax)+beautylvl[j];
        }
    }
    long long finalmax=temp[3][3];
    for(long i=4;i<=n;i++){
        if(temp[3][i]>finalmax) finalmax=temp[3][i];
    }
    printf("%lld\n",finalmax);
    return 0;
}