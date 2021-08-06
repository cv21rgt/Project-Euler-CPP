/*
 * Problem: If we list all the natural numbers below 10 that are multiples of 3 or 5 we get 3, 5, 6 and 9.
 *          The sum of these multiples is 23. Find the sum of all multiples of 3 or 5 below 1000.
*/

#include <iostream>

int main()
{
    const int number { 1000 };
    long long sum { 0 };

    for (int i { 3 }; i < number; ++i)
    {
        if ((i % 3 == 0) || (i % 5 == 0))
        {
            sum += i;
        }
    }

    std::cout << "Sum of all multiples of 3 or 5 below " << number << " is " << sum << '\n';

    return 0;
}