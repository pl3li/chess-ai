#include "main.h"
using namespace std;

void queen(Node& root, int row, int col, bool side){
    rook(root, row, col, side);
    bishop(root, row, col, side);
}
