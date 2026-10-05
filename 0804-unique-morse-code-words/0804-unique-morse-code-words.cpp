class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> s;
        for(auto wrd : words){
            string str = "";
            for(auto ch : wrd ){
                str += morse[ch-'a'];
            }
                s.insert(str);
        }
        return s.size();
    }
};