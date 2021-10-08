/*Description
小张的好朋友小松要过生日了，小张打算为他挑选一件礼物。在市场上他发现有一个珠子手镯的商店很不错。
在这家商店会出售特殊的珠子并穿成一个手镯，在货架上珠子排成一排，每一个珠子上有一个小写英文字母。
店家有一个特殊的规定，必须在一排珠子中按顺序从左到右挑选。小张心中已经有一个想要送给小松的单词，
请你告诉他应该如何挑选珠子使得手镯上珠子的字母组成小张想要的单词。

Input
第一行，一个字符串，表示货架上的一排珠子，仅包含小写英文字母，长度在200000以内。
第二行，一个字符串，表示小张想要的单词，仅包含小写英文字母，长度在10000以内。

Output
输出一行整数，表示小张按照从左到右需要挑选的珠子在货架上的位置。

Notes
从左到右按顺序选出的珠子上的字母为'p'，'p'，'y'，'h'，'a'。串成环形的手镯后可以组成"happy"。
数据保证有解，若有多种选取方法，输出其中字典序最小的一个，比如1 2 3 4比1 3 4 5的字典序小。
提交后查看结果页面错误信息一栏，前4行的编译错误大家不用理会，第5行是关于你的结果的信息。*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#define AMAX 200010
#define BEADMAX 10010
char a[AMAX],bead[2*BEADMAX];
bool occupied[AMAX];
int circulate[AMAX][26], ans[BEADMAX], tmp[BEADMAX];
int main(){
    int i,j;
    scanf("%s%s",a,bead);
    int alen=strlen(a);
    int beadlen=strlen(bead);
    memset(circulate,-1,sizeof circulate);
    strncat(bead,bead,2*BEADMAX-beadlen-1);  //双倍链代环
    for(i=0;i<beadlen;i++) ans[i]=INT_MAX;   //初始化字典序，使用最大字典序
    for(i=alen-1;i>=0;i--){                  //序列自动机
        for(j=0;j<26;j++) circulate[i][j]=circulate[i+1][j];
        circulate[i][a[i]-'a']=i;
    }
    for(i=0;i<beadlen;i++){                   //遍历所有环
        memset(occupied,0,sizeof occupied);   //刷新使用情况
        int pointer=0,k=0;
        bool loop=true,best=true;
        for(j=0;j<beadlen;j++){
            if(occupied[pointer]) pointer+=1;   //一直更新当前新位置
            pointer=circulate[pointer][bead[i+j]-'a'];
            occupied[pointer]=true;
            tmp[k++]=pointer+1;  //存放实际位置
            if(pointer==-1){    //后面没有bead字符了
                loop=false;
                break;
            }
        }
        if(loop){
            for(j=0;j<beadlen;j++){
                if(tmp[j]>ans[j]){
                    best=false;
                    break;
                } 
                else if(tmp[j]<ans[j]) break;
            }
            if(best) for(j=0;j<beadlen;j++) ans[j]=tmp[j];
                
        }
    }
    for(i=0;i<beadlen;i++) printf("%d%c",ans[i],i==beadlen-1?'\n':' ');
    return 0;
}