class Solution {
public:
    long long isPossible(int cap,vector<int>& p) {
        long long cnt = 0;
        for(int i : p) cnt += (i + cap - 1)/cap;
        return cnt;

    }
    int minEatingSpeed(vector<int>& p, int h) {
        int l = 1;
        int r = *max_element(p.begin(), p.end());
        int m = 0;
        if(p.size() == 1) return (p[0] + h - 1)/h;
        while(l <= r)
        {
            m = (l + (r - l) / 2);
            if(isPossible(m,p) <= h)
            {
                r = m - 1;
            }
            else l = m + 1;
        }
        return l;
    }
};