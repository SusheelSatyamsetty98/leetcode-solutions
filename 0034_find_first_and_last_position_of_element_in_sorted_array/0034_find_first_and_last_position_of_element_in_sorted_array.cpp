class Solution {
public:
    int lb(vector<int>& nums, int target,bool isLowerBound)
    {
        int res = -1;
        long int low = 0;
        long int high = nums.size()-1;
        
        while(low <= high)
        {
            int mid = low+(high-low)/2;
            
            if(nums[mid] == target)
            {
                res = mid;
                if(isLowerBound)
                    high = mid - 1; // first
                else
                    low = mid + 1; // second
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid -1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int last = -1;
        vector<int> res;
        
        first = lb(nums,target,true);
        if(first == -1)
        {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        
        last = lb(nums,target,false);
        res.push_back(first);
        res.push_back(last);
        
        return res;
        
    }
};