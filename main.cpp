#include "matrix.hpp"
#include "cassert"
#include <iostream>

int main()
{
    Matrix<int, 0> matrix;

    for (size_t i = 0, j = 0; i < 10; ++i, ++j)
    {
        matrix[i][j] = i;
    }

    for (size_t i = 0, j = 9; i < 10; ++i, --j)
    {
        matrix[i][j] = j;
    }

    for (size_t i = 1; i < 9; ++i)
    {
        for(size_t j = 1; j < 9; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }

        std::cout << std::endl;
    }

    std::cout << matrix.size() << std::endl;

    for (const auto &[axes, value] : matrix)
    {
        const auto [x, y] = axes;
        std::cout << "[" << x << "," << y << "]" << " " << value << std::endl;
    }

    return 0;
}
