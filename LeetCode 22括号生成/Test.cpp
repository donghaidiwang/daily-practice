#include<iostream>
#include<string>
#include<vector>
using namespace std;
namespace lxy
{
    class Solution {
    public:
        void dfs(vector<string>& ret, string& tmp, int left, int right, int n)
        {
            if (left == n && right == n)
            {
                ret.push_back(tmp);
                return;
            }
            if (left < n)
            {
                tmp += '(';
                dfs(ret, tmp, left + 1, right, n);
                tmp.pop_back();
            }
            if (left > right)
            {
                tmp += ')';
                dfs(ret, tmp, left, right + 1, n);
                tmp.pop_back();
            }
        }
        vector<string> generateParenthesis(int n)
        {
            vector<string> ret;
            string tmp;
            dfs(ret, tmp, 0, 0, n);
            return ret;
        }
    };
        void test()
        {
            Solution().generateParenthesis(3);
        } 
}
int main()
{
    lxy::test();
    return 0;
}