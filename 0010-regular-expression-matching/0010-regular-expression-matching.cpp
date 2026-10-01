class Solution {
public:
    int dp[21][21];
    bool solve(int i , int j ,string &s,string &p){
        if(j == p.size()){
            return i == s.size();
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
    bool fst_ch_mch = false;
    if(i< s.size() && (s[i] == p[j] || p[j] == '.')){
        fst_ch_mch= true;
    }
    if(j+1 < p.size() && p[j+1] == '*'){
        bool not_take = solve(i,j+2,s,p);
        bool take = fst_ch_mch && solve(i+1,j,s,p);

        return dp[i][j] = not_take || take;
    }
    return dp[i][j] = fst_ch_mch && solve(i+1,j+1,s,p);
    }
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,p);
    }
};