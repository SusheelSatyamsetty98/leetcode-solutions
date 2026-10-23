class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        map<int,int> mp;
        vector<int> res;

        int sz = nums.size();
        for(int i = 0; i < sz; i++)
        {
            if(mp.find(target - nums[i]) != mp.end())
            {
                res.push_back(mp[target - nums[i]]);
                res.push_back(i);
                return res;
            }
            else
            {
                mp[nums[i]] = i;
            }
        }
        return res;
    }
};
