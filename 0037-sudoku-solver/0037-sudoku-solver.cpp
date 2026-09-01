class Solution {
public:
    bool rakhdo(vector<vector<char>> & board, int row , int col , char dig){
        // H
        for(int j =0; j< 9; j++){
            if(board[row][j] == dig) {
                return false;
            }
        }
        //  V
        for(int i =0 ; i<9; i++){
            if(board[i][col] == dig){
                return false;
            }
        }
        // grid dekh le bHAI
        int srow = (row/3)*3;
        int scol = (col/3)*3;
        for(int i =srow; i<srow+3; i++){
            for(int j= scol ; j<scol+3; j++ ){
                if(board[i][j] == dig){
                    return false;
                }
            }
        }
        return true;
      }
    bool help(vector<vector<char>>& board , int row , int col){
      if(row == 9 ){
        return true;
      }
      int nxtrow = row;
      int nxtcol = col+1;
      if(nxtcol == 9){
        nxtrow = row+1;
        nxtcol = 0;
      }
      if(board[row][col] != '.'){
        return help(board , nxtrow, nxtcol);
      }

      for(char dig ='1'; dig<='9';dig++){
        if(rakhdo(board,row,col,dig)){
            board[row][col] =dig ;
            if(help(board,nxtrow,nxtcol)){
                return true;
            }
            board[row][col] = '.';
        }
      }
      return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        help(board,0,0);
    }
};