#include<algorithm>
using namespace std;
class Solution {
public:
    double myPow(double x, int n)
    {
        if (n == 0 || x == 1)
        {
            return 1;
        }
        long N = abs(n);
        double x_contribution = x;
        double ret = 1;
        while (N > 0)
        {
            if (N % 2 == 1)
            {
                ret *= x_contribution;
            }
            x_contribution *= x_contribution;
            N >>= 1;
        }
        return n > 0 ? ret : 1 / ret;
    }
};
int main()
{
    return 0;
}