//
// Created by eylon on 04/04/2022.
//
#include <iostream>
#include <vector>
#include <iterator>
#include "Matrix.hpp"
using namespace std;
using namespace zich;

int main(){
//    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
//    std::vector<double> arr = {3, 1, 0, 0, 3, 0, 0, 0, 3};
//    Matrix a{identity, 3, 3};
//    Matrix b{arr, 3, 3};
//    std::cout << a << std::endl;
//    std::cout << ((a++) == a) << endl;
//    Matrix c = a;
//    --a;
//    std::cout << (c == a) << endl;
//    for(uint i = 0; i < 3; ++i){
//        for(uint j = 0; j < 3; ++j){
//            std::cout << a.mat[i][j] << ", ";
//        }
//        std::cout << std::endl;
//    }
//    std::cout << (a != b) << std::endl;
//    std::cout << b.mat_sum() << std::endl;

//    Matrix c = b-a-a;
//    for(uint i = 0; i < 3; ++i){
//        for(uint j = 0; j < 3; ++j){
//            std::cout << c.mat[i][j] << ", ";
//        }
//        std::cout << std::endl;
//    }


//    istream_iterator<string>ii(cin);
//    istream_iterator<string>eos;
//    string s1 = *ii;
//    ++ii;
//    string s2 = *ii;
//    cout <<s1 << ' '<< s2 <<'\n';

Matrix a;
std::cin >> a;
std::cout << a;



    return 0;
}


// [1 0 0], [0 1 0], [0 0 1]