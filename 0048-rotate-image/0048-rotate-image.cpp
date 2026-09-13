class Solution {
public:

void badaldo(vector<vector<int>>& mat){
       int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
        swap(mat[i][j], mat[j][i]);
    }
}
}

void reverse (vector<vector<int>>& mat){
int row =0;
int n = mat.size();
while(row<n){
int start = 0;
int end = mat.size()-1;
while(start<end){
    swap(mat[row][start],mat[row][end]);
    start++;
    end--;
}
row++;
}


}

    void rotate(vector<vector<int>>& mat) {
 badaldo(mat);
 return reverse(mat);

       
    }
};