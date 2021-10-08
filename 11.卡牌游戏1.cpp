/*Description
小张在玩一种卡牌游戏，牌组由 2n 张牌组成，其中 n 张上写有数字 1...n 各一张，其余 n 张上全部是数字 0 。
现在牌组经过随机打乱后，小张拿走其中 n 张牌作为手牌，其余 n 张牌作为牌堆。
小张想经过若干次如下操作使得牌堆自顶向下的牌依次为 1...n 。
每一次操作，小张选择任意一张手牌放到牌堆底，并将牌堆顶的牌放入手牌。
他想知道最少进行几次操作，使得牌堆自顶向下的牌依次为 1...n 。

Input
第一行一个数 n(1 < n < 200000 ) 。
第二行 n 个数，表示小张手中的牌。
第三行 n 个数，表示牌堆，数组从左向右的顺序表示牌堆自顶向下的顺序。

Output
一个整数，表示最少执行的操作数。*/

#include <stdio.h>
#include <string.h>
#define MAXLEN 200010
main(){
    int temp=0;
    long n,j,k;
    long hand[MAXLEN]={0},card[MAXLEN]={0},count[MAXLEN]={0},diff[MAXLEN]={0};
    scanf("%ld\n",&n);
    for(j=0;j<n;j++){
        scanf("%d",&hand[j]);
        if(j!=n-1) scanf(" ");
        else scanf("\n");
    }
    for(j=0;j<n;j++){
        scanf("%d",&card[j]);
        if(j!=n-1) scanf(" ");
        else scanf("\n");
    }
    for(j=0;j<n;j++){
        if(hand[j]!=0);
        else{
            temp=hand[j];
            hand[j]=card[0];
            for(k=0;k<n-1;k++){
                card[k]=card[k+1];
            }
            card[n-1]=temp;
            j--; 
            count++; 
        }      
    }
    printf("%ld\n",count);
}