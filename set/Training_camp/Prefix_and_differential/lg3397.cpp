#include <cstdio>
#include <iostream>
using namespace std;
int a[1005][1005];	//差分标记数组 → 前缀和数组(原地转换)

int main()
{
    int n, m;
    cin >> n >> m;
    int x1, y1, x2, y2;
    for (int i = 1; i <= m; i++) 
    {
        cin >> x1 >> y1 >> x2 >> y2;
        a[x1][y1] += 1;
        a[x1][y2+1] += -1;
        a[x2+1][y1] += -1;
        a[x2+1][y2+1] += 1;
    }
    //原地计算:从左到右、从上到下遍历
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // 此时 a[i][j-1] 和 a[i-1][j] 已经是前缀和
            // a[i][j] 还是原始差分值
            a[i][j] = a[i][j-1] + a[i-1][j] + a[i][j] - a[i-1][j-1];
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    
    return 0;
	/*优化点：
	- 空间优化: 删除 suma 数组,直接在 a 数组上原地计算前缀和,节省约 4MB 内存(1005×1005×4字节)
	- 核心思想: 二维差分后原地计算前缀和,无需额外存储空间
	- 关键点: 
	1.当a[i][j]用作计算前缀和时,只依赖左边和上边的值,而这些值已经被计算过了
	2.当a[i][j]用作二维差分，只影响右边和下边未来的前缀和的值
	*/
}
