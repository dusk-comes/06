#include <cstddef>
#include <cassert>
#include <stdexcept>
#include <vector>
#include <map>

template <typename Type, Type Value>
class Matrix
{
    public:
        Matrix() = delete;
        
        Matrix(size_t rows, size_t columns) :
            _rows(rows),
            _columns(columns),
            _default_value(Value)
        {
        }

       class Columns
       {
           public:
               Columns(size_t columns, Type value) :
                   _columns(columns),
                   _default_value(value)
               {
               }

               Type& operator[](size_t column)
               {
                   if (column > _columns)
                       throw std::out_of_range ("");

                   if (auto r = values.find(column); r == values.end())
                   {
                       return _default_value;
                   }
                   else
                   {
                       return values[column];
                   }
               }

           private:
                size_t _columns;
                Type _default_value;
                std::map<size_t, Type> values;
       };

       Columns& operator[](size_t row)
       {
           if (row > _rows)
               throw std::out_of_range ("");

           if (auto r = _matrix.find(row); r == _matrix.end())
           {
               _matrix.insert({row, Columns(_columns, _default_value)});
           }

           return _matrix.at(row);
       }

    private:
        size_t _rows;
        size_t _columns;
        Type _default_value;
        std::map<size_t, Columns> _matrix;
};

int main()
{
    Matrix<int, 1> m(2, 2);
    m[1][1] = 666;
    assert(m[1][1] == 666);
    assert(m[0][1] == 1);
    assert(m[1][0] == 1);
    return 0;
}
