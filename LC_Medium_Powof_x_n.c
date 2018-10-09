// Implement pow(x, n), which calculates x raised to the power n (x ^ n).
//
// Example 1:
//
// Input: 2.00000, 10
// Output: 1024.00000
// Example 2:
//
// Input: 2.10000, 3
// Output: 9.26100
// Example 3:
//
// Input: 2.00000, -2
// Output: 0.25000
// Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
// Note:
//
// -100.0 < x < 100.0
// n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]

#include<stdio.h>
#include<limits.h>

double myPow(double, int);

double myPow(double x, int n) {
    double ret_val = 1;
    int temp1 = 1, temp2 = 1;
    if(n < 0)
    {
        x = 1/x;
        if(n == INT_MIN)
        {
            n = INT_MAX;
            x *= x;
        }
        else n = n * -1;
    }
    while(n > 0)
    {
        if((n & 1) != 0) ret_val *= x;
        x *= x;
        n >>= 1;
    }
    return ret_val;
}

void main()
{
  double x;
  int n;
  printf("Enter x:");
  scanf("%lf", &x);
  printf("Enter n:");
  scanf("%d", &n);
  printf("%lf raised to %d is %lf", x, n, myPow(x, n));
}
