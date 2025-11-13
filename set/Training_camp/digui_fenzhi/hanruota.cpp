#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
void move(vector<int>& A, vector<int>& B, vector<int>& C, int n)
{
	if (n == 1) 
	{//直接移动 
		int x = A.back(); 
		C.push_back(x);
		A.pop_back();
		return;
	}
	//n>=2
	move(A, C, B, n-1);//将A上面的n-1块看作整体移到B，C为中介
	if(1) 
	{
		int x = A.back();
	C.push_back(x);
	A.pop_back();//移动A底部圆盘，达到目的 
	}
	move(B, A, C, n-1);//再将B中剩余的n-1的圆盘移到C
	//让它自己调用实现就好了
}
void hanota(vector<int>& A, vector<int>& B, vector<int>& C) 
{
    int n = A.size();
	move(A, B, C, n);//以B为中介，将A移到C
	//move(A, B, C, 1);//然后将最后一块移到C就好了 
}
int main()
{
	vector<int> A, B, C;
	int n;
	cin >> n;
	int x;
	for (int i = 0; i<n; i++)
	{
		cin >> x;
		A.push_back(x);
	}
	hanota(A,B,C);
	for (int i = 0; i<n;i++)
	{
		cout << C[i] << ' ';
	}
	cout << endl;
	return 0;
}
