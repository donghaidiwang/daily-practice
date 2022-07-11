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
        if (head == nullptr || head->next == nullptr)//Ϊ�ջ���ֻ��һ���ڵ�
        {
            return head;
        }
        ListNode* left = head, * newhead = left->next;
        while (left && left->next)//left->next��ֹ�������ڵ�
        {
            ListNode* right = left->next;
            ListNode* nleft = right->next;
            if (nleft && nleft->next)//��һ����ҽڵ㲻Ϊ�ղ�����һ���������ڵ�
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