/*
 * Problem: The prime factors of 13,195 are 5, 7, 13 and 29. What is the largest prime factor of the
 *          number 600,851,475,143
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

// Template function that checks whether n is a factor or not
template <typename T>
bool isFactor(T number, T n)
{
    bool factor { false };

    if (number % n == 0)
        factor = true;
    
    return factor;
}

/* Try this program with a smaller number first e.g 475143. If you use a very large no. such as 
 * 600851475143 it will take a long time to run (even days). I have not found a way to improve
 * run time yet. 
*/
int main()
{
    long number { 475143 }; // start with a smaller no. first

    // variable to hold the largest prime factor
    long maxPrimeFactor {1};

    bool isPrime { false };
    bool factor { false };

    for (long n {2}; n <= number; ++n)
    {
        isPrime = isPrimeNumber(n);
        
        if (isPrime == true)
        {
            factor = isFactor(number, n);
            if (factor == true)
            {
                std::cout << n << ' '; // print prime no.'s that are factors
                if ( n > maxPrimeFactor)
                    maxPrimeFactor = n;
            }
        }
        
    }

    std::cout << "\nLargest prime factor of " << number << " is " << maxPrimeFactor << '\n'; 

    std::cout << '\n';

    return 0;
}