/*Description
DarkDawn在乐学上出了一道给定括号序列，判断其合法性的问题。
括号序列是由左括号“(”和右括号“)”组成的非空序列。对于一个括号序列很容易判定其合法性。比如“()”、“(())()”、
“(()())”、“(()(()))”、“()()()”都是合法的，而 “)”、“(”、“(()”、“(()))(” 都是非法的。
Roark看了一眼题，立刻去饮水机处接了一杯水。
DarkDawn意识到他是在暗示这道题太水了，于是立刻把题改了改，增加了一、、难度。
给定 n 个括号序列，两两配对，问最多能组成多少对合法括号序列。（每一个括号序列只能在一对中出现）
Roark接完水回来再看了看新题，开始挠头了，快帮帮他！

Input
第一行输入整数 n 左小括號 斜體字 1 斜體字 小於等於 n 斜體字 小於等於 斜體字 100000 右小括號 表示有 n 个括号序列。
接下来 n 行，每行输入一个只由 "(" 和 ")" 构成的字符串 si 。（字符串长度满足1 <= |si| <= 1e5）
所有字符串长度总和满足 Σi |si| <= 5e5。

Output
输出一个整数，表示最大的合法括号序列对数。

Hint
第一组用例可以组成2对合法括号序列，分别是 "((   )())"、"(   )"。*/

#include<stdio.h>
#include<string.h>
#define MAXLEN 100050
long long left[MAXLEN]={0},right[MAXLEN]={0},count=0;

int pair(char c,char d){          //两两匹配的函数
    if(c=='(' && d==')')return 1;
    else return 0;
}
void simplified(char s[]){
    int top_index=-1;
    char temp[MAXLEN];
    for(int i=0;i<strlen(s);i++){
        if(top_index!=-1 && pair(temp[top_index],s[i])) top_index--;  //出栈
        else temp[++top_index]=s[i];  //入栈
    }
    if(top_index==-1){               //情况 1：最简形式为空，本身匹配，返回空
        count++;
        return;
    }
    char ch=temp[top_index];
    int num_element=top_index+1;    //化简后的栈内剩余元素
    while(top_index>=0){
        if(temp[top_index]!=ch)return;  //情况 2：栈内不是同号的字符串，返回空
        top_index--;
    }
    if(ch=='(') left[num_element]++;   //情况 3：记录最简化形式在left和right
    else right[num_element]++;
}
main(){
    int n;
    char s[MAXLEN];
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        scanf("%s",s);
        simplified(s);
    }
    long long output=count/2;  //本身就匹配的字符串，两两匹配
    for(int i=0;i<MAXLEN;i++){
        if(left[i]<right[i]) output+=left[i];
        else output+=right[i];
    }
    printf("%lld\n",output);
}