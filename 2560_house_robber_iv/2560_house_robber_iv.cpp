class Solution {
public:
    bool isPossible(vector<int>& nums, int cap,int k)
    {
        int ch = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] <= cap)
            {
                i++;
                ch++;
            }
        }
        return (ch >= k) ? true : false;
    }
    int minCapability(vector<int>& nums, int k) {
        int l = 1;
        int r = *max_element(nums.begin(),nums.end());
        int m;
        while(l <= r)
        {
            m = (l + (r-l) / 2);
            if(isPossible(nums,m,k))
            {
                r = m - 1;
            }
            else l = m + 1;
        }
        return l;
    }
};