#include <vector>
#include <iostream>
#include <stdexcept>


// Matrix a;
// cin >> a;

namespace zich{
    class Matrix{
        private:
            std::vector<std::vector<double>> mat;
            int row;
            int col;

        public:
            // constructor destructor
            Matrix(){
                row = 1;
                col = 1;
                this->mat[0][0] = 1;
            }
            Matrix(std::vector<double> mat, int row, int col){
                if(mat.size() != (row * col)){
                    throw std::exception("size of matrix not good!!!");
                }
                this->mat = std::vector<std::vector<double>>(row, std::vector<double>(col));
                for(int i = 0; i < row; ++i){

                }
                this->row = row;
                this->col = col;
            }
            ~Matrix(){};

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