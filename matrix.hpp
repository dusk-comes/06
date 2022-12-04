#include <array>
#include <cstddef>
#include <map>

template <typename T, T DefVal, int Dim=2>
class Matrix
{
    public:
        using Index = std::array<int, Dim>;
        using Iterator = typename std::map<Index, T>::iterator;
        class MatrixProxy;
        friend class MatrixProxy;

        Matrix();

        size_t size();

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
                int _current_dim;

                friend class Matrix;
                MatrixProxy(Matrix&, int);

                T& get();
        };

    private:
        T _default_value = DefVal;
        std::map<Index, T> _matrix;

        void set(Index, T);
        T& get(Index);
};
