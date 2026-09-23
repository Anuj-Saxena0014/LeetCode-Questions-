class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i =1;i<n;i++){
            int a = i;
            int b= n-a;
            if(to_string(a).find('0') == string :: npos &&
            to_string(b).find('0') == string :: npos){
                return {a,b};
            }
        }
        return {};
    }
};