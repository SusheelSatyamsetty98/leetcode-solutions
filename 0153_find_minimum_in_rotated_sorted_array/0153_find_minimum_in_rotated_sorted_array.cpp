class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int mid =0;

        mid = low + (high-low)/2;

        if(nums[mid] > nums[high])
        {
            low = mid+1;
        }
        else if(nums[mid] < nums[high])
        {
            high = mid -1;
        }
        
        while(low <= high)
        {
            if(mid-1 >= 0 && mid +1 < nums.size())
            {
                if(nums[mid-1] > nums[mid] && nums[mid+1] > nums[mid])
                {
                    break;
                }
            }
            
            mid = low + (high-low)/2;

            if(nums[mid] > nums[high])
            {
                low = mid+1;
            }
            else if(nums[mid] < nums[high])
            {
                high = mid -1;
            }
            else
            {
                break;
            }
        }
        
        return nums[mid];
    }
};