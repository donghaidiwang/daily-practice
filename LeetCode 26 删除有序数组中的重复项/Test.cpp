#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int fast = 0, slow = 0, size = nums.size();
        while (fast < size - 1)
        {
            if (nums[fast] != nums[fast + 1])
            {
                nums[slow++] = nums[fast];
            }
            fast++;
        }
        nums[slow++] = nums[fast];
        return slow;
    }
};
int main()
{
    return 0;
}