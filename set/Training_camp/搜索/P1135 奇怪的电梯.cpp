#include <iostream>
#include <queue>
using namespace std;
int n, k[205], a,b;//起点a，终点b 
int main()
{
	cin >> n >> a >> b;
	for (int i=1; i<=n; i++)cin >> k[i];
	queue<int> qu;
	qu.push(a);
	while (!qu.empty())
	{
		int now = qu.front();
		qu.pop();
		for(int i=0; i<=1; i++)
		{
			if (i==0)
			{//上 
				
			}
			else
			{//下 
				
			} 
		}
	}
	
	
}
