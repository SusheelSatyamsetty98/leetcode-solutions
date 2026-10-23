class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res;  
        int count[101] = {0};
        
        for(auto it : nums)
        {
            count[it]++;
        }

        for(int i = 1; i < 101; i++)
        {
            count[i] += count[i - 1];
        }

        for(auto it : nums)
        {
            res.push_back(it > 0 ? count[it - 1] : 0);
        }
    
        return res;    
    }
};