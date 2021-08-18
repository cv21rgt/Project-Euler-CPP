/*
 *    In the 20×20 grid below, four numbers along a diagonal line have been marked in red.

        08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08
        49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
        81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65
        52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91
        22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80
        24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50
        32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70
        67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21
        24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72
        21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95
        78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92
        16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57
        86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58
        19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40
        04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66
        88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69
        04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36
        20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16
        20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54
        01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48

 *    The product of these numbers is 26 × 63 × 78 × 14 = 1788696.
 *
 *     What is the greatest product of four adjacent numbers in the same direction 
 *     (up, down, left, right, or diagonally) in the 20×20 grid?
 *
 *     Solution: 70600674
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

// Function to get all the values in columns (Top to Bottom)
std::map<int, std::vector<int>> getValuesGoingDown(int A[][20], int rows, int cols)
{
    int key { 1 };
    std::vector<int> v;
    std::map<int, std::vector<int>> down;

    for (int i { 0 }; i < cols; ++i)
    {
        for (int j { 0 }; j < rows; ++j)
        {
            // place elements for each column in a vector
            v.push_back(A[j][i]);
        }

        // add the vector to a map
        // only add columns with 4 or more values into map
        if (v.size() > 3)
        {
            down[key] = v;
            key += 1;
        }

        // clear the previous vector contents to get ready for the next column
        v.clear();
    }

    return down;
}

// Function to get all the values in rows (Left to Right)
std::map<int, std::vector<int>> getValuesGoingRight(int A[][20], int rows, int cols)
{
    int key { 1 };
    std::vector<int> v;
    std::map<int, std::vector<int>> right;

    for (int i { 0 }; i < rows; ++i)
    {
        for (int j { 0 }; j < cols; ++j)
        {
            // place elements for each row in a vector
            v.push_back(A[i][j]);
        }

        // add the vector to a map
        // only add rows with 4 or more values into map
        if (v.size() > 3)
        {
            right[key] = v;
            key += 1;
        }

        // clear the previous vector contents to get ready for the next row
        v.clear();
    }

    return right;
}

// get diagonal values - Bottom left to Top Right 
std::map<int, std::vector<int>> getDiagonalsBottomLeftToTopRight(int A[][20], int rows, int cols)
{
    int i {0};
    int key {1};
    std::vector<int> v;
    std::map<int, std::vector<int>> diagonals;
    
    for (int k { 0 }; k <= cols + rows -2; ++k)
    {
        for (int j { 0 }; j <= k; ++j)
        {
            i = k - j;
            if(i < rows && j < cols)
            {
                // place elements in a vector 
                v.push_back(A[i][j]);
            }
        }
        // only add diaginals with 4 or more values into map
        if (v.size() > 3)
        {
            diagonals[key] = v;
            key += 1;
        }
        
        // clear the previous vector contents to get ready for the next diagonal
        v.clear();
    }

    return diagonals;
}

// get diagonal values - Top left to Bottom right
std::map<int, std::vector<int>> getDiagonalsTopLeftToBottomRight(int A[][20], int rows, int cols)
{
    int key {1};
    std::vector<int> v;
    std::map<int, std::vector<int>> diagonals;

    for (int i { rows - 1 }; i > 0; --i)
    {
        for (int j { 0 }, x { i }; x <= cols - 1; ++j, ++x)
        {
            // place elements in a vector 
            v.push_back(A[x][j]);
        }
        
        // only add diaginals with 4 or more values into map
        if (v.size() > 3)
        {
            diagonals[key] = v;
            key += 1;
        }
        
        // clear the previous vector contents to get ready for the next diagonal
        v.clear();
    }

    for (int i { 0 }; i <= cols - 1; ++i)
    {
        for (int j { 0 }, y { i }; y <= rows - 1; ++j, ++y)
        {
            // place elements in a vector 
            v.push_back(A[j][y]);
        }
        
        // only add diaginals with 4 or more values into map
        if (v.size() > 3)
        {
            diagonals[key] = v;
            key += 1;
        }
        
        // clear the previous vector contents to get ready for the next diagonal
        v.clear();
    }

    return diagonals;
    
}


// Given a vector of integers, this function returns the maximum product that can be obtained
// from any four adjacent values
long long maxAdjacentProduct(const std::vector<int>& v)
{
    long long product{1};
    long long maxProduct{1};

    for (int i{0}; i < v.size(); ++i)
    {
        // if less than 4 values are left in the vector there is not need to continue
        // this will stop the following loop trying to access an index which is out of range
        if ((static_cast<int>(v.size()) - i) < 4)
            break;

        for (int j{i}; j < (i+4); ++j)
        {
            product *= v.at(j);
        }
        
        if (product > maxProduct)
            maxProduct = product;

        // set product to 1 before next outer iteration
        product = 1;        
    }

    return maxProduct;
}


// Function that returns the maximum product of any 4 adjacent values in a vector by taking into
// account both the forward and reverse directions
long long maxProductBothDirections(const std::vector<int>& v)
{
    // get maximum product of any 4 adjacent values in the forward direction
    long long maxForwardAdjacentProduct{ maxAdjacentProduct(v) };

    // reverse contents of vector to cover diagonal values going in the opposite direction
    std::vector<int> vReverse;
    for (auto revItr { v.rbegin() }; revItr != v.rend(); ++revItr)
        vReverse.push_back(*revItr);

    // get maximum product of any 4 adjacent values in the reverse direction
    long long maxReverseAdjacentProduct { maxAdjacentProduct(vReverse) };

    // compare the max products in the forward & reverse directions and return the highest value    
    return (maxForwardAdjacentProduct >= maxReverseAdjacentProduct) ? maxForwardAdjacentProduct : maxReverseAdjacentProduct;
}

// Returns the maximum adjacent product
long long product(const std::map<int, std::vector<int>>& m)
{
    long long maxAdjacentProduct { 1 };
    long long tempMaxProduct { 1 };
    
    for (const auto& pair : m)
    {
        tempMaxProduct = maxProductBothDirections(pair.second);
        
        if (tempMaxProduct > maxAdjacentProduct)
            maxAdjacentProduct = tempMaxProduct;
    }

    return maxAdjacentProduct;
}

int main()
{
    constexpr int rows { 20 };
    constexpr int cols { 20 };
    int grid[rows][cols] {
        {  8,  2, 22, 97, 38, 15,  0, 40,  0, 75,  4,  5,  7, 78, 52, 12, 50, 77, 91,  8 },
        { 49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48,  4, 56, 62,  0 },
        { 81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30,  3, 49, 13, 36, 65 },
        { 52, 70, 95, 23,  4, 60, 11, 42, 69, 24, 68, 56,  1, 32, 56, 71, 37,  2, 36, 91 },
        { 22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80 },
        { 24, 47, 32, 60, 99,  3, 45,  2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50 },
        { 32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70 },
        { 67, 26, 20, 68,  2, 62, 12, 20, 95, 63, 94, 39, 63,  8, 40, 91, 66, 49, 94, 21 },
        { 24, 55, 58,  5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72,},
        { 21, 36, 23,  9, 75,  0, 76, 44, 20, 45, 35, 14,  0, 61, 33, 97, 34, 31, 33, 95 },
        { 78, 17, 53, 28, 22, 75, 31, 67, 15, 94,  3, 80,  4, 62, 16, 14,  9, 53, 56, 92 },
        { 16, 39,  5, 42, 96, 35, 31, 47, 55, 58, 88, 24,  0, 17, 54, 24, 36, 29, 85, 57 },
        { 86, 56,  0, 48, 35, 71, 89,  7,  5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58 },
        { 19, 80, 81, 68,  5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77,  4, 89, 55, 40 },
        {  4, 52,  8, 83, 97, 35, 99, 16,  7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66 },
        { 88, 36, 68, 87, 57, 62, 20, 72,  3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69 },
        {  4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18,  8, 46, 29, 32, 40, 62, 76, 36 },
        { 20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74,  4, 36, 16 },
        { 20, 73, 35, 29, 78, 31, 90,  1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57,  5, 54 },
        {  1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52,  1, 89, 19, 67, 48 } 
    };

    
    // get Diagonals
    auto diagonalsBottomLeftToTopRight { getDiagonalsBottomLeftToTopRight(grid, rows, cols) };
    
    auto diagonalsTopLeftToBottomRight { getDiagonalsTopLeftToBottomRight(grid, rows, cols) };

    // get rows and columns
    auto rowsLeftToRight { getValuesGoingRight(grid, rows, cols) };

    auto columnsTopToDown { getValuesGoingDown(grid, rows, cols) };
    
    // get maximum adjacent products (products in reverse direction also included)
    auto maxProductDiagonalsBottomLeftToTopRight { product(diagonalsBottomLeftToTopRight) };
    auto maxProductDiagonalsTopLeftToBottomRight { product(diagonalsTopLeftToBottomRight) };
    auto maxProductLeftToRight { product(rowsLeftToRight) };
    auto maxProductTopToDown { product(columnsTopToDown) };
    
    // get the maximum value among the adjacent products
    auto m = std::max({maxProductDiagonalsBottomLeftToTopRight, maxProductDiagonalsTopLeftToBottomRight,
                            maxProductLeftToRight, maxProductTopToDown});

    std::cout << "The greatest product of four adjacent numbers in the same direction " 
              << "(up, down, left, right, or diagonally) in the 20×20 grid? = " << m << '\n';

    std::cout << '\n';
    return 0;
}