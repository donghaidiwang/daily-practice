#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix;
        matrix.resize(n);
        for (int i = 0; i < n; i++)
        {
            matrix[i].resize(n);
        }
        int top = 0, left = 0, right = n - 1, floor = n - 1;
        int num = 1;
        while (num <= n * n)
        {
            for (int i = left; i <= right; i++)
            {
                matrix[top][i] = num++;
            }
            top++;
            for (int i = top; i <= floor; i++)
            {
                matrix[i][right] = num++;
            }
            right--;
            for (int i = right; i >= left; i--)
            {
                matrix[floor][i] = num++;
            }
            floor--;
            for (int i = floor; i >= top; i--)
            {
                matrix[i][left] = num++;
            }
            left++;
        }
        return matrix;
    }
};
int main()
{
    return 0;
}