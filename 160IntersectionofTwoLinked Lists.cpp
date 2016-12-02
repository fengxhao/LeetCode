//160. Intersection of Two Linked Lists
//先找到两个链表相差多少，让长的链表先走比短链表多的长度，然后两个链表一起走知道两个指针相等。
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int lenA = 0, lenB = 0;
		ListNode *p = headA;
		ListNode *q = headB;
		ListNode *pa = headA;
		ListNode *qb = headB;
		while (p)
		{
			p = p->next;
			lenA++;
		}
		while (q)
		{
			q = q->next;
			lenB++;
		}
		if (lenA > lenB)
		{
			for (int i = 0; i < lenA - lenB; i++)
				pa = pa->next;
		}
		else
		{
			for (int i = 0; i < lenB - lenA; i++)
				qb = qb->next;
		}
		while (pa != qb)
		{
			pa = pa->next;
			qb = qb->next;
		}
		return pa;
	}
};