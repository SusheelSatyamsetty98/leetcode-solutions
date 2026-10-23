class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& i)
    {
        int res = 1;
        sort(i.begin(),i.end(),cmp);
        int prev_start = i[0][0];
        int prev_end = i[0][1];
        for(int idx = 0; idx < i.size(); idx++)
        {
            int curr_start = i[idx][0];
            int curr_end = i[idx][1];
            if(curr_start >= prev_end)
            {
                res++;
                prev_start = curr_start;
                prev_end = curr_end;
            }
        }
        return i.size() - res;        
    }
};