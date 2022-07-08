#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> vv;
        if (nums.size() < 4)
        {
            return vv;
        }
        sort(nums.begin(), nums.end());
        int start = 0, end = nums.size() - 1;
        for (start = 0; start < nums.size() - 3; start++)
        {
            while (start > 0 && nums[start] == nums[start - 1])
            {
                start++;
            }
            for (end = nums.size() - 1; end - 2 > start; end--)
            {
                while (end < nums.size() - 1 && nums[end] == nums[end + 1])
                {
                    end--;
                }
                int left = start + 1, right = end - 1;
                while (left < right)
                {
                    long sum = nums[start] + nums[left];
                    sum += nums[right] + nums[end];
                    if (left < right && sum < target)
                    {
                        left++;
                    }
                    else if (left<right && sum>target)
                    {
                        right--;
                    }
                    else
                    {
                        vv.push_back({ nums[start],nums[left],nums[right],nums[end] });
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1])
                        {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right + 1])
                        {
                            right--;
                        }
                    }

                }
            }
        }
        return vv;
    }
    void test()
    {
        vector<int> v{ 1,0,-1,0,-2,2 };
        fourSum(v, 0);
    }
};
int main()
{
    Solution().test();
}