//
// Created by eylon on 09/04/2022.
//
#include "sources/Matrix.hpp"

using namespace std;
using namespace zich;

int main(){
    bool keep_going = true;
    string oper;
    Matrix a;
    Matrix b;
    double num;
    char y_n;
    cout.setf(std::ios::boolalpha);
    cout << "enter matrix a" << endl;
    cin >> a;
    cout << "enter matrix b" << endl;
    cin >> b;
    while(keep_going){
        cout << "enter operator you want to check" << endl;
        cin >> oper;
        if(oper == "+"){
            cout << "a+b = " << endl << (a+b) << endl;
        }else if(oper == "+="){
            cout << "a+=b = " << endl << (a+=b) << endl;
        }else if(oper == "u+"){
            cout << "+a = " << endl << (+a) << endl;
        }else if(oper == "-"){
            cout << "a-b = " << endl << (a-b) << endl;
        }else if(oper == "-="){
            cout << "a-=b = " << endl << (a-=b) << endl;
        }else if(oper == "u-"){
            cout << "-a = " << endl << (-a) << endl;
        }else if(oper == "=="){
            cout << "a==b is " << (a==b) << endl;
        }else if(oper == "<"){
            cout << "a<b is " << (a<b) << endl;
        }else if(oper == ">"){
            cout << "a>b is " << (a>b) << endl;
        }else if(oper == "<="){
            cout << "a<=b is " << (a<=b) << endl;
        }else if(oper == ">="){
            cout << "a>=b is " << (a>=b) << endl;
        }else if(oper == "!="){
            cout << "a!=b is " << (a!=b) << endl;
        }else if(oper == "d*"){
            cout << "enter number" << endl;
            cin >> num;
            cout << num << "*a= " << endl << (num*a) << endl;
        }else if(oper == "*d"){
            cout << "enter number" << endl;
            cin >> num;
            cout << "a*" << num << "= " << endl << (a*num) << endl;
        }else if(oper == "*=d"){
            cout << "enter number" << endl;
            cin >> num;
            cout << "a*=" << num << " = " << endl << (a*=num) << endl;
        }else if(oper == "*"){
            cout << "a*b= " << endl << (a*b) << endl;
        }else if(oper == "*="){
            cout << "a*=b = " << endl << (a*=b) << endl;
        }else if(oper == "++a"){
            cout << "++a = " << endl << (++a) <<endl;
        }else if(oper == "a++"){
            cout << "a++ = " << endl << (a++) << endl;
        }else if(oper == "--a"){
            cout << "--a = " << endl << (--a) << endl;
        }else if(oper == "a--"){
            cout << "a-- = " << endl << (a--) << endl;
        }
        oper = "";
        num = 0;
        cout << "do you want to continue?" << endl << "press y to continue or n to stop" << endl;
        cin >> y_n;
        if(y_n == 'n'){
            keep_going = false;
        }
    }

    return 0;
};