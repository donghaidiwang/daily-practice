#include<vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int left = 0, size = nums.size(), right = size - 1;
        while (left <= right)
        {
            if (nums[left] == val)
            {
                nums[left] = nums[right--];
            }
            else
            {
                left++;
            }
        }
        return left;
    }
};
int main()
{
    return 0;
}