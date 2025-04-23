#include <iostream>
#include <stdexcept>
#include <sstream>
#include "board.h"

#define cout std::cout
#define cerr std::cerr
#define nl std::endl

using namespace std;

/**
 * Get Human Readable C++ Version
 * @return std::string
 */
std::string print_version() {
    std::ostringstream version;
    switch (__cplusplus) {
        case 202101L:
            version << "C++23";
            break;
        case 202002L:
            version << "C++20";
            break;
        case 201703L:
            version << "C++17";
            break;
        case 201402L:
            version << "C++14";
            break;
        case 201103L:
            version << "C++11";
            break;
        case 199711L:
            version << "C++98";
            break;
        default:
            version << "pre-standard C++: " << __cplusplus;
            break;
    }
    return version.str();
}

int main() {

    cout << print_version() << nl;

    board b1;
    cout << b1 << nl;
    cout << b1.dim() << nl << nl;

    board b2(10,10);
    cout << b2 << nl;
    cout << b2.dim() << nl << nl;

    b1.set(0,0,'p');
    b1.set(1,1,'q');
    b1.set(7,7,'r');
    b1.set(6,6,'s');
    cout << b1 << nl;

    cout << b1.get(0,0) << nl;
    cout << b1.get(7,7) << nl;

    try {
        b1.set(8,8,'x');
    } catch (const std::exception &e) {cerr  << e.what() << nl;}

    try {
        b1.set(-1,-1,'x');
    } catch (const std::exception &e) {cerr  << e.what() << nl;}

    try {
        char x = b1.get(8,8);
    } catch (const std::exception &e) {cerr  << e.what() << nl;}

    try {
        char x = b1.get(-1,-1);
    } catch (const std::exception &e) {cerr  << e.what() << nl;}

    b1(2,2) = 'p';
    b1(3,3) = 'q';
    b1(4,4) = 'r';
    b1(5,5) = 's';
    cout << b1 << nl;

    cout << b1(2,2) << nl;
    cout << b1(5,5) << nl;

    try {
        b1(8,8)  = 'x';
    } catch (const std::exception &e) {cerr  << e.what() << nl;}

    try {
        b1(-1,-1) = 'x';
    } catch (const std::exception &e) {cerr  << e.what() << nl;}

    try {
        char x = b1(8,8);
    } catch (const std::exception &e) {cerr  << e.what() << nl;}

    try {
        char x = b1(-1,-1);
    } catch (const std::exception &e) {cerr  << e.what() << nl;}

    board b3;
    b3.init();
    cout << b3 << nl << nl;

    for(int i = 0 ; i < b3.dim().first ; i++)
        for(int j = 0 ; j < b3.dim().second; j++)
            for(int k = 0 ; k < b3.dim().first ; k++)
                for(int l = 0 ; l < b3.dim().second ; l++)
                    try{
                        b3.move(i,j,k,l);
                        cout << "** Moved from ("
                            << i << "," << j << ") to ("
                            << k << "," << l << ")" << nl;
                    } catch(const std::exception& e) {cerr << e.what() << nl;}

    return 0;
}
