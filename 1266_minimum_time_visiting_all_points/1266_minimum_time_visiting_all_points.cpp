class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        auto prev = points[0];

        for(int i = 1; i < points.size(); i++)
        {
            auto current = points[i];
            res += max(abs(current[0] - prev[0]), abs(current[1] - prev[1]));
            prev = points[i];
        }

        return res;  
    }
};