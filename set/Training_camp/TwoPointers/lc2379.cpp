#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
//char blocks[105]; 		//= {'\0'}
int minimumRecolors(string blocks, int k)
{
	int l=0, r = l+k-1;//固定窗口长度为k
	int ans = k+1, cnt_w= 0;//[l, r]内W的个数 
	for (int i=l; i<=r; i++)
	{
		if (blocks[i] == 'W')cnt_w++;
	}
	ans = min(cnt_w, ans);
	while (r < blocks.length()-1)
	{
		if (blocks[l++] == 'W')cnt_w--;//移动左指针
		if (blocks[++r] == 'W')cnt_w++;
		ans = min(ans, cnt_w);//找窗口内最少W数
	}
	return ans; 
}
int main()
{
	string blocks;
	int k;
	scanf("%d", &k);
	getchar();	//cin.ignore();//*******************************都行 
	getline(cin, blocks);
	//cout << blocks  << endl;
	int ans =  minimumRecolors(blocks, k);
	printf("%d", ans);
	return 0;
}
/*
7
WBBWWBBWBW

*/
