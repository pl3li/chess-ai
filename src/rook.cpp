#include <iostream>
#include <string>
#include <vector>
#include "main.h"

using namespace std;

void rook(Node& root, int row, int col, bool side){
    int index;
    char source = root->board[row][col];
    char target;

    // Checks the rows
    for(index=row; index<10; index++){
        target = root->board[index][col];
        if(target != source){
            if(' ' != target){
                if(!same_side(side, target))
                    tree_insert(root, row, col, index, col);
                break;
            }
            tree_insert(root, row, col, index, col);
        }
    }

    for(index=row; index>1; index--){
        target = root->board[index][col];
        if(target != source){
            if(' ' != target){
                if(!same_side(side, target))
                    tree_insert(root, row, col, index, col);
                break;
            }
            tree_insert(root, row, col, index, col);
        }
    }

    // Checks the columns
    for(index=col; index<10; index++){
        target = root->board[row][index];
        if(target != source){
            if(' ' != target){
                if(!same_side(side, target))
                    tree_insert(root, row, col, row, index);
                break;
            }
            tree_insert(root, row, col, row, index);
        }
    }
    for(index=col; index>1; index--){
        target = root->board[row][index];
        if(target != source){
            if(' ' != target){
                if(!same_side(side, target))
                    tree_insert(root, row, col, row, index);
                break;
            }
            tree_insert(root, row, col, row, index);
        }
    }
}
