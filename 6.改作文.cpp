/*Description
小张的英语不太好，今天他又要面临英语作文的困扰了。
终于他在ddl的前一秒完成了他的作文，但是由于太过匆忙，很多单词的大小写出现了问题。
请你在一秒之内帮他改完英语作文吧！

Input
给出若干行字符串表示小张的作文，以EOF结束。
保证文章总长度不超过1000000个字符。
整篇文章只有大小写英文字母，空格，'.'，','，'?'，'!'。
并且保证每个标点符号都紧跟前面的单词，单词之间恰好一个空格。

Output
输出修改后的作文，要求每一句第一个单词的首字母大写，其他单词所有字母小写。
'.'，'?'，'!'表示每一句的结束。*/

#include<math.h>
#include<cstring>
#include<iostream>
using namespace std;
const int n=1000000;
char a[n];

int change(int x){
    if(x>='a' && x<='z') return x-32;
    else return x+32;
}
main(){
        while(gets(a)!=NULL){
            if(a[0]>='a' && a[0]<='z')a[0]=change(a[0]);
            if(a[1]>='A' && a[1]<='Z')a[1]=change(a[1]);
            for(int i=2;a[i]!='\0';i++){
                if(a[i-1]==' '){
                    if(a[i-2]=='.'|| a[i-2]=='!'|| a[i-2]=='?'){
                        if(a[i]>='a' && a[i]<='z')a[i]=change(a[i]);
                    }
                    else if(a[i-2]==','){
                        if(a[i]>='A' && a[i]<='Z')a[i]=change(a[i]);
                    }
                    else{
                        if(a[i]>='A' && a[i]<='Z')a[i]=change(a[i]);
                    }
                }
                else if(a[i-1]>='a' && a[i-1]<='z' || a[i-1]>='A' && a[i-1]<='Z' ){
                    if(a[i]>='A' && a[i]<='Z')a[i]=change(a[i]);
                }
            }
            puts(a);
        } 
}

