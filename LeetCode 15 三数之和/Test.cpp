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
            if (i > 0 && nums[i] == nums[i - 1])//�����ظ�
            {
                continue;
            }
            if (nums[i] > 0)//�������������һ����������0����ô��һ�������ܵ���0
            {
                break;
            }
            int left = i + 1;
            int right = size - 1;
            while (left < right)
            {
                if (left < right && nums[left] + nums[right] + nums[i]>0)//�͹�������ָ������
                {
                    right--;
                }
                else if (left < right && nums[left] + nums[right] + nums[i] < 0)//�͹�С����ָ������
                {
                    left++;
                }
                else
                {
                    vv.push_back({ nums[i],nums[left],nums[right] });
                    left++;
                    right--;
                    //ȥ��
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