#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
//char blocks[105]; 		//= {'\0'}
int minimumRecolors(string blocks, int k) {
    int l= 0, r= k-1;	//string从0开始存储 
	int ans = k; // 初始化为可能的最大值（全白的情况）//******************************
	int x=0;
	//cout << blocks.length() << endl;
	while (r <= blocks.length())
	{
		for (int i = l; i <= r; i++)
		{		
			if (blocks[i] == 'W')
			{
				x++;
			}
		}
		ans = min(ans, x);
		x=0;
		l++;
		r++;
	}
	return ans;
}
int main()
{
	string blocks;
	int k;
	scanf("%d", &k);
	getchar();	//***************************************************都行 
	//cin.ignore();
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
