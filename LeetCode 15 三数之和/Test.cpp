#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    static vector<vector<int>> threeSum(vector<int>& nums)
    {
        int size = nums.size();
        vector<vector<int>> vv;
        if (size < 3)
        {
            return vv;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])//避免重复
            {
                continue;
            }
            if (nums[i] > 0)//数组递增，若第一个数都大于0，那么和一定不可能等于0
            {
                break;
            }
            int left = i + 1;
            int right = size - 1;
            while (left < right)
            {
                if (left < right && nums[left] + nums[right] + nums[i]>0)//和过大让右指针左移
                {
                    right--;
                }
                else if (left < right && nums[left] + nums[right] + nums[i] < 0)//和过小让左指针右移
                {
                    left++;
                }
                else
                {
                    vv.push_back({ nums[i],nums[left],nums[right] });
                    left++;
                    right--;
                    //去重
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
        return vv;
    }
};
int main()
{
    vector<int> v{-2,0,1,1,2};
    Solution::threeSum(v);
    return 0;
}