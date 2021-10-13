/*Description
想必同学们已经深刻体会到军训的辛苦了，与此同时我们也应该感谢教官们的辛苦付出。现在请你帮助教官小张解决如下问题吧！
马上集合了，但现在同学们分布在操场各个位置。共有 n 位同学，他们在操场的位置可以用 (xi,yi) 表示。现在小张想知道对于每一个 i ，前 i 个同学集合应该如何选择位置使得所有同学走的总曼哈顿距离最短。

Input
本题为多组数据。第一行一个数， T 表示数据组数。
每组数据第一行一个数 n(1 <= n <= 500000 ) ，表示同学个数。
接下来 n 行，每行两个数 xi,yi(-10^9 <= xi,yi <= 10^9 ) ，表示每个同学位置。
数据保证所有组数据  Σ n <=  500000 。

Output
每组数据第一行输出数据组数的信息（见样例）。
之后 n 行，每行一个数，保留4位小数，表示前 i 位同学集合到同一个点最少走的曼哈顿距离。

Notes
 (x1,y1),(x2,y2) 两点曼哈顿距离为 |x1-x2| +|y1-y2| 。
*/

#include <bits/stdc++.h>
using namespace std;
class getMedian{
	public:
	    priority_queue <long long,vector<long long>,less<long long>> maxHeap;
        priority_queue <long long,vector<long long>,greater<long long>> minHeap;
		getMedian(){};
		void addNum(int num);
		int Median();
};

int getMedian::Median(){
	int median;
	if(minHeap.size()==maxHeap.size()) median=maxHeap.top();
	else if(minHeap.size()<maxHeap.size()) median=maxHeap.top();
	else median=minHeap.top();
	return median;
}

void getMedian::addNum(int n){
	if(maxHeap.empty()){
		maxHeap.push(n);
		return;
	}
	else if(maxHeap.size()==minHeap.size()){
		if(n<=maxHeap.top())maxHeap.push(n);
		else minHeap.push(n);
	}
	else if(maxHeap.size()>minHeap.size()){
		if (n<=maxHeap.top()){
			minHeap.push(maxHeap.top());
			maxHeap.pop();
			maxHeap.push(n);
		}
		else minHeap.push(n);
	}
	else{
		if (n>=minHeap.top()){
			maxHeap.push(minHeap.top());
			minHeap.pop();
			minHeap.push(n);
		}
		else maxHeap.push(n);
	}
}

int main(){
	int T,j;
	scanf("%d",&T);
	for(j=0;j<T;j++){
		printf("Case: %d\n", j+1);
		getMedian m[2];
	    int n,i,j,num[2],median[2],new_median[2];
	    long long ans[2]={0};
	    scanf("%d",&n);
	    for(i=0;i<n;i++){
		    for(j=0;j<2;j++){
			    new_median[j]=median[j];
			    scanf("%d",num+j);
			    m[j].addNum(num[j]);
			    median[j]=m[j].Median();
		    }
		    if(i==0) printf("0.0000\n");
		    else{
			    for(j=0;j<2;j++){
				    if(i%2) ans[j]+=abs(new_median[j]-num[j]);
				    else ans[j]+=abs(median[j]-num[j]);
			    } 
			    printf("%lld.0000\n", ans[0]+ans[1]);
		    }
	    }
	}
	return 0;
}

