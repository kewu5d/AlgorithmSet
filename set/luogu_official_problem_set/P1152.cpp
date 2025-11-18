#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long 
using namespace std;
vector<ll> a;
int n = 0;//1~n 
int vis[1005] = {0};
int main()
{
	cin >> n;//疑惑输出，题目没有给单独对n的输出样例 
	ll temp;
	for (int i=0; i<n; i++){
        cin >> temp;
		a.push_back(temp);
	}
	//sort(a.begin(), a.end() + len);不能对其排序，可以对差值排队 
	
	int flag = 0;
	for (int i=1; i<n; i++)
	{
		ll x;
		if (a[i] >= a[i-1]) x = a[i] - a[i-1];
		else x = a[i-1] - a[i];//或者使用abs函数 
		if ( x <=n-1 && vis[x] == 0) {
			vis[x] = 1;
		}
//		else if(vis[x] == 1){
//			flag++;	//重复的不能超过2个 ,运行有一个 
//			if (flag >= 2)break;
//		}
		else {
			flag =1;break;
		}
	}	
	if (flag)cout << "Not jolly" << endl;
	else cout << "Jolly" << endl;
	return 0;
	
}
