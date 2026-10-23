class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        sort(p.begin(),p.end());
        sort(t.begin(),t.end());
        int res = 0;
        int p_ptr = 0;
        int t_ptr = 0;

        while(p_ptr < p.size() && t_ptr < t.size())
        {
            if(p[p_ptr] <= t[t_ptr])
            {
                p_ptr++;
                res++;
            }
            t_ptr++;
        }
        return res;
    }
};