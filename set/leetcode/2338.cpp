#include <iostream>
#include <vector>
#define ll long long
using namespace std;
const ll mod = 1e9+7;
int n, m;//maxValue
vector<int> a;//int a[10005];//arr:0~n
int ans;//保存答案 
int idealArrays(int n, int maxValue) {
	 
    
}
void dfs(int x)
{
	if (x > n)
	{
		ans++;
		return;
	}
	//从大于等于上一个选数 的数开始选择填入 
	for (int i = !a.empty()?a.back():1; i<=m; i++)
	{
		if (a.size() == 0)
		{//直接放 
			a.push_back(i);
			dfs(x+1);
			a.pop_back();
		}
		else if (i % *(a.end()-1) == 0)
		{
			a.push_back(i);
			dfs(x+1);
			a.pop_back();
		}
	}
}
int main()
{
	cin >> n >> m;
	dfs(1);
	cout << ans << endl;
	return 0;
}




