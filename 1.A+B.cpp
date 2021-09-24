/*Description
学过《计算机科学导论》的你应该熟悉“二进制运算”吧？
和十进制不同的是：二进制运算“逢二进一”。下面举一个二进制加法的运算实例:
   11101
+    110
--------
  100011
下面请你模拟这个过程。

Input
第一行输入一个正整数 T 空格 左括号 1 小於等於 T 小於等於 10 右括号，表示接下来有 T 组数据；
接下来 T 行，每行输入两个二进制串 a 和 b 中间用空格隔开，保证它们长度 1 小於等於 竖线 a 竖线 逗號 空格 竖线 b 竖线 小於等於 10 的 5 次方 并且没有前导 0。

Output
对于每组数据，请按模拟二进制加法，按题目描述的格式输出正确的运算结果，注意换行，没有多余的空格和换行。*/

#include "stdio.h"
#include "math.h"
#include "string.h"
#include "stdlib.h"

int max(int a,int b){
    if(a>b)return a;
    else return b;
}

main(){
    int T,i,j,k;
    int cf=0,sum=0;
    char a[100001],b[100001];
    int a1[100001],b1[100001],len1,len2,maxlen;
    scanf("%d\n",&T);
    for(i=0;i<T;i++){
        cf=0;
        scanf("%s %s",a,b);
        len1=strlen(a);
        len2=strlen(b);
        maxlen=max(len1,len2);
        int c[maxlen];
        memset(a1,0,sizeof(a1));
        memset(b1,0,sizeof(b1));
        maxlen=max(len1,len2); 

        //倒序排列，把char数组转换成int数组
        for(j=len1-1;j>=0;j--)a1[len1-j-1]=a[j]-'0';
        for(k=len2-1;k>=0;k--)b1[len2-k-1]=b[k]-'0';

        for(j=0;j<maxlen;j++){
            sum=(cf+a1[j]+b1[j])%2;
            cf=(cf+a1[j]+b1[j])/2;
            c[j]=sum;
        }
        if(cf){
            c[maxlen]=1;
            maxlen++;
        }

        //output
        for(j=1;j<maxlen-len1+3;j++) printf(" ");
        printf("%s\n",a);
        printf("+");
        for(j=1;j<maxlen-len2+2;j++) printf(" ");
        printf("%s\n",b);
        for(j=1;j<maxlen+3;j++)printf("-");
        printf("\n  "); 
        for(j=maxlen-1;j>=0;j--)printf("%d",c[j]);
        printf("\n");
    }
}

