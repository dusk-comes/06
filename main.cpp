#include "matrix.hpp"
#include "cassert"

int main()
{
    Matrix<int, 0, 2> m;
    m[2][2] = 3;
    [[maybe_unused]] int val = m[2][2];
    assert(m[1][1] == 0);

    return 0;
}
