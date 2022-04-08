#include "Matrix.hpp"
#include <string>


bool zich::Matrix::check_matrix(const Matrix& other) const{
    bool ans = false;
    if(this->col == other.col && this->row == other.row){
        ans = true;
    }
    return ans;
}

zich::Matrix zich::Matrix::operator+(const Matrix& other){
    if(!(zich::Matrix::check_matrix(other))){
        throw std::invalid_argument("other matrix size not match the matrix size");
    }

    std::vector<double> ans((uint)(this->row * this->col), 0.0);
    for(uint i = 0; i < this->row; ++i){
        for(uint j = 0; j < this->col; ++j){
            uint pos = ((uint)(this->col)*i) + j;
            ans[pos] = (this->mat[i][j] + other.mat[i][j]);
        }
    }
    return zich::Matrix{ans, this->row, this->col};
}
zich::Matrix& zich::Matrix::operator+=(const Matrix& other){
    if(!(zich::Matrix::check_matrix(other))){
        throw std::invalid_argument("other matrix size not match the matrix size");
    }

    for(uint i = 0; i < this->row; ++i){
        for(uint j = 0; j < this->col; ++j){
            this->mat[i][j] += other.mat[i][j];
        }
    }
    return *this;
}
zich::Matrix zich::Matrix::operator+(){
    std::vector<double> ans((uint)(this->row * this->col), 0.0);
    for(uint i = 0; i < this->row; ++i){
        for(uint j = 0; j < this->col; ++j){
            uint pos = ((uint)(this->col)*i) + j;
            ans[pos] = this->mat[i][j];
        }
    }
    return zich::Matrix{ans, this->row, this->col};
}

zich::Matrix zich::Matrix::operator-(const Matrix& other){
    if(!(zich::Matrix::check_matrix(other))){
        throw std::invalid_argument("other matrix size not match the matrix size");
    }

    std::vector<double> ans((uint)(this->row * this->col), 0.0);
    for(uint i = 0; i < this->row; ++i){
        for(uint j = 0; j < this->col; ++j){
            uint pos = ((uint)(this->col)*i) + j;
            ans[pos] = (this->mat[i][j] - other.mat[i][j]);
        }
    }
    return zich::Matrix{ans, this->row, this->col};
}
zich::Matrix& zich::Matrix::operator-=(const Matrix& other){
    if(!(zich::Matrix::check_matrix(other))){
        throw std::invalid_argument("other matrix size not match the matrix size");
    }

    for(uint i = 0; i < this->row; ++i){
        for(uint j = 0; j < this->col; ++j){
            this->mat[i][j] -= other.mat[i][j];
        }
    }
    return *this;
}
zich::Matrix zich::Matrix::operator-(){
    std::vector<double> ans((uint)(this->row * this->col), 0.0);
    for(uint i = 0; i < this->row; ++i){
        for(uint j = 0; j < this->col; ++j){
            uint pos = ((uint)(this->col)*i) + j;
            ans[pos] = -(this->mat[i][j]);
        }
    }
    return zich::Matrix{ans, this->row, this->col};
}

bool zich::Matrix::operator==(const Matrix& mat){
    if(!(zich::Matrix::check_matrix(mat))){
        throw std::invalid_argument("other matrix size not match the matrix size");
    }
    for(uint i = 0; i < this->row; ++i){
        for(uint j = 0; j < this->col; ++j){
            if(this->mat[i][j] != mat.mat[i][j]){
                return false;
            }
        }
    }
    return true;
}
bool zich::Matrix::operator<(const Matrix& mat){
    if(!(zich::Matrix::check_matrix(mat))){
        throw std::invalid_argument("other matrix size not match the matrix size");
    }

    int sum = 0;
    int sum2 = 0;
    for(uint i = 0; i < this->row; ++i){
        for(uint j = 0; j < this->col; ++j){
            sum += this->mat[i][j];
            sum2 += mat.mat[i][j];
        }
    }

    return sum < sum2;
}

bool zich::Matrix::operator>(const Matrix& mat){
    if(!(zich::Matrix::check_matrix(mat))){
        throw std::invalid_argument("other matrix size not match the matrix size");
    }

    int sum = 0;
    int sum2 = 0;
    for(uint i = 0; i < this->row; ++i){
        for(uint j = 0; j < this->col; ++j){
            sum += this->mat[i][j];
            sum2 += mat.mat[i][j];
        }
    }

    return sum > sum2;
}
bool zich::Matrix::operator<=(const Matrix& mat){
    if(!(zich::Matrix::check_matrix(mat))){
        throw std::invalid_argument("other matrix size not match the matrix size");
    }

    int sum = 0;
    int sum2 = 0;
    for(uint i = 0; i < this->row; ++i){
        for(uint j = 0; j < this->col; ++j){
            sum += this->mat[i][j];
            sum2 += mat.mat[i][j];
        }
    }

    return sum <= sum2;
}
bool zich::Matrix::operator>=(const Matrix& mat){
    if(!(zich::Matrix::check_matrix(mat))){
        throw std::invalid_argument("other matrix size not match the matrix size");
    }

    int sum = 0;
    int sum2 = 0;
    for(uint i = 0; i < this->row; ++i){
        for(uint j = 0; j < this->col; ++j){
            sum += this->mat[i][j];
            sum2 += mat.mat[i][j];
        }
    }

    return sum >= sum2;
}
bool zich::Matrix::operator!=(const Matrix& mat){
    return (!((*this) == mat));
}

zich::Matrix zich::operator*(double a, Matrix &mat) {
    return (mat*a);
}
zich::Matrix zich::Matrix::operator*(double a){
    std::vector<double> ans((uint)(this->row * this->col), 0.0);
    for(uint i = 0; i < this->row; ++i){
        for(uint j = 0; j < this->col; ++j){
            uint pos = (((uint)this->col)*i) + j;
            ans[pos] = (this->mat[i][j] * a);
        }
    }

    return zich::Matrix{ans, this->row, this->col};
}
zich::Matrix& zich::Matrix::operator*=(double a){
    for(uint i = 0; i < this->row; ++i){
        for(uint j = 0; j < this->col; ++j){
            this->mat[i][j] *=a;
        }
    }

    return *this;
}
zich::Matrix zich::Matrix::operator*(const Matrix& a){
    if(this->col != a.row){
        throw std::invalid_argument("matrix size not good for multiplying");
    }

    std::vector<double> ans((uint)(this->row * a.col), 0.0);
    for(uint i = 0; i < this->row; ++i){
        for(uint j = 0; j < a.col; ++j){
            uint pos = (((uint)a.col)*i) + j;
            for(uint k = 0; k < a.row; ++k){
                ans[pos] += (this->mat[i][k] * a.mat[k][j]);
            }
        }
    }

    return zich::Matrix{ans, this->row, a.col};
}
zich::Matrix& zich::Matrix::operator*=(const Matrix& a){
    if(this->col != a.row){
        throw std::invalid_argument("matrix size not good for multiplying");
    }

    std::vector<std::vector<double>> ans((uint)(this->row), std::vector<double>((uint)(a.col), 0.0));
    for(uint i = 0; i < this->row; ++i){
        for(uint j = 0; j < a.col; ++j){
            for(uint k = 0; k < a.row; ++k){
                ans[i][j] += (this->mat[i][k] * a.mat[k][j]);
            }
        }
    }
    this->mat = ans;
    return *this;
}

zich::Matrix& zich::Matrix::operator++(){
    for(uint i = 0; i < this->row; ++i){
        for(uint j = 0; j < this->col; ++j){
            this->mat[i][j] +=1;
        }
    }
    return *this;
}
zich::Matrix zich::Matrix::operator++(int){
    std::vector<double> ans((uint)(this->row*this->col), 0.0);
    for(uint i = 0; i < this->row; ++i){
        for(uint j = 0; j < this->col; ++j){
            uint pos = (((uint)this->col)*i) + j;
            ans[pos] = this->mat[i][j];
        }
    }
    zich::Matrix copy{ans, this->row, this->col};
    ++(*this);
    return copy;
}
zich::Matrix& zich::Matrix::operator--(){
    for(uint i = 0; i < this->row; ++i){
        for(uint j = 0; j < this->col; ++j){
            this->mat[i][j] -=1;
        }
    }
    return *this;
}
zich::Matrix zich::Matrix::operator--(int){
    std::vector<double> ans((uint)(this->row*this->col), 0.0);
    for(uint i = 0; i < this->row; ++i){
        for(uint j = 0; j < this->col; ++j){
            uint pos = (((uint)this->col)*i) + j;
            ans[pos] = this->mat[i][j];
        }
    }
    zich::Matrix copy{ans, this->row, this->col};
    --(*this);
    return copy;
}

std::ostream& zich::operator<<(std::ostream& os, const zich::Matrix& mat){
    for(uint i = 0; i < mat.row; ++i){
        os << "[";
        for(uint j = 0; j < mat.col; ++j){
            if(j == mat.col -1){
                os << mat.mat[i][j];
            }else{
                os << mat.mat[i][j] << " ";
            }
        }
        os << "]";
        os << "\n";
    }
    return os;
}

std::istream& zich::operator>>(std::istream& is, zich::Matrix& mat){

// [1 0 0], [0 1 0], [0 0 1]

    bool flag = true;
    int r = 0;
    std::string str_num;
    double curr_num = 0;
    int c = 0;
    int prev_col = 0;
    std::vector<double> vec;
    for(char a = char(is.get()); a != '\n'; a = is.get()){
        if(a == '['){
            flag = true;
            r++;
            if(c == 0){
                c = prev_col;
            }else if(prev_col != c){
                throw std::invalid_argument("number of columns is not good!!!!!");
            }
            prev_col = 0;
            continue;
        }
        if(a == ' ' || a == ']'){
            if(flag){
                try{
                    curr_num = std::stod(str_num);
                }catch (...){
                    throw std::invalid_argument("bad input!!!!!");
                }
                vec.push_back(curr_num);
                prev_col++;
                str_num = "";
            }
            continue;
        }
        if(a == ','){
            flag = false;
            continue;
        }
        str_num += a;
    }
    mat.col = c;
    mat.row = r;
    mat.mat.assign((uint)(r), std::vector<double>((uint)c));
    for(uint i = 0; i < r; ++i){
        for(uint j = 0; j < c; ++j){
            uint pos = (((uint)c)*i) + j;
            mat.mat[i][j] = vec[pos];
        }
    }
    return is;
}
