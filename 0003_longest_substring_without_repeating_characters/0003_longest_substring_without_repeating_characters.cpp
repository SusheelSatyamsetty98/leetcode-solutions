class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int,int> mp;
        
        if(s.size() <= 1)
            return s.size();
        
        size_t i = 0;
        size_t j = i+1;
        mp.clear();
        size_t res = 0;
        
        mp[s[i]-'a'] = i + 1;
        while(j < s.size())
        {
            if(mp[s[j]-'a'])
            {
                res = max(res,mp.size());
                while(1)
                {
                    if (mp[s[i]-'a'] == mp[s[j] - 'a'])
                    {
                       mp.erase(s[i]-'a');
                        i++; 
                        break;
                    }
                    mp.erase(s[i]-'a');
                    i++;
                }
            }
            
            mp[s[j]-'a'] = j + 1;

            j++;
        }

        res = max(res,mp.size());
        return res;
    }
};