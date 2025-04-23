#ifndef _BOARD_H_
#define _BOARD_H_

#include <iostream>
#include <utility>

using namespace std;

template<typename F, typename S>
std::ostream& operator<<(std::ostream &os, const std::pair<F,S> &p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

class board {
    private:
        char *b ;
        int row = 8; int col = 8;
    public:
        board(); // default constructor
        board(int,int); // param. constructor
        board(const board&);    // copy constructor
        board& operator=(const board&); // copy assignment

        std::pair<int,int> dim();   // return dim
        bool is_valid_range(int,int) const; // check range

        char get(int,int);  // getter
        void set(int, int, char); // setter
        const char& operator()(int,int) const; // () getter
        char& operator()(int,int);  // () setter
        bool is_free(int,int);
        bool is_occupied(int,int);

        friend std::ostream& operator<<(std::ostream&, const board&);

        void init();
        void move(int, int, int, int);

        ~board();
};

#endif
