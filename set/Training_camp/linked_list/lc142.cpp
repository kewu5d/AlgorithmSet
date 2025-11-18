#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef struct ListNode
{
	int val;
	ListNode* next;
}ListNode;
ListNode *detectCycle(ListNode *head) {
    ListNode* f = head;
	ListNode* s = head;
	while (f != NULL)//有环就一直走 
	{
		if (f->next == NULL)
		{
			return NULL;//无环 
		}
		f = f->next->next;
		s = s->next;
		if (s == f)
		{//在环内相遇 
			ListNode* p = head;
			while (p != s)
			{
				p = p->next;
				s = s->next;
				
			}
			return s;
			
		}
	}
	return NULL;//无环 
}
int main()
{
	int n, pos, x;
	cin >> n >> pos;
	ListNode* head = NULL;
	ListNode* tear = NULL;
	ListNode* flag = NULL;
	for (int i = 0; i < n; i++) 
	{
		cin >> x;
		ListNode* s = (ListNode*)malloc(sizeof(ListNode));
		s->next = NULL;
		s->val = x;
		if (i == 0 )
		{
			head = tear = s;
		}
		else 
		{
			tear->next = s;
			tear = s;
		}
		if (pos == i) 
		flag = s;
	}
	tear->next = flag;
	ListNode* ansp = detectCycle(head);
	cout << ansp->val << endl;
	return 0;
	
}
