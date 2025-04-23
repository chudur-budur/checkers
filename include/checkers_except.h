#ifndef _CHECKERS_EXCEPT_H_
#define _CHECKERS_EXCEPT_H_

#include <stdexcept>
#include <string>
#include <utility>

using namespace std;

class position_error : public std::out_of_range {
    private:
        int row, col;
    public:
        position_error(const std::string&);
        position_error(const int&, const int&);
};

class move_error : public std::runtime_error {
    private:
        int from_row, from_col;
        int to_row, to_col;
    public:
        move_error(const int&, const int&, const int&, const int&);
};

#endif
