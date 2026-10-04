class Solution {
public: 
    int dp[101][101];
    bool solve(int idx, int bal , string &s){
        if(bal <0) return false;
        if(idx == s.size()){
        return bal ==0;
        }

        if (dp[idx][bal] != -1)
            return dp[idx][bal];

        char cc = s[idx];
        if(cc == '('){
            return dp[idx][bal] = solve(idx+1,bal+1,s);
        }
        if(cc == ')'){
             return dp[idx][bal] = solve(idx+1,bal-1,s);
        }
        if(cc == '*'){
            bool usedopen = solve(idx +1, bal+1,s);
            bool usedclose = solve(idx+1,bal-1,s);
            bool usedempty = solve(idx+1,bal,s);

          return dp[idx][bal] = usedopen || usedclose || usedempty;
        }
        return false;
    }
    bool checkValidString(string s) {
        memset(dp, -1, sizeof(dp));
       return solve(0,0,s); 
    }
};