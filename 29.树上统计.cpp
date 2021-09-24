/*Background
除了上课答疑之外，给同学们出题也是小学期助教的工作之一，今天又轮到Roark出题了。
Roark本打算出这样一道题：
“给出一个有n个节点，n-1条边的连通图，每条边长均为1。
求对于所有的点对 (u,v)，Σ dist(u,v)。其中 dist(u,v) 指的是 (u,v) 之间的最短距离。”
但当他把题目说给DarkDawn时，却得到了这样的答复：
Roark自然不敢违抗DarkDawn的命令T^T，只好稍稍增加了一点难度，题目就变成了现在的样子。

Description
给出一个有n个节点，n-1条边的连通图，每条边长均为1。除此之外，现在原图上的每两个不相邻且仅间隔一个节点的节点间建边，边长仍为1。
求对于所有的点对 (u,v)，Σ dist(u,v)。其中 dist(u,v) 指的是 (u,v) 之间的最短距离。

Input
第一行输入n，表示节点数 (2 <= n <= 200000)。
接下来n-1行每行两个整数 a,b，表示原图在节点a和节点b之间有一条边。

Output
输出Σ dist(u,v) */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXLEN 200010
ll treesize[MAXLEN],distoRoot[MAXLEN],totaldist[MAXLEN],finaldist,oddroot,evenroot;
vector <ll> side[MAXLEN];

void route(ll node,ll cmp){    //计算路径
    for(ll k=0;k<side[node].size();k++){
        ll tmp=side[node][k];
        ll Even=distoRoot[node]%2==0?evenroot:oddroot-1;  //判断节点数
        if(tmp!=cmp){
            totaldist[tmp]=totaldist[node]+Even-treesize[tmp]+1;   //节点距离=父节点距离+节点数-子节点+1
            finaldist+=totaldist[tmp];
            route(tmp,node);
        }
    }
}

void odd_even(ll node,ll cmp,ll root,ll depth){        //找出所有点的奇偶节点数
    for(ll k=0;k<side[node].size();k++){
        ll tmp=side[node][k];
        if(tmp!=cmp){
            if(depth&1==1)oddroot+=1;                  //时刻更新奇偶节点数
            else evenroot+=1;
            distoRoot[tmp]=depth;                      //dist存放每一个节点的距离
            totaldist[root]+=(depth%2)+(depth/2);     // Σ节点到 root的距离   //除2 并向上取整
            odd_even(tmp,node,root,depth+1);          
        }
    }
}

int subtree(ll node,ll cmp){   //找出所有点的子树规模
    for(ll k=0;k<side[node].size();k++){
        ll tmp=side[node][k];
        if(tmp!=cmp)treesize[node]+=subtree(tmp,node);
    }
    return ++treesize[node];
}

int main(){
    ll a,b,n;
    scanf("%lld",&n);
    for(ll i=0;i<=n-2;i++){
        scanf("%lld%lld",&a,&b);
        side[a].push_back(b);
        side[b].push_back(a);
    }
    ll root=a;
    subtree(root,0);             //返回 root 的 treesize
    odd_even(root,0,root,1);     //找出 root 的奇偶节点数 涉及变量：oddroot,evenroot,distoRoot[],totaldist[]
    finaldist+=totaldist[root];   
    route(root,0);               //计算 root 的总路径
    printf("%lld\n",finaldist/2);
    return 0;
}
