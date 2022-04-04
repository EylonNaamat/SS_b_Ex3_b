#include "Matrix.hpp"
#include <stdexcept>


bool zich::Matrix::check_matrix(const Matrix& other){
    if(this->col == other.col && this->row == other.col){
        return true;
    }
    return false;
}

zich::Matrix zich::Matrix::operator+(const Matrix& other){
    if(!(zich::Matrix::check_matrix(other))){
        throw std::invalid_argument("other matrix size not match the matrix size");
    }
    vector<double> ans((this->row * this->col), 0.0);

    return *this;
}
zich::Matrix& zich::Matrix::operator+=(const Matrix& other){
    return *this;
}
zich::Matrix zich::Matrix::operator+(){
    return *this;
}

zich::Matrix zich::Matrix::operator-(const Matrix& other){
    return *this;
}
zich::Matrix& zich::Matrix::operator-=(const Matrix& other){
    return *this;
}
zich::Matrix zich::Matrix::operator-(){
    return *this;
}

bool zich::Matrix::operator==(const Matrix& mat){
    return true;
}
bool zich::Matrix::operator<(const Matrix& mat){
    return true;
}

bool zich::Matrix::operator>(const Matrix& mat){
    return true;
}
bool zich::Matrix::operator<=(const Matrix& mat){
    return true;
}
bool zich::Matrix::operator>=(const Matrix& mat){
    return true;
}
bool zich::Matrix::operator!=(const Matrix& mat){
    return true;
}

zich::Matrix zich::operator*(double a, Matrix& mat){
    return mat;
}
zich::Matrix zich::Matrix::operator*(double a){
    return *this;
}
zich::Matrix& zich::Matrix::operator*=(double a){
    return *this;
}
zich::Matrix zich::Matrix::operator*(const Matrix& a){
    return *this;
}
zich::Matrix& zich::Matrix::operator*=(const Matrix& a){
    return *this;
}

zich::Matrix& zich::Matrix::operator++(){
    return *this;
}
zich::Matrix zich::Matrix::operator++(int){
    return *this;
}
zich::Matrix& zich::Matrix::operator--(){
    return *this;
}
zich::Matrix zich::Matrix::operator--(int){
    return *this;
}

std::ostream& zich::operator<<(std::ostream& os, const Matrix& mat){
    return os;
}

std::istream& zich::operator>>(std::istream& is, const Matrix& mat){
    return is;
}
