class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
       int m = mat.size();
        int n = mat[0].size();
        vector<pair<int, int>> rows;

        for(int i = 0; i < m; i++) {
            int soldiers = 0;

            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1) {
                    soldiers++;
                }
            }

            rows.push_back({soldiers, i});
        }

        sort(rows.begin(), rows.end());

        vector<int> ans;

        for(int i = 0; i < k; i++) {
            ans.push_back(rows[i].second);
        }

        return ans;
    }
};