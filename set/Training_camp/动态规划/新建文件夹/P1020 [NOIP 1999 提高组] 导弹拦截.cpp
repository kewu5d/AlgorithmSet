/*
导弹依次飞来，所以不能跳着拦截 

de[i] :第i个导弹是  最多作为第de[i]被一套系统拦截的导弹 
运用动态规划的思想数组名也可以写成dp[i] 

第一发导弹高度可能很低呢，
怎样设置拦截的高度，后续只能单调不增的导弹
 - 每一个导弹初始化为1（表示第1个拦截的导弹）
 - 往前遍历找第一个高度更大或相等的，找到啦就更新当前导弹是（第【找到的导弹是第几个拦截的】 +1）拦截的 
 
本题有两问：
1. 一套系统拦截最多？
2. 最少需要几套系统才能全部拦截（并不一定是在一套系统拦截最多后在分析，而是全局分析最少需要几套）？ 
	- 这里导弹依次飞来，所以每一个导弹飞过来都要及时进行拦截 
	
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int shot[100005];//飞来的导弹高度 
int de[100005];//表示飞来第i枚导弹作为被系统最多第几个拦截
int main()
{
	int i = 1, ans1 = 0; 
	vector<int> ans2;
	//时间复杂度是On^2 
	while (cin >> shot[i]) 
	{
		de[i] = 1;//初始化为1，不能被连续拦截
		for (int j = i-1; j>=1; j--) 
		{
			if (shot[j] >= shot[i])
			{
				de[i] = max(de[i], de[j] + 1);
				if (de[i] > ans1)ans1 = de[i];//找同一套系统最多拦截的导弹数 
				//break;
				//不能找第一个就跳出，需要遍历前面的所有，找到最大合法拦截高度接上 
			}
		}
		//第2问 
		int flag =1;
		for (int j=0; j<ans2.size(); j++) 
		{
			if (ans2[j] >= shot[i])
			{
				ans2[j] = shot[i];//成功拦截，第j个系统最大拦截高度更新 
				flag = 0;
				break;
			}
		}
		if(flag)ans2.push_back(shot[i]);//现有系统都不能拦截，只能新增系统拦截 
		i++;
	}
	
	cout << ans1 << endl;
	cout << ans2.size() << endl;
	return 0;
	
}













