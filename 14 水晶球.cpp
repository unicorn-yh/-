/*Description
和许多同龄女孩子一样，久莲也喜欢水晶球。还有 10 天，就是心心念念的他生日了。
久莲希望把全世界最大最好看的水晶球送给他。她找到了宝石收藏家亚瑟斯，希望能够寻求他的帮助。
亚瑟斯很快被打动了，拿出了精心收集的 n 块美丽的水晶石，这些水晶石初始是长宽高分别为 a,b,c 的长方体。
亚瑟斯许诺久莲可以从中取走 1 块水晶石作为她礼物的原材料。
同时亚瑟斯有一种魔法，如果这两块长方形水晶石在某一个面能够完美的契合在一起（完美的契合是指这两个长方形面全等），
那么可以将它们融合成一块完整的大石头，如果真的实现的话，那么久莲就可能打磨出更大的水晶球啦！
久莲太希望把最美最大的水晶球送给他了，你快帮帮她如何选择吧。

Input
第一行输入一个正整数 n (1 <= n <= 10^5)；
接下来 n 行中，第 i 行输入三个正整数 ai,bi,ci (1 <= ai,bi,ci <= 10^9) 表示第 i 块水晶石的长宽高。
注意可能有两个长得一模一样的水晶石，但是在这种情况下还是将它们视作是两块不同的水晶石。

Output
第一行请输出一个正整数 k (1 <= k <= 2)，表示久莲选择的水晶球数量。
第二行请输出 k 个正整数，如果 k=1，请输出一个正整数 x (1 <= x <= n) 表示久莲选择的水晶石。
如果 k=2，则请输出两个正整数 x,y (1 <= x,y <= n) （用空格间隔），表示久莲希望亚瑟斯帮她将编号为 x 和 y 
的水晶石融合成一块更大的水晶石，并选择用这块水晶石来打磨加工。请注意，这两块水晶石必须满足 “完美契合” 的条件，
否则这个选择不合法。如果有多种最优的选择，则你可以输出任意一种合法的最优方案。

Hint
对于样例，如果久莲选择第六个水晶球，那么她可以打磨成半径为 r=2.5 的水晶球，这是最优的选择。*/

#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAXLEN 100010

struct rect{
   public:
   long long height, width, length, index;
}r[MAXLEN];

bool cmp(struct rect x, struct rect y){
    if(x.length!=y.length) return x.length>y.length;    //按长度排序
    else if(x.width!=y.width) return x.width>y.width;  //按宽度排序
    else return x.height>y.height;                     //按高度排序
}

int main(){
    long long n,x=0,y=0,maxheight=0,i;     
    cin >> n;
    for(i=0;i<n;i++){             //水晶不合并
        long long tmp[3];
        cin >> tmp[0] >> tmp[1] >> tmp[2];
        sort(tmp,tmp+3);              //顺序排列
        r[i].length=tmp[2];
        r[i].width=tmp[1];
        r[i].height=tmp[0];
        r[i].index=i+1;
        if(r[i].height>maxheight){
            maxheight=r[i].height;   //不断更新最高的高度
            x=r[i].index;            //记录下标，不合并时只取 x
        }
    }
    sort(r,r+n,cmp);               //对结构体数组，按照长宽高进行排序
    for(i=0;i<n-1;i++){
        if(r[i].length==r[i+1].length && r[i].width==r[i+1].width){   
            long long tmp =r[i].height+r[i+1].height;   //合并
            if(tmp>r[i].width) tmp=r[i].width;          //寻找水晶体的最短边
            if(tmp>maxheight){             
                maxheight=tmp;                        //更新两个水晶的最大高度
                x=r[i].index;                         //记录下标          
                y=r[i+1].index;
            }
        }
    }
    if(!y) cout << '1' << endl << x << endl;
    else cout << '2' << endl << x << ' ' << y << endl;
    return 0;
}
