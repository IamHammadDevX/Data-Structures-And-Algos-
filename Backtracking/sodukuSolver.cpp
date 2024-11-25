#include<iostream>
#include<vector>
using namespace std;

// Soduku Solver
// 9*9 matrix
// conditions:
// 1 row -> 1-9 exactly once
// 1 col -> 1-9 exactly once
// 3*3 matrix 1-9 exactly once

bool isSafe(int row, int col, vector<vector<int> >& board, int val)
{
    for (int i = 0; i < board.size(); i++)
    {
        // check for row & col
        if (board[row][i] == val || board[i][col] == val)
        {
            return false;
        }

        // check for 3*3 matrix
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
        {
            return false;
        }

    }
    return true;
}

bool solve(vector<vector<int> >& board)
{
    int n = board[0].size();

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            // check for empty cell
            if (board[row][col] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(row, col, board, val))
                    {
                        board[row][col] = val;
                        // recusion
                        bool nextPossibleSol = solve(board);
                        if (nextPossibleSol)
                        {
                            return true;
                        }
                        else
                        {
                            // backtrack
                            board[row][col] = 0;
                        }
                    }

                }
                return false;
            }

        }

    }
    return true;
}
void solveSudoKu(vector<vector<int> >& sudoku)
{
    solve(sudoku);
}


int main()
{




    return 0;
}