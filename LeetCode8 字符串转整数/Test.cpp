#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
class Solution{
public:
    static int myAtoi(string s)
    {
        int i,j;
        int max = pow(2,31) - 1;
        for (i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                break;
            }
        }
        int flag = 1;
        int start = i;
        if (start < s.size())
        {
            if (s[start] == '+')
            {
                flag = 1;
                start++;
            }
            else if (s[start] == '-')
            {
                flag = -1;
                start++;
            }
        }
        else
        {
            return 0;
        }
        long x = 0;
        i = start;
        while (i < s.size() && isdigit(s[i]))
        {
            x = x * 10 + s[i] - '0';
             if (x > max)
             {
                if (flag == 1)
                {
                    return max;
                }
                else
                {
                    return -max - 1;
                }
            }
            i++;
        }
        return (int)flag * x;
    }
};
int main()
{
    string s("-42");
    int ret=Solution::myAtoi(s);
    cout << ret;
    return 0;
}