class Solution {
public:
    string reformatDate(string date) {
        int n = date.length();
        string year = date.substr(n - 4, 4);
        string monthStr = date.substr(n - 8, 3);
        string day = isdigit(date[1]) ? date.substr(0, 2) : "0" + date.substr(0, 1);
        
        vector<string> months ={
            "Jan", "Feb", "Mar", "Apr", "May", "Jun", 
            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
        };
        
        string mon = "";
        for (int i = 0; i < 12; i++){
            if (months[i] == monthStr){
                mon = (i + 1 < 10 ? "0" : "") + to_string(i + 1);
                break;
            }
        }
        
        return year + "-" + mon + "-" + day;
    }
};