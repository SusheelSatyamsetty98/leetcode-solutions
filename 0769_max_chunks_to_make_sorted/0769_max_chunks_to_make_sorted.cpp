class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int pre = 0;
        int act =0;
        int res = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            pre += i;
            act += arr[i];
            if(pre == act) res++;
        }    
        return res;
    }
};