/*
 * Problem: A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 *                       a^2 + b^2 = c^2
 *
 *          For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 *
 *          There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 *          Find the product abc.
 *
 * Solution: 31875000
*/

#include <iostream>

int main()
{
    // initialize variables to hold the Pythagorean triplets
    int a {1};    
    int b {1};
    int c {1};

    // variable to hold the product of a x b x c
    long long product {1};
    
    // variables for the three conditions that must be met
    // by a Pythagorean triplet
    bool condition_1 {false};
    bool condition_2 {false};
    bool condition_3 {false};

    // variable to help exit loop early when we find the solution
    bool track { false };

    for (a; a < 1000; ++a)
    {
        for (b = a + 1; b < 1000; ++b)
        {
            for (c = b + 1; c < 1000; ++c)
            {
                condition_1 = (a < b < c) ? true: false;
                condition_2 = ((a*a + b*b) == c*c) ? true: false;
                condition_3 = ((a + b + c) == 1000) ? true: false;
                
                if (condition_1 == true && condition_2 == true && condition_3 == true)
                {
                    product = a * b * c;
                    track = true;
                    break;
                }
            }

            if (track)
                break;
        }

        if (track)
            break;
    }

    std::cout << "Pythagorean triplet for which a + b + c = 1000 is " 
              << a << "^2 + " 
              << b << "^2 = "
              << c << "^2" << '\n';
    std::cout << "The product of abc is "
              << product << '\n'; 
    
    return 0;
}