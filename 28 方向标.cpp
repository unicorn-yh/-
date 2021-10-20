#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 2147483647
ll dp[2005][2005],start[2005],n,result=0;
ll min(ll x,ll y){
    ll ans;
    ans=x>y?y:x;
    return ans;
}
ll max(ll x,ll y){
    ll ans;
    ans=x>y?x:y;
    return ans;
}
int main(){
    scanf("%lld",&n);
    scanf("%lld",&start[0]);
    dp[1][start[0]]=1;
    for(int i=1;i<=n;i++){
        scanf("%lld",&start[i]);
        for(int j=0;j<=n+1;j++){
            ll left=min(start[i-1],j);
            ll right=max(start[i-1],j);
            if(start[i]<=left)dp[i][right]=(dp[i][right]+dp[i-1][j])%mod;
            if(start[i]>=right)dp[i][left]=(dp[i][left]+dp[i-1][j])%mod;
            if(start[i]>left && start[i]<right){
                dp[i][right]=(dp[i][right]+dp[i-1][j])%mod;
                dp[i][left]=(dp[i][left]+dp[i-1][j])%mod;
            }
        }
    }
    for(int i=0;i<=n+1;i++) result=(result+dp[n][i])%mod;
    printf("%lld\n",result);
    return 0;
}