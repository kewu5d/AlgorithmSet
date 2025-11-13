#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef struct listnode
{
	int val;
	listnode* next;
}ListNode;
ListNode* trainingPlan(ListNode* head, int cnt) {
	//巧妙的思路，整个快慢指针 
    ListNode* fast = head;
	ListNode* slow = head;
	//让fast指针先走cnt-1步 
	for (int i = 1; i <= cnt-1; i++)
	{
		fast = fast->next;
	}
	while (fast->next != NULL) 
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}
int main()
{
	int n, cnt, x;
	cin >> n >> cnt;
	ListNode* head = NULL;
	ListNode* tear = NULL;
	for (int i = 1; i<= n; i++)
	{
		cin >> x;
		ListNode* s = (ListNode*)malloc(sizeof(ListNode));
		s->next = NULL;
		s->val = x;
		if (i == 1)
		{
			head = tear = s;
			
		}
		else
		{
			tear->next = s;
			tear = s;
		}
	}
	ListNode* anspos = trainingPlan(head, cnt);
	cout << anspos->val << endl;
	return 0;
}

