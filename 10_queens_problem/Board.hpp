#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <string>

class Board {
public:
    Board();

    void print() const;
    void place_queens();

    //todo, (after completeing by placing one at the (0,0) position then start at the (1,0) position)
    void place_queens_all();

private:
    bool check_place(const int row, const int col) const;
    
    void place_queens_helper(int row, int col, int queens_placed, bool& finished);

    std::vector<std::string> board;
    unsigned board_size;
};

#endif