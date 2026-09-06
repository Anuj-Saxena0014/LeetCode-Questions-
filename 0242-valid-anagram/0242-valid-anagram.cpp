class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        
        vector <int> str(26); 
        for(int i=0 ; i<s.size(); i++)
            str[s[i]-'a']++;
         for(int i= 0 ; i<t.size();i++ ){
            int x = --str[t[i]-'a'];
            if(x < 0 )
             return false;
         
        }
        return true;
    }
};