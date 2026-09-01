class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));

        int srow = 0, erow= n- 1;
        int scol = 0, ecol= n- 1;

        int num = 1;

        while(srow <= erow && scol <= ecol) {

            for(int j = scol; j <= ecol; j++) {
                mat[srow][j] = num++;
            }
            for(int i = srow + 1; i <= erow; i++) {
                mat[i][ecol] = num++;
            }

            for(int j = ecol - 1; j >= scol; j--) {
                if(srow == erow)
                    break;

                mat[erow][j] = num++;
            }

            for(int i = erow - 1; i >= srow + 1; i--) {
                if(scol == ecol)
                    break;

                mat[i][scol] = num++;
            }

            srow++;
            erow--;
            scol++;
            ecol--;
        }

        return mat; 
    }
};