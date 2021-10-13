/*又是北湖深坑，惊不惊喜，意不意外？！
Rack觉得用水填湖太没意思了，用石头填坑多有意思。假设北湖的地面还是一维的，每一块宽度都为1，高度是非负整数，
用一个数组来表示。现提供不限量的1x2规格的石头，问是否可以将北湖填平。（所有地面到达同一高度即为填平）
注：石头只能水平或垂直填放。

Input
样例有多组输入至文件末尾；每组用例占两行；
第一行输入1个整数n表示北湖地面总宽度；
第二行输入n个整数用空格间隔，表示地面高度。

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
            if((height[max_index]-height[i])%2)tmp=0;
            else tmp=1;
            if(!s.empty() && tmp==s.top())s.pop();
            else s.push(tmp);
        }
        int size=s.size();
        if(size<=1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}