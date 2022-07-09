#include<iostream>
 struct ListNode
 {
     int val;
     ListNode *next;
 };
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* cur = head;
        int sz = 0, count = 0, pos = 0;
        while (cur != nullptr)
        {
            sz++;
            cur = cur->next;
        }
        if (sz == n)//ͷɾ
        {
            ListNode* next = head->next;
            delete head;
            head = next;
            return head;
        }
        pos = sz - n;
        cur = head;
        while (count < pos - 1)
        {
            count++;
            cur = cur->next;
        }
        ListNode* next = cur->next->next;
        delete cur->next;
        cur->next = next;
        return head;
    }
};
int main()
{
    return 0;
}