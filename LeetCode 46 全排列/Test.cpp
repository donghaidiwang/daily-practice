#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> tmp;
    void dfs(vector<int>& s, int sum, vector<int>& count)
    {
        if (sum == s.size())
        {
            ret.push_back(tmp);
            return;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (count[s[i] + 10] > 0)
            {
                tmp.push_back(s[i]);
                count[s[i] + 10]--;
                dfs(s, sum + 1, count);
                tmp.pop_back();
                count[s[i] + 10]++;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<int> count;
        count.resize(21);
        for (auto e : nums)
        {
            count[e + 10]++;
        }
        dfs(nums, 0, count);
        return ret;
    }
};
int main()
{
    return 0;
}