class Solution {
public:
    vector<vector<int>> final;

    void fn(int idx, vector<int>& c, int target, vector<int>& temp) {
        if((idx >= c.size()) || (temp.empty()) || (target < 0))
        {
            return;
        }
        
        if (0 == target)
        {
            final.push_back(temp);
            return;
        }
        
        temp.push_back(c[idx]);
        fn(idx,c,(target - c[idx]),temp);
        temp.pop_back();
        
        fn(idx+1,c,target,temp);
    }

    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<int> temp;
        
        // sort(c.begin(), c.end());
        
        for(int i = 0; i < c.size(); i++)
        {
            if(c[i] <= target)
            {
                temp.clear();
                temp.push_back(c[i]);
                fn(i,c,target - c[i],temp);
            }
        }
        
        return final;    
    }
};