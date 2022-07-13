#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle)
    {
        if (needle.size() == 0)
        {
            return 0;
        }
        char* str = &haystack[0], * s = &needle[0];
        char* cur = str, * end = str + haystack.size() - 1;
        while (*str && end - str + 1 >= needle.size())
        {
            if (*s == '\0')
            {
                return str - &haystack[0];
            }
            if (*cur == *s)
            {
                cur++;
                s++;
            }
            else
            {
                s = &needle[0];
                cur = ++str;
            }
        }
        return -1;
    }
};
int main()
{
    return 0;
}