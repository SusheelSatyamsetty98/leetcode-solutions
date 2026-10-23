class Solution {
public:
    long long isPossible(vector<int>& nums, int cap) {
        long long res = 0;
        for(int i = 0; i < nums.size(); i++) res += (nums[i]-1)/cap;
        return res;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        int m = 0;
        if(maxOperations > r) return 1;
        while(l < r)
        {
            m = (l + (r - l) / 2);
            if(isPossible(nums,m) <= maxOperations) r = m;
            else l = m + 1;
        }    
        return r;
    }
};