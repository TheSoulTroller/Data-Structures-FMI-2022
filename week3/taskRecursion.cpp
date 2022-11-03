#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// task 5.1
double polinome(int n, double x) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 2 * x;
    }
    return 2 * x * polinome(n - 1, x) + 2 * (n - 1) * polinome(n - 2, x);
}

// task 5.2
int mult(int m, int n)
{
    if (n == 1)
    {
        return m;
    }
    else
    {
        return m + mult(m, n - 1);
    }
}

// task 5.3
int largestCommonDenominator(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    if(a == 0)
    {
        return b;
    }
    if(a > b)
    {
        return largestCommonDenominator(b, a % b);
    }
    else
    {
        return largestCommonDenominator(a, b % a);
    }
}

// task 5.4
int prodOfOneToNWithStepK(int n, int k)
{
    if(n <= 1)
    {
        return 1;
    }
    return n * prodOfOneToNWithStepK(n - k, k);
}

// task 5.5
int sumOfDigitsOfNInBaseK(int n, int k)
{
    if(n < k)
    {
        return n;
    }
    return n % k + sumOfDigitsOfNInBaseK(n / k, k);
}

int main()
{
    // cout << polinome(3, 2) << endl;
    
    // cout << mult(3,4) << endl;
    
    // cout << largestCommonDenominator(12, 8) << endl;
    // cout << largestCommonDenominator(8, 12) << endl;

    // cout << prodOfOneToNWithStepK(10, 2) << endl;

    // cout << sumOfDigitsOfNInBaseK(123, 10) << endl;

    return 0;
}