class Solution {
public:
    int openLock(vector<string>& de, string target)
    {
        int res = 0;
        string start = "0000";
        int tr_sz = target.size();
        queue<string> q;
        unordered_map<string,int> mp;
        unordered_set<string> s(de.begin(),de.end());
        
        q.push(start);
        mp[start] = 1;

        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                string curr = q.front();
                q.pop();
                
                if(s.count(curr)) continue;

                if(curr == target) return res;

                for(int i = 0; i < tr_sz; i++)
                {
                    string neigh1 = curr;
                    int temp = neigh1[i] - '0';
                    temp += 1;
                    if(temp == 10) neigh1[i] = '0';
                    else neigh1[i] = temp + '0';
                    if(!s.count(neigh1) && !mp.count(neigh1))
                    {
                        mp[neigh1] = 1;
                        q.push(neigh1);
                        cout << neigh1 << " ";
                    }

                    string neigh2 = curr;
                    temp = neigh2[i] - '0';
                    temp -= 1;
                    if(temp == -1) neigh2[i] = '9';
                    else neigh2[i] = temp + '0';
                    if(!s.count(neigh2) && !mp.count(neigh2))
                    {
                        mp[neigh2] = 1;
                        q.push(neigh2);
                        // cout << neigh << " ";
                    }
                }
            }
            res++;
        }

        return -1;
    }
};