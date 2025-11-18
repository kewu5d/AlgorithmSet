/*
思路：
- 按火气值，从大到小的顺序依次分配罪犯
- 能合并，就进行两次合并
- 不能，就说明在之前的合并操作后，二者已经在一个集合里了，此时他俩的冲突值既是答案
    - 另外，二者的天敌在同一个集合也不能合并，返回
注意：
- 题目要求的特殊情况，需要照顾到
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct crime
{
	int a, b, c;//ab罪犯之间的怒气值 c
}c_angry[100005];
int f[40005];//1~n对立翻倍 n+1~2n
bool cmp(crime a, crime b)
{
	return a.c > b.c;//降序 
}
int find(int x)
{
	if (f[x] == x)
	{
		return x;//是他本身 
	}
	int fx = find(f[x]);
	f[x] = fx;//压缩 (直接指向父亲)
	return f[x];
}
int ans; 
int main()
{
	int n, m;//罪犯数，仇人对数
	scanf("%d %d", &n, &m) ;
	for (int i = 1; i<= m; i++)
	{
		scanf("%d %d %d", &c_angry[i].a, &c_angry[i].b, &c_angry[i].c);
	}
	//2n个节点单独成集合
	for (int i = 1; i<= n; i++) 
	{
		f[i] = i;
		f[i+n] = i+n;
	}
	//按怒气值排序
	sort(c_angry+1, c_angry+m+1, cmp) ;
	//处理m对仇人，对其分配到两个监狱中去
	for (int i = 1; i<= m; i++)  
	{
		int a = c_angry[i].a;
		int b = c_angry[i].b;
		int fa = find(a) ;
		int fb = find(b);
		int f2a = find(a + n);//a的敌人
		int f2b = find(b + n);//b的敌人
		if (fa != fb && f2a != f2b) 
		{ //都不在一个集合，两两分开交叉合并 ----两罪犯分开放 
			f[fa] = f2b;
			f[fb] = f2a;	
		}
		else
		{//由于之前的操作，在一个集合里//发生冲突，即最大冲突值 
			 ans = c_angry[i].c;
			 break;
		}
		
	}
	printf("%d", ans);
	return 0 ;
}

