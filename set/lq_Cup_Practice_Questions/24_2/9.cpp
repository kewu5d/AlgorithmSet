/*
小蓝有一个 n 行 m 列的矩阵 a[i][j] ，他想在矩阵中找出一个"口"字形状的区域，使得区域上的值的和最大。
具体讲，一个"口"字形状的区域可以由两个坐标 (x1, y1) 和 (x2, y2) 确定，满足：
1 <= x1 < x2 <= n ； 
1 <= y1 < y2 <= m ； 
x2 - x1 = y2 - y1 。 
区域上的值是指对应区域的所有点的值，即"口"字的框上的值，不含框内和框外的值。
【输入格式】
输入的第一行包含两个整数 n, m ，分别表示行数和列数。
接下来 n 行，每行包含 m 个整数，相邻数之间使用一个空格分隔，依次表示矩阵的每行每列的值，本部分的第 i 行第 j 列表示 a[i][j] 。
【输出格式】
输出一行包含一个整数，表示最大的和。

【样例输入】
5 6
1 -1 2 -2 3 -3
-1 2 -2 3 -3 4
2 -2 3 -3 4 -4
-2 3 -3 4 -4 5
3 -3 4 -4 5 -5
【样例输出】
4
*/

#include <iostream>
using namespace std;
int main()
{
	int n, m;	//n:行数 m:列数 
	cin >> n >> m;
	//int a[305][305];
	int a[n + 1][m + 1];
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}
	int max_Sum = a[1][1] + a[1][2] + a[2][1] + a[2][2]; 		//（为0不妥！，这里可以赋个已知（随便找个口）总和值数，或者无穷小量）
	//cout << max_Sum << endl;
	//原谅我自卑，我真的很怕暴力 
	//选择“口 ”
	//左上角（x1, y1） 
	for (int x1 = 1; x1 <= n; x1++) 
	{
		for (int y1 = 1; y1 <= m; y1++)
		{
			//右下角（x2, y2） 
			//通过加边side法实现，正方口形 
			for (int side = 1; x1 + side <= n && y1 + side <= m; side++) 	//判断条件：不可以越界 
			{
				int x2 = x1 + side;
				int y2 = y1 + side;	//(x2, y2)
				
				int sum = 0;	//sum置零 
				//将口拆分求和
				//左边一竖(y定)
				for (int i = x1; i <= x2; i++) 
				{
					sum += a[i][y1];
				}
				//右边一竖
				for (int i = x1; i <= x2; i++) 
				{
					sum += a[i][y2];
				}
				//上边(x定)
				for (int i = y1 + 1; i < y2; i++) 
				{
					sum += a[x1][i];
				}
				//下边
				for (int i = y1 + 1; i < y2; i++) 
				{
					sum += a[x2][i];
				} 
				//得到此时这个口字的总和sum 
				
				cout << sum << endl; 
			
				//max_Sum = max{max_Sum, sum};
				if (max_Sum < sum)
				{
					max_Sum = sum;
				}
			}
		}
	}
	cout << max_Sum << endl;
	return 0;
}
/*
#include <iostream>  
#include <vector>  
#include <algorithm>  
using namespace std;  

int main() {  
    int n, m;  
    cin >> n >> m;  

    // 输入矩阵  (vector向量)
    vector<vector<int>> a(n + 1, vector<int>(m + 1));  
    for (int i = 1; i <= n; i++) {  
        for (int j = 1; j <= m; j++) {  
            cin >> a[i][j];  
        }  
    }  

    int maxSum = INT_MIN; // 初始化最大值为负无穷  （为0不行！，这里可以赋个已知（随便找个口）总和值数） 

    // 枚举左上角 (x1, y1)  
    for (int x1 = 1; x1 <= n; x1++) {  
        for (int y1 = 1; y1 <= m; y1++) {  
            // 枚举右下角 (x2, y2)，并保证是*****正方形****
            //通过同时加边 
            for (int side = 1; x1 + side <= n && y1 + side <= m; side++) {  
                int x2 = x1 + side;  //（x2, y2） 
                int y2 = y1 + side;  

                // 计算“口”字形状的边框和  
                int sum = 0;  

                // 左边一竖  
                for (int x = x1; x <= x2; x++) {  
                    sum += a[x][y1];  
                }  

                // 上面一横  
                for (int y = y1 + 1; y <= y2; y++) {  
                    sum += a[x1][y]; //y1+1:避免重复计算正方形的左上顶角元素 
                }  

                // 右边一竖  
                for (int x = x1 + 1; x <= x2; x++) {  
                    sum += a[x][y2];  //x1+1:避免重复计算正方形的右上顶角元素
                }  

                // 下面一横  
                for (int y = y1 + 1; y < y2; y++) {  
                    sum += a[x2][y];  //y1 + 1; y < y2：同时避免重复计算左下、右下元素 
                }  

                // 更新最大值  
                maxSum = max(maxSum, sum); 	//C语言中没有 
            }  
        }  
    }  

    // 输出结果  
    cout << maxSum << endl;  

    return 0;  
}
*/
