#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
struct TreeNode {
	int val;
 	struct TreeNode *left;//+struct是C语言的写法 
 	struct TreeNode *right;
};
int t[1005];
TreeNode* inittree(int i)
{
	if (t[i] <= 0)
	{
		return NULL;
	}
	TreeNode* r = (TreeNode*)malloc(sizeof(TreeNode));
	r->val = t[i];
	r->left = inittree(2*i);
	r->right = inittree(2*i + 1);
	return r;
}
bool check(TreeNode* p, TreeNode* q)
{//root的左右子树 p、q 
	if (p == NULL && q == NULL)
	{
		return true;
	}
	else if (p == NULL || q == NULL)
	{
		return false;
	}
	else
	{//都不为空 
		//return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
		if(p->val == q->val) 
		if (check(p->left, q->right))
		if (check(p->right, q->left)) return true;
		else return false;
		else return false;
		else return false;
	}
}
bool checkSymmetricTree(struct TreeNode* root) {
    if (root == NULL)
    {
    	return true;
	}
	return check(root->left, root->right);	
}
//注意考虑空树的情况 
int main()
{
	//顺序表存储---构造完全二叉树---i    2i  2i+1
	int n, x; 
	cin >> n;
	for (int i = 1; i<=n;i++)
	{
		cin >> x;
		t[i] = x;//-1表示NULL 
	}
	TreeNode* root = inittree(1);
	bool ans = checkSymmetricTree(root); 
    cout << ans << endl;
    return 0;

}
