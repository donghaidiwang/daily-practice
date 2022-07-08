#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> ret;
    string tmp;
    vector<string>board = {
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
    };
    void DFS(int pos, string digits)
    {
        if (pos == digits.size())
        {
            ret.push_back(tmp);
            return;
        }
        int num = digits[pos] - '0' - 2;
        for (int i = 0; i < board[num].size(); i++)
        {
            tmp += board[num][i];
            DFS(pos + 1, digits);
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() < 1)
        {
            return ret;
        }
        DFS(0, digits);
        return ret;
    }
    void test()
    {
        string t("2345");
        letterCombinations(t);
    }
};
int main()
{
    Solution().test();
}
