/*
 * Problem: By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime 
            is 13. What is the 10 001st prime number?
 * Solution: 104743
*/

#include <iostream>

// Template function that checks whether n is prime or not
template <typename T>
bool isPrimeNumber(T n)
{
   bool isPrime { true };

   for(T i = 2; i <= n/2; i++) 
   {
      if (n % i == 0)
      {
         isPrime = false;
         break;
      }
   }  
   return isPrime;
}

int main()
{
    // generate prime numbers and stop when we get the 10 001st prime number

    int number {2};
    int count {1};

    bool isPrime { false };

    long prime { 2 };

    while (count <= 10001)
    {
        // check if a number is prime
        isPrime = isPrimeNumber(number);

        // if its a prime number, we increment count
        if (isPrime)
        {
            count += 1;
            prime = number;
        }

        // increment the variable 'number'
        number += 1;

    }

    std::cout << "\nThe 10 001st prime number is " << prime << '\n';

    std::cout << '\n';
    return 0;
}