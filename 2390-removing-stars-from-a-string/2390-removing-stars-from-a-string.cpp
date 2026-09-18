class Solution {
public:
    string removeStars(string s) {
        string str = "";
        for(char ch : s){
            if(ch != '*'){
                str.push_back(ch);
            }
            else{
                str.pop_back();
            }
        }
        return str;
    }
};