#include "main.h"
using namespace std;

void king(Node& root, int row, int col, bool side){
    int r, c;
    char target;

    for(r=row-1; r<row+2; r++){
        for(c=col-1; c<col+2; c++){
            if(r == row && c == col)
                continue;

            target = root->board[r][c];
            if('x' != target && !same_side(side, target))
                tree_insert(root, row, col, r, c);
        }
    }
}
