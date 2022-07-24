#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int pre = nums[0];
        int Max = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            pre = max(nums[i] + pre, nums[i]);
            Max = max(pre, Max);
        }
        return Max;
    }
};
int main()
{
    return 0;
}