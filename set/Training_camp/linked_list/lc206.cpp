#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef struct listnode
{
	listnode* next;
	int value;
}ListNode;
//使用原地转置
ListNode* reverseList(ListNode* head) {
	if (head == NULL)
    {
        return NULL;
    }
	//思路1 
    ListNode* p = head;//标记数组 
    if (head->next != NULL)
    {
    	p = head->next;//节点数大于1，连接后续节点 
	}
	else
	{
		//节点数刚好为1
		return head; 
	 } 
    ListNode* t = p;
    head->next = NULL;
    //头插
    while (p != NULL)
    {
    	//cout << head->value << ' ';
		t = p->next;
    	p->next = head;
		head = p;
		p = t;
	}
	//cout << head->next->value << ' ';
	return head;
} 
int main()
{
	int n;
	cin >> n;
	ListNode* head = (listnode*)malloc(sizeof(listnode));
	head->next =NULL;
	ListNode* tear = head;// 
	//尾插法存数
	cin >> head->value;//存第一个数 
	for(int i = 2; i<=n; i++) 
	{
		//新建节点 
		ListNode* x = (listnode*)malloc(sizeof(listnode));
		x->next = NULL;
		cin >> x->value;
		tear->next = x;
		tear = x;
	}
	ListNode* anshead = reverseList(head);
//	for (int i = 0; i < n; i++)
//	{
//		cout << head->value << ' ';
//		head = head->next;
//	}
	while (anshead != NULL)
	{
		cout << anshead->value << " ";
		anshead = anshead->next;
	}
	return 0;
}
