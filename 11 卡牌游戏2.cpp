#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAXLEN 200010
int main(){
    int flag=0,op=1,i,j;
    long hand[MAXLEN]={0},card[MAXLEN]={0},count[MAXLEN]={0},diff[MAXLEN]={0};
    long n,first=-1,bigdiff=0,startpoint=0,startstep=0,step;
    cin >> n;
    for(i=0;i<n;i++) cin >> hand[i];
    for(i=0;i<n;i++) cin >> card[i];
    for(i=0;i<n;i++){
        if(card[i]!=0){
            count[card[i]]=i+2;
            diff[card[i]]=i+2-card[i];
            if(i+2-card[i]>=bigdiff) bigdiff=i+2-card[i];
        }
        if(card[i]==1) first=i;  //记录数字为 1 的位置
    }
    if(first==-1){            //1在hand里，either用启动点或者轮着放
        step=diff[1]+n;
        for(i=2;i<=n;i++){
            if(diff[i]>startpoint){
                flag=1;
                step=diff[i]+n;
                startpoint=diff[i];
            }
        }
        if(!flag){
            cout << n << endl;
            return 0;
        }
        else{
            cout << step << endl;
            return 0;
        }
    }
    for(i=0;i<n-first;i++){    //判断1后面是否紧跟着2,3...
        if(card[i+first]!=i+1){  //未跟紧
            op=0;
            break;
        }
    }
    if(op==0){                //未跟紧的情况
        startpoint=diff[i];
        step=diff[i]+n;
        for(i=2;i<=n;i++){
            if(diff[i]>startpoint){
                startpoint=diff[i];
                step=diff[i]+n;
            }
        }
        cout << step << endl;
        return 0;
    }
    else{                   //紧跟的情况：判定是否能取到所有的数字
        flag=0;
        startstep=n-first+1;
        for(i=startstep,j=1;i<=n;i++,j++) if(count[i]>j) flag=1;
        if(flag==0){
            cout << first << endl;
            return 0;
        } 
        else{
            cout << first+n+1 << endl;
            return 0;
        }
    }
}