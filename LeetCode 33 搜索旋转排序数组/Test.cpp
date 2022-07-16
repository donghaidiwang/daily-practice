#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int size = nums.size();
        if (size == 1)
        {
            return (nums[0] == target ? 0 : -1);
        }
        int left = 0;
        int right = size - 1;
        int mid = 0;
        while (left <= right)
        {
            mid = (left + right) >> 1;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[left] <= nums[mid])
            {
                if (target >= nums[left] && target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if (target > nums[mid] && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return -1;

    }
};
int main()
{
    return 0;
}