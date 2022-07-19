#include<string>
using namespace std;
class Solution {
public:
    string& child(string& ret, int n)
    {
        if (n == 1)
        {
            return ret;
        }
        string tmp;
        int size = ret.size();
        for (int i = 0; i < size; i++)
        {
            int count = 1;
            while (i + 1 < size && ret[i] == ret[i + 1])
            {
                count++;
                i++;
            }
            tmp.push_back(count + '0');
            tmp.push_back(ret[i]);
        }
        ret = child(tmp, n - 1);
        return ret;
    }
    string countAndSay(int n)
    {
        string s = "1";
        return child(s, n);
    }
};
int main()
{
    return 0;
}