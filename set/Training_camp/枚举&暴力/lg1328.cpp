#include <iostream>
#include<cstdio>
using namespace std;
//得分表----即甲队乙的结果数组
int gpa[5][5] = {	//结果关于主对角线相反
	{0, 0, 1, 1, 0},
	{1, 0, 0, 1, 0},
	{0, 1, 0, 0, 1},
	{0, 0, 1, 0, 1},
	{1, 1, 0, 0, 0},
};
int main()
{
	 
	int N, Na, Nb;
	
	scanf("%d %d %d", &N, &Na, &Nb);
	//对于 100% 的数据，0<N≤200,0<NA≤200, 0 <NB≤200 。
	int a[205], b[205];	//出拳数组
	for (int i = 0; i < Na; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < Nb; i++)
	{
		scanf("%d", &b[i]);
	}
	int agpa = 0, bgpa = 0;	//二人得分
	//int ai = 0, bi = 0;	//二人的本次出拳

	//模拟
	for (int i = 0; i < N; i++)
	{
		int ai = i % Na;
		int bi = i % Nb;
		agpa += gpa[a[ai]][b[bi]];
		bgpa += gpa[b[bi]][a[ai]];	//注意：乙对甲的结果也是要记录的！
		
	}
	printf("%d %d\n", agpa, bgpa);
	return 0;
	/*
	时空：O(N)、O(N)
	可优化点
	1. 移除不必要的头文件
	2. 将得分表声明为常量: 使用 const 关键字,表明这是只读数据
	3. **简化循环变量**: 不需要维护 ai 和 bi 两个独立变量,
		直接在循环中计算 i % Na 和 i % Nb
	4. 调整变量声明位置，使代码逻辑更清晰
	5. 循环从0开始: 改为 for (int i = 0; i < N; i++),
		更符合常规习惯，也利于简化循环变量，搭配取余
	*/
}
