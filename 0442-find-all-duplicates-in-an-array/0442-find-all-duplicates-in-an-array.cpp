class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;

        for (int x : nums){
            mp[x]++;
        }

        for (auto& it : mp){
            if (it.second == 2){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};