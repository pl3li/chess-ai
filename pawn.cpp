#include "main.h"
using namespace std;

void pawn(Node& root, int row, int col, bool side){
    char target;

    // White's Move
    if(0 == side){
        target = root->board[row-1][col-1]; // Top Left Capture
        if(' ' != target && 'x' != target && !same_side(side, target))
            tree_insert(root, row, col, row-1, col-1);

        target = root->board[row-1][col+1]; // Top Right Capture
        if(' ' != target && 'x' != target && !same_side(side, target))
            tree_insert(root, row, col, row-1, col+1);

        target = root->board[row-1][col]; // One Space Forward
        if(' ' == target)
            tree_insert(root, row, col, row-1, col);

        target = root->board[row-2][col]; // Two Spaces Forward (Starting)
        if(8 == row && ' ' == target && ' ' == root->board[row-1][col])
            tree_insert(root, row, col, row-2, col);
    }

    // Black's Move
    else{
        target = root->board[row+1][col-1]; // Bottom Left Capture
        if(' ' != target && 'x' != target && !same_side(side, target))
            tree_insert(root, row, col, row+1, col-1);

        target = root->board[row+1][col+1]; // Bottom Right Capture
        if(' ' != target && 'x' != target && !same_side(side, target))
            tree_insert(root, row, col, row+1, col+1);

        target = root->board[row+1][col]; // One Space Forward
        if(' ' == target)
            tree_insert(root, row, col, row+1, col);

        target = root->board[row+2][col]; // Two Spaces Forward (Starting)
        if(3 == row && ' ' == target && ' ' == root->board[row+1][col])
            tree_insert(root, row, col, row+2, col);
    }
}
