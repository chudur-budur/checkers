#include <stdexcept>
#include "checkers_except.h"

position_error::position_error(const std::string& message): std::out_of_range(message) {}


position_error::position_error(const int& row, const int& col) {
    /*
    this->row = row;
    this->col = col;
    std::string message = "Invalid position: ("
        + std::to_string(row)
        + ","
        + std::to_string(col)
        + ").";
    std::out_of_range(message);*/
}
