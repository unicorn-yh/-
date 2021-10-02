/*Description
请编写一个程序，从输入中读取一篇中文文章，并统计出该文章中 ASCII 字符以外的重复出现的每一个字重复出现的次数。
文章使用 UTF-8 编码，可能会出现任何可以用 UTF-8 编码表示的字符（不限于中文）。
文章中所有的字符在 UCS-2 能够表示的范围内，即字符的 Unicode 值用两个字节就可以表示。

Input
一篇文章，总字数不限、每行字符数不限。每个字重复出现的次数不超过 60000 次。

Output
按照 Unicode 编码从小到大的顺序，输出文章中 ASCII (0 ~ 127) 字符以外的每一个重复出现过的字重复出现的次数。
每行包含三项内容，首先是重复的字符（以 UTF-8 编码输出），然后是该字符的 Unicode 编码值
（十六进制输出，字母均使用小写，长度不足 4 位数的用 0 补齐），最后输出该字符的重复次数。
如果文章中没有出现重复的字，则输出No repeat!。*/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct chinesewords{
	int value;
	unsigned char s[5];
}cn[65536];
 
int main(){
	unsigned char a,b,c,d;
	int u,i,flag=0;
	for(i=1;i<=65535;i++) cn[i].value=0;
	while(scanf("%c",&a)!=EOF){
		if((a >> 4)<8) continue;
		else if((a >> 4)==15){
			b=getchar();
			c=getchar();
			d=getchar();
			u=((a & 7)<<18)+((b & 63)<<12)+((c & 63)<<6)+(d & 63);
			cn[u].value++;
			cn[u].s[0]=a;
			cn[u].s[1]=b;
			cn[u].s[2]=c;
			cn[u].s[3]=d;
			cn[u].s[4]='\0';
		}
		else if((a >> 4)==14){
			b=getchar();
			c=getchar();
			u=((a & 15) << 12)+((b & 63) << 6)+(c & 63);
			cn[u].value++;
			cn[u].s[0]=a;
			cn[u].s[1]=b;
			cn[u].s[2]=c;
			cn[u].s[3]='\0';
		}
		else if((a >> 4) >= 12){
			b=getchar();
			u=((a & 31) << 6)+(b & 63);
			cn[u].value++;
			cn[u].s[0]=a;
			cn[u].s[1]=b;
			cn[u].s[2]='\0';
		}
	}
	for(i=1;i<=65535;i++){
		if(cn[i].value>1){
			printf("%s 0x%04x %d\n",cn[i].s,i,cn[i].value);
			flag=1;
		}
	}
	if (flag==0)cout << "No repeat!" << endl;	
	return 0;
}