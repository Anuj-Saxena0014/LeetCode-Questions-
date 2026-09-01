class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> s;
        for(int i =0 ; i<9 ; i++){
            for(int j =0; j<9; j++){
                if(board[i][j] == '.') continue;

                string r = string(1, board[i][j]) +"_ROW_" + to_string(i);
                string c = string(1, board[i][j]) +"_COL_" + to_string(j);
                string box = string(1, board[i][j]) +"_BOX_" + to_string(i/3) + to_string(j/3);

                if(s.find(r) != s.end()||
                   s.find(c) != s.end() ||
                   s.find(box) != s.end() ){
                    return false;
                   }
                   s.insert(r);
                   s.insert(c);
                   s.insert(box);
            }
        }
        return true;
    }
};