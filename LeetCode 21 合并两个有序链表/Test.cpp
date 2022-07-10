struct ListNode
{
    ListNode(int data, ListNode* _next)
    {
        val = data;
        next = _next;
    }
    ~ListNode()
    {
        val = 0;
        delete next;
        next = nullptr;
    }
    int val;
    ListNode* next;
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* ret = new ListNode(-1, nullptr);
        ListNode* left = list1, * right = list2, * prev = ret;
        if (left == nullptr)
        {
            return right;
        }
        else if (right == nullptr)
        {
            return left;
        }
        while (left && right)
        {
            if (left->val <= right->val)
            {
                prev->next = left;
                left = left->next;
            }
            else
            {
                prev->next = right;
                right = right->next;
            }
            prev = prev->next;
        }
        prev->next = left == nullptr ? right : left;
        return ret->next;
    }
};
int main()
{
    return 0;
}