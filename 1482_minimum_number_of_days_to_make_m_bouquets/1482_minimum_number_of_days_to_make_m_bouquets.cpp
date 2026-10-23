class Solution {
public:
    bool isPossible(vector<int>& d, int m, int k,int cap) {
        int temp_k = 0;
        int temp_m = 0;
        for(int i = 0;i < d.size(); i++)
        {
            if(d[i] <= cap)
            {
                temp_k++;
                if(temp_k == k)
                {
                    temp_k = 0;
                    temp_m++;
                }
            }
            else temp_k = 0;
        }
        return (temp_m >= m) ? true : false;
    }

    int minDays(vector<int>& d, int m, int k)
    {
        if(d.size() < (long long)m * k ) return -1;
        long long l = 1;
        long long r = *max_element(d.begin(),d.end());
        r *= d.size();
        long long mid = 0;


        while(l < r)
        {
            mid = (l + (r - l) / 2);
            if(isPossible(d,m,k,mid)) r = mid;
            else l = mid + 1;
        }
        
        return r;
    }
};