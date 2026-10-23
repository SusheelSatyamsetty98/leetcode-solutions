class Solution {
public:
    bool isPossible(vector<int>& c, int cap, long long k)
    {
        long long cnt = 0;
        for(int i = 0; i < c.size(); i++)
        {
            cnt += c[i]/cap;
        }
        return (cnt >= k) ? true : false; 
    }
    
    int maximumCandies(vector<int>& c, long long k)
    {
        sort(c.begin(),c.end());
        int l = 1;
        int r = *max_element(c.begin(), c.end());
        int res = 0;
        int m = 0;

        while(l <= r)
        {
            m = (l + (r - l) / 2);
            if(isPossible(c,m,k))
            {
                res = m;
                l = m + 1;
            }
            else r = m - 1;
        }
        return res;        
    }
};