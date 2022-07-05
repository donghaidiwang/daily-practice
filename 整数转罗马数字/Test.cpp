#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Solution {
public:
    string intToRoman(int num)
    {
        char tmp[13][3] = { {"I"},{"IV"},{"V"},{"IX"},{"X"},{"XL"},{"L"},{"XC"},{"C"},{"CD"},{"D"},{"CM"},{"M"} };
        int nums[13] = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
        int count[13] = { 0 };
        for (int i = 12; i >= 0; i--)
        {
            count[i] = num / nums[i];
            num %= nums[i];
        }
        string ret;
        for (int i = 12; i >= 0; i--)
        {
            while (count[i]--)
            {
                ret.append(tmp[i]);
            }
        }
        return ret;
    }
};
int main()
{
    return 0;
}