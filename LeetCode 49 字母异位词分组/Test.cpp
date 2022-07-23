#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    bool issame(const string& a, const string& b)
    {
        int sa = a.size(), sb = b.size();
        if (sa != sb)
        {
            return false;
        }
        int tmp[26] = { 0 };
        for (int i = 0; i < sa; i++)
        {
            tmp[a[i] - 'a']++;
        }
        for (int i = 0; i < sb; i++)
        {
            tmp[b[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (tmp[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> ret;
        for (int i = 0; i < strs.size(); i++)
        {
            vector<string> tmp;
            tmp.push_back(strs[i]);
            for (int j = i + 1; j < strs.size(); j++)
            {
                if (issame(strs[i], strs[j]))
                {
                    tmp.push_back(strs[j]);
                    strs.erase(strs.begin() + j);
                    j--;
                }
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};
int main()
{
    return 0;
}