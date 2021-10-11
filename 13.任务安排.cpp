/*Description
小张经常为了事情太多安排不开而苦恼。现在他手头有 n 项任务，每项任务都有一个开始时间 si 和结束时间 ei 。
要想完成一个任务必须从开始时间做到结束时间，并且同一时间小张只能进行一项任务。小张想知道他最多可以完成几项任务。

Input
第一行一个整数 n(1 <= n <= 300000 ) ，表示小张手头任务的个数。
接下来 n 行，每行两个整数 si,ei(1 <= si < ei <= 10^9 ) ，表示任务的开始时间和结束时间。

Output
一行一个整数，表示小张最多可以完成几项任务。*/

#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
struct mission{
    public: 
    int start;
    int end;
}m[300010];
struct oop{
    bool operator()(const mission &i,const mission &j){
        if(i.end!=j.end) return i.end<j.end;
        else return i.start<j.start;
    }
};
int main(){
    int n,count=1;
    cin >> n;
    for(int i=0;i<n;i++) cin >> m[i].start >> m[i].end;
    sort(m,m+n,oop());   //依照 end值，顺序排列从小到大
    int max_end=m[0].end;
    for(int i=1;i<n;i++){
        if(m[i].start>=max_end){
            count++;
            max_end=m[i].end;
        }
    }
    cout << count << endl;
    return 0;
}
