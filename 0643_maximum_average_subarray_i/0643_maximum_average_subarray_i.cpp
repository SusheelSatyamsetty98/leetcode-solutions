class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(nums.size() <= 1)
        {
            return static_cast<double>(nums[nums.size()-1]);  
        }
    
        int i = 0;
        int j = 0;
        double sum = 0;
        double res = INT_MIN;
        int temp = 0;

        while(j < nums.size())
        {
            temp++;
            sum += nums[j];

            if(temp == k)
            {
                res = max(res,(sum/k));
                sum -= nums[i];
                i++;
                temp--;
            }
            j++;
        }
        return res;
    }
};