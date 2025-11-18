//选数求sum(),isprime()
#include <iostream>
using namespace std;
int x[21];
int ans;int n,k;
bool isprime(int x)
{
	if (x==0 && x==1)return 0;
	for (int i=2; i*i <x; i++)
	{
		if (x%i == 0)return 0;
	}
	return 1;
}
void dfs(int i, int sum, int k)
{
	if (k == 0)
	{//选够了 
		if (isprime(sum))ans++;
		return ;
	}
	//不降原则，i下标开始选 
	for (i; i<=n-k+1; i++)//n-k+1 ,保障从i开始能选k个 
	{					//递归也是一样的 
		dfs(i+1, sum+x[i], k-1);
	}
}
int main()
{
	 cin >> n >> k;
	for (int i=1;i<=n;i++)cin >> x[i];
	//选数
	dfs(1, 0, k);//1下标开始选，和为0，选k个 
	cout << ans << endl;
	return 0;
}
