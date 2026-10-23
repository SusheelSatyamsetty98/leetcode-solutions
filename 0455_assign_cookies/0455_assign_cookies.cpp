class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int n = g.size();
        int m = s.size();
        int j =0;
        
        for(int i = 0; (i < m) && (j < n); i++)
        {
            if(s[i] >= g[j])
                j++;
        }
        
        return j;
    }
};