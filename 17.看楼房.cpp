/*Description
小张在暑假时间进行了暑期社会调查。调查的内容是楼房的颜色如何影响人们的心情。
于是他找到了一个楼房从左到右排成一排的小区，这个小区一共有 n 栋楼房，每个楼房有一个颜色 c 和一个高度 h。
小张调查的内容为每次他站在第 i 栋楼和第 i+1 栋楼之间向左看，他记录下此时他看到的楼房颜色数作为他的调查结果。
由于小张在暑假时间沉迷游戏来不及做实地调查，只好拜托你将调查结果告诉他。

Input
本题有多组数据。每组数据第一行一个整数 n 。表示有 n 栋楼房从左到右排成一排。
第二行 n 个数，表示每个楼房的颜色 (1 ≤ c ≤ 10^6 )。
第三行 n 个数，表示每个楼房的高度 (1 ≤ c ≤ 10^9 )。
数据保证所有组数据的 n ≤ 1000000。

Output
每组数据输出 n 个数，第 i 个数表示他站在第 i 栋楼和第 i+1 栋楼之间向左看，能够看到的楼房颜色数。

提示
在从左向右看楼房的时候，左边较矮的楼房会被右边较高的楼房挡住。
*/

#include <bits/stdc++.h>
using namespace std;
#define MAXLEN 1000010
long n,i;
int colors[MAXLEN];
long num_color=0;
struct Building{
    public:
    long color,height;
}building[MAXLEN];
stack <struct Building> b;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        num_color=0;    //能看到的颜色个数
        scanf("%ld",&n);
        memset(colors,0,sizeof(colors));
        while(!b.empty())b.pop();
        for(i=0;i<n;i++) scanf("%ld",&building[i].color);
        for(i=0;i<n;i++) scanf("%ld",&building[i].height);
        b.push(building[0]);
        colors[building[0].color]++;
        num_color++;
        printf("%ld ",num_color);
        for(i=1;i<n;i++){
            if(b.empty()||building[i].height<b.top().height){
                b.push(building[i]);
                if(colors[building[i].color]==0) num_color++;
                colors[building[i].color]++;
            }
            else{
                while(building[i].height>=b.top().height){
                    colors[b.top().color]--;
                    if(colors[b.top().color]==0) num_color--;
                    b.pop();
                    if(b.empty()||building[i].height<b.top().height){    //不明白
                        b.push(building[i]);
                        if(colors[building[i].color]==0) num_color++;
                        colors[building[i].color]++;
                        break;
                    }
                }
            }
            printf("%d%c",num_color,i==n-1?'\n':' ');
        }
    }
    return 0;
}