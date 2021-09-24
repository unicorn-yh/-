/*Description
小张是一个密室逃脱爱好者，在密室逃脱的游戏中，你需要解开一系列谜题最终拿到出门的密码。
现在小张需要打开一个藏有线索的箱子，但箱子上有下图所示的密码锁。
每个点是一个按钮，每个按钮里面有一个小灯。如上图，红色代表灯亮，白色代表灯灭。
每当按下按钮，此按钮的灯以及其上下左右四个方向按钮的灯状态会改变（如果原来灯亮则灯灭，如果原来灯灭则灯亮）。
如果小张通过按按钮将灯全部熄灭则能可以打开箱子。对于这个密码锁，我们可以先按下左上角的按钮，密码锁状态变为下图。
再按下右下角的按钮，密码锁状态变为下图。最后按下中间的按钮，灯全部熄灭。
现在小张给你一些密码锁的状态，请你告诉他最少按几次按钮能够把灯全部熄灭。

Input
第一行两个整数 n,m(1 <= n,m <= 16 ) 。
接下来 n 行，每行一个长度为 m 的01字符串，0表示灯初始状态灭，1表示灯初始状态亮。

Output
一行一个整数，表示最少按几次按钮可以把灯全部熄灭。

Notes
第一个样例见题目描述，第二个样例按左上和右下两个按钮。测试用例保证一定有解。*/

#include <stdio.h>
#define MAXLEN 18
int n,m,a[MAXLEN][MAXLEN];
int t[MAXLEN][MAXLEN];
int ans=256;

void inverse(int *k){
    if(*k==1)*k=0;
    else *k=1;
}
void push(int a[][MAXLEN],int b,int c){
    inverse(&a[b][c]);
    if(b-1>=0)inverse(&a[b-1][c]);
    if(c-1>=0)inverse(&a[b][c-1]);
    if(b+1<n)inverse(&a[b+1][c]);
    if(c+1<m)inverse(&a[b][c+1]);
}
void temp(){          //暂时存放上一个数组
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            t[i][j]=a[i][j];
        }
    }
}
int calculate(){             //确定第一排全部为0
    temp();
    int step=0,i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<m;j++){
            if(t[i][j]==1){
                push(t,i+1,j);
                step++;
            }
        }
    }
    for(i=0;i<m;i++){
        if(t[n-1][i]==1) return -1;
    }
    return step;
}
void dfs(int step,int count){    //枚举第一排按键的所有按法
    if(step==m){
        int b=calculate();
        if(b==-1)return;
        if(b+count<ans) ans=count+b;
        return;
    }
    push(a,0,step);
    dfs(step+1,count+1);
    push(a,0,step);
    dfs(step+1,count);
}
main(){
    int i,j;
    scanf("%d %d\n",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            char c;
            c=getchar();
            a[i][j]=c-'0';
        }
        getchar();     //吸去换行符
    }
    dfs(0,0);
    printf("%d\n",ans);

}