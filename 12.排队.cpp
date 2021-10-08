/*Description
小张在暑假时间来到工地搬砖挣钱。包工头交给他一项艰巨的任务，将一排砖头按照从低到高的顺序排好。
可是小张的力量有限，每次只能交换相邻的两块砖头，请问他最少交换几次能够完成任务？

Input
第一行一个整数 n(1 <= n <= 300000 ) ，表示砖头数量。
第二行 n 个整数 ai(-1000000000 <= ai <= 1000000000 ) ，表示砖头的高度。

Output
一个整数，表示最少交换几次能够完成任务。*/

#include<stdio.h>
#include<iostream>
using namespace std;
#define MAXLEN 1000010
int a[MAXLEN],b[MAXLEN];    //b：辅助数组
long long count;
void separate_merge_sort(int left,int right){   //归并排序，求逆序
    if(right-left>0){    //区间中元素个数大于 1 就继续分割
        int mid=(left+right)/2;
        int i=left;        //辅助数组的下标
        int m=left;
        int n=mid+1;
        separate_merge_sort(left,mid);
        separate_merge_sort(mid+1,right);
        while(m<=mid||n<=right){     //左或右不为空
            if(n>right||(m<=mid && a[m]<=a[n])) 
                b[i++]=a[m++];    //将左半数组复制到辅助数组
            else{
                b[i++]=a[n++];    //将右半数组复制到辅助数组
                count=count+mid-m+1;   //累加逆序数
            }
        }
        for(i=left;i<=right;i++) a[i]=b[i];   //把排序好的辅助数组复制到 a 数组里
    }
    
}
int main(){
    int n;
    while(cin >> n){
        for(int i=0;i<n;i++) cin >> a[i];
        count=0;
        separate_merge_sort(0,n-1);
        cout << count << endl;
    }
    return 0;
}