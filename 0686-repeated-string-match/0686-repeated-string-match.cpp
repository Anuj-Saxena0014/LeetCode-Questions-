class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string ans ="";
        int c=0;
       while(ans.size()< b.size()){
        ans +=a;
        c++;
        }
        if(ans.find(b) !=string::npos) return c;
        ans += a;
        c++;
        if(ans.find(b) !=string::npos)  return c;
        return -1;
    }
};