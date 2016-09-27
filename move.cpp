#include <iostream>
#include <string>
#include <algorithm>
#include "main.h"

using namespace std;

void next_move(Node& root, int depth){
    if(depth >= MAX_DEPTH)
        return;

    int i, j;
    for(i=2; i<10; i++){
        for(j=2; j<10; j++){
            char c = root->board[i][j];

            if(0 == root->cur_side){ // WHITE has moved. Looking for BLACK pieces to move
                switch(c){
                    case 'q': queen(root, i, j, 1); break;
                    case 'r': rook(root, i, j, 1); break;
                    case 'b': bishop(root, i, j, 1); break;
                    case 'n': knight(root, i, j, 1); break;
                    case 'p': pawn(root, i, j, 1); break;
                    case 'k': king(root, i, j, 1); break;
                }
            }
            else{ // BLACK has moved. Looking for WHITE pieces to move.
                switch(c){
                    case 'Q': queen(root, i, j, 0); break;
                    case 'R': rook(root, i, j, 0); break;
                    case 'B': bishop(root, i, j, 0); break;
                    case 'N': knight(root, i, j, 0); break;
                    case 'P': pawn(root, i, j, 0); break;
                    case 'K': king(root, i, j, 0); break;
                }
            }
        }
    }
    // Iterates through each of the generated possibilities
    vector<Node>::iterator it;
    for(it=root->next.begin(); it!=root->next.end(); it++)
        next_move(*it, depth+1);
}
