#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int maxArea(int* height, int heightSize)
{
    int max = 0, size = 0;
    int* left = height, * right = height + heightSize - 1;
    while (left < right)
    {
        size = fmin(*left, *right) * (right - left);
        if (size > max)
        {
            max = size;
        }
        if (*left < *right)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return max;
}
int main()
{
    return 0;
}