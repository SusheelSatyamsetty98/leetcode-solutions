class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<int,vector<int>> mp;
        vector<int> res;
        int sz = s.size();
        for(int i = 0; i < sz; i++)
        {
            if(mp.find(s[i]) == mp.end()) mp[s[i]] = {i,i};
            else mp[s[i]][1] = i;
        }

        int maxIdx = mp[s[0]][1];
        int old = 0;
        for(int i = 1; i < sz; i++)
        {
            if(mp[s[i]][0] < maxIdx)
            {
                maxIdx = max(maxIdx, mp[s[i]][1]);
            }
            else
            {
                res.push_back(maxIdx+1-old);
                old = maxIdx+1;
                maxIdx = mp[s[i]][1];
            }
        }
        res.push_back(maxIdx+1-old);
        return res; 
    }
};