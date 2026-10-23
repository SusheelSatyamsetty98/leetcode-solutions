class Solution {
public:
    int n = 0;
    void helpfn(int i, vector<int>& arr,vector<int>& temp, vector<vector<int>>& res)
    {
        if(i >= n)
        {
            res.push_back(temp);
            return;
        }

        for(int j = i; j < n; j++)
        {
            temp.push_back(arr[i]);
            helpfn(j+1, arr, temp, res);
            temp.pop_back();
        }

        return;
    }
    vector<vector<int>> subsets(vector<int>& arr)
    {
        n = arr.size();
        vector<int> temp;
        vector<vector<int>> res;
        temp.clear();
        res.push_back(temp);
        
        for(int i = 0; i < n ; i++)
        {
            helpfn(i,arr,temp,res);
            temp.clear();
        }  

        return res;
    }
};