class Solution {
public:
    bool solve(string s,string p){
        if(p.size() == 0){
            return s.size() ==0;
        }
    bool fst_ch_mch = false;
    if(s.size() > 0 && (s[0] == p[0] || p[0] == '.')){
        fst_ch_mch= true;
    }
    if(p.size() >= 2 && p[1] == '*'){
        bool not_take = solve(s,p.substr(2));
        bool take = fst_ch_mch && solve(s.substr(1),p);

        return not_take || take;
    }
    return fst_ch_mch && solve(s.substr(1),p.substr(1));
    }
    bool isMatch(string s, string p) {
        return solve(s,p);
    }
};