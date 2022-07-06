#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Solution {
public:
    int romanToInt(string s)
    {
        char tmp[7] = { 'I','V','X','L','C','D','M' };
        int nums[7] = { 1,5,10,50,100,500,1000 };
        int num = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < 7; j++)
            {
                if (s[i] == tmp[j])
                {
                    int k = 0;
                    for (k = j + 1; k < 7; k++)
                    {
                        if (i < s.size() - 1 && s[i + 1] == tmp[k])
                        {
                            num -= nums[j];
                            break;
                        }
                    }
                    if (k == 7)
                    {
                        num += nums[j];
                        break;
                    }
                }
            }
        }
        return num;
    }
};
int main()
{
    return 0;
}