#include<vector>
using namespace std;
class Solution {
public:
    void child(int end, int& num, vector<int>& s)
    {
        if (end == 0)
        {
            return;
        }
        int i = 0;
        for (i = 0; i < end; i++)
        {
            if (s[i] + i >= end)
            {
                break;
            }
        }
        num++;
        child(i, num, s);
    }
    int jump(vector<int>& nums)
    {
        int size = nums.size();
        if (size == 1)
        {
            return 0;
        }
        if (size == 2)
        {
            return 1;
        }
        int num = 0;
        child(size - 1, num, nums);
        return num;
    }
};
int main()
{
    return 0;
}