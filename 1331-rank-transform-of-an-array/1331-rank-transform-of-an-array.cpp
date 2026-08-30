class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
      vector<int> copy = arr;
      sort(copy.begin(), copy.end());
      unordered_map<int, int> rank;
      int r = 1;
      for(int i = 0; i < copy.size(); i++) {
          if(rank.find(copy[i]) == rank.end()) {
                rank[copy[i]] = r;
                r++;
            }
        }

        vector<int> ans;

        for(int x : arr) {
            ans.push_back(rank[x]);
        }

        return ans;
    }
};