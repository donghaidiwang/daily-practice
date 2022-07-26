#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        int i;
        for (i = intervals.size() - 1; i >= 0; i--)
        {
            if (newInterval[0] == intervals[i][0])
            {
                intervals.insert(intervals.begin() + i, newInterval);
                break;
            }
            else if (i > 0 && newInterval[0]<intervals[i][0] && newInterval[0]>intervals[i - 1][0])
            {
                intervals.insert(intervals.begin() + i, newInterval);
                break;
            }
            else if (i == 0 && newInterval[0] < intervals[i][0])
            {
                intervals.insert(intervals.begin() + i, newInterval);
                break;
            }
        }
        if (i < 0)
        {
            intervals.push_back(newInterval);
        }
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