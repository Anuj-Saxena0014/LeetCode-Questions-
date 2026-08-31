class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        int x0 = c[0][0];
        int y0 = c[0][1];
        int x1 = c[1][0];
        int y1 = c[1][1];
        for (int i = 2; i < c.size(); i++) {
            int x = c[i][0];
            int y = c[i][1];
            if ((y - y0) * (x1 - x0) != (y1 - y0) * (x - x0)) {
                return false;
            }
        }
        return true;
    }
};