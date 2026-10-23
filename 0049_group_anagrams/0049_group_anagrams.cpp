class Solution {
public:
    string calHashForString(string str)
    {
        string res;
        vector<int> hash(26,0);
        int size = str.size();

        for(int i = 0; i < size; i++)
        {
            hash[str[i]-'a'] += 1;
        }

        res.assign(hash.begin(),hash.end());

        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        map<string,vector<int>> mp;
        vector<vector<string>> res;
        
        int str_size = strs.size();
        for(int i = 0; i < str_size; i++)
        {
            string hashkey = calHashForString(strs[i]);
            mp[hashkey].push_back(i);
        }
        
        for(auto &[k,s] : mp)
        {
            vector<string> temp;
            for(int i : s)
            {
                temp.push_back(strs[i]);
            }
            res.push_back(temp);
        }

        return res;
    }
};
