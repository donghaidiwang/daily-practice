#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)//为空或者只有一个节点
        {
            return head;
        }
        ListNode* left = head, * newhead = left->next;
        while (left && left->next)//left->next防止奇数个节点
        {
            ListNode* right = left->next;
            ListNode* nleft = right->next;
            if (nleft && nleft->next)//下一组的右节点不为空并且下一组有两个节点
            {
                left->next = nleft->next;
            }
            else
            {
                left->next = nleft;
            }
            right->next = left;
            left = nleft;
        }
        return newhead;
    }
};
int main()
{
    return 0;
}