/*
 * Problem: The sum of the squares of the first ten natural numbers is, 
                    1^2 + 2^2 + ... + 10^2 = 385
            The square of the sum of the first ten natural numbers is, 
                    (1 + 2 + ... + 10)^2 = 55^2 = 3025
            Hence the difference between the sum of the squares of the first ten natural numbers and 
            the square of the sum is 3025 - 385 = 2640.
            Find the difference between the sum of the squares of the first one hundred natural numbers 
            and the square of the sum.
 * Solution: 25164150
*/

#include <iostream>

int main()
{
    int sumOfSquares {0};
    int sum {0};

    for (int i{1}; i <= 100; ++i)
    {
        sumOfSquares += (i * i);
        sum += i;
    }

    int squareOfSum { sum * sum };
    int difference { squareOfSum - sumOfSquares };

    std::cout << "\nDifference between the Sum of Squares for the "
              << "first 100 natural numbers and the Square of the sum is "
              << difference << '\n';

    std::cout << '\n';

    return 0;
}