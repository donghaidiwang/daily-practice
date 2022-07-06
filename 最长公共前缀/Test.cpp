#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
char* longestCommonPrefix(char** strs, int strsSize)
{
    char** end = strs + strsSize - 1;
    char** start = strs;
    char* ret = (char*)calloc(sizeof(char), 201);
    int t = 0;
    for (int i = 0;; i++)
    {
        char s = *(*start + i);
        if (s == 0)
        {
            break;
        }
        while (start <= end)
        {
            char tmp = *(*start + i);
            if (tmp != s || tmp == 0)
            {
                t = 1;
                break;
            }
            start++;
        }
        if (t)
        {
            break;
        }
        ret[i] = s;
        start = strs;
    }
    return ret;
}
int main()
{
    return 0;
}