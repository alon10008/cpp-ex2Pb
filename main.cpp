#include "Board.hpp"
#include <iostream>

using namespace std;
using namespace ariel;

int main() {

    Board b;
    b.post(0, 0, Direction::Horizontal, "     __   __     "); 
    b.post(1, 0, Direction::Horizontal, "     \\/---\\/     ");
    b.post(2, 0, Direction::Horizontal, "      ). .(      ");
    b.post(3, 0, Direction::Horizontal, "     ( (\") )     ");
    b.post(4, 0, Direction::Horizontal, "      )   (      ");
    b.post(5, 0, Direction::Horizontal, "     /     \\ hjw ");
    b.post(6, 0, Direction::Horizontal, "    (       )`97 ");
    b.post(7, 0, Direction::Horizontal, "   ( \\ /-\\ / )   ");
    b.post(8, 0, Direction::Horizontal, "    w'W   W'w    ");
    b.show();  
    return 0;

}
