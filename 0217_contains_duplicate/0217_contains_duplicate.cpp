class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool res = false;
        set<int> a;
        
        for(auto it : nums)
        {
            a.insert(it);
        }
        
        (a.size() == nums.size()) ? res = false : res = true;
        
        return res; 
    }
};