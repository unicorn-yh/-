#include<bits/stdc++.h>
using namespace std;
int letter[16],flag=0,bigrot[4][4];   //bigrot 表示大的 16个正方形区域
char m[18][18],m1[18][18],w[16],smallrot[4][4];  //smallrot 表示小的 4*4方块（旋转备用）

int rowcheck(int a){                 //a 代表小行行数，满足返回1，不满足返回0
    for (int i=0;i<16;i++){
        switch(m[a][i]){
            case '0': letter[0]++; break;
            case '1': letter[1]++; break;
            case '2': letter[2]++; break;
            case '3': letter[3]++; break;
            case '4': letter[4]++; break;
            case '5': letter[5]++; break;
            case '6': letter[6]++; break;
            case '7': letter[7]++; break;
            case '8': letter[8]++; break;
            case '9': letter[9]++; break;
            case 'A': letter[10]++; break;
            case 'B': letter[11]++; break;
            case 'C': letter[12]++; break;
            case 'D': letter[13]++; break;
            case 'E': letter[14]++; break;
            case 'F': letter[15]++; break;
        }
    }
    for(int i=0;i<16;i++){
        if(letter[i]==0 || letter[i]>1){
            memset(letter,0,sizeof(letter));
            return 0;
        }
    }
    memset(letter,0,sizeof(letter));
    return 1;
}

int columncheck(){
    for (int i=0;i<16;i++){
        switch(w[i]){
            case '0': letter[0]++; break;
            case '1': letter[1]++; break;
            case '2': letter[2]++; break;
            case '3': letter[3]++; break;
            case '4': letter[4]++; break;
            case '5': letter[5]++; break;
            case '6': letter[6]++; break;
            case '7': letter[7]++; break;
            case '8': letter[8]++; break;
            case '9': letter[9]++; break;
            case 'A': letter[10]++; break;
            case 'B': letter[11]++; break;
            case 'C': letter[12]++; break;
            case 'D': letter[13]++; break;
            case 'E': letter[14]++; break;
            case 'F': letter[15]++; break;
        }
    }
    for(int i=0;i<16;i++){
        if(letter[i]==0 || letter[i]>1){
            memset(letter,0,sizeof(letter));
            return 0;
        }
    }
    memset(letter,0,sizeof(letter));
    return 1;
}

int recover(int c,int d){
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            m[4*(c-1)+i][4*(d-1)+j]=m1[4*(c-1)+i][4*(d-1)+j];
        }
    }
    return 0;
}

int rotate(int num,int c,int d){  //n代表旋转几次，x代表大行行数，y代表第几个方块
    for (int i=0;i<num;i++){
        for (int j=3;j>=0;j--){
            for (int k=0;k<4;k++){
                smallrot[3-j][k]=m[4*(c-1)+k][4*(d-1)+j];
            }
        }
        for (int j=0;j<4;j++){   //把 smallrot 赋值给 m
            for (int k=0;k<4;k++){
                m[4*(c-1)+j][4*(d-1)+k]=smallrot[j][k];
            }
        }
    }
    bigrot[c-1][d-1]=num;
    return 0;
}

int dfs(int a,int b){    //a代表大行行数, b代表旋转的是第几个方块
    if(flag)return 0;    //递归终止条件
    if(b==4){
        for(int i=0;i<4;i++){
            rotate(i,a,b);
            if(rowcheck(4*(a-1))){
                flag=1;
                return 0;
            }
            else{
                recover(a,b);
                bigrot[a-1][b-1]=0;
            }
        }
    }
    else{
        for(int i=0;i<4;i++){
            rotate(i,a,b);
            dfs(a,b+1);
            if(rowcheck(4*(a-1))){
                flag=1;
                return 0;
            }
            else recover(a,b);
        }
    }
    return 0;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        flag=0;
        for(int i=0;i<16;i++){
            scanf("%s",&m[i]);
            for (int j=0;j<16;j++) m1[i][j]=m[i][j];
        }
        for(int k=1;k<5;k++){//此时i代表大行的行数(从1开始)
            flag=0;
            dfs(k,1);
        }
        for (int a1=0;a1<2;a1++){
            for (int a2=0;a2<2;a2++){
               for (int a3=0;a3<2;a3++){
                    for (int a4=0;a4<2;a4++){   
                        w[0]=m[0][0+3*a1];
                        w[1]=m[1][0+3*a1];
                        w[2]=m[2][0+3*a1];
                        w[3]=m[3][0+3*a1];
                        w[4]=m[4][0+3*a2];
                        w[5]=m[5][0+3*a2];
                        w[6]=m[6][0+3*a2];
                        w[7]=m[7][0+3*a2];
                        w[8]=m[8][0+3*a3];
                        w[9]=m[9][0+3*a3];
                        w[10]=m[10][0+3*a3];
                        w[11]=m[11][0+3*a3];
                        w[12]=m[12][0+3*a4];
                        w[13]=m[13][0+3*a4];
                        w[14]=m[14][0+3*a4];
                        w[15]=m[15][0+3*a4];
                        if(columncheck()) goto f;
                        for (int i=0;i<4;i++) bigrot[3][i]=(bigrot[3][i]+2)%4;
                    }
                    for (int i=0;i<4;i++) bigrot[2][i]=(bigrot[2][i]+2)%4;           
                }
                for (int i=0;i<4;i++) bigrot[1][i]=(bigrot[1][i]+2)%4;
            }
            for (int i=0;i<4;i++) bigrot[0][i]=(bigrot[0][i]+2)%4;
        }
    f:
        int result=0,result1=0;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++){
                result+=bigrot[i][j];
                result1+=(bigrot[i][j]+2)%4;
            }
 
        if(result<result1){
            printf("%d\n",result);
            for(int j=0;j<4;j++){
                for(int k=0;k<4;k++){
                    for(int m=0;m<bigrot[j][k];m++) printf("%d %d\n",j+1,k+1);
                }
            }
        }
        else{
            printf("%d\n",result1);
            for(int j=0;j<4;j++){
                for(int k=0;k<4;k++){
                    for(int m=0;m<(bigrot[j][k]+2)%4;m++) printf("%d %d\n",j+1,k+1);
                }
            }
        }
    }
    return 0;
}

/*INPUT
1
681D5A0C9FDBB2F7
0A734B62E167D9E5
5C9B73EF3C208410
F24ED18948A5CA63
39FAED5616400B74
D120C4B7CA3DEF38
7EC829A085BE6D51
B56438F129F79C2A
5C7FBC4E3D08719F
AE8B1673BF42A58D
60D3AF25619C30BE
294190D8EA57264C
C7D1B35606835EAB
AF52A1E019BE4306
8B36DC78D425F7C9
E409492FC7FA18D2
*/