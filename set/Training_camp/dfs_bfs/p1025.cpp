#include<cstdio>
#include<iostream>
using namespace std; 
int n,k,cnt;
void dfs(int last,int sum,int cur)	//current现在的，目前的 
{
    if(cur>k)
    {
        if(sum==n) cnt++;
        return;
    }
    for(int i=last;sum+i*(k-cur)<=n;i++)//剪枝，只用枚举到sum+i*(k-cur)<=n为止
        dfs(i,sum+i,cur);
}
int main()
{
    scanf("%d %d",&n,&k);
    dfs(1,0,1);//这里是从0开始填入位置0，1，2，当cur==3时，得到可行解，进行判断 
    printf("%d",cnt);
}
