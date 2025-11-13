//6人桌优先放3人寝室。4人桌优先放4人，在放2人，在3人 
#include <iosstream>
#include <cstdio>
using namespace std;
struct B4
{
	int n;
	int num = 4;
}
struct B6
{
	int n;
	int num = 6;
}
struct S
{
	int a2, a3, a4;
	struct B4 b4;
	struct B6 b6;
 } 
 struct S[105];
int main()
{
	int q;cin >> q;
	for (int i= 0;i <q;i++)
	{
		cin >> S[i].a2 >> S[i].a3 >> S[i].a4 >> S[i].b4.b >> S[i].b6.b;
	}
	while (q--)
	{
		int ans = 0;
		//优先b4 
		while (S[q].b4.n > 0) 
		{
			//放a4 
			if(S[q].b4.num >= 4 && S[q].a4>0) 
			{
				ans += 4;
				S[q].a4--;
				S[q].b4.num -= 4;
				if (S[q].b4.num == 0) 
				{
					S[q].b4.n--;
					continue;
				}
			}
			//a4空
			//放a2,a2%2 == 0 (成对放入)
			//放a2 
			if (S[q].b4.num >= 4 && S[q].a2>0 && S[q].a2 % 2 ==0)
			{
				ans += 4;
				S[q].a2 -= 2;
				S[q].b4.num -= 4;
				if (S[q].b4.num == 0) 
				{
					S[q].b4.n--;
					continue;
				}
			}//否则我们放a3 
			else if(S[q].b4.num >= 4 && S[q].a3>0) 
			{
				ans += 3;
				S[q].a3--;
				S[q].b4.num -= 3;
				S[q].b4.n--;
				continue;//b4中放了3，就不能放别的了 
			}
		}
		
		while(S[q].b6.n > 0)
		{
			//放a3 
			if (S[q].b6.num >= 3 && S[q].a3>0 )
			{
				ans += 3;
				S[q].a3--;
				S[q].b6.num -= 3;
				if (S[q].b6.num == 0) 
				{
					S[q].b6.n--;
					continue; 
				}
				continue;//a3还有，继续放a3 
			}
			//放a4 
			if(S[q].b6.num >= 4 && S[q].a4>0) 
			{
				ans += 4;
				S[q].a4--;
				S[q].b6.num -= 4;
				if (S[q].b6.num == 0) 
				{
					S[q].b6.n--;
					continue;
				}
			}
			//放a2 
			if (S[q].b6.num >= 2 && S[q].a2>0)
			{
				ans += 2;
				S[q].a2--;
				S[q].b6.num -= 2;
				if (S[q].b6.num == 0) 
				{
				S[q].b6.n--;
				continue;
				}
			}
		}

	}
	
}

