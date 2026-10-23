class Solution {
public:
    bool isPossible(string s, string p, vector<int>& rm, int cap)
    {
        string temp = s;
        for(int i = 0; i < cap && i < rm.size(); i++)
        {
            temp[rm[i]] = '*';
        }

        int j = 0;

        for(int i = 0;i < temp.size() && j < p.size(); i++)
        {
            if(temp[i] == '*') i++;
            if(temp[i] == p[j]) j++;
        }
        return (j == p.size()) ? true : false;
    }

    int maximumRemovals(string s, string p, vector<int>& rm)
    {
        int l = 0;
        int r = rm.size();
        int res = 0;
        int m = 0;

        while(l <= r)
        {
            m = l + (r - l) / 2;
            if(isPossible(s,p,rm,m))
            {
                res = m;
                l = m + 1;
            }
            else r = m - 1;
        }
        return res;
    }
};