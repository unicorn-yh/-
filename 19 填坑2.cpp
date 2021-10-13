/*Description
emmm，还是北湖深坑，不用惊喜，不用意外。
我们继续用石头填！北湖的地面依旧是一维的，每一块宽度都为1，高度是非负整数，用一个数组来表示。
还是提供不限量的1x2规格的石头。但是这一次是 Dark来填坑，他有很强烈的强迫症，
所有的石头只能水平摆放（宽为2，高为1）。问这样是否可以将北湖填平。（所有地面到达同一高度即为填平）

Input
样例有多组输入至文件末尾；每组用例占两行；
第一行输入1个整数 n表示北湖地面总宽度；
第二行输入 n个整数,用空格间隔，表示地面高度。

Output
若能填平则输出“YES”，否则输出“NO”。
*/

#include <bits/stdc++.h>
using namespace std;
#define MAXLEN 200010
long long height[MAXLEN]={0},n;
stack <int> s;
int main(){
    int i;
    while(scanf("%lld",&n)!=EOF){
        int max_index=0, tmp=0;
        memset(height,0,sizeof(height[0]));
        while(!s.empty()) s.pop();
        for(i=0;i<n;i++){
            scanf("%lld",&height[i]);
            if(height[i]>height[max_index])max_index=i;
        }
        for(i=0;i<n;i++){
            if(!s.empty() && height[i]==s.top())s.pop();
            else {
                if(!s.empty() && s.top()<height[i]) break;
                else s.push(height[i]);
            }
        }
        if(!s.size()) printf("YES\n");
        else if(s.size()==1 && s.top()==height[max_index]) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}