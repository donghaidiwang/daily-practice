#include<iostream>
using namespace std;
class Solution {
public:
    //int divide(int dividend, int divisor)
    //{
    //    if (dividend == INT_MIN && divisor == -1)
    //    {
    //        return INT_MAX;
    //    }
    //    int flag = ((dividend >> 31 ^ divisor >> 31) == 1);//����λ��򣬲�ͬΪ��-����ͬΪ��+
    //    int now = -1, ret = 0;
    //    if (dividend > 0)
    //        dividend = -dividend;
    //    if (divisor > 0)
    //        divisor = -divisor;
    //    int mod = divisor;
    //    while (mod >= dividend >> 1)
    //    {
    //        mod <<= 1;
    //        now <<= 1;
    //    }
    //    while (dividend <= divisor)//�����Ļ���dividend>=divisor,��������������
    //    {
    //        while (mod < dividend)
    //        {
    //            mod >>= 1;
    //            now >>= 1;
    //        }
    //        while (dividend <= mod)
    //        {
    //            dividend -= mod;
    //            ret += now;
    //        }
    //    }
    //    if (flag == 1)
    //    {
    //        return ret;
    //    }
    //    return -ret;
    //}
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }
        if (divisor == INT_MIN)
        {
            if (dividend == INT_MIN)
            {
                return 1;
            }
            return 0;
        }
        int flag = (dividend > 0 && divisor > 0 || dividend < 0 && divisor < 0);//Ϊ��+��Ϊ��-
        if (dividend > 0)
            dividend = -dividend;
        if (divisor > 0)
            divisor = -divisor;
        int mod = -divisor;//�����������ƣ�û�취��now��mod�ĳ�����
        int now = 1, ret = 0;
        while (-mod > dividend >> 1)//��mod���ڱȱ�����С�����ֵ
        {
            mod <<= 1;
            now <<= 1;
        }
        while (dividend <= divisor)//�����Ļ���dividend>=divisor,��������������
        {
            while (-mod < dividend)
            {
                mod >>= 1;
                now >>= 1;
            }
            while (dividend <= -mod)
            {
                dividend += mod;
                ret -= now;
            }
        }
        if (flag == 1)
        {
            return -ret;
        }
        return ret;
    }
    void test()
    {
        int a = 10,b =3;
        cout<<divide(a, b);
    }
};
int main()
{
    Solution().test();
	return 0;
}