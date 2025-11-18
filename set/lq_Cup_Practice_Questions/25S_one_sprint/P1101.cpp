#include <iostream>
using namespace std;
char mat[105][105];
int n, flag[105][195];//标记是否完全匹配上，1匹配上用于最后的输出
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};//顺时针 
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
char match[8] = "izhong";//0~5
int main()
{
	cin >> n;
	for (int i=0; i<n; i++) 
	{
		cin >> mat[i];
	}
	///cout << mat[0][0] << endl;
	//时间复杂度O(48*n^2) 
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			//对当前点（i，j）遍历8个方向
			if (mat[i][j] == 'y')
			{
				for (int k=0; k<8; k++)
				{//枚举方向 
					int xx = i, yy = j, cnt= 0;
					for (int m=0; m<6; m++)
					{//该方向匹配次数 
						xx += dx[k];
						yy += dy[k];
						if (xx>=0 && xx<n && yy>=0 && yy<n && mat[xx][yy] == match[m])
						{
							cnt++;
						}//
						else break;
					}
					if (cnt == 6)
					{//完全匹配才打标记，不要先打标记没匹配上再取消标记，因为同一个字母可能是多个单词公用的 
						while(cnt)
						{
							flag[xx][yy] = 1;
							xx -= dx[k];//回退 
							yy -= dy[k];
							cnt--;
						}
						flag[xx][yy] = 1;//枚举点（i，j） 
					}
					
				}
			}
		}
	}
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			if (flag[i][j])cout << mat[i][j];
			else cout << '*';
		}
		cout << '\n';
	}
	return 0;
}
