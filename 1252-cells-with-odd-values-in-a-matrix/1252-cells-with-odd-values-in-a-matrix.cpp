class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> nmat(m, vector<int>(n, 0));
        for(int k=0;k<indices.size();k++){
            int r = indices[k][0];
            int c = indices[k][1];
        
        for(int j=0;j<n;j++){
            nmat[r][j]++;
        }
        for(int i=0;i<m;i++){
            nmat[i][c]++;
        }
        }
        int count=0;
        for(int i =0;i<nmat.size();i++){
            for(int j =0;j<nmat[0].size();j++){
                if(nmat[i][j] % 2 != 0){
                    count++;
                }
            }
        }
        return count;
    }
};