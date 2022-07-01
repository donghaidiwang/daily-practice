#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
char* convert(char* s, int numRows)
{
    int i, j, k = 0, n = numRows;
    int len = strlen(s);
    char* ret = (char*)calloc(len + 1, sizeof(char));
    if (numRows == 1 || numRows > len)
    {
        return s;
    }
    for (i = 1; i <= numRows; i++)
    {
        if (i == 1 || i == numRows)
        {
            for (j = i; j <= len; j += 2 * numRows - 2)
            {
                ret[k++] = s[j - 1];
            }
            n--;
        }
        else
        {
            for (j = i; j <= len; j += 2 * numRows - 2)
            {
                ret[k++] = s[j - 1];
                int tmp = 2 * n - 2;
                if (j - 1 + tmp < len)
                {
                    ret[k++] = s[j - 1 + tmp];
                }
            }
            n--;
        }
    }
    return ret;
}
int main()
{
    char s[] = "AB";
    char* r = convert(s,1);
    puts(r);
}