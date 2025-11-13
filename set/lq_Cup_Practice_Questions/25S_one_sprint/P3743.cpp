/*
1. n台设备、每台每秒消耗ai、每台存储bi个单位能量 
2.  充电宝每秒充p能量 
3. 所有设备一起用，可以用充电宝
4. 永远可以用下去，输出-1
  有设备能量降为0，输出最多使用时长
  
思路：贪心？ 
- 每次优先给能量最低的充 
二分？dp？ 
*/

#include <iostream> 
using namespace std;
const int N = 1e5+5;
double n, p, a[N], b[N];//分数级，半秒也行 
bool check(double time)
{
	double B = time * p;//充电器最多提供的能量 
	for (int i=1; i<=n; i++)
	{
		if (time*a[i] <= b[i])continue;
		else{
			B = B -(time*a[i] - b[i]);
		}
	}
	if (B >= 0)return true;
	else return false;
}
int main()
{
	cin >> n >> p;
	double sum = 0;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i] >> b[i];
		sum += a[i];
	}
	if (sum <= p)
	{
		cout << -1 << endl;return 0;
	}

	double l = 0, r = 1e20, mid;
	while (l < r)
	{
		if (r -l < 1e-5)break;
		mid = (l+r)/2;
		if (check(mid))
		{
			l = mid;
		}
		else r = mid;
	}
	cout << mid << endl;
	return 0;
}

