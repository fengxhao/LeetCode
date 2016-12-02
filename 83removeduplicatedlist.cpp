//Given a sorted linked list, delete all duplicates such that each element appear only once.
//For example,
//Given 1->1->2, return 1->2.
//Given 1->1->2->3->3, return 1->2->3.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
        return head;
        ListNode *p=head->next;
        ListNode *q=head;
        while(p)
        {   
            if(p->val==q->val)
            {
               q->next=p->next;
            }
            else
              {
                  q->next=p;
                  q=p;
              }
             p=p->next;
        }
        return head;
    }
};