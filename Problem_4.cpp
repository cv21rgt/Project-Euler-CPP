/*
 * Problem: A palindromic number reads the same both ways. The largest palindromic made from the 
 *          product of two 2-digit numbers is 9009 = 91 x 99. Find the largest palindromic made from
 *          the product of two 3-digit numbers. 
 * 
 * Solution: 906609
*/

#include <iostream>
#include <string>

int main()
{
    int product {0};
    int largestPalindrome {0};

    
    int n1 {0};
    int n2 {0};

    // 3 digit numbers are from 100 to 999
    for (int i{100}; i <= 999; ++i)
    {
        for (int j{100}; j <= 999; ++j)
        {
            product = i * j;

            // convert product to String
            std::string strProduct { std::to_string(product) };
            // variable to hold 'strProduct' in reverse
            std::string reverseProduct {""};
            // iterate through string and get it in reverse
            for (auto revItr {strProduct.rbegin()}; revItr != strProduct.rend(); ++revItr)
                reverseProduct += (*revItr);
            
            // compare forward and reverse string
            if (strProduct == reverseProduct)
            {
                // print all products that result in a palindrome
                std::cout << i << " x " << j << " = " << strProduct << " <---> " << reverseProduct << '\n';
                // find the largest palindrome
                if (product > largestPalindrome)
                {
                    n1 = i;
                    n2 = j;
                    largestPalindrome = product;
                }
            }           

        }
    }

    std::cout << "\nThe largest palindrome from two 3-digit numbers is " << largestPalindrome
              << " and is the product of " << n1 << " x " << n2 << '\n';
              

    return 0;
}