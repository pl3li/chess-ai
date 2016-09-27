#include <iostream>
#include <vector>
#include <string>
#include "main.h"

using namespace std;

int map_to_int(char c){
    int val;
    switch(c){
        case 'a': val=1; break;
        case 'b': val=2; break;
        case 'c': val=3; break;
        case 'd': val=4; break;
        case 'e': val=5; break;
        case 'f': val=6; break;
        case 'g': val=7; break;
        case 'h': val=8; break;
        default: val=0;
    }
    return val;
}

void exec_player_move(Node& root, string mv){
    // Mapping mv to the correct array coordinates (s,t) --> (u,v)
    int s = 8 - (mv.c_str()[1] - '0') + 2;
    int t = map_to_int(mv.c_str()[0]) + 1;
    int u = 8 - (mv.c_str()[3] - '0') + 2;
    int v = map_to_int(mv.c_str()[2]) + 1;

    // Replacing the target square with source square
    char source = root->board[s][t];
    char target = root->board[u][v];

    root->board[u][v] = source;
    root->board[s][t] = ' ';

    if(' ' != target)
        root->materials[target] -= 1;
}
