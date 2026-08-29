class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int maxc = 0;
        for(int x : candies) {
            maxc = max(maxc, x);
        }
        for(int i = 0; i < candies.size(); i++) {
           if(candies[i] + extraCandies >= maxc)
            {
                res.push_back(true);
            }
            else
            {
                res.push_back(false);
            }
        }
       return res;
    }
};