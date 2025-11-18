#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
double n; 
double ans;
struct node
{
	int idx;
	double t;
}t[1005];
bool cmp(node x, node y)
{
	return x.t < y.t;
}
int main()
{
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> t[i].t;
		t[i].idx = i;
	}
	int temp = n;
	sort(t+1, t+1+temp, cmp);
	double len = n-1;
	for (int i=1; i<=n; i++)
	{
		ans += t[i].t * len / n;
		len--;
	}
	for (int i=1; i<=n; i++)cout << t[i].idx << ' ';
	cout << endl;
	printf("%.2f", ans);
	return 0;
	
}
