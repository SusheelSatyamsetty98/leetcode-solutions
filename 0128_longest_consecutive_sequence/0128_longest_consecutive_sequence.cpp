class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> mp;

        if(nums.size() <= 0)
            return 0;
        else if (nums.size() == 1)
            return 1;

        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]] = 1;
        
        int i = 0;
        auto it = mp.begin();
        int val = it->first;
        int idx = 1;
        int maxLen = 0;
        
        if (it != mp.end()) {
            ++it;
        }
        
        for (; it != mp.end(); ++it)
        {
            if(abs(it->first - val) != 1)
            {
                maxLen = max(maxLen,idx);
                idx = 1;
            }
            else
                idx++;
            val = it->first;
        }
        maxLen = max(maxLen,idx);
        return maxLen;
    }
};