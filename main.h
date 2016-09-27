#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED


#define LOWEST_SCORE -10000
#define HIGHEST_SCORE 10000
#define MAX_DEPTH 3


// ==================== NODE AND BOARD STRUCTURE TYPE ==============================
struct tNode{
    char board[12][12] = {
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r', 'x', 'x'},
        {'x', 'x', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'x', 'x'},
        {'x', 'x', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'x', 'x'},
        {'x', 'x', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'x', 'x'},
        {'x', 'x', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'x', 'x'},
        {'x', 'x', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'x', 'x'},
        {'x', 'x', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'x', 'x'},
        {'x', 'x', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'}
    };

    map<char, int> materials;

    // @param bool cur_side :: white=0 black=1
    bool cur_side;
    string b_king_pos;
    string w_king_pos;
    string mv;

    vector<tNode*> next;
};
typedef tNode* Node;


// ==================== BASIC FUNCTIONALITY AND TREE OPERATIONS ====================
void print_board(Node& root);
void exec_player_move(Node& root, string mv);
void tree_insert(Node& root, int x, int y, int p, int q);
void tree_delete(Node& root);


// ==================== AI FUNCTIONS ===============================================
bool same_side(bool side, char target);
void next_move(Node& root, int depth);
double static_eval(Node& root);
bool is_repeat(Node& test);


// ==================== MOVE GENERATION FUNCTIONS FOR DIFFERENT PIECES =============
void queen(Node& root, int row, int col, bool side);
void rook(Node& root, int row, int col, bool side);
void bishop(Node& root, int row, int col, bool side);
void knight(Node& root, int row, int col, bool side);
void pawn(Node& root, int row, int col, bool side);
void king(Node& root, int row, int col, bool side);


// ==================== MINIMAX WITH ALPHA-BETA AND PREVIOUS MOVES VECTOR ==========
double minimax_alpha_beta(Node& root, Node& best, int depth, bool state, double alpha, double beta);
extern vector<string> prev_moves;
extern int static_evals;

#endif // MAIN_H_INCLUDED
