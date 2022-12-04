#include "matrix.hpp"
#include <stdexcept>

template <typename T, T DefVal, int Dim>
Matrix<T, DefVal, Dim>::Matrix()
{
}

template <typename T, T DefVal, int Dim>
void Matrix<T, DefVal, Dim>::set(Index index, T value)
{
    if (auto pos = _matrix.find(index); pos != _matrix.end() && value == DefVal)
    {
        _matrix.erase(pos);
        return;
    }

    if (value != DefVal)
        _matrix[index] = value;
}

template <typename T, T DefVal, int Dim>
T& Matrix<T, DefVal, Dim>::get(Index index)
{
    if (auto element = _matrix.find(index); element == _matrix.end())
        return _default_value;
    else
        return element->second;
}

template <typename T, T DefVal, int Dim>
size_t Matrix<T, DefVal, Dim>::size()
{
    return _matrix.size();
}

template <typename T, T DefVal, int Dim>
auto Matrix<T, DefVal, Dim>::operator[](size_t axis) -> MatrixProxy
{
    return MatrixProxy(*this, axis);
}

template <typename T, T DefVal, int Dim>
Matrix<T, DefVal, Dim>::Matrix::MatrixProxy::MatrixProxy(Matrix &m, int axis) :
    _matrix(m),
    _index{axis},
    _current_dim{1}
{
    if (_current_dim >= Dim)
        throw std::out_of_range ("Number of axiss exceed dimensions of matrix");
}

template <typename T, T DefVal, int Dim>
auto Matrix<T, DefVal, Dim>::MatrixProxy::operator[](size_t axis) -> MatrixProxy&
{
    if (_current_dim >= Dim)
        throw std::out_of_range ("Number of axiss exceed dimensions of matrix");

    _index[_current_dim++] = axis;
    return *this;
}

template <typename T, T DefVal, int Dim>
auto Matrix<T, DefVal, Dim>::MatrixProxy::operator=(const T &value) -> MatrixProxy&
{
    if (_current_dim < Dim)
        throw std::range_error ("Attempt to access a matrix by not fulfilled index");

    _matrix.set(_index, value);
    return *this;
}

template <typename T, T DefVal, int Dim>
Matrix<T, DefVal, Dim>::MatrixProxy::operator T&()
{
    if (_current_dim < Dim)
        throw std::range_error ("Attempt to accesss a matrix by not fulfilled index");

    return _matrix.get(_index);
}

template class Matrix<int, 0, 2>;
