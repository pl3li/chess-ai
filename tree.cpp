#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "main.h"

using namespace std;

bool same_side(bool side, char target){

    if(0 == side && ('Q'==target || 'R'==target || 'B'==target || 'N'==target || 'P'==target || 'K'==target))
        return true;
    if(1 == side && ('q'==target || 'r'==target || 'b'==target || 'n'==target || 'p'==target || 'k'==target))
        return true;
    return false;
}

bool is_repeat(Node& test){

    string board_hash = "";
    char c;
    int i, j;

    for(i=2; i<10; i++){
        for(j=2; j<10; j++){
            c = test->board[i][j];
            if(' ' != c)
                board_hash += c;
            else
                board_hash += '0';
        }
    }

    if(0 == board_hash.size() || find(prev_moves.begin(), prev_moves.end(), board_hash) == prev_moves.end()){
        prev_moves.push_back(board_hash);
        // cout << "NEW HASH :: " << board_hash << endl;
        return false;
    }
    // cout << "OLD HASH :: " << board_hash << endl;
    return true;
}


void tree_insert(Node& root, int x, int y, int p, int q){

    Node next = new tNode;

    // Copying the current board state to the new board state
    int a, b;
    for(a=0; a<12; a++){
        for(b=0; b<12; b++){
            next->board[a][b] = root->board[a][b];
        }
    }

    // Moving the piece from (x,y) to (p,q), replacing if needed
    char source = next->board[x][y];
    char target = next->board[p][q];
    next->board[p][q] = source;
    next->board[x][y] = ' ';

    // Checks if this board state has already been examined; skips it if it has been examined
    if(!is_repeat(next)){

        next->materials = root->materials;
        if(' ' != target)
            next->materials[target] -= 1;

        // Copying attributes from old node to new node
        next->w_king_pos = root->w_king_pos;
        next->b_king_pos = root->b_king_pos;
        next->cur_side = !(root->cur_side);

        string conv_array[12] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11"};
        next->mv = "(" + conv_array[x] +  "," + conv_array[y] + ")" + "->" + "(" + conv_array[p] +  "," + conv_array[q] + ")";

        root->next.push_back(next);
    }
    else{
        delete next;
    }
}

void tree_delete(Node& root){
    if(NULL == root)
        return;
    if(true == root->next.empty())
        return;

    vector<Node>::reverse_iterator r_iter;
    for(r_iter = root->next.rbegin(); r_iter != root->next.rend(); r_iter++){
        tree_delete(*r_iter);
        Node old = root->next.back();
        root->next.pop_back();
        delete old;
    }
}
