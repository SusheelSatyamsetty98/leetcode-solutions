class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i = 1;
        set<int> a;
        vector<int> res;
        
        for(auto it : nums)
        {
            a.insert(it);
        }
        
        // i = *a.rbegin();
        set<int>::iterator it = a.begin(); 
        for(int i = 1; i <= nums.size(); i++)
        {
            if(i != *it)
            {
                res.push_back(i);
            }
            else
            {
                it++;
            }
        }
        
        return res;
    }
};