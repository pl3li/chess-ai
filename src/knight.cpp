#include "main.h"
using namespace std;

void knight(Node& root, int row, int col, bool side){

    // Arrays store possible coordinates for a Knight
    int row_pos[8] = {row-2, row-2, row-1, row-1, row+1, row+1, row+2, row+2};
    int col_pos[8] = {col-1, col+1, col-2, col+2, col-2, col+2, col-1, col+1};

    int i, r, c;
    char target;
    for(i=0; i<8; i++){
        r = row_pos[i];
        c = col_pos[i];
        target = root->board[r][c];
        if('x' != target && !same_side(side, target))
            tree_insert(root, row, col, r, c);
    }
}
