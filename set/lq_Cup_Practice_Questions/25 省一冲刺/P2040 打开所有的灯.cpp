#include <bits/stdc++.h>
#define P pair<int,int>
#define sc scanf
#define pi printf
#define N 1500
#define M 300005
#define INF 0x3f3f3f3f
 using namespace std;
//inline int getmax(int x,int y){return (x>y)?x:y;}
//inline int getmin(int x,int y){return (x>y)?y:x;}
int n,ans=INF,tot,a[13],s[13],how[13];
//inline void get(int n)
//{
//    int cnt=0;
//    memset(s,0,sizeof s);
//    while(n)
//    {
//        s[cnt++]=n%2;
//        n/=2;
//    }
//}
int main()
{
    for(int i=0;i<9;i++) scanf("%d",a+i);//0位置存 
    for(int used=0;used<(1<<9);used++) // 暴力枚举二进制
    {
        get(used); memset(how,0,sizeof how);
        for(int i=0;i<9;i++) //算i号的灯盏被操作了多少次!
            if(s[i]) //9 个格子的打暴力,其实可以变得简洁一些!
            {
                if(!i) how[0]++,how[1]++,how[3]++;
                else if(i==1) how[0]++,how[1]++,how[2]++,how[4]++;
                else if(i==2) how[1]++,how[2]++,how[5]++;
                else if(i==3) how[0]++,how[6]++,how[4]++,how[3]++;
                else if(i==4) how[4]++,how[1]++,how[3]++,how[5]++,how[7]++;
                else if(i==5) how[4]++,how[5]++,how[2]++,how[8]++;
                else if(i==6) how[6]++,how[3]++,how[7]++;
                else if(i==7) how[7]++,how[6]++,how[8]++,how[4]++;
                else if(i==8) how[5]++,how[7]++,how[8]++;
            }
        bool flag=true;
        for(int i=0;i<9;i++)  // 计算是否可行!
            if(how[i]%2==1 && a[i]) flag=false;
            else if(how[i]%2==0 && !a[i]) flag=false;
        if(flag)
        {
            tot=0;
            for(int i=0;i<9;i++) if(s[i]) tot++;
            ans=getmin(tot,ans);
        } 
    }
   printf("%d\n",ans);
   return 0; 
}

