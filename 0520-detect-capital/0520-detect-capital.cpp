class Solution {
public:
    bool detectCapitalUse(string word) {
        int upp =0;
        for(char ch: word){
            if(isupper(ch)){
                upp++;
            }
        }
        if(upp == word.size() || upp == 0){
            return true;
        }
        if(isupper(word[0])  && upp == 1){
            return true;
        } 
        return false;
    }
};