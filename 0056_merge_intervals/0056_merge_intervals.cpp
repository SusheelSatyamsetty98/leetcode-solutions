class Solution {
  public:
    static bool compare(vector<int> n1, vector<int> n2)
    {
        return n1.front() < n2.front();
    }
    vector<vector<int>> merge(vector<vector<int>>& vct)
    {
        int n = vct.size();

        if(n <= 1)
        {
            return vct;
        }

        vector<vector<int>> ans;
        vector<int> temp;
        sort(vct.begin(),vct.end(),compare);

        auto it = vct.begin();
        temp = *it;
        it++;

        for(it; it != vct.end(); ++it)
        {
            if(temp[1] >= (*it)[0])
            {
                temp[0] = min(temp[0],(*it)[0]);
                temp[1] = max(temp[1],(*it)[1]); 
            }
            else if(temp[1] < (*it)[0])
            {
                ans.push_back(temp);
                temp = *it;
            }
        }
        ans.push_back(temp);

        return ans;
    }
};