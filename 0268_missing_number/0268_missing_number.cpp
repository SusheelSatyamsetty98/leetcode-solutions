class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 1;
        int sum_arr = 0;
        int sum_idx = 0;
        
        for(auto it : nums)
        {
            sum_arr += it;
            sum_idx += i;
            i++;
        }
        
        (sum_arr == sum_idx) ? i = 0 : i = abs(sum_arr - sum_idx);
        
        return i;    
    }
};