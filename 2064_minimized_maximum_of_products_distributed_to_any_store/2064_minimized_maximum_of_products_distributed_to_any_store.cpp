class Solution {
public:
    long long isPossible(vector<int>& q, int cap)
    {
        long long cnt = 0;
        for(int i : q) cnt += (i + cap - 1) / cap;
        return cnt;
    }
    
    int minimizedMaximum(int n, vector<int>& q) {
        int l = 1;
        int r = *max_element(q.begin(),q.end());

        while(l < r)
        {
            int m = l + (r - l) / 2;
            if(isPossible(q,m) <= n) r = m;
            else l = m + 1;
        }
        return r;
    }
};