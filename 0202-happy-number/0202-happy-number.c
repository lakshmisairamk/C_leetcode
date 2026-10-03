#include <stdbool.h>

int sumOfSquares(int n)
{
    int sum = 0;
    int digit;

    while (n > 0)
    {
        digit = n % 10;
        sum += digit * digit;
        n = n / 10;
    }

    return sum;
}

bool isHappy(int n)
{
    while (n != 1)
    {
        n = sumOfSquares(n);

        if (n == 4)
            return false;
    }

    return true;
}