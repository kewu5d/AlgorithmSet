#include <iostream>
#include <cstdio>
using namespace std;
int loan, pay, month;
//财经知识假设利率按月累计：loan = loan*(1+rate) - pay 
//loan*(1+rate)：这就是贷款加利息的过程，利滚利。
//当利率设定过高，会导致无法在指定month内还完甚至利滚利永远还不完 
//所以本题是二分答案题，二分利率rate, 使month后loan趋近于0 
int main()
{
	cin >> loan >> pay >> month;
	//数据保证答案不超过 300.0%,所以r可以为大于3的数 
	double l=0, r=5, mid;//第一次二分分数 
	while (l < r)
	{
		mid = (l+r)/2;
		if (r-l < 0.0001)break;//-----------temp还款趋近于0的另一个角度就是答案rate设定也趋近于0 
		double temp = loan;
		for (int i=1; i<=month; i++)
		{
			temp = temp*(1+mid) - pay;
		}
		if (temp < 0) l = mid;
		//else if (temp < 0.000001 || temp ==0)break;//趋近于0或等于0--------TLE
		else if (temp > 0) //rate设大了
		{
			r = mid;
		}
		else break;//temp == 0
	}
	printf("%.1f\n", mid*100);//*100,百分制
	return 0; 
}
