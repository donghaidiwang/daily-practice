#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> tmp;
    void child(vector<int>& s, int target, int start)
    {
        if (target == 0)
        {
            ret.push_back(tmp);
            return;
        }
        for (int i = start; i < s.size(); i++)
        {
            if (i > start && s[i] == s[i - 1])
            {
                continue;
            }
            if (target - s[i] >= 0)
            {
                tmp.push_back(s[i]);
                child(s, target - s[i], i + 1);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        child(candidates, target, 0);
        return ret;
    }
};
int main()
{
    return 0;
}