#include <iostream>
#include <cstdio>
using namespace std;
int a2, a3, a4, b4,b6;
int main()
{
	int q;cin >> q;//q：数据组数
	while (q--) 
	{
		int ans=0;
		cin >> a2 >>a3>>a4>>b4>>b6;
		//思路：先处理b6,b6变b4，再处理b4-------每个凳子安排完!!!!!
		while (a3 >= 2 && b6>0)
		{
			b6--;a3-=2;
			ans +=6;
		}
		while (a2 > 0 && b6>0)
		{
			a2--;b6--;b4++;
			ans+=2;
		} 
		while (b6>0 && a4 >0)
		{
			b6--;a4--;
			ans+=4;
		}
		//漏处理了---可能余1的a3寝室 
		while (b6 && a3) 
		{
			b6--;a3--;
			ans+=3;
		}
		while (b4>0 && a4>0)
		{
			b4--;a4--;
			ans+=4;
		}
		while (b4>0 && a2 >=2)
		{
			b4--;a2-=2;
			ans+=4;
		}
		while (b4>0 && a3>0)
		{
			b4--;a3--;
			ans+=3;
		}
		//漏处理余1的a2寝室 
		while (b4 && a2) 
		{
			b4--;a2--;
			ans+=2;
		}
		cout << ans << endl;
	}
	return 0;
}
