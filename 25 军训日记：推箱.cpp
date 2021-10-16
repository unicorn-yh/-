#include<bits/stdc++.h>
using namespace std;
long long a[200010]={0},sum,aver,maxaver=0;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){ 
        scanf("%lld",&a[i]);
        sum+=a[i];
        aver=sum/i;
        if(aver>maxaver)maxaver=aver;
    }
    printf("%lld\n",maxaver); 
    return 0;
}