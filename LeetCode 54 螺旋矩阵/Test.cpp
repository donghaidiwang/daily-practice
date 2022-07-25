#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        int top = 0, left = 0, right = matrix[0].size() - 1, floor = matrix.size() - 1;
        vector<int> ret;
        while (left <= right && top <= floor)
        {
            for (int i = left; i <= right; i++)
            {
                ret.push_back(matrix[top][i]);
            }
            top++;
            if (left > right || top > floor)
            {
                break;
            }
            for (int i = top; i <= floor; i++)
            {
                ret.push_back(matrix[i][right]);
            }
            right--;
            if (left > right || top > floor)
            {
                break;
            }
            for (int i = right; i >= left; i--)
            {
                ret.push_back(matrix[floor][i]);
            }
            floor--;
            if (left > right || top > floor)
            {
                break;
            }
            for (int i = floor; i >= top; i--)
            {
                ret.push_back(matrix[i][left]);
            }
            left++;
        }
        return ret;
    }
};
int main()
{
    return 0;
}