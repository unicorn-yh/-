/*Description
十年前，北湖还只是一个深坑，未完成蓄水工作。为了确保蓄水工作的顺利进行，我们需要对北湖的蓄水量进行粗略估计。
为了简化运算，我们假设北湖的地面是一维的，每一块宽度都为1，高度是非负整数，那么可以用一个数组来表达一块地面。
例如数组 [0,1,0,2,1,0,1,3,2,1,2,1]可以用来表示下图地面：
北湖深坑 样例解释 图中绿色代表地面部分，蓝色部分代表蓄水部分，蓄水量为 6 。

Input
样例输入有多组。
第一行输入整数 T [1 <= T <= 100] 表示有 T 组用例；
接下来，对于每组用例，输入一个正整数 n (1 <= n <= 100000)，表示地面总宽度为 n 。
接下来一行是 n 个数 ai，用空格隔开，表示地面高度。(0 <= ai <= 1e9)

Output
对于每个用例输出一行一个数字，表示蓄水总量。*/

#include <stdio.h>
long long left[100000]={0},right[100000]={0},height[100000]={0};
main(){
   int n,T,i;
   long long total=0;
   scanf("%d\n",&T);
   for(;T;T--){
       scanf("%d",&n);
       for(i=0;i<n;i++) scanf("%lld",&height[i]);
       left[0]=height[0];        //边缘情况 单独考虑
       right[n-1]=height[n-1];   //边缘情况 单独考虑
       for(i=1;i<n-1;i++){
           if(height[i]<left[i-1])left[i]=left[i-1];
           else left[i]=height[i];
       }
       for(i=n-2;i>0;i--){
           if(height[i]<right[i+1])right[i]=right[i+1];
           else right[i]=height[i];
       }
       total=0;
       for(i=1;i<n-1;i++){         //计算总储水量
           if(left[i]>right[i])total+=(right[i]-height[i]);
           else total+=(left[i]-height[i]);
       }
       printf("%lld\n",total);
   }

}