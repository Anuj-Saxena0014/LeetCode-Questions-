class Solution {
public:
    int countSegments(string s) {
        int c =0;
        stringstream wordhai(s);
        string str;
        while(wordhai >> str){
            c++;
        }
        return c;
    }
};