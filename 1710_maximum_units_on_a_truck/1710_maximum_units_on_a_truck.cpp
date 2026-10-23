class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& b, int truckSize) {
        sort(b.begin(),b.end(),cmp);
        int res = 0;
        int n = b.size();
        for(int i = 0; i < n; i++)
        {
            if(truckSize-b[i][0] >= 0) res += (b[i][0] * b[i][1]);
            else if (truckSize-b[i][0] < 0){ res += (b[i][1] * truckSize); break;}
            truckSize -= b[i][0];
        } 
        return res;
    }
};