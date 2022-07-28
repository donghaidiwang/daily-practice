
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
        while (pos != size - k - 1)//�ҵ���һ�η�ת��β���
        {
            end = end->next;
            pos++;
        }
        Listreverse(start, end);//��ת��0��size-k-1��
        head = end;//����ͷ�ڵ�
        while (end->next)//��endָ���������һ���ڵ�
        {
            end = end->next;
        }
        //���ڵ�start������λ���൱��ԭ����end,����start��nextΪ�ڶ��η�ת��ͷ���
        Listreverse(start->next, end);//��ת��size-k,size-1��
        start->next = end;//��һ�η�ת���β��������ϵڶ��η�ת���ͷ���
        while (end->next)//��endָ���������һ���ڵ�
        {
            end = end->next;
        }
        Listreverse(head, end);//���巭ת��0��size-1��
        head = end;//����ͷ�ڵ�
        return head;
    }
};
int main()
{
    return 0;
}