#include<bits/stdc++.h>

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = accumulate(nums.begin(),nums.end(),0);
        if(target > l) return 0;
        else if (target == l) return nums.size();
        
        l = 0;
        int r = 0;
        int res = INT_MAX;
        int sum = 0;
        int sz = nums.size();
        while(r < sz)
        {
            sum += nums[r];
            while(sum >= target)
            {
                res = min(res, (r-l+1));
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return res;
    }
};