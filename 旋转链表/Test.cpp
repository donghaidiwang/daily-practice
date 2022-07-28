
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    void Listreverse(ListNode*& start, ListNode*& end)
    {
        if (start == nullptr || start->next == nullptr)
        {
            return;
        }
        ListNode* n1 = nullptr, * n2 = start, * n3 = start->next, * next = end->next;
        while (n2 != next)
        {
            n2->next = n1;
            n1 = n2;
            n2 = n3;
            if (n3)
                n3 = n3->next;
        }
        start->next = next;
    }
    ListNode* rotateRight(ListNode* head, int k)
    {
        ListNode* cur = head;
        int size = 0;
        while (cur)
        {
            cur = cur->next;
            size++;
        }
        if (size == 0 || size == 1)
        {
            return head;
        }
        k %= size;
        if (k == 0)
        {
            return head;
        }
        ListNode* start = head;
        ListNode* end = head;
        int pos = 0;
        while (pos != size - k - 1)//找到第一次翻转的尾结点
        {
            end = end->next;
            pos++;
        }
        Listreverse(start, end);//翻转（0，size-k-1）
        head = end;//更新头节点
        while (end->next)//让end指向链表最后一个节点
        {
            end = end->next;
        }
        //现在的start所处的位置相当于原本的end,所以start的next为第二次翻转的头结点
        Listreverse(start->next, end);//翻转（size-k,size-1）
        start->next = end;//第一次翻转后的尾结点链接上第二次翻转后的头结点
        while (end->next)//让end指向链表最后一个节点
        {
            end = end->next;
        }
        Listreverse(head, end);//整体翻转（0，size-1）
        head = end;//更新头节点
        return head;
    }
};
int main()
{
    return 0;
}