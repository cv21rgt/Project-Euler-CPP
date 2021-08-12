/*
 * Problem: The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *          Find the sum of all the primes below two million.
 * 
 * Solution: 142913828922
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
   long long sum {2};
   bool isPrime {false};
   for (int i {3}; i < 2000000; ++i)
   {
      // only work with odd numbers - because most prime numbers are odd except for 2
      if (i % 2 != 0)
      {
         isPrime = isPrimeNumber(i);
         if (isPrime)
            sum += i;
      }
   }

   std::cout << "Sum of all prime numbers below 2 million is " << sum << '\n';
   return 0;
}