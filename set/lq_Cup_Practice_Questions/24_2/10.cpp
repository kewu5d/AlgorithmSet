/*小蓝正在玩一个寻宝游戏。寻宝游戏在一个方格图上进行。方格图中的每一个格子都有一个坐标 (r, c)，
其中越往北 r 越小，越往南 r 越大，越往东 c 越大，越往西 c 越小。
南北相邻方格的 c 坐标相同，r 坐标差一。东西相邻方格的 r 坐标相同， c 坐标差一。
游戏开始时，小蓝站在 (0, 0) 处，面向北边。游戏区域无限大，且没有障碍。每一步，小蓝控制自己的角色走一步，他可以有如下三种选择：
向前走：朝现在的方向前进到相邻的方格中，并保持当前的方向。 
向左走：向左转90度，并前进到相邻的方格中（即进入到原来左边的方格），面向的方向变为了原来的左边。 
向右走：向右转90度，并前进到相邻的方格中（即进入到原来右边的方格），面向的方向变为了原来的右边。 
小蓝玩了一会儿，一共走了 n 步，他记录了自己的每一个动作。但是他没有找到宝藏。
他怀疑前面的某一步出现了失误。他想知道，如果他改变之前的某一步，能到的位置有哪些。
由于这个太复杂，他想知道最终到的位置（第 n 步后到的位置）有多少种。
【输入格式】
输入的第一行包含一个整数 n ，表示小蓝走了 n 步。
第二行包含一个长度为 n 的由大写字母组成的字符串，依次表示小蓝走的每一步。字母 F 、 L 、 R 分别表示对应的步是向前走、向左走、向右走。
【输出格式】
输出一行，包含一个整数，表示如果改变某一步，可以到的位置的种类数。

【样例输入】
3
FLR
【样例输出】
6		---->这里包括每一步改成另外两种情况时的最终位置的情况。 
*/
//思路：
#include <iostream> 
using namespace std;
typedef struct
{
	int r = 0;
	int c = 0;
}all_Position;
all_Position p[100005];
int x;	//记录p[x] 
//设为全局、初始条件 
int r, c;
char dirction = 'N';	//N、S、W、E 

//计算最终位置函数 
void location(char* a, int n)
{
	for (int i = 0; i < n; i++) 
	{
		if (a[i] == 'F')
		{
			switch (dirction)
			{
				case 'N':
					r--;
					//不需要更新朝向 
					//******不要忘记break****** 
					break;
				case 'S':
					r++;
					break;
				case 'W':
					c--;
					break;
				case 'E':
					c++;
					break;
			}
		}
		else if (a[i] == 'L')//需要跟新朝向 
		{
			switch (dirction)
			{
				case 'N':
					c--;
					dirction = 'W'; 
					break;
				case 'S':
					c++;
					dirction = 'E';
					break;
				case 'W':
					r++;
					dirction = 'S';
					break;
				case 'E':
					r--;
					dirction = 'N';
					break;
			}
		}
		else if (a[i] == 'R')//需要跟新朝向 
		{
			switch (dirction)
			{
				case 'N':
					c++;
					dirction = 'E'; 
					break;
				case 'S':
					c--;
					dirction = 'W';
					break;
				case 'W':
					r--;
					dirction = 'N';
					break;
				case 'E':
					r++;
					dirction = 'S';
					break;
			}
		}
		//cout << "目前位置：" << r << ' ' << c << endl;
	}
}
//改变某一步，与原来最终位置不同情况函数
int differ(char* a, int n) 
{ 
	//int cnt = 0; 
	for (int i = 0; i < n; i++)
	{
		//将每一步，换成走另外两种情况 
		if (a[i] == 'F')	 
		{
			//改L
			a[i] = 'L';
			location(a, n);
			//与原位置比较 
			if (r != p[0].r || c != p[0].c)	//说明出现不同于原最终位置的新情况 
			{
				//cnt++;
				p[x].r = r;
				p[x].c = c;
				x++; 	
			}
			//*******初始化条件***********
			r = c = 0;
			dirction = 'N';
			//改R
			a[i] = 'R';
			////cout << a << endl;表示调试//// 
			location(a, n);
			if (r != p[0].r || c != p[0].c)
			{
				p[x].r = r;
				p[x].c = c;
				x++; 
			}
			r = c = 0;
			dirction = 'N';
		}
		else if (a[i] == 'L')
		{
			//改F
			a[i] = 'F';
			location(a, n);
			if (r != p[0].r || c != p[0].c)
			{
				p[x].r = r;
				p[x].c = c;
				x++; 
			}
			r = c = 0;
			dirction = 'N';
			//改R
			a[i] = 'R';
			location(a, n);
			if (r != p[0].r || c != p[0].c)
			{
				p[x].r = r;
				p[x].c = c;
				x++; 
			}
			r = c = 0;
			dirction = 'N';
		}
		else if (a[i] == 'R') 
		{
			//改L
			a[i] = 'L';
			location(a, n);
			if (r != p[0].r || c != p[0].c)
			{
				p[x].r = r;
				p[x].c = c;
				x++; 
			}
			r = c = 0;
			dirction = 'N';
			//改F
			a[i] = 'F';
			location(a, n);
			if (r != p[0].r || c != p[0].c)
			{
				p[x].r = r;
				p[x].c = c;
				x++; 
			}
			r = c = 0;
			dirction = 'N';
		}
		
		
	}
	//return cnt;
}

int main()
{
	int n;	//小蓝走得步数
	cin >> n;
	//行走方向：F、L、R、 
	char a[n];
	//初始位置和朝向 
	cin >> a;
	//r = c = 0;	
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
	location(a, n) ;
	//cout << "原最终位置：" << r << ' ' << c << endl;
	p[x].r = r;
	p[x].c = c;	
	x++;
	//重新恢复初始状态 
	r = c = 0; 
	dirction = 'N';
	
	differ(a, n) ;
	cout << x - 1 << endl;

	
	//****存在一个隐患****：p[x-1] 中是否有相同的元素？ 
	int count = 0;
	for (int i = 1; i < x; i++ ) 	//i <= x-1;因为differ函数，x++的缘故，结构体数组实际元素为x-1个，p[x] 位置空出来了村下一个值 
	{
		for (int j = i + 1; j < x && (p[i].r != p[j].r || p[i].c != p[j].c); )
		{
			j++;
			if (j == x)	//说明p[i]与其他元素都不相同 
			{
				count++;
			}
		}
	}
	//cout << count << endl;
	
	
	return 0;
}
