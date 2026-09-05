class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
      unordered_map<int, int> freq;
       for(int x : nums){
            freq[x]++;
        }
         int mfreq = 0;
        for(auto &it : freq){
            mfreq = max(mfreq, it.second);
        }
        int ans = 0;
         for(auto &it : freq){
            if(it.second == mfreq){
                ans += it.second;
            }
        }

        return ans;  
    }
};