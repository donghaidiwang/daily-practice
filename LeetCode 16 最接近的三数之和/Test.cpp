#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int mingap = 10000;
        int min = 0;
        for (int i = 0; i < size; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1;
            int right = size - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target)
                {
                    return target;
                }
                int gap = abs(sum - target);
                if (gap < mingap)
                {
                    mingap = gap;
                    min = sum;
                }
                if (left < right && sum < target)
                {
                    left++;
                }
                else if (left<right && sum>target)
                {
                    right--;
                }
                while (left < right && nums[left] == nums[left + 1])
                {
                    left++;
                }
                while (left < right && nums[right] == nums[right - 1])
                {
                    right--;
                }
            }
        }
        return min;
    }
};
int main()
{
    return 0;
}