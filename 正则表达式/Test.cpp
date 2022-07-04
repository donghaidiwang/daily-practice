#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    static bool isMatch(string s, string p)
    {
        char dp[21][31] = { 0 };
        dp[0][0] = 1;
        //for(int i=1;i<s.size();i++)
        //{
        //   dp[i][0]=0;
        //}
        for (int i = 0; i <= s.size(); i++)
        {
            for (int j = 1; j <= p.size(); j++)
            {
                if (p[j - 1] != '*')
                {
                    if (i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.'))
                    {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
                else
                {
                    if (j >= 2 && i >= 1 && (s[i - 1] == p[j - 2] || p[j - 2] == '.'))
                    {
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 2] || dp[i][j - 1];
                    }
                    else if (j >= 2)
                    {
                        dp[i][j] = dp[i][j - 2];
                    }
                }

            }
        }
        return dp[s.size()][p.size()];
    }
};
int main()
{
    string s1 = "aa";
    string s2 = "a";
    bool ret = Solution::isMatch(s1, s2);
    cout << ret;
    return 0;
}