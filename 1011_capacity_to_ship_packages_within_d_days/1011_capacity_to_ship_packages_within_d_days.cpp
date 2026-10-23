class Solution {
public:
    int isPossible(vector<int>& weights, int mid,int days) {
        int res = 1;
        int temp = 0;
        for(int i = 0;i < weights.size(); i++)
        {
            if(temp + weights[i] <= mid) temp += weights[i];
            else
            {
                res++;
                temp = weights[i];
            }
        }
        return (res <= days) ? true : false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end());
        int r = accumulate(weights.begin(),weights.end(),0);
        int m = 0;

        while(l < r)
        {
            m = (l + (r - l) / 2);
            if(isPossible(weights,m,days)) r = m;
            else l = m + 1;
        }
        return r;
    }
};