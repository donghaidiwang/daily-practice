#include<vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int end = 0, max_len = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i + nums[i] >= nums.size() - 1)
            {
                return true;
            }
            max_len = max(max_len, i + nums[i]);
            if (end == i)
            {
                if (end == max_len && nums[end] == 0)
                {
                    return false;
                }
                end = max_len;
            }
        }
        return true;
    }
};
int main()
{
    return 0;
}