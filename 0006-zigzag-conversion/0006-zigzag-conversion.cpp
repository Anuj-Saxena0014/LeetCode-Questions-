class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return  s;
        int n= s.size();
        string str ="";
        int jump = (numRows -1)*2;
        for(int i =0; i<numRows;i++){
            for(int j =i;j<n;j+=jump){
          str += s[j];
          if(i>0 && i<numRows-1 && (j+jump -2*i) < n){
            str += s[j+jump - 2*i];
          }
            }
        }
        return str;
    }
};