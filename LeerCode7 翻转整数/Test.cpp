#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
class Solution {
public:
    int reverse(int x)
    {
        int flag = 1;
        int max = pow(2, 31) - 1;
        if (x < 0)
        {
            if (-(x + 1) == max)
            {
                return 0;
            }
            x = -x;
            flag = -1;
        }
        int num[32] = { 0 };
        int i = 0;
        while (x)
        {
            num[i++] = x % 10;
            x /= 10;
        }
        int rx = 0;

        for (int j = 0; j < i; j++)
        {
            if (rx > max / 10)
            {
                return 0;
            }
            rx *= 10;
            rx += num[j];
        }
        if (flag < 0)
        {
            return -rx;
        }
        else
        {
            return rx;
        }
    }
};
int main()
{
    return 0;
}