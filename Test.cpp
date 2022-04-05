#include "doctest.h"
#include <vector>
#include "Matrix.hpp"

using namespace zich;

TEST_CASE("Bad input arithmetic operators"){
    std::vector<double> arr1 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    Matrix a{arr1,3,3};
    std::vector<double> arr2 = {1};
    Matrix b{arr2,1,1};

    CHECK_THROWS((a+b));
    CHECK_THROWS((a+=b));
    CHECK_THROWS((a-b));
    CHECK_THROWS((a-=b));

}

TEST_CASE("Bad input comparing operators"){
    std::vector<double> arr1 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    Matrix a{arr1,3,3};
    std::vector<double> arr2 = {1};
    Matrix b{arr2,1,1};


//    CHECK_THROWS((a > b));
//    CHECK_THROWS((a >= b));
//    CHECK_THROWS((a == b));
//    CHECK_THROWS((a < b));
//    CHECK_THROWS((a <= b));
//    CHECK_THROWS((a != b));

    CHECK_THROWS((a.operator>(b)));
    CHECK_THROWS((a.operator>=(b)));
    CHECK_THROWS((a.operator==(b)));
    CHECK_THROWS((a.operator<(b)));
    CHECK_THROWS((a.operator<=(b)));
    CHECK_THROWS((a.operator!=(b)));
}

TEST_CASE("Bad input multiplying matrices"){
    std::vector<double> arr1 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    Matrix a{arr1,3,3};
    std::vector<double> arr2 = {1};
    Matrix b{arr2,1,1};

    CHECK_THROWS((a*b));
    CHECK_THROWS((a*=b));
    arr1 = {1,0,0,1,0,0};
    Matrix c{arr1, 3, 2};
    Matrix d{arr1, 2, 3};
    arr1 = {1,0,0};
    Matrix e{arr1, 3, 1};
    CHECK_THROWS((e*(c*d)));
    CHECK_NOTHROW((c*d));
}

// TEST_CASE("bad input constructor and istream"){
//     std::vector<double> arr1 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
//     CHECK_THROWS((zich::Matrix a{arr1, 3, 5}));
////     Matrix a;
////     cin >> a;
// }


TEST_CASE("Good input positive arithmetic operators"){
    std::vector<double> arr1 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    Matrix a{arr1,3,3};
    std::vector<double> arr2 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix b{arr2,3,3};
    std::vector<double> arr3 = {4, 0, 0, 0, 4, 0, 0, 0, 4};
    Matrix c{arr3,3,3};

    CHECK(((a+b) == c));
    CHECK(((b+a) == c));
    CHECK(((a+b) == (b+a)));


    a+=b;
    CHECK((a == c));
    CHECK(((+a) == a));
}

TEST_CASE("Good input negative arithmetic operators"){
    std::vector<double> arr1 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    Matrix a{arr1,3,3};
    std::vector<double> arr2 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix b{arr2,3,3};
    std::vector<double> arr3 = {4, 0, 0, 0, 4, 0, 0, 0, 4};
    Matrix c{arr3,3,3};

    CHECK(((c-b) == a));
    CHECK(((c-a) == b));
    CHECK(((c-b) == (-(b-c))));

    c -= b;
    CHECK((c == a));
    CHECK(((-(-a)) == a));
}

TEST_CASE("Good input comparing operators"){
    std::vector<double> arr1 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    Matrix a{arr1,3,3};
    std::vector<double> arr2 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    Matrix b{arr2,3,3};

    CHECK((a == b));

    CHECK((!(a != b)));

    std::vector<double> arr3 = {4, 0, 0, 0, 3, 0, 0, 0, 3};
    Matrix c{arr3,3,3};

    CHECK((c > a));
    CHECK((c >= a));
    CHECK((a < c));
    CHECK((a <= c));
    CHECK((a != c));

    std::vector<double> arr4 = {4, 0, 0, 0, 3, 0, 0, 0, 2};
    Matrix d{arr4,3,3};

    CHECK((a != d));
    CHECK((a <= d));
    CHECK((a >= d));
    CHECK((!(a < d)));
    CHECK((!(a > d)));
}

TEST_CASE("Good input prefix and postfix operators"){
    std::vector<double> arr1 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    Matrix a{arr1,3,3};
    std::vector<double> arr2 = {4, 1, 1, 1, 4, 1, 1, 1, 4};
    Matrix b{arr2,3,3};

    // all notes are at comparing time
    CHECK(((a++) != b)); // a is {3, 0, 0, 0, 3, 0, 0, 0, 3}
    CHECK((a == b)); // now a is {4, 1, 1, 1, 4, 1, 1, 1, 4}
    CHECK(((a--) == b)); // a is {4, 1, 1, 1, 4, 1, 1, 1, 4}
    CHECK((a != b)); // now a is {3, 0, 0, 0, 3, 0, 0, 0, 3}

    CHECK(((++a) == b)); // a is {4, 1, 1, 1, 4, 1, 1, 1, 4}
    CHECK(((--a) != b)); // a is {3, 0, 0, 0, 3, 0, 0, 0, 3}
    CHECK((a == (--b))); // b is {3, 0, 0, 0, 3, 0, 0, 0, 3}
    CHECK((a != (++b))); // b is {4, 1, 1, 1, 4, 1, 1, 1, 4}
}

TEST_CASE("Good input multiplying operators"){
    std::vector<double> arr1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix a{arr1,3,3};
    std::vector<double> arr2 = {4, 1, 1, 1, 4, 1, 1, 1, 4};
    Matrix b{arr2,3,3};

    CHECK(((b * 1) == (b * a)));
    CHECK(((a*b) == b));
    CHECK(((b*a) == b));
    CHECK(((a *= b) == b));
    CHECK(((b * (-1)) == (-b)));
    CHECK(((b * 1) == (+b)));
    Matrix c{arr2,3,3}; // c is {4, 1, 1, 1, 4, 1, 1, 1, 4}
    CHECK(((b *= (-1)) == (-c))); // b is {-4, -1, -1, -1, -4, -1, -1, -1, -4}
    CHECK(((b *= (-1)) == (+c))); // b is {4, 1, 1, 1, 4, 1, 1, 1, 4}
}
