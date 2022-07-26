#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;
        vector<int> dp(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][1] <= dp[1])
            {
                continue;
            }
            else if (intervals[i][0] <= dp[1])
            {
                dp[1] = intervals[i][1];
            }
            else
            {
                ret.push_back(dp);
                dp = intervals[i];
            }
        }
        ret.push_back(dp);
        return ret;
    }
};
int main()
{
    return 0;
}