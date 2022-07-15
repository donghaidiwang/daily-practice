#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        int i = nums.size() - 1, j = i;
        while (i > 0 && nums[i - 1] >= nums[i])
        {
            i--;
        }
        if (i > 0)
        {
            while (j >= 0 && nums[i - 1] >= nums[j])
            {
                j--;
            }
            swap(nums[i - 1], nums[j]);
        }
        reverse(nums.begin() + i, nums.end());
    }
};
int main()
{
    return 0;
}