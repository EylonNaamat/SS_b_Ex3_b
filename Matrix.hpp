#include <vector>
#include <iostream>
#include <stdexcept>



namespace zich{
    class Matrix{
    public:
        std::vector<std::vector<double>> mat;
        int row;
        int col;
        const static int min_num = 0;

    public:
        // constructor destructor
        Matrix(){
            row = 1;
            col = 1;
            this->mat.assign(1, std::vector<double>(1));
            this->mat[0][0] = 1;
        }
        Matrix(std::vector<double> mat, int row, int col){
            if(row < this->min_num || col < this->min_num){
                throw std::invalid_argument("size of matrix not good");
            }
            if(mat.size() != (row * col)){
                throw std::invalid_argument("size of matrix not good!!!");
            }
            this->row = row;
            this->col = col;
            this->mat.assign((uint)(this->row), std::vector<double>((uint)this->col));
            for(uint i = 0; i < row; ++i){
                for(uint j = 0; j < col; ++j){
                    uint pos = (((uint)this->col)*i) + j;
                    this->mat[i][j] = mat[pos];
                }
            }
        }
        ~Matrix(){};

        bool check_matrix(const Matrix& other) const;

        Matrix operator+(const Matrix& other); // binary plus
        Matrix& operator+=(const Matrix& other); // binary addition
        Matrix operator+(); // unary plus

        Matrix operator-(const Matrix& other); // binary minus
        Matrix& operator-=(const Matrix& other); // binary subtraction
        Matrix operator-(); // unary minus

        // comparing operators
        bool operator==(const Matrix& mat);
        bool operator<(const Matrix& mat);
        bool operator>(const Matrix& mat);
        bool operator<=(const Matrix& mat);
        bool operator>=(const Matrix& mat);
        bool operator!=(const Matrix& mat);

        // multiplying operators
        friend Matrix operator*(double a, Matrix& mat);
        Matrix operator*(double a);
        Matrix& operator*=(double a);
        Matrix operator*(const Matrix& a);
        Matrix& operator*=(const Matrix& a);

        // postfix and prefix addition and subtraction
        Matrix& operator++(); // prefix operator i.e ++mat
        Matrix operator++(int); // suffix operator i.e mat++
        Matrix& operator--(); // prefix operator i.e --mat
        Matrix operator--(int); // suffix operator i.e mat--

        // input output operators
        friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);
        friend std::istream& operator>>(std::istream& is, const Matrix& mat);
    };

}