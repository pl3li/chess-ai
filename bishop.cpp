#include <iostream>
#include "main.h"
using namespace std;

void bishop(Node& root, int row, int col, bool side){
    int s, t;
    char source = root->board[row][col];
    char target = root->board[row][col];

    // Lower-Right Diagonal
    s = row; t = col;
    while('x' != target){
        target = root->board[s][t];
        if('x' != target && target != source){
            if(' ' != target){
                if(!same_side(side, target))
                    tree_insert(root, row, col, s, t);
                break;
            }
            tree_insert(root, row, col, s, t);
        }
        s++; t++;
    }

    // Upper-Left Diagonal
    s = row; t = col; target = root->board[row][col];
    while('x' != target){
        target = root->board[s][t];
        if('x' != target && target != source){
            if(' ' != target){
                if(!same_side(side, target))
                    tree_insert(root, row, col, s, t);
                break;
            }
            tree_insert(root, row, col, s, t);
        }
        s--; t--;
    }

    // Upper-Right Diagonal
    s = row; t = col; target = root->board[row][col];
    while('x' != target){
        target = root->board[s][t];
        if('x' != target && target != source){
            if(' ' != target){
                if(!same_side(side, target))
                    tree_insert(root, row, col, s, t);
                break;
            }
            tree_insert(root, row, col, s, t);
        }
        s--; t++;
    }

    // Lower-Left Diagonal
    s = row; t = col; target = root->board[row][col];
    while('x' != target){
        target = root->board[s][t];
        if('x' != target && target != source){
            if(' ' != target){
                if(!same_side(side, target))
                    tree_insert(root, row, col, s, t);
                break;
            }
            tree_insert(root, row, col, s, t);
        }
        s++; t--;
    }
}
