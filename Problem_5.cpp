/*
 * Problem: 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without 
 *          any remainder. What is the smallest positive number that is evenly divisible by all of the 
 *          numbers from 1 to 20?
 * 
 * Solution: 232792560
*/

#include <iostream>

int main()
{
    // variable to hold the smallest multiple
    long smallestMultiple { 1 };

    // variable that will be used to track if a value is the
    // smallestMultiple
    bool track { false };

    while (smallestMultiple > 0)
    {
        // loop through all numbers from 1 to 20
        for (int i{1}; i <= 20; ++i)
        {
            // test whether smallestMultiple is divisible by all numbers between 0 and 20

            // if it fails even on one number
            if (smallestMultiple % i != 0)
            {
                track = false;
                // no need to continue looping, break out of for..loop
                break;
            }

            // however if smallestMultiple is divisible by every no. between 0 and 20
            if( smallestMultiple % i == 0)
            {
                track = true;
            }
        }

        // if we have found our smallestMultiple break out of the while...loop
        if (track)
            break;
        else // increase our while loop variable if we have not yet found our smallestMultiple
            smallestMultiple += 1;
    }

    std::cout << "Smallest number that can be divided "
              << "by each of the numbers from 1 to 20 without leaving a remainder is "
              << smallestMultiple << '\n';

    return 0;
}