class Solution {
public:
    bool validbox(vector<vector<char>>& board, int sr, int er, int sc , int ec){
        unordered_set<char> s;
        for(int i =sr; i<= er; i++ ){
            for(int j = sc; j<= ec;j++){
               if(board[i][j]== '.' ) continue;

                if(s.find(board[i][j]) != s.end())
                 return false;
            
            s.insert(board[i][j]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
      
      for(int r =0; r< 9 ; r++){
        unordered_set<char> s;
        for(int c =0; c <9; c++){
            if(board[r][c] == '.') continue;

            if(s.find(board[r][c]) != s.end()) {
                return false;
            }
            s.insert(board[r][c]);
        }
      }

      for(int c =0; c< 9 ; c++){
        unordered_set<char> s;
        for(int r =0; r <9; r++){
            if(board[r][c] == '.') continue;

            if(s.find(board[r][c]) != s.end()) {
                return false;
            }
            s.insert(board[r][c]);
        }
      }
      
      for(int sr =0; sr<9; sr+=3){
        int er = sr+2;
        for(int sc =0; sc<9; sc+=3){
            int ec = sc+2;

            if(!validbox(board,sr,er, sc, ec)){
                return false;
            }
        }
      }
    return true;
    }
};