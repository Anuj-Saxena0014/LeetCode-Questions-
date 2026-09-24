class Solution{
public:
    vector<int> constructRectangle(int area){
        
        int mindiff = INT_MAX;
        vector<int> ans;

        for(int i = 1; i <= area; i++){
            if(area % i == 0){
                int j = area / i;
                if(i >= j) {
                int diff = i - j;
                if(diff < mindiff){
                   mindiff = diff;
                    ans = {i, j};
                    }
                }
            }
        }
        return ans;
    }
};