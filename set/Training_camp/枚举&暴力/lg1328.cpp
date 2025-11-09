#include <iostream>
#include<cstdio>
using namespace std;
//得分表
int gpa[5][5] = {	//结果关于主对角线相反
	{0, 0, 1, 1, 0},
	{1, 0, 0, 1, 0},
	{0, 1, 0, 0, 1},
	{0, 0, 1, 0, 1},
	{1, 1, 0, 0, 0},
};
int agpa, bgpa;	//二人得分
int ai, bi;	//二人的本次出拳 

int main()
{
	int N, Na, Nb;
	scanf("%d %d %d", &N, &Na, &Nb);
	//对于 100% 的数据，0<N≤200,0<N A	≤200, 0 < NB≤200 。
	int a[205], b[205];	//出拳数组
	for (int i = 0; i < Na; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < Nb; i++)
	{
		scanf("%d", &b[i]);
	}

	//模拟
	for (int i = 1; i <= N; i++)
	{
		agpa += gpa[a[ai]][b[bi]];
		bgpa += gpa[b[bi]][a[ai]];;
		ai = (ai + 1) % Na;
		bi = (bi + 1) % Nb;
	}
	printf("%d %d\n", agpa, bgpa);
	return 0;
}
