

//一眼二分答案，最小化最远跳跃距离 

//使用超能力一次，L变2L
//- 再挑不到的时候用 
//仔细分析：：一次超能力相当于多一次添加检查点的次数
//				但检查点并没有增加 

#include <iostream> 
#include <algorithm> 
using namespace std;

int n, m, a[100005];
int vis[1];//是否使用超能力 
void dfs()
{
	
} 
bool check(int l)
{
	if (m*l >= a[n])return true;//还是会TLE 
	int cnt =0, now = 0;
	//int x = m;//添加次数 
	for (int i=1; i<=n ;i++)
	{
		if(now + l >= a[i])
		{
			now = a[i];
		}
		else {
			now += l;
			i--;//这点还没有跳到，搭配i++，继续跳a[i] 
			cnt++; 
		}
	}
	cnt--;
	return cnt <= m;
}
int main()
{
	cin >> n >> m;
	for (int i=1; i<=n; i++)cin >> a[i];
	
	int l = 0, r = 1e8, mid;
	int ans = 1e9;
	while (l <= r)
	{
		mid = (l+r)/2;
		if (check(mid))
		{//L设置过大，还能再小点，求最小值 
			ans = min(ans, mid);
			r = mid-1;
		}
		else l = mid+1;
	}
	
	cout << ans << endl;
	return 0;
}


