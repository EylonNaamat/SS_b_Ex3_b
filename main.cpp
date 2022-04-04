//
// Created by eylon on 04/04/2022.
//
#include <iostream>
#include <vector>
#include "Matrix.hpp"
using namespace std;
using namespace zich;

int main(){
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    Matrix a{identity, 3, 3};
    cout << a.row << endl;
    for(uint i = 0; i < 3; ++i){
        for(uint j = 0; j < 3; ++j){
            cout << a.mat[i][j] << ", ";
        }
        cout << endl;
    }
    return 0;
}

