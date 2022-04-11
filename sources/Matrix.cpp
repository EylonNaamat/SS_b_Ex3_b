#include "Matrix.hpp"
#include <string>

/**
 * this function checks if the matrix we need to compare is the same size as the matrix we comparing it to
 * @param other
 * @return
 */
bool zich::Matrix::check_matrix(const Matrix& other) const{
    bool ans = false;
    if(this->col == other.col && this->row == other.row){
        ans = true;
    }
    return ans;
}

/**
 * this function gets a matrix and returns a matrix that is the addition of this matrix to the other matrix
 * if they arent the same size throw exception
 * creating a vector of double, which we use to keep the addition of one matrix to the other
 * returning new matrix which is the addition
 * @param other
 * @return
 */
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

/**
 * this function gets a matrix and adds it to the matrix we apply the function on
 * if the size isnt the same throw exception
 * we add the matrix and returning a reference to "this" matrix
 * @param other
 * @return
 */
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

/**
 * this function returns a matrix which is a copy of the matrix that applied the function
 * @return
 */
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

/**
 * this function gets a matrix and returns a matrix that is the subtraction of this matrix to the other matrix
 * if they arent the same size throw exception
 * creating a vector of double, which we use to keep the subtraction of one matrix to the other
 * returning new matrix which is the subtraction
 * @param other
 * @return
 */
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

/**
 * this function gets a matrix and subtract it from the matrix we apply the function on
 * if the size isnt the same throw exception
 * we subtract the matrix and returning a reference to "this" matrix
 * @param other
 * @return
 */
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

/**
 * this function returns a matrix which is the negative matrix of the matrix that applied the function on
 * @return
 */
zich::Matrix zich::Matrix::operator-(){
    std::vector<double> ans((uint)(this->row * this->col), 0.0);
    for(uint i = 0; i < this->row; ++i){
        for(uint j = 0; j < this->col; ++j){
            uint pos = ((uint)(this->col)*i) + j;
            if(this->mat[i][j] != 0){
                ans[pos] = -(this->mat[i][j]);
            }else{
                ans[pos] = (this->mat[i][j]);
            }
        }
    }
    return zich::Matrix{ans, this->row, this->col};
}

bool zich::operator==(const Matrix& a, const Matrix& b){
    if(a.row != b.row || a.col != b.col){
        throw std::invalid_argument("size not good");
    }
    for(uint i = 0; i < a.row; ++i){
        for(uint j = 0; j < a.col; ++j){
            if(a.mat[i][j] != b.mat[i][j]){
                return false;
            }
        }
    }
    return true;
}

/**
 * this function gets a matrix and returns if this matrix is exactly the same as the other matrix
 * if the size isnt the same throw exception
 * go through the matrix item by item and check if every item is exactly the same
 * @param mat
 * @return
 */
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

/**
 * this function gets a matrix and checks if the sum of it matrix is less than the sum of the matrix it got
 * if the size isnt the same throw exception
 * than sum the two matrices and check which is bigger
 * @param mat
 * @return
 */
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

/**
 * this function gets a matrix and checks if the sum of it matrix is more than the sum of the matrix it got
 * if the size isnt the same throw exception
 * than sum the two matrices and check which is bigger
 * @param mat
 * @return
 */
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

/**
 * this function gets a matrix and checks if the sum of it matrix is less than or equal to the sum of the matrix it got
 * if the size isnt the same throw exception
 * than sum the two matrices and check which is bigger
 * @param mat
 * @return
 */
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

/**
 * this function gets a matrix and checks if the sum of it matrix is more than or equal to the sum of the matrix it got
 * if the size isnt the same throw exception
 * than sum the two matrices and check which is bigger
 * @param mat
 * @return
 */
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

/**
 * this function gets a mtrix and checks if it exactly the same as the matrix it got, if not return true
 * we use the operator== to determine if the matrices are equal
 * @param mat
 * @return
 */
bool zich::Matrix::operator!=(const Matrix& mat){
    return (!((*this) == mat));
}

/**
 * this is a friend function, this function gets a double and a matrix and returns a matrix which is the mult of the double and matrix we got
 * we use the operator* that gets a double for this function
 * @param a
 * @param mat
 * @return
 */
zich::Matrix zich::operator*(double a, Matrix &mat) {
    return (mat*a);
}

/**
 * this function gets a double and returns a matrix which is the matrix "this" multiplied by this double
 * we create a vector with the size of the matrix we got with only 0
 * than we multiplying every item in the matrix by the double we got
 * than return a matrix with this vector
 * @param a
 * @return
 */
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

/**
 * this function gets a double and returns a reference to "this" matrix multiplied by this double
 * we go through the matrix vec of vec and multiply every item by this double
 * @param a
 * @return
 */
zich::Matrix& zich::Matrix::operator*=(double a){
    for(uint i = 0; i < this->row; ++i){
        for(uint j = 0; j < this->col; ++j){
            this->mat[i][j] *=a;
        }
    }

    return *this;
}

/**
 * this function gets a matrix and returns a matrix which is the matrix we gets after multiplying the two matrices
 * first we check if the col number of the left matrix is the same as the row number of the matrix we got
 * if not throw exception
 * then create a vector with the proper size (this->row * a.col)
 * then we multiply the two matrices by the next logic:
 * the first row of the left matrix multiplied by the first col of the right matrix, then the next col etc.
 * @param a
 * @return
 */
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

/**
 * this function gets a matrix and modified the matrix that applied this function, multiplying the two matrices
 * we check first if the size of the matrix we got is good if not throw exception
 * then we create a vector of vector of double  with the proper size (this->row * a.col)
 * then we insert this vector the right values as explained in the previous function
 * and changing the vector of vectors the matrix has
 * @param a
 * @return
 */
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

/**
 * this function adds one to every item on the matrix and return a reference to this matrix
 * @return
 */
zich::Matrix& zich::Matrix::operator++(){
    for(uint i = 0; i < this->row; ++i){
        for(uint j = 0; j < this->col; ++j){
            this->mat[i][j] +=1;
        }
    }
    return *this;
}

/**
 * this function saves a copy of the matrix and than incrementing the original matrix by 1
 * and returns the copy of the matrix prior to the incrementation
 * @return
 */
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

/**
 * this function subtracts by one every item on the matrix and return a reference to this matrix
 * @return
 */
zich::Matrix& zich::Matrix::operator--(){
    for(uint i = 0; i < this->row; ++i){
        for(uint j = 0; j < this->col; ++j){
            this->mat[i][j] -=1;
        }
    }
    return *this;
}

/**
 * this function saves a copy of the matrix and than subtract every item of the original matrix by 1
 * and returns the copy of the matrix prior to the subtraction
 * @return
 */
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

/**
 * this function is a friend function gets an ostream and a matrix
 * this function prints the matrix to the screen by the next format:
 * [a b c ...]
 * [e f g ...]
 * [h i j ...]
 * ............
 * [x y z ...]
 * @param os
 * @param mat
 * @return
 */
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
        if(i != mat.row-1){
            os << "\n";
        }
    }
    return os;
}

/**
 * this function gets an istream and a matrix and initialize a matrix according to the input we get from istream
 * this function go through every char of is and if the char is '[' it means a new row has began so we add 1 to r
 * if the char is space or ']' it means that a number has terminated so we cast him to double, if we get an exception
 * it means the input wasnt good so we throw exception
 * if it succeed we add this number to a vector
 * and we check if the number of columns is the same in every row
 * if not throw exception
 * then we modified the vector of vectors the matrix has
 * @param is
 * @param mat
 * @return
 */
std::istream& zich::operator>>(std::istream& is, zich::Matrix& mat){
    bool flag = true;  // flag to check if the ' ' we got is between number in a row or a ' ' between rows in the input
    bool flag2 = true; // flag to check if after "," comes space
    int r = 0;  // a row counter, count when sees '['
    int b_r = 0;  // a row checker, count when sees ']'
    std::string str_num;
    double curr_num = 0;
    int c = 0;
    int prev_col = 0;
    std::vector<double> vec;
    for(char a = char(is.get()); (a != '\n') && (a != EOF); a = is.get()){
        if(!flag2 && a != ' '){
            throw std::invalid_argument("bad input");
        }
        if(a == ' '){
            flag2 = true;
        }
        if(a == '['){
            flag = true;
            r++;
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
                if(a == ']'){
                    if(c == 0){
                        c = prev_col;
                    }else if(prev_col != c){
                        throw std::invalid_argument("number of columns is not good!!!!!");
                    }
                    prev_col = 0;
                    b_r++;
                    if(b_r != r){
                        throw std::invalid_argument("bad input!");
                    }
                }
            }
            continue;
        }
        if(a == ','){
            flag = false;
            flag2 = false;
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


