/*

    Time Complexity : O(9^(N*N)) : For every unassigned index there are 9 possible options so the worst-case time
    complexity of sudoku solver is O(9^(N*N)).

    Space Complexity : O(1), Constant space.

    Solved using Matrix + Backtracking.

*/

class Solution {
private:
    bool isValid(vector<vector<char>>& board, int row, int col, char ch){
        for(int i=0; i<9; i++){
            if(board[i][col] == ch){
                return false;
            }
            if(board[row][i] == ch){
                return false;
            }
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == ch){
                return false;
            }
 //    int sq=(int)sqrt(9);
	// int rs=r-r%sq;
	// int cs=c-c%sq;
	// for(int i=rs;i<rs+sq;i++){
	// 	for(int j=cs;j<cs+sq;j++){
	// 		if(grid[i][j]==x)return false;
	// 	}
	// }
      //  }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == '.'){
                    for(char ch='1'; ch<='9'; ch++){
                        if(isValid(board, i, j, ch)){
                            board[i][j] = ch;
                            if(solve(board) == true){
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
