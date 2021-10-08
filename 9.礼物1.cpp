/*Description
小张的好朋友小松要过生日了，小张打算为他挑选一件礼物。在市场上他发现有一个珠子手镯的商店很不错。
在这家商店会出售特殊的珠子并穿成一个手镯，在货架上珠子排成一排，每一个珠子上有一个小写英文字母。
店家有一个特殊的规定，必须在一排珠子中按顺序从左到右挑选。小张心中已经有一个想要送给小松的单词，
请你告诉他应该如何挑选珠子使得手镯上珠子的字母组成小张想要的单词。

Input
第一行，一个字符串，表示货架上的一排珠子，仅包含小写英文字母，长度在200000以内。
第二行，一个字符串，表示小张想要的单词，仅包含小写英文字母，长度在10000以内。

Output
输出一行整数，表示小张按照从左到右需要挑选的珠子在货架上的位置。

Notes
从左到右按顺序选出的珠子上的字母为'p'，'p'，'y'，'h'，'a'。串成环形的手镯后可以组成"happy"。
数据保证有解，若有多种选取方法，输出其中字典序最小的一个，比如1 2 3 4比1 3 4 5的字典序小。
提交后查看结果页面错误信息一栏，前4行的编译错误大家不用理会，第5行是关于你的结果的信息。*/

#include<stdio.h>
#include<string.h>
char bead[200050],pre[20020];
int len_b,len_p,k,flag,flag_num=0,print_count=0,dp[200050][30],i,j;
long int num[10010],num_temp[10010];
int main()
{
 //存放下标
bead[0]='&';  //一定要给第一个元素，要不然strlen=0
scanf("%s",bead+1);  //从下标1开始存起
scanf("%s",pre);
len_b=strlen(bead)-1;  //因为从1开始存起，真实长度需要-1
len_p=strlen(pre);
for(i=0;i<len_p;i++)num[i]=2147483647;  //初始化成一个最大数，所以第一次比较的时候，num_temp存入num
//创建序列自动机dp开始,d[i][j]=第i位置之后j字符首次出现的位置
    memset(dp,-1,sizeof(dp));  //初始化的值不可能出现，如果出现了就是匹配失败
  //dp[i][j]记录位置i之后j字符第一次出现的位置
  for(j=len_b-1;j>=0;j--)  //从bead的最后第二个开始循环
  {
      for(i=0;i<26;i++)  //i代表从0到25个字符
      {
          if(bead[j+1]-'a'==i)dp[j][i]=j+1;  //-'a'是判断是哪个字符
          else dp[j][i]=dp[j+1][i];
      }
  }
//创建序列自动机结束
strncat(pre,pre,len_p);  //double pre字符串，之后要遍历每个可能的环形组合，例如使用happyhappy字符串，从h到y每次顺次读取5个字符
for(i=0;i<len_p;i++)  //比较的轮数(由pre的长度决定：可能的顺序的组合个数)，每一次的比较，都可能会有新的方法和下标字典序
{     //每次都置零（不被上一次的结果影响），记录每个组合如果匹配成功的下标
    memset(num_temp,0,sizeof(num_temp));
    //用序列自动机查找
    k=0;  //k记录下标,每一次循环可能组合的时候都更新位置成0，每次的子串组合都从0开始找
    flag=0;  //标记是否匹配成功,0代表成功,1代表不成功
    for(j=0;j<len_p;j++)
    {
        //如果等于-1,不匹配
        //pre[i+j]是因为要从短串的每个元素挨个开始，例如happyhappy先从h开始，然后a开始....然后p开始，依次遍历可能的组合：happy,appyh,ppyha,pyhap,yhapp只要是顺着的都是一个子串组合
        //k下标代表位置，二维下标代表要查找的字母(-'a'是因为要转换成数字0~25)
        //pre[i+j]-'a'是每次要查找的字符
        if(dp[k][pre[i+j]-'a']==-1){flag=1;break;}  //=-1也就是在k位置之后没有pre[i+j]-'a'这个字符，不能组成环形，break了继续compare下一个子串，不用记录下标
        k=dp[k][pre[i+j]-'a'];  //更新k的位置，k是下一次开始查找的位置，这样就可以实现跳跃着寻找，不用花时间逐个遍历
        //k位置之后，pre[i+j]-'a'第一次出现的位置
        num_temp[j]=k;  //存入下标

    }
    //判断字典序，如果比较小，才存入num最终答案
         if(j==len_p&&flag!=1)  //j走到最后也就是匹配成功,才比较下标
    {
      //比较字典序，=,<,>的情况,
      //有=继续比较
      //有小过的直接赋给num,然后break
        flag_num=0;
           //先比较num_temp和num,如果num_temp的字典序比较靠前，才赋给num
          for(j=0;j<len_b;j++)  //比较的轮数
          {
              if(num_temp[j]==num[j])continue;
              if(num_temp[j]<num[j])
              {
                  for(int p=0;p<len_p;p++)
                    {
                        num[p]=num_temp[p];
                    }
                    flag_num=1;
                    break;
              }
              else if(num_temp[j]>num[j])break;
              if(flag_num==1)break;
          }

    }
}
//输出答案
for(i=0;i<len_p;i++)
{
    printf("%lld",num[i]);
    if(print_count<len_p-1)printf(" ");
    print_count++;

}
printf("\n");

}