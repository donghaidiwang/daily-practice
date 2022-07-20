#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2)
    {
        if (num1[0] == '0' || num2[0] == '0')
        {
            return(string("0"));
        }
        int size = num1.size() + num2.size();
        int* tmp = new int[size] {0};
        for (int i = num1.size() - 1; i >= 0; i--)
        {
            int a = num1[i] - '0';
            for (int j = num2.size() - 1; j >= 0; j--)
            {
                int b = num2[j] - '0';
                int ans = a * b + tmp[i + j + 1];
                tmp[i + j + 1] = ans % 10;
                tmp[i + j] += ans / 10;
            }
        }
        string ret;
        for (int i = 0; i < size; i++)
        {
            if (i == 0 && tmp[i] == 0) continue;
            ret.push_back(tmp[i] + '0');
        }
        return ret;
    }
};
int main()
{
    return 0;
}