#include <iostream>
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>
#include "board.h"

board::board() {
    b = new char[this->row * this->col];
    for(int i = 0 ; i < this->row ; i++) {
        for(int j = 0 ; j < this->col ; j++)
            b[i * this->row + j] = '.';
    }
}

board::board(int row, int col) : row(row), col(col) {
    b = new char[this->row * this->col];
    for(int i = 0 ; i < this->row; i++) {
        for(int j = 0 ; j < this->col; j++)
            b[i * this->row + j] = '.';
    }
}

board::board(const board& other) : board(other.row, other.col) {
    std::copy(b, b + (row * col), other.b);
}

board& board::operator=(const board& other) {
    if (&other != this)
    {
        board temp(other);
        std::swap(b, temp.b);
        std::swap(row, temp.row);
        std::swap(col, temp.col);
    }
    return *this;
}

std::pair<int,int> board::dim() {
    return std::pair<int,int>({this->row, this->col});
}

bool board::is_valid_range(int row, int col) const {
    return row >= 0 and row < this->row and col >= 0 and col < this->col;
}

char board::get(int row, int col) {
    if(is_valid_range(row, col))
        return b[row * this->row + col];
    else
        throw std::out_of_range(
                "Invalid indices: ("
                + std::to_string(row)
                + ","
                + std::to_string(col) + ").");
}

void board::set(int row, int col, char piece) {
    if(is_valid_range(row, col))
        b[row * this->row + col] = piece;
    else
        throw std::out_of_range(
                "Invalid indices: ("
                + std::to_string(row)
                + ","
                + std::to_string(col) + ").");
}

const char& board::operator()(int row, int col) const {
    if(is_valid_range(row, col))
        return b[row * this->row + col];
    else
        throw std::out_of_range(
                "Invalid indices: ("
                + std::to_string(row)
                + ","
                + std::to_string(col) + ").");
}

char& board::operator()(int row, int col) {
    if(is_valid_range(row, col))
        return b[row * this->row + col];
    else
        throw std::out_of_range(
                "Invalid indices: ("
                + std::to_string(row)
                + ","
                + std::to_string(col) + ").");
}

bool board::is_free(int row, int col) {
    return (*this)(row,col) == '.';
}

bool board::is_occupied(int row, int col) {
    return (*this)(row,col) != '.';
}

std::ostream& operator<<(std::ostream& os, const board& b) {
    int row = b.row; int col = b.col;
    int i, j;
    os << " ";
    for(j = 0 ; j < col-1 ; j++)
        os << static_cast<char>(97 + j) << " ";
    os << static_cast<char>(97 + j);
    os << "\n";
    for(i = 0 ; i < row-1; i++) {
        os << i+1 << (row < 10 ? " " : "\t");
        for(j = 0 ; j < col-1; j++)
            os << b.b[i * row + j] << " ";
        os << b.b[i * row + (col-1)] << "\n";
    }
    os << i+1 << " ";
    for(j = 0 ; j < col-1; j++) os << b.b[(row-1) * row + j] << " ";
    os << b.b[(row-1) * row + (col-1)];
    return os;
}

void board::init() {
    int max_row = (row-2)/2;
    for(int i = 0 ; i < max_row ; i++) {
        for(int j = (i % 2 == 0 ? 1 : 0) ; j < col ; j += 2)
            (*this)(i,j) = 'w';
    }

    for(int i = row-1 ; i >= (row - max_row) ; i--) {
        for(int j = (i % 2 == 0 ? 1 : 0) ; j < col ; j += 2)
            (*this)(i,j) = 'b';
    }
}

void board::move(int from_row, int from_col, int to_row, int to_col) {
    if(is_free(from_row, from_col))
        throw std::runtime_error(
                "No piece to move at ("
                + std::to_string(from_row)
                + ","
                + std::to_string(from_col) + ").");
    if(is_occupied(to_row, to_col))
        throw std::runtime_error(
                "Can\'t move to ("
                + std::to_string(to_row)
                + ","
                + std::to_string(to_col) + ").");
    if(to_row < from_row or to_col < from_col)
        throw std::runtime_error("Invalid move: ("
                + std::to_string(from_row)
                + ","
                + std::to_string(from_col)
                + ") to ("
                + std::to_string(to_row)
                + ","
                + std::to_string(to_col) + ").");
    int row_diff = to_row - from_row;
    int col_diff = to_col - from_col;
    if(row_diff > 2 or col_diff > 2)
        throw std::runtime_error("Invalid move: ("
                + std::to_string(from_row)
                + ","
                + std::to_string(from_col)
                + ") to ("
                + std::to_string(to_row)
                + ","
                + std::to_string(to_col) + ").");
    return;
}

board::~board() {
    delete [] b;
}
