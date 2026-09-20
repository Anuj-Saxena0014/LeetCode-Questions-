class Solution {
public:
    int reverseDegree(string s) {
          int sum = 0;

        for (int i = 0; i < s.size(); i++) {
            char lower = tolower(s[i]);

            int rev = 26 - (lower - 'a');

            sum += rev * (i + 1);
        }

        return sum; }
};