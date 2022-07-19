#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> tmp;
    void child(vector<int>& s, int target, int& start)
    {
        int size = s.size();
        if (target == 0)
        {
            ret.push_back(tmp);
            return;
        }
        for (int i = start; i < size; i++)
        {
            if (target - s[i] >= 0)
            {
                tmp.push_back(s[i]);
                child(s, target - s[i], i);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        int start = 0;
        child(candidates, target, start);
        return ret;
    }
    void test()
    {
        vector<int> candidates = { 2,3,6,7 };
        int target = 7;
        combinationSum(candidates, target);
    }
};
int main()
{
    Solution().test();
    return 0;
}