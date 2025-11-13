#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int l, n, k;
int sign[N];//第i个标志距起点距离 
int index;//最大距离--空旷指数 
int main()
{
	cin >> l >> n >> k;//最多增k个 
	for (int i=1; i<=n; i++)
	{ 
		cin >> sign[i];//递增排序好了 
		if (sign[i] - sign[i-1] > index)
			index = sign[i] - sign[i-1];
	}
	int l = 1, r = index, mid;//l从1开始，mid（分母）不能w为0 
	while (l <= r)
	{
		mid = (l + r)/2;//最小化最大距离（空旷指数） 
		//在上一个路标距离mid以内必须有下一个路标 
		int temp= 0; 
		for (int i=2; i<=n; i++)
		{//在原有路标间新增new路标 
			if ((sign[i]-sign[i-1])%mid != 0){
				temp += (sign[i]-sign[i-1])/mid;
			}
			else temp += (sign[i]-sign[i-1])/mid -1;
		}
		if (temp > k)l = mid+1;
		else r = mid-1;
	}
	cout << l << endl;
	return 0;
}
