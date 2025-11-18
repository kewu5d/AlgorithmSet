//观察数据范围，时间复杂度得小于n^2 

#include <iostream>
#include <cstdio>
#include <cstring> 
using namespace std;
int a[300010], b[300010];//a原数组，b为差分数组
int sumb[300010];//貌似这题不需要原数组
struct ope	//操作区间 
{
	int l, r;
};
int main()
{
    int n, m;cin >> n>>m;//1~n
    struct ope x[m+1] = { 0 };
    for (int i = 1; i<=m; i++)
    {
    	cin >> x[i].l >> x[i].r;
	}
    for (int i=1; i<=m; i++)
    {
        b[x[i].l]++;
        b[x[i].r+1]--;
    }
    //计算bsum
    for (int i=1; i<=n; i++)
    {
        sumb[i] = sumb[i-1] + b[i];
    }
    int ans = 0;//记录商品数一直为0的商品 
    for (int i = 1; i <= n; i++)if(sumb[i] == 0)ans++;
    //依次单独去除某一个操作
	for (int i = 1;i <= m; i++) 
	{
		int t = 0;
		for (int j= x[i].l; j <= x[i].r; j++) 			//偏向于暴力的解法（有超时的隐患） 
		{//在第i次操作内【l，r】 商品为1就会被减成0 
			if (sumb[j] == 1)t++;
		}
		cout << ans+t << endl;
	}
    
	/*超时 
    int flag =1;
    int cnt = m;//输出m次 
    while(cnt--)
    {
    	//清空b[]和sumb[]
		memset(b, 0, sizeof(b));
		memset(sumb, 0, sizeof(sumb));
        for (int i=1; i<=m; i++)
        {
            //cin >> l >> r;
            if (i == flag)continue;//跳过这次操作 
            b[x[i].l]++;
            b[x[i].r+1]--;
        }
        //计算bsum
        int ans = 0;
        for (int i=1; i<=n; i++)
        {
            sumb[i] = sumb[i-1] + b[i];
            if (sumb[i] == 0){
                ans++;
            }
        }
        cout << ans << endl;
        flag++;//下一个需要跳过的操作数 
    }*/
    return 0;
}
