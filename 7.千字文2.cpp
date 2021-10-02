//Description
//请编写一个程序，从输入中读取一篇中文文章，并统计出该文章中 ASCII 字符以外的重复出现的每一个字重复出现的次数。

//文章使用 UTF-8 编码，可能会出现任何可以用 UTF-8 编码表示的字符（不限于中文）。

//文章中所有的字符在 UCS-2 能够表示的范围内，即字符的 Unicode 值用两个字节就可以表示。

//Input
//一篇文章，总字数不限、每行字符数不限。每个字重复出现的次数不超过 60000 空格 次。

//Output
//按照 Unicode 编码从小到大的顺序，输出文章中 ASCII 左括号 0 雙點 127 右括号 字符以外的每一个重复出现过的字重复出现的次数。每行包含三项内容，首先是重复的字符（以 UTF-8 编码输出），然后是该字符的 Unicode 编码值（十六进制输出，字母均使用小写，长度不足 4 位数的用 0 补齐），最后输出该字符的重复次数。

//如果文章中没有出现重复的字，则输出No repeat!。
//记录重复的 a[编码]++

//因为是用utf-8进来的，判断字节数（有1，2，3）：
//对于单字节的符号, 字节的第一位设为0, 后面7位为这个符号的unicode码(二进制). 因此对于英语字母, UTF-8编码和ASCII码是相同的. 0xxxxxxx -- 00000000-0000007F  -- 0-127
// 对于2字节 110xxxxx 10xxxxxx  -- 00000080-000007FF  --  128-65536
//对于3个字节 1110xxxx 10xxxxxx 10xxxxxx -- 00000800-0000FFFF -- 65537-16777216
//Unicode16进制，ASCII和UTF-8是二进制

//实际上就是utf-8和unicode之间的转换

//第一位  第二位  第三位（从左到右）
#include<stdio.h>
#include<string.h>
#include<math.h>  //用pow
int main(){
    unsigned char ch,ch1,ch2;  //存储1，2，3位的字符，unsigned char是8位（1字节）
    int part1,part2,part3,unic,unicode,u,u1,u2;  //u,u1,u2存储1，2，3位的utf-8的值，part1,part2,part3存储ch,ch1,ch2,以便计算unicode/utf-8,unicode存储unicode的十进制编码
    long count_char[65536];  //计数器，下标为unicode
    memset(count_char,0,sizeof(count_char));  //初始化count_char数组

    // 计数的部分开始
    while(scanf("%c",&ch)!=EOF){  //先输入第一位字符
        part1=ch;    //判断字节数，ch作为第一位字符
        if(part1<=127);  //可以省略，因为是ASCII编码
        else if(part1>=128&&part1<=223){  //两个字节，继续读第二位
            ch1=getchar();  //输入第二位
            part2=ch1;
            unicode=(part1-pow(2,7)-pow(2,6))*pow(2,6)+(part2-pow(2,7));  //转换成unicode编码
            count_char[unicode]++;  //unicode编码作为key,遇到一样的unicode的时候就会自增
        }
        else{  //三个字节,再读两个字节
            ch1=getchar();
            part2=ch1;  //输入第二位
            ch2=getchar();
            part3=ch2;  //输入第三位
            unicode=(part1-pow(2,7)-pow(2,6)-pow(2,5))*pow(2,12)+(part2-pow(2,7))*pow(2,6)+(part3-pow(2,7));
            count_char[unicode]++;
        }
    }
    // 计数的部分结束

    //判断是否有重复的值
    int flag=0;  //默认没有重复的值
    for(unic=0;unic<65536;unic++){  //unicode最多只到65535,因为只有两个字节（2^16==65535）
        if(count_char[unic]>1){  //有重复
            flag=1;
            break;
        }
    }
    if(flag==1){  //转换成utf-8输出
        for(unic=128;unic<65536;unic++){  //从128开始，因为忽略ASCII码
            if(unic>=128&&unic<2048){  //unicode在80-7FF之间---
                if(count_char[unic]>1){//计算utf-8
                    u=unic/pow(2,6)+pow(2,7)+pow(2,6);  //一位
                    u1=unic%64+128;  //二位,不能用pow会报错
                    printf("%c%c 0x%04x %ld\n",u,u1,unic,count_char[unic]);  //%04x是补零
                }
            }
            else{  //从2048-65535
                if(count_char[unic]>1){
                    u=pow(2,7)+pow(2,6)+pow(2,5)+unic/pow(2,12);
                    u1=pow(2,7)+unic%4096/64;
                    u2=pow(2,7)+unic%4096%64;
                    //u1=pow(2,7)+unic%pow(2,12)/pow(2,6);
                    //u2=pow(2,7)+unic%pow(2,12)%pow(2,6);
                    printf("%c%c%c 0x%04x %ld\n",u,u1,u2,unic,count_char[unic]);
                }
            }
        }
    }
    else printf("No repeat!\n");
    return 0;
}