#include <array>
#include <cstddef>
#include <map>

template <typename T, T DefVal, size_t Dim=2>
class Matrix
{
    public:
        using Index = std::array<size_t, Dim>;
        using Iterator = typename std::map<Index, T>::iterator;
        class MatrixProxy;
        friend class MatrixProxy;

        Matrix();

        size_t size();
        Iterator begin();
        Iterator end();

        MatrixProxy operator[](size_t);

        class MatrixProxy
        {
            public:
                MatrixProxy& operator[](size_t);
                MatrixProxy& operator=(const T&);
                operator T&();
                bool operator==(const T&);
        
            private:
                Matrix &_matrix;
                Index _index;
                size_t _current_dim;

                friend class Matrix;
                MatrixProxy(Matrix&, size_t);

                T& get();
        };

    private:
        T _default_value = DefVal;
        std::map<Index, T> _matrix;

        void set(Index, T);
        T& get(Index);
};

#include "matrix.ipp"
