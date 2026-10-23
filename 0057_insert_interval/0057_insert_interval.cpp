class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& itr, vector<int>& newitr) {
        vector<vector<int>> res;
        int n = itr.size();
        int i = 0;
        while((i < n) && (itr[i][1] < newitr[0]))
        {
            res.push_back(itr[i]);
            i++;
        }
        while((i < n) && (newitr[1] >= itr[i][0]))
        {
            newitr[0] = min(newitr[0],itr[i][0]);
            newitr[1] = max(newitr[1], itr[i][1]);
            i++;
        }
        res.push_back(newitr);
        for(i; i < n; i++)
        {
            res.push_back(itr[i]);
        }
        return res;
    }
};