#include <iostream>
#include "main.h"

using namespace std;

void print_row(char row[]){
    int i;

    for(i=2; i<10; i++)
        cout << '|' << "  " << row[i] << "  ";
    cout << '|' << endl;
    cout << "      +-----+-----+-----+-----+-----+-----+-----+-----+" << endl;
}


void print_board(Node& root){
    cout << "      +-----+-----+-----+-----+-----+-----+-----+-----+" << endl;
    int i;
    int col = 8;
    for(i=2; i<10; i++){
        cout << "   " << col << "  ";
        col--;
        print_row(root->board[i]);
    }
    cout << "         A     B     C     D     E     F     G     H   " << endl << endl;
}
