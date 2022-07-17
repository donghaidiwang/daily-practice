#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int size = nums.size();
        if (size == 0)
        {
            return vector<int> {-1, -1};
        }
        int left = 0;
        int right = size - 1;
        int mid = 0;
        while (left <= right)
        {
            mid = (left + right) >> 1;
            if (nums[mid] >= target)//left最终会指向第一个一个满足的下标
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        int leftindex = left;
        left = 0;
        right = size - 1;
        while (left <= right)
        {
            mid = (left + right) >> 1;
            if (nums[mid] > target)//right最终会指向最后一个满足的下标
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        int rightindex = right;
        if (leftindex < size && rightindex >= 0 && nums[leftindex] == target && nums[right] == target)
            return vector<int> {leftindex, rightindex};
        else
            return vector<int> {-1, -1};
    }
    void test()
    {
        vector<int> v({1,1,1,2,4,4,4,5,5,5,5,6,7,8,8,9,9,9,9,9,9,10});
        searchRange(v, 9);
    }
};
int main()
{
    Solution().test();
    return 0;
}