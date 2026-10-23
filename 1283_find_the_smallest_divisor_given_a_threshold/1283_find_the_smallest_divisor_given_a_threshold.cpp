class Solution {
public:
    long long isPossible(vector<int>& nums, int mid) {
        long long res = 0;
        long long test = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            res += (nums[i]-1)/mid + 1;
        }
        return res;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        int m = 0;

        while(l < r)
        {
            m = (l + (r - l) / 2);
            if(isPossible(nums,m) <= threshold) r = m;
            else l = m + 1;
        }    
        
        return r;
    }
};