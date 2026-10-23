class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;

        int min =prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            // for(auto it = out.begin(); it != out.end(); it++)
            // {
            //     if((prices[i] - *it) > max)
            //     {
            //         max = prices[i] - *it;
            //     }
            // }
            // out.push_back(prices[i]);
            int cost = prices[i] - min;
            max = (max > cost) ? max : cost;
            min = (min < prices[i]) ? min : prices[i];
        }
        return max;    
    }
};