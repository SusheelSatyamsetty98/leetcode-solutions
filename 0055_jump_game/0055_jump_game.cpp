class Solution {
public:
    bool canJump(vector<int>& nums) {
        int res = 0;
        int sz = nums.size();
        if(sz == 1) return true;
        for(int i = 0; i < sz; i++)
        {
            if(i > res) return false;
            res = max(res,i+nums[i]);
        }
        return true;
    }
};