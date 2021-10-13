/*小军的军训进行到了一半了，今天军训教官搞了一波突然袭击，进行了一个寝的查。
提前了解到查寝消息的小军准备进行一波整理归纳，来使自己的寝室变得更加整洁。
具体来说，小军有n件物品，放在n个盒子里，第i个盒子有物品i，小军会进行m次整理，第i次整理，
小军会依次在第x个盒子顶拿走物品放入第y个盒子内，直至第x个盒子完全搬空。
比如第1个盒子自顶向下有物品1、2，第2个盒子有物品3，将盒子1内的物品搬入盒子2内后结果是： 
第1个盒子没有物品，第2个盒子自顶向下是2、1、3
现在，小军告诉你n还有m次操作具体是什么，你能告诉他最后每个盒子内有几个物品，他们具体是什么么？

Input
一个正整数n代表盒子和物品数，一个正整数m代表整理归纳的次数
接下来m行输入，一行两个正整数x y，代表用上述的方法将盒子x的物品搬到盒子y里
1≤n≤10^5, 1≤m≤10^6, 1≤x,y≤n (题目保证x != y)

Output
有n行输出
第i行，先输出一个正整数k，表示第i个盒子内的物品数，接下来输出n个数，表示第i个盒子自顶向下的物品标号

注意：
行末无空格，文末有回车。*/

#include <bits/stdc++.h>
using namespace std;
#define MAXLEN 100010
long isUsed[MAXLEN]=[0],first[MAXLEN]=[0],last[MAXLEN]=[0],count[MAXLEN]={0},next[MAXLEN][2]={0};
int main(){
    long m,n,i,j,temp,x,y;
    scanf("%ld %ld",&n,&m);   //n代表盒子和物品数 m代表整理归纳的次数
    for(i=1;i<=n;i++){
        first[i]=i;
        last[i]=i;
        num[i]=1;
    }
    for(i=1;i<=m;i++){
        scanf("%ld %ld",&x,&y);
        if(count[x]==0) continue;
        else{
            if(count[y]==0){
                first[y]=last[x];
                last[y]=first[x];
            }
            else{
                if(next[first[x]][1]==0) next[first[x]][1]=first[y];
                else if(next[first[x]][0]==0) next[first[x]][0]=first[y];
                if(next[first[y]][1]==0) next[first[y]][1]=first[x];
                else if(next[first[y]][0]==0) next[first[y]][0]=first[x];
                first[y]=last[x];
            }
            num[y]+=num[x];
            first[x]=0;
            last[x]=0;
            count[x]=0;
        }
    }
    for(i=1;i<=n;i++){
        if(count[i]==0) printf("0\n");
        else{
            printf("%ld %ld",count[i],first[i]);
            isUsed[first[i]]=1;
            temp=first[i];
            for(j=0;j<count[i]-1;j++){
                if(next[temp][0]!=0 && flag[next[temp][0]]!=1){
                    printf(" %ld",next[temp][0]);
                    temp=next[temp][0];
                    isUsed[temp]=1;
                }
                if(next[temp][1]!=0 && flag[next[temp][1]]!=1){
                    printf(" %ld",next[temp][1]);
                    temp=next[temp][1];
                    isUsed[temp]=1;
                }
            }
            printf("\n");
        }
    }
    return 0;
}