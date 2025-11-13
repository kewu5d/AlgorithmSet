#include <iostream>
#include <cstdio>
using namespace std;
int n, k;int last;//上一个填入的数1<=last<=n-1,下一个数last<=x<=n-1//初始化为0
int ans;
int summ[10] = {0};//已填入数的和
int qsum(int idx)
{
	int sum=0;
	for (int i=1;i<=idx; i++)
	{
		sum += summ[i];
	}
	return sum;
}
void dfs(int idx)
{
	int total = 0;	//目前所排总数 
	if (idx > k)
	{
		total = qsum(idx);
		if (total == n) 
		{
			ans++;
		}
		return;
	}
	 
//	while(idx<=k) 
//	{//合法填入 
		for (int i=1;i <= n-1;i++)//在1~n-1中选数填入 
		{
			if (i >= last)//升序（不降序） 填入 --------剪枝1 *********
			{
				summ[idx] = i;
				last = i;//更新last，为下个位置选择铺垫 
				total = qsum(idx);
				if (total > n) 
				{
					return;//结束深搜 ----------剪枝2 **********
				}
				//高级剪枝**********
				if (total+i*(k-idx) > n) return;//之后的位置均要填入大于等于i的数，假设最小都填i，结果仍大于n，直接返回 
				else dfs(idx+1);//合法，继续填下一个位置 
				//回溯********** 
				summ[idx] = 0;
				last = summ[idx-1];//****
			}
		}
//	}
	//当idx>k时，填入完成得到一个可行解，判断是否为答案解
	
}
int main()
{
//	cin >> n >> k;
	scanf("%d %d", &n, &k);
	dfs(1);//填第一个位置的值 
	printf("%d\n", ans);
	return 0;
}
